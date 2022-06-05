#include "stm32f1xx.h"
#include "tim.h"
#include "i2c.h"

#define I2C_OWNADDRESS_7BIT 0x00004000U
#define I2C_MODE_I2C 0x00000000U
#define SLAVE_OWN_ADDRESS 0xD0 // real address is 0x68
#define I2C_REQUEST_WRITE 0x00
#define I2C_REQUEST_READ  0x01

__IO uint32_t tmpreg;

void I2C1init(void) {
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN; // port B clock enable
    RCC->APB2ENR |= RCC_APB2ENR_AFIOEN; // Alternate Function I/O clock enable

    // I2C1_SCL
    GPIOB->CRL |= GPIO_CRL_MODE6; // output mode, max speed 50 Mhz
    GPIOB->CRL |= GPIO_CRL_CNF6_0; // AF output open-drain
    GPIOB->CRL |= GPIO_CRL_CNF6_1; // AF output open-drain

    // I2C1_SDA
    GPIOB->CRL |= GPIO_CRL_MODE7; // output mode, max speed 50 Mhz
    GPIOB->CRL |= GPIO_CRL_CNF7_0; // AF output open-drain
    GPIOB->CRL |= GPIO_CRL_CNF7_1; // AF output open-drain

    SET_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN); // i2c1 clock enable
    tmpreg = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_I2C1EN); // delay after an RCC peripheral clock enabling

    CLEAR_BIT(I2C1->OAR2, I2C_OAR2_ENDUAL); // disable  acknowledge on Own Address2 match address
    CLEAR_BIT(I2C1->CR1, I2C_CR1_ENGC); // disable General Call
    CLEAR_BIT(I2C1->CR1, I2C_CR1_NOSTRETCH); // enable Clock stretching: wait for slave
    CLEAR_BIT(I2C1->CR1, I2C_CR1_PE); // disable I2C peripheral
    MODIFY_REG(I2C1->CR2, I2C_CR2_FREQ, 36);
    MODIFY_REG(I2C1->TRISE, I2C_TRISE_TRISE, 36 + 1); //100
    // MODIFY_REG(I2C1->TRISE, I2C_TRISE_TRISE, 11); //400
    MODIFY_REG(I2C1->CCR, (I2C_CCR_FS | I2C_CCR_DUTY | I2C_CCR_CCR), 180); //100
    // MODIFY_REG(I2C1->CCR, (I2C_CCR_FS | I2C_CCR_DUTY | I2C_CCR_CCR), 0x0000801E); //400

    MODIFY_REG(I2C1->OAR1, I2C_OAR1_ADD0 | I2C_OAR1_ADD1_7 | I2C_OAR1_ADD8_9 | I2C_OAR1_ADDMODE, I2C_OWNADDRESS_7BIT); // set the Own Address1
    MODIFY_REG(I2C1->CR1, I2C_CR1_SMBUS | I2C_CR1_SMBTYPE | I2C_CR1_ENARP, I2C_MODE_I2C); // configure I2C1 peripheral mode with parameter : I2C

    SET_BIT(I2C1->CR1, I2C_CR1_PE); // ensable I2C peripheral

    MODIFY_REG(I2C1->CR1, I2C_CR1_ACK, I2C_CR1_ACK); // TypeAcknowledge
    MODIFY_REG(I2C1->OAR2, I2C_OAR2_ADD2, 0); // set the 7bits Own Address2
}

void I2C1_WriteBytes(uint16_t addr,uint8_t *buf, uint16_t bytes_count) {
    uint16_t i;
    CLEAR_BIT(I2C1->CR1, I2C_CR1_POS); // disable Pos

    // Prepare the generation of a ACKnowledge condition
    // after the address receive match code or next received byte
    MODIFY_REG(I2C1->CR1, I2C_CR1_ACK, I2C_CR1_ACK);

    SET_BIT(I2C1->CR1, I2C_CR1_START); // generate a START condition
    while (!READ_BIT(I2C1->SR1, I2C_SR1_SB)) {}; // indicate the status of Start Bit (master mode)
    (void) I2C1->SR1; // read state

    // Transmit Address SLAVE
    MODIFY_REG(I2C1->DR, I2C_DR_DR, SLAVE_OWN_ADDRESS | I2C_REQUEST_WRITE);
    while (!READ_BIT(I2C1->SR1, I2C_SR1_ADDR)) {};
    (void) I2C1->SR1;
    (void) I2C1->SR2;

    // Transmit address begin
    MODIFY_REG(I2C1->DR, I2C_DR_DR, (uint8_t) addr);
    while (!READ_BIT(I2C1->SR1, I2C_SR1_TXE)) {};

    // Write data
    for(i=0;i<bytes_count;i++) {
        MODIFY_REG(I2C1->DR, I2C_DR_DR, buf[i]);
        while (!READ_BIT(I2C1->SR1, I2C_SR1_TXE)) {};
    }

    SET_BIT(I2C1->CR1, I2C_CR1_STOP); // generate a STOP condition
}

void I2C1_ReadBytes(uint16_t addr, uint8_t *buf, uint16_t bytes_count) {
    uint16_t i;

    //Disable Pos
    CLEAR_BIT(I2C1->CR1, I2C_CR1_POS);

    //Prepare the generation of a ACKnowledge condition
    //after the address receive match code or next received byte
    MODIFY_REG(I2C1->CR1, I2C_CR1_ACK, I2C_CR1_ACK);

    //Generate a START condition
    SET_BIT(I2C1->CR1, I2C_CR1_START);
    //Indicate the status of Start Bit (master mode)
    while (!READ_BIT(I2C1->SR1, I2C_SR1_SB)) {};
    //read state
    (void) I2C1->SR1;

    //Transmit Address
    MODIFY_REG(I2C1->DR, I2C_DR_DR, SLAVE_OWN_ADDRESS | I2C_REQUEST_WRITE);
    while (!READ_BIT(I2C1->SR1, I2C_SR1_ADDR)) {};
    (void) I2C1->SR1;
    (void) I2C1->SR2;

    //Transmit Address begin
    MODIFY_REG(I2C1->DR, I2C_DR_DR, (uint8_t) addr);
    while (!READ_BIT(I2C1->SR1, I2C_SR1_TXE)) {};

    // Repeated Start
    SET_BIT(I2C1->CR1, I2C_CR1_START);
    while (!READ_BIT(I2C1->SR1, I2C_SR1_SB)) {};
    (void) I2C1->SR1;
    //Transmit Address
    MODIFY_REG(I2C1->DR, I2C_DR_DR, SLAVE_OWN_ADDRESS | I2C_REQUEST_READ);
    while (!READ_BIT(I2C1->SR1, I2C_SR1_ADDR)) {};
    (void) I2C1->SR1;
    (void) I2C1->SR2;

    for(i=0;i<bytes_count;i++) {
        if(i<(bytes_count-1)) {
            while (!READ_BIT(I2C1->SR1, I2C_SR1_RXNE)) {};
            buf[i] = READ_BIT(I2C1->DR, I2C_DR_DR);
        } else {
            CLEAR_BIT(I2C1->CR1, I2C_CR1_ACK);
            // Stop
            SET_BIT(I2C1->CR1, I2C_CR1_STOP);
            while (!READ_BIT(I2C1->SR1, I2C_SR1_RXNE)) {};
            buf[i] = READ_BIT(I2C1->DR, I2C_DR_DR);
        }
    }
}
