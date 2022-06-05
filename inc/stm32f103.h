#ifndef _STM32F103_H_
#define _STM32F103_H_ 
 
//0x4002 2000 - 0x4002 23FF  Flash������ӿڼĴ��� /////////////////////
#define  FLASH_ACR          (*(volatile unsigned long *)0x40022000) //FLASH���ʿ��ƼĴ���  
#define  FLASH_KEYR         (*(volatile unsigned long *)0x40022004) //FLASH FPECKEY �Ĵ���
#define  FLASH_OPTKEYR      (*(volatile unsigned long *)0x40022008) //FLASH OTPKEY �Ĵ���
#define  FLASH_SR           (*(volatile unsigned long *)0x4002200C) //FALSH״̬�Ĵ���
#define  FLASH_CR           (*(volatile unsigned long *)0x40022010) //FLASH���ƼĴ���
#define  FLASH_AR           (*(volatile unsigned long *)0x40022014) //FLASH��ַ�Ĵ���
#define  Reserved           (*(volatile unsigned long *)0x40022018) //����
#define  FLASH_OBR          (*(volatile unsigned long *)0x4002201C) //FLASH��ѡ��Ĵ���
#define  FLASH_WRPR         (*(volatile unsigned long *)0x40022020) //FLASHд�����Ĵ���    

            

//0x4002 1000 - 0x4002 13FF ��λ��ʱ�ӿ���///////////////////// 

#define  RCC_CR         (*(volatile unsigned long *)0x40021000) //ʱ�ӿ��ƼĴ��� 
#define  RCC_CFGR       (*(volatile unsigned long *)0x40021004) //ʱ�����üĴ��� 
#define  RCC_CIR        (*(volatile unsigned long *)0x40021008) //ʱ���жϼĴ���  
#define  RCC_APB2RSTR   (*(volatile unsigned long *)0x4002100c) //APB2 ���踴λ�Ĵ��� 
#define  RCC_APB1RSTR   (*(volatile unsigned long *)0x40021010) //APB1 ���踴λ�Ĵ��� 
#define  RCC_AHBENR     (*(volatile unsigned long *)0x40021014) //AHB����ʱ��ʹ�ܼĴ��� 
#define  RCC_APB2ENR    (*(volatile unsigned long *)0x40021018) //APB2 ����ʱ��ʹ�ܼĴ��� 
#define  RCC_APB1ENR    (*(volatile unsigned long *)0x4002101c) //APB1 ����ʱ��ʹ�ܼĴ��� 
#define  RCC_BDCR       (*(volatile unsigned long *)0x40021020) //��������ƼĴ��� 
#define  RCC_CSR        (*(volatile unsigned long *)0x40021024) //����/״̬�Ĵ��� 
//0x4002 0000 - 0x4002 03FF DMA//////////////////////////////// 

#define  DMA_ISR        (*(volatile unsigned long *)0x40020000)//DMA�ж�״̬�Ĵ��� 
#define  DMA_IFCR       (*(volatile unsigned long *)0x40020004)//DMA�жϱ�־����Ĵ��� 
#define  DMA_CCR1       (*(volatile unsigned long *)0x40020008)//DMAͨ�����üĴ���1 
#define  DMA_CCR2       (*(volatile unsigned long *)0x4002001C)//DMAͨ�����üĴ���2 
#define  DMA_CCR3       (*(volatile unsigned long *)0x40020030)//DMAͨ�����üĴ���3 
#define  DMA_CCR4       (*(volatile unsigned long *)0x40020044)//DMAͨ�����üĴ���4 
#define  DMA_CCR5       (*(volatile unsigned long *)0x40020058)//DMAͨ�����üĴ���5 
#define  DMA_CCR6       (*(volatile unsigned long *)0x4002006C)//DMAͨ�����üĴ���6 
#define  DMA_CCR7       (*(volatile unsigned long *)0x40020080)//DMAͨ�����üĴ���7 
#define  DMA_CNDTR1     (*(volatile unsigned long *)0x4002000C)//DMAͨ�����������Ĵ���1 
#define  DMA_CNDTR2     (*(volatile unsigned long *)0x40020020)//DMAͨ�����������Ĵ���2 
#define  DMA_CNDTR3     (*(volatile unsigned long *)0x40020034)//DMAͨ�����������Ĵ���3 
#define  DMA_CNDTR4     (*(volatile unsigned long *)0x40020048)//DMAͨ�����������Ĵ���4 
#define  DMA_CNDTR5     (*(volatile unsigned long *)0x4002005C)//DMAͨ�����������Ĵ���5 
#define  DMA_CNDTR6     (*(volatile unsigned long *)0x40020070)//DMAͨ�����������Ĵ���6 
#define  DMA_CNDTR7     (*(volatile unsigned long *)0x40020054)//DMAͨ�����������Ĵ���7 
#define  DMA_CPAR1      (*(volatile unsigned long *)0x40020010)//DMAͨ�������ַ�Ĵ�1 
#define  DMA_CPAR2      (*(volatile unsigned long *)0x40020024)//DMAͨ�������ַ�Ĵ�2 
#define  DMA_CPAR3      (*(volatile unsigned long *)0x40020038)//DMAͨ�������ַ�Ĵ�3 
#define  DMA_CPAR4      (*(volatile unsigned long *)0x4002004C)//DMAͨ�������ַ�Ĵ�4 
#define  DMA_CPAR5      (*(volatile unsigned long *)0x40020060)//DMAͨ�������ַ�Ĵ�5 
#define  DMA_CPAR6      (*(volatile unsigned long *)0x40020074)//DMAͨ�������ַ�Ĵ�6 
#define  DMA_CPAR7      (*(volatile unsigned long *)0x40020088)//DMAͨ�������ַ�Ĵ�7 
#define  DMA_CMAR1      (*(volatile unsigned long *)0x40020014)//DMAͨ���洢����ַ�Ĵ���1 
#define  DMA_CMAR2      (*(volatile unsigned long *)0x40020028)//DMAͨ���洢����ַ�Ĵ���2 
#define  DMA_CMAR3      (*(volatile unsigned long *)0x4002003C)//DMAͨ���洢����ַ�Ĵ���3 
#define  DMA_CMAR4      (*(volatile unsigned long *)0x40020050)//DMAͨ���洢����ַ�Ĵ���4 
#define  DMA_CMAR5      (*(volatile unsigned long *)0x40020064)//DMAͨ���洢����ַ�Ĵ���5 
#define  DMA_CMAR6      (*(volatile unsigned long *)0x40020078)//DMAͨ���洢����ַ�Ĵ���6 
#define  DMA_CMAR7      (*(volatile unsigned long *)0x4002008C)//DMAͨ���洢����ַ�Ĵ���7 


//0x4001 3800 - 0x4001 3BFF USART1///////////////////////////// 
#define USART1_SR        (*(volatile unsigned long *)0x40013800)//״̬�Ĵ��� 
#define USART1_DR        (*(volatile unsigned long *)0x40013804)//���ݼĴ��� 
#define USART1_BRR       (*(volatile unsigned long *)0x40013808)//���ر��ʼĴ��� 
#define USART1_CR1       (*(volatile unsigned long *)0x4001380C)//���ƼĴ���1 
#define USART1_CR2       (*(volatile unsigned long *)0x40013810)//���ƼĴ���2 
#define USART1_CR3       (*(volatile unsigned long *)0x40013814)//���ƼĴ���3 
#define USART1_GTPR      (*(volatile unsigned long *)0x40013818)//����ʱ���Ԥ��Ƶ�Ĵ��� 

//0x4001 3000 - 0x4001 33FF SPI1/////////////////////////////// 
#define  SPI1_CR1        (*(volatile unsigned long *)0x40013000)//SPI���ƼĴ���1 
#define  SPI1_CR2        (*(volatile unsigned long *)0x40013004)//SPI���ƼĴ���2
#define  SPI1_SR         (*(volatile unsigned long *)0x40013008)//SPI״̬�Ĵ���
#define  SPI1_DR         (*(volatile unsigned long *)0x4001300C)//SPI���ݼĴ���
#define  SPI1_CRCPR      (*(volatile unsigned long *)0x40013010)//SPI CRC����ʽ�Ĵ���
#define  SPI1_RXCRCR     (*(volatile unsigned long *)0x40013014)//SPI CRC Rx�Ĵ���
#define  SPI1_TXCRCR     (*(volatile unsigned long *)0x40013018)//SPI CRC Tx�Ĵ���


//0x4001 2C00 - 0x4001 2FFF TIM1ʱ��/////////////////////////// 
#define  TIM1_CR1      (*(volatile unsigned long *)0x40012C00)//���ƼĴ���1 
#define  TIM1_CR2      (*(volatile unsigned long *)0x40012C04)//���ƼĴ���2 
#define  TIM1_SMCR     (*(volatile unsigned long *)0x40012C08)//��ģʽ���ƼĴ��� 
#define  TIM1_DIER     (*(volatile unsigned long *)0x40012C0C)//DMA/�ж�ʹ�ܼĴ��� 
#define  TIM1_SR       (*(volatile unsigned long *)0x40012C10)//״̬�Ĵ��� 
#define  TIM1_EGR      (*(volatile unsigned long *)0x40012C14)//�¼������Ĵ��� 
#define  TIM1_CCMR1    (*(volatile unsigned long *)0x40012C18)//����/�Ƚ�ģʽ�Ĵ���1 
#define  TIM1_CCMR2    (*(volatile unsigned long *)0x40012C1C)//����/�Ƚ�ģʽ�Ĵ���2 
#define  TIM1_CCER     (*(volatile unsigned long *)0x40012C20)//����/�Ƚ�ʹ�ܼĴ��� 
#define  TIM1_CNT      (*(volatile unsigned long *)0x40012C24)//������ 
#define  TIM1_PSC      (*(volatile unsigned long *)0x40012C28)//Ԥ��Ƶ�� 
#define  TIM1_ARR      (*(volatile unsigned long *)0x40012C2C)//�Զ���װ�ؼĴ��� 
#define  TIM1_RCR      (*(volatile unsigned long *)0x40012C30)//���ڼ����Ĵ��� 
#define  TIM1_CCR1     (*(volatile unsigned long *)0x40012C34)//����/�ȽϼĴ���1 
#define  TIM1_CCR2     (*(volatile unsigned long *)0x40012C38)//����/�ȽϼĴ���2 
#define  TIM1_CCR3     (*(volatile unsigned long *)0x40012C3C)//����/�ȽϼĴ���3 
#define  TIM1_CCR4     (*(volatile unsigned long *)0x40012C40)//����/�ȽϼĴ��� 
#define  TIM1_BDTR     (*(volatile unsigned long *)0x40012C44)//ɲ���������Ĵ��� 
#define  TIM1_DCR      (*(volatile unsigned long *)0x40012C48)//DMA���ƼĴ��� 
#define  TIM1_DMAR     (*(volatile unsigned long *)0x40012C4C)//����ģʽ��DMA��ַ 

//0x4001 2800 - 0x4001 2BFF ADC2/////////////////////////////// 
#define  ADC2_SR        (*(volatile unsigned long *)0x40012400)//ADC״̬�Ĵ��� 
#define  ADC2_CR1       (*(volatile unsigned long *)0x40012404)//ADC���ƼĴ���1 
#define  ADC2_CR2       (*(volatile unsigned long *)0x40012408)//ADC���ƼĴ���2 
#define  ADC2_SMPR1     (*(volatile unsigned long *)0x4001240C)//ADC����ʱ��Ĵ���1 
#define  ADC2_SMPR2     (*(volatile unsigned long *)0x40012410)//ADC����ʱ��Ĵ���2 
#define  ADC2_JOFR1     (*(volatile unsigned long *)0x40012414)//ADCע��ͨ������ƫ�ƼĴ���1 
#define  ADC2_JOFR2     (*(volatile unsigned long *)0x40012418)//ADCע��ͨ������ƫ�ƼĴ���2 
#define  ADC2_JOFR3     (*(volatile unsigned long *)0x4001241C)//ADCע��ͨ������ƫ�ƼĴ���3 
#define  ADC2_JOFR4     (*(volatile unsigned long *)0x40012420)//ADCע��ͨ������ƫ�ƼĴ���4 
#define  ADC2_HTR       (*(volatile unsigned long *)0x40012424)//DC���Ź��߷�ֵ�Ĵ��� 
#define  ADC2_LRT       (*(volatile unsigned long *)0x40012428)//ADC���Ź��ͷ�ֵ�Ĵ��� 
#define  ADC2_SQR1      (*(volatile unsigned long *)0x4001242C)//ADC�������мĴ���1 
#define  ADC2_SQR2      (*(volatile unsigned long *)0x40012430)//ADC�������мĴ���2 
#define  ADC2_SQR3      (*(volatile unsigned long *)0x40012434)//ADC�������мĴ���3 
#define  ADC2_JSQR      (*(volatile unsigned long *)0x40012438)//ADCע�����мĴ��� 
#define  ADC2_JDR1      (*(volatile unsigned long *)0x4001243C)//ADC ע�����ݼĴ���1 
#define  ADC2_JDR2      (*(volatile unsigned long *)0x40012440)//ADC ע�����ݼĴ���2 
#define  ADC2_JDR3      (*(volatile unsigned long *)0x40012444)//ADC ע�����ݼĴ���3 
#define  ADC2_JDR4      (*(volatile unsigned long *)0x40012448)//ADC ע�����ݼĴ���4 
#define  ADC2_DR        (*(volatile unsigned long *)0x4001244C)//ADC�������ݼĴ��� 

//0x4001 2400 - 0x4001 27FF ADC1/////////////////////////////// 
#define  ADC1_SR        (*(volatile unsigned long *)0x40012400)//ADC״̬�Ĵ��� 
#define  ADC1_CR1       (*(volatile unsigned long *)0x40012404)//ADC���ƼĴ���1 
#define  ADC1_CR2       (*(volatile unsigned long *)0x40012408)//ADC���ƼĴ���2 
#define  ADC1_SMPR1     (*(volatile unsigned long *)0x4001240C)//ADC����ʱ��Ĵ���1 
#define  ADC1_SMPR2     (*(volatile unsigned long *)0x40012410)//ADC����ʱ��Ĵ���2 
#define  ADC1_JOFR1     (*(volatile unsigned long *)0x40012414)//ADCע��ͨ������ƫ�ƼĴ���1 
#define  ADC1_JOFR2     (*(volatile unsigned long *)0x40012418)//ADCע��ͨ������ƫ�ƼĴ���2 
#define  ADC1_JOFR3     (*(volatile unsigned long *)0x4001241C)//ADCע��ͨ������ƫ�ƼĴ���3 
#define  ADC1_JOFR4     (*(volatile unsigned long *)0x40012420)//ADCע��ͨ������ƫ�ƼĴ���4 
#define  ADC1_HTR       (*(volatile unsigned long *)0x40012424)//DC���Ź��߷�ֵ�Ĵ��� 
#define  ADC1_LRT       (*(volatile unsigned long *)0x40012428)//ADC���Ź��ͷ�ֵ�Ĵ��� 
#define  ADC1_SQR1      (*(volatile unsigned long *)0x4001242C)//ADC�������мĴ���1 
#define  ADC1_SQR2      (*(volatile unsigned long *)0x40012430)//ADC�������мĴ���2 
#define  ADC1_SQR3      (*(volatile unsigned long *)0x40012434)//ADC�������мĴ���3 
#define  ADC1_JSQR      (*(volatile unsigned long *)0x40012438)//ADCע�����мĴ��� 
#define  ADC1_JDR1      (*(volatile unsigned long *)0x4001243C)//ADC ע�����ݼĴ���1 
#define  ADC1_JDR2      (*(volatile unsigned long *)0x40012440)//ADC ע�����ݼĴ���2 
#define  ADC1_JDR3      (*(volatile unsigned long *)0x40012444)//ADC ע�����ݼĴ���3 
#define  ADC1_JDR4      (*(volatile unsigned long *)0x40012448)//ADC ע�����ݼĴ���4 
#define  ADC1_DR        (*(volatile unsigned long *)0x4001244C)//ADC�������ݼĴ��� 


// 0x4001 1800 - 0x40011BFF GPIOE/////////////////////////////// 
#define GPIOE_CRL       (*(volatile unsigned long *)0x40011800) //�˿�E���õͼĴ��� 
#define GPIOE_CRH       (*(volatile unsigned long *)0x40011804) //�˿�E���ø߼Ĵ��� 
#define GPIOE_IDR        (*(volatile unsigned long *)0x40011808) //�˿�E�������ݼĴ��� 
#define GPIOE_ODR        (*(volatile unsigned long *)0x4001180c) //�˿�E������ݼĴ� 
#define GPIOE_BSRR        (*(volatile unsigned long *)0x40011810) //�˿�Eλ����/��λ�Ĵ��� 
#define GPIOE_BRR        (*(volatile unsigned long *)0x40011814) //�˿�Eλ��λ�Ĵ� 
#define GPIOE_LCKR      (*(volatile unsigned long *)0x40011818) //�˿�E���������Ĵ��� 

//0x4001 1400 - 0x4001 17FF GPIOD////////////////////////////// 
#define GPIOD_CRL       (*(volatile unsigned long *)0x40011400) //�˿�D���õͼĴ��� 
#define GPIOD_CRH       (*(volatile unsigned long *)0x40011404) //�˿�D���ø߼Ĵ��� 
#define GPIOD_IDR        (*(volatile unsigned long *)0x40011408) //�˿�D�������ݼĴ��� 
#define GPIOD_ODR        (*(volatile unsigned long *)0x4001140c) //�˿�D������ݼĴ� 
#define GPIOD_BSRR        (*(volatile unsigned long *)0x40011410) //�˿�Dλ����/��λ�Ĵ��� 
#define GPIOD_BRR        (*(volatile unsigned long *)0x40011414) //�˿�Dλ��λ�Ĵ� 
#define GPIOD_LCKR      (*(volatile unsigned long *)0x40011418) //�˿�D���������Ĵ��� 

//0x4001 1000 - 0x4001 13FF GPIOC////////////////////////////// 
#define GPIOC_CRL       (*(volatile unsigned long *)0x40011000) //�˿�C���õͼĴ��� 
#define GPIOC_CRH       (*(volatile unsigned long *)0x40011004) //�˿�C���ø߼Ĵ��� 
#define GPIOC_IDR        (*(volatile unsigned long *)0x40011008) //�˿�C�������ݼĴ��� 
#define GPIOC_ODR        (*(volatile unsigned long *)0x4001100c) //�˿�C������ݼĴ� 
#define GPIOC_BSRR        (*(volatile unsigned long *)0x40011010) //�˿�Cλ����/��λ�Ĵ��� 
#define GPIOC_BRR        (*(volatile unsigned long *)0x40011014) //�˿�Cλ��λ�Ĵ� 
#define GPIOC_LCKR      (*(volatile unsigned long *)0x40011018) //�˿�C���������Ĵ��� 

//0X4001 0C00 - 0x4001 0FFF GPIOB ////////////////////////////// 
#define GPIOB_CRL       (*(volatile unsigned long *)0x40010C00) //�˿�B���õͼĴ��� 
#define GPIOB_CRH       (*(volatile unsigned long *)0x40010C04) //�˿�B���ø߼Ĵ��� 
#define GPIOB_IDR        (*(volatile unsigned long *)0x40010C08) //�˿�B�������ݼĴ��� 
#define GPIOB_ODR        (*(volatile unsigned long *)0x40010C0c) //�˿�B������ݼĴ� 
#define GPIOB_BSRR        (*(volatile unsigned long *)0x40010C10) //�˿�Bλ����/��λ�Ĵ��� 
#define GPIOB_BRR        (*(volatile unsigned long *)0x40010C14) //�˿�Bλ��λ�Ĵ� 
#define GPIOB_LCKR      (*(volatile unsigned long *)0x40010C18) //�˿�B���������Ĵ��� 

//0x4001 0800 - 0x4001 0BFF GPIOA////////////////////////////// 
#define GPIOA_CRL       (*(volatile unsigned long *)0x40010800) //�˿�A���õͼĴ��� 
#define GPIOA_CRH       (*(volatile unsigned long *)0x40010804) //�˿�A���ø߼Ĵ��� 
#define GPIOA_IDR        (*(volatile unsigned long *)0x40010808) //�˿�A�������ݼĴ��� 
#define GPIOA_ODR        (*(volatile unsigned long *)0x4001080c) //�˿�A������ݼĴ� 
#define GPIOA_BSRR        (*(volatile unsigned long *)0x40010810) //�˿�Aλ����/��λ�Ĵ��� 
#define GPIOA_BRR        (*(volatile unsigned long *)0x40010814) //�˿�Aλ��λ�Ĵ� 
#define GPIOA_LCKR      (*(volatile unsigned long *)0x40010818) //�˿�A���������Ĵ��� 

//0x4001 0400 - 0x4001 07FF EXTI//////////////////////////////// 
#define  EXTI_IMR       (*(volatile unsigned long *)0x40010400)//�ж����μĴ��� 
#define  EXTI_EMR       (*(volatile unsigned long *)0x40010404)//�¼����μĴ� 
#define  EXTI_RTSR      (*(volatile unsigned long *)0x40010408)//�����ش���ѡ��Ĵ��� 
#define  EXTI_FTSR      (*(volatile unsigned long *)0x4001040C)//�½��ش���ѡ��Ĵ��� 
#define  EXTI_SWIER     (*(volatile unsigned long *)0x40010410)//����ж��¼��Ĵ� 
#define  EXTI_PR        (*(volatile unsigned long *)0x40010414)//����Ĵ��� 

//0x4001 0000 - 0x4001 03FF AFIO//////////////////////////////// 
#define  AFIO_EVCR      (*(volatile unsigned long *)0x40010000)//�¼����ƼĴ� 
#define  AFIO_MAPR      (*(volatile unsigned long *)0x40010004)//������ӳ��͵���I/O���üĴ��� 
#define  AFIO_EXTICR1   (*(volatile unsigned long *)0x40010008)//�ⲿ�ж����üĴ���1 
#define  AFIO_EXTICR2   (*(volatile unsigned long *)0x4001000C)//�ⲿ�ж����üĴ���2 
#define  AFIO_EXTICR3   (*(volatile unsigned long *)0x40010010)//�ⲿ�ж����üĴ���3 
#define  AFIO_EXTICR4   (*(volatile unsigned long *)0x40010014)//�ⲿ�ж����üĴ���3 
//#define      (*(volatile unsigned long *)0x40010000)// 
//#define      (*(volatile unsigned long *)0x40010000)// 

//0x4000 7000 - 0x4000 73FF ��Դ����//////////////////////////// 
#define PWR_CR          (*(volatile unsigned long *)0x40007000) //��Դ���ƼĴ� 
#define PWR_CSR         (*(volatile unsigned long *)0x40007004) //��Դ����/״̬�Ĵ��� 


//0x4000 6C00 - 0x4000 6FFF �󱸼Ĵ���(BKP)///////////////////// 
#define   BKP_DR0      (*(volatile unsigned long *)0x40006C04)//�������ݼĴ���0 
#define   BKP_DR1      (*(volatile unsigned long *)0x40006C08)//�������ݼĴ���1 
#define   BKP_DR2      (*(volatile unsigned long *)0x40006C0C)//�������ݼĴ���2 
#define   BKP_DR3      (*(volatile unsigned long *)0x40006C10)//�������ݼĴ���3 
#define   BKP_DR4      (*(volatile unsigned long *)0x40006C14)//�������ݼĴ���4 
#define   BKP_DR5      (*(volatile unsigned long *)0x40006C18)//�������ݼĴ���5 
#define   BKP_DR6      (*(volatile unsigned long *)0x40006C1C)//�������ݼĴ���6 
#define   BKP_DR7      (*(volatile unsigned long *)0x40006C20)//�������ݼĴ���7 
#define   BKP_DR8      (*(volatile unsigned long *)0x40006C24)//�������ݼĴ���8 
#define   BKP_DR9      (*(volatile unsigned long *)0x40006C28)//�������ݼĴ���9 
#define   BKP_RTCCR    (*(volatile unsigned long *)0x40006C2C)//RTCʱ��У׼�Ĵ��� 
#define   BKP_CR       (*(volatile unsigned long *)0x40006C30)//���ݿ��ƼĴ��� 
#define   BKP_CSR      (*(volatile unsigned long *)0x40006C34)//���ݿ���/״̬�Ĵ��� 

//0x4000 6000 - 0x4000 63FF USB/CAN �����SRAM 512�ֽ�////////// 

//0x4000 6400 - 0x4000 67FF bxCAN/////////////////////////////// 
#define   CAN_MCR     (*(volatile unsigned long *)0x40006400)//CAN �����ƼĴ��� 
#define   CAN_MSR     (*(volatile unsigned long *)0x40006404)//CAN ��״̬�Ĵ��� 
#define   CAN_TSR     (*(volatile unsigned long *)0x40006408)//CAN����״̬�Ĵ��� 
#define   CAN_RF0R    (*(volatile unsigned long *)0x4000640C)//CAN����FIFO 0 �Ĵ��� 
#define   CAN_RF1R    (*(volatile unsigned long *)0x40006410)//CAN����FIFO 1 �Ĵ��� 
#define   CAN_IER     (*(volatile unsigned long *)0x40006414)//CAN �ж�����Ĵ��� 
#define   CAN_ESR     (*(volatile unsigned long *)0x40006418)//CAN ����״̬�Ĵ��� 
#define   CAN_BTR     (*(volatile unsigned long *)0x4000641C)//CAN λʱ�����ԼĴ��� 
#define   CAN_TI0R    (*(volatile unsigned long *)0x40006580)//���������ʶ���Ĵ���0 
#define   CAN_TI1R    (*(volatile unsigned long *)0x40006590)//���������ʶ���Ĵ���1 
#define   CAN_TI2R    (*(volatile unsigned long *)0x400065A0)//���������ʶ���Ĵ���2 
#define   CAN_TDT0R   (*(volatile unsigned long *)0x40006584)//�����������ݳ��Ⱥ�ʱ����Ĵ���0 
#define   CAN_TDT1R   (*(volatile unsigned long *)0x40006594)//�����������ݳ��Ⱥ�ʱ����Ĵ���1 
#define   CAN_TDT2R   (*(volatile unsigned long *)0x400065A4)//�����������ݳ��Ⱥ�ʱ����Ĵ���2 
#define   CAN_TDL0R   (*(volatile unsigned long *)0x40006588)//����������ֽ����ݼĴ���0 
#define   CAN_TDL1R   (*(volatile unsigned long *)0x40006598)//����������ֽ����ݼĴ���1 
#define   CAN_TDL2R   (*(volatile unsigned long *)0x400065A8)//����������ֽ����ݼĴ���2 
#define   CAN_TDH0R   (*(volatile unsigned long *)0x4000658C)//����������ֽ����ݼĴ���0 
#define   CAN_TDH1R   (*(volatile unsigned long *)0x4000659C)//����������ֽ����ݼĴ���1 
#define   CAN_TDH2R   (*(volatile unsigned long *)0x400065AC)//����������ֽ����ݼĴ���2 
#define   CAN_RI0R    (*(volatile unsigned long *)0x400065B0)//����FIFO�����ʶ���Ĵ���0 
#define   CAN_RI1R    (*(volatile unsigned long *)0x400065C0)//����FIFO�����ʶ���Ĵ���1 
#define   CAN_RDT0R   (*(volatile unsigned long *)0x400065BC)//����FIFO�������ݳ��Ⱥ�ʱ����Ĵ���0 
#define   CAN_RDT1R   (*(volatile unsigned long *)0x400065C4)//����FIFO�������ݳ��Ⱥ�ʱ����Ĵ���1 
#define   CAN_RDL0R   (*(volatile unsigned long *)0x400065B8)//����FIFO������ֽ����ݼĴ���0 
#define   CAN_RDL1R   (*(volatile unsigned long *)0x400065C8)//����FIFO������ֽ����ݼĴ���1 
#define   CAN_RDH0R   (*(volatile unsigned long *)0x400065BC)//����FIFO������ֽ����ݼĴ���0 
#define   CAN_RDH1R   (*(volatile unsigned long *)0x400065CC)//����FIFO������ֽ����ݼĴ���1 
#define   CAN_FMR     (*(volatile unsigned long *)0x40006600)//CAN ���������ؼĴ��� 
#define   CAN_FM0R    (*(volatile unsigned long *)0x40006604)//CAN ������ģʽ�Ĵ��� 
#define   CAN_FS0R    (*(volatile unsigned long *)0x4000660C)//CAN ������λ��Ĵ��� 
#define   CAN_FFA0R   (*(volatile unsigned long *)0x40006610)//CAN ������FIFO�����Ĵ��� 
#define   CAN_FA0R    (*(volatile unsigned long *)0x4000661C)//CAN ����������Ĵ��� 
#define   CAN_F0R     (*(volatile unsigned long *)0x40006640)//CAN ��������0�Ĵ��� 
#define   CAN_F1R     (*(volatile unsigned long *)0x400066AC)//CAN ��������1�Ĵ��� 

//0x4000 5800 - 0x4000 57FF I2C2//////////////////////////////// 
#define I2C2_CR1       (*(volatile unsigned long *)0x40005800)//���ƼĴ���1 
#define I2C2_CR2       (*(volatile unsigned long *)0x40005804)//���ƼĴ���2 
#define I2C2_OAR1      (*(volatile unsigned long *)0x40005808)//�����ַ�Ĵ���1 
#define I2C2_OAR2      (*(volatile unsigned long *)0x4000580C)//�����ַ�Ĵ���2 
#define I2C2_DR        (*(volatile unsigned long *)0x40005810)//���ݼĴ��� 
#define I2C2_SR1       (*(volatile unsigned long *)0x40005814)//״̬�Ĵ���1 
#define I2C2_SR2       (*(volatile unsigned long *)0x40005818)//״̬�Ĵ���2 
#define I2C2_CCR       (*(volatile unsigned long *)0x4000581C)//ʱ�ӿ��ƼĴ��� 
#define I2C2_TRISE     (*(volatile unsigned long *)0x40005820)//TRISE�Ĵ��� 
//0x4000 5400 - 0x4000 57FF I2C1//////////////////////////////// 
#define I2C1_CR1       (*(volatile unsigned long *)0x40005400)//���ƼĴ���1 
#define I2C1_CR2       (*(volatile unsigned long *)0x40005404)//���ƼĴ���2 
#define I2C1_OAR1      (*(volatile unsigned long *)0x40005408)//�����ַ�Ĵ���1 
#define I2C1_OAR2      (*(volatile unsigned long *)0x4000540C)//�����ַ�Ĵ���2 
#define I2C1_DR        (*(volatile unsigned long *)0x40005410)//���ݼĴ��� 
#define I2C1_SR1       (*(volatile unsigned long *)0x40005414)//״̬�Ĵ���1 
#define I2C1_SR2       (*(volatile unsigned long *)0x40005418)//״̬�Ĵ���2 
#define I2C1_CCR       (*(volatile unsigned long *)0x4000541C)//ʱ�ӿ��ƼĴ��� 
#define I2C1_TRISE     (*(volatile unsigned long *)0x40005420)//TRISE�Ĵ��� 



//0x4001 3800 - 0x4001 3BFF USART2////////////////////////////// 
#define USART1_SR        (*(volatile unsigned long *)0x40013800)//״̬�Ĵ��� 
#define USART1_DR        (*(volatile unsigned long *)0x40013804)//���ݼĴ��� 
#define USART1_BRR       (*(volatile unsigned long *)0x40013808)//���ر��ʼĴ��� 
#define USART1_CR1       (*(volatile unsigned long *)0x4001380C)//���ƼĴ���1 
#define USART1_CR2       (*(volatile unsigned long *)0x40013810)//���ƼĴ���2 
#define USART1_CR3       (*(volatile unsigned long *)0x40013814)//���ƼĴ���3 
#define USART1_GTPR      (*(volatile unsigned long *)0x40013818)//����ʱ���Ԥ��Ƶ�Ĵ��� 

//0x4000 4400 - 0x4000 47FF USART2////////////////////////////// 
#define USART2_SR        (*(volatile unsigned long *)0x40004400)//״̬�Ĵ��� 
#define USART2_DR        (*(volatile unsigned long *)0x40004404)//���ݼĴ��� 
#define USART2_BRR       (*(volatile unsigned long *)0x40004408)//���ر��ʼĴ��� 
#define USART2_CR1       (*(volatile unsigned long *)0x4000440C)//���ƼĴ���1 
#define USART2_CR2       (*(volatile unsigned long *)0x40004410)//���ƼĴ���2 
#define USART2_CR3       (*(volatile unsigned long *)0x40004414)//���ƼĴ���3 
#define USART2_GTPR      (*(volatile unsigned long *)0x40004418)//����ʱ���Ԥ��Ƶ�Ĵ��� 

//0x4000 4800 - 0x4000 4BFF USART3////////////////////////////// 
#define USART3_SR        (*(volatile unsigned long *)0x40004800)//״̬�Ĵ��� 
#define USART3_DR        (*(volatile unsigned long *)0x40004804)//���ݼĴ��� 
#define USART3_BRR       (*(volatile unsigned long *)0x40004808)//���ر��ʼĴ��� 
#define USART3_CR1       (*(volatile unsigned long *)0x4000480C)//���ƼĴ���1 
#define USART3_CR2       (*(volatile unsigned long *)0x40004810)//���ƼĴ���2 
#define USART3_CR3       (*(volatile unsigned long *)0x40004814)//���ƼĴ���3 
#define USART3_GTPR      (*(volatile unsigned long *)0x40004818)//����ʱ���Ԥ��Ƶ�Ĵ��� 

//0x4000 3800 - 0x4000 3BFF SPI2//////////////////////////////// 

//0x4000 3000 - 0x4000 33FF �������Ź�(IWDG)//////////////////// 
#define  IWDG_KR        (*(volatile unsigned long *)0x40003000)//��ֵ�Ĵ��� 
#define  IWDG_PR        (*(volatile unsigned long *)0x40003004)//Ԥ��Ƶ�Ĵ��� 
#define  IWDG_RLR       (*(volatile unsigned long *)0x40003008)//��װ�ؼĴ��� 
#define  IWDG_SR        (*(volatile unsigned long *)0x4000300C)//״̬�Ĵ��� 
//0x4000 2C00 - 0x4000 2FFF ���ڿ��Ź�(WWDG)//////////////////// 
#define  WWDG_CR        (*(volatile unsigned long *)0x40002C00)//���ƼĴ��� 
#define  WWDG_CFR       (*(volatile unsigned long *)0x40002C04)//���üĴ��� 
#define  WWDG_SR        (*(volatile unsigned long *)0x40002C08)//״̬�Ĵ��� 
//0x4000 2800 - 0x4000 2BFF RTC///////////////////////////////// 
#define  RTC_CRH       (*(volatile unsigned long *)0x40002800)//RTC���ƼĴ�����λ 
#define  RTC_CRL       (*(volatile unsigned long *)0x40002804)//RTC���ƼĴ�����λ 
#define  RTC_PRLH      (*(volatile unsigned long *)0x40002808)//RTCԤ��Ƶװ�ؼĴ�����λ 
#define  RTC_PRLL      (*(volatile unsigned long *)0x4000280C)//RTCԤ��Ƶװ�ؼĴ�����λ 
#define  RTC_DIVH      (*(volatile unsigned long *)0x40002810)//RTCԤ��Ƶ��Ƶ���ӼĴ�����λ 
#define  RTC_DIVL      (*(volatile unsigned long *)0x40002814)//RTCԤ��Ƶ��Ƶ���ӼĴ�����λ 
#define  RTC_CNTH      (*(volatile unsigned long *)0x40002818)//RTC �������Ĵ�����λ 
#define  RTC_CNTL      (*(volatile unsigned long *)0x4000281c)//RTC�������Ĵ����� 
#define  RTC_ALRH      (*(volatile unsigned long *)0x40002820)//RTC���ӼĴ����� 
#define  RTC_ALRL      (*(volatile unsigned long *)0x40002824)//RTC���ӼĴ�����λ 
//0x4000 0800 - 0x4000 0BFF TIM4��ʱ��////////////////////////// 
#define  TIM4_CR1     (*(volatile unsigned long *)0x40000800)//���ƼĴ���1 
#define  TIM4_CR2     (*(volatile unsigned long *)0x40000804)//���ƼĴ���2 
#define  TIM4_SMCR    (*(volatile unsigned long *)0x40000808)//��ģʽ���ƼĴ��� 
#define  TIM4_DIER    (*(volatile unsigned long *)0x4000080C)//DMA/�ж�ʹ�ܼĴ��� 
#define  TIM4_SR      (*(volatile unsigned long *)0x40000810)//״̬�Ĵ��� 
#define  TIM4_EGR     (*(volatile unsigned long *)0x40000814)//�¼������Ĵ��� 
#define  TIM4_CCMR1   (*(volatile unsigned long *)0x40000818)//����/�Ƚ�ģʽ�Ĵ��� 
#define  TIM4_CCMR2   (*(volatile unsigned long *)0x4000081C)//����/�Ƚ�ģʽ�Ĵ���2 
#define  TIM4_CCER    (*(volatile unsigned long *)0x40000820)//����/�Ƚ�ʹ�ܼĴ��� 
#define  TIM4_CNT     (*(volatile unsigned long *)0x40000824)//������ 
#define  TIM4_PSC     (*(volatile unsigned long *)0x40000828)//Ԥ��Ƶ�� 
#define  TIM4_ARR     (*(volatile unsigned long *)0x4000082C)//�Զ���װ�ؼĴ��� 
#define  TIM4_CCR1    (*(volatile unsigned long *)0x40000834)//����/�ȽϼĴ���1 
#define  TIM4_CCR2    (*(volatile unsigned long *)0x40000838)//����/�ȽϼĴ���2 
#define  TIM4_CCR3    (*(volatile unsigned long *)0x4000083C)//����/�ȽϼĴ���3 
#define  TIM4_CCR4    (*(volatile unsigned long *)0x40000840)//����/�ȽϼĴ���4 
#define  TIM4_DCR     (*(volatile unsigned long *)0x40000848)//DMA���ƼĴ��� 
#define  TIM4_DMAR    (*(volatile unsigned long *)0x4000084C)//����ģʽ��DMA��ַ 
//0x4000 0400 - 0x4000 07FF TIM3��ʱ��////////////////////////// 
#define  TIM3_CR1     (*(volatile unsigned long *)0x40000400)//���ƼĴ���1 
#define  TIM3_CR2     (*(volatile unsigned long *)0x40000404)//���ƼĴ���2 
#define  TIM3_SMCR    (*(volatile unsigned long *)0x40000408)//��ģʽ���ƼĴ��� 
#define  TIM3_DIER    (*(volatile unsigned long *)0x4000040C)//DMA/�ж�ʹ�ܼĴ��� 
#define  TIM3_SR      (*(volatile unsigned long *)0x40000410)//״̬�Ĵ��� 
#define  TIM3_EGR     (*(volatile unsigned long *)0x40000414)//�¼������Ĵ��� 
#define  TIM3_CCMR1   (*(volatile unsigned long *)0x40000418)//����/�Ƚ�ģʽ�Ĵ��� 
#define  TIM3_CCMR2   (*(volatile unsigned long *)0x4000041C)//����/�Ƚ�ģʽ�Ĵ���2 
#define  TIM3_CCER    (*(volatile unsigned long *)0x40000420)//����/�Ƚ�ʹ�ܼĴ��� 
#define  TIM3_CNT     (*(volatile unsigned long *)0x40000424)//������ 
#define  TIM3_PSC     (*(volatile unsigned long *)0x40000428)//Ԥ��Ƶ�� 
#define  TIM3_ARR     (*(volatile unsigned long *)0x4000042C)//�Զ���װ�ؼĴ��� 
#define  TIM3_CCR1    (*(volatile unsigned long *)0x40000434)//����/�ȽϼĴ���1 
#define  TIM3_CCR2    (*(volatile unsigned long *)0x40000438)//����/�ȽϼĴ���2 
#define  TIM3_CCR3    (*(volatile unsigned long *)0x4000043C)//����/�ȽϼĴ���3 
#define  TIM3_CCR4    (*(volatile unsigned long *)0x40000440)//����/�ȽϼĴ���4 
#define  TIM3_DCR     (*(volatile unsigned long *)0x40000448)//DMA���ƼĴ��� 
#define  TIM3_DMAR    (*(volatile unsigned long *)0x4000044C)//����ģʽ��DMA��ַ 
//0x4000 0000 - 0x4000 03FF TIM2��ʱ��////////////////////////// 
#define  TIM2_CR1     (*(volatile unsigned long *)0x40000000)//���ƼĴ���1 
#define  TIM2_CR2     (*(volatile unsigned long *)0x40000004)//���ƼĴ���2 
#define  TIM2_SMCR    (*(volatile unsigned long *)0x40000008)//��ģʽ���ƼĴ��� 
#define  TIM2_DIER    (*(volatile unsigned long *)0x4000000C)//DMA/�ж�ʹ�ܼĴ��� 
#define  TIM2_SR      (*(volatile unsigned long *)0x40000010)//״̬�Ĵ��� 
#define  TIM2_EGR     (*(volatile unsigned long *)0x40000014)//�¼������Ĵ��� 
#define  TIM2_CCMR1   (*(volatile unsigned long *)0x40000018)//����/�Ƚ�ģʽ�Ĵ��� 
#define  TIM2_CCMR2   (*(volatile unsigned long *)0x4000001C)//����/�Ƚ�ģʽ�Ĵ���2 
#define  TIM2_CCER    (*(volatile unsigned long *)0x40000020)//����/�Ƚ�ʹ�ܼĴ��� 
#define  TIM2_CNT     (*(volatile unsigned long *)0x40000024)//������ 
#define  TIM2_PSC     (*(volatile unsigned long *)0x40000028)//Ԥ��Ƶ�� 
#define  TIM2_ARR     (*(volatile unsigned long *)0x4000002C)//�Զ���װ�ؼĴ��� 
#define  TIM2_CCR1    (*(volatile unsigned long *)0x40000034)//����/�ȽϼĴ���1 
#define  TIM2_CCR2    (*(volatile unsigned long *)0x40000038)//����/�ȽϼĴ���2 
#define  TIM2_CCR3    (*(volatile unsigned long *)0x4000003C)//����/�ȽϼĴ���3 
#define  TIM2_CCR4    (*(volatile unsigned long *)0x40000040)//����/�ȽϼĴ���4 
#define  TIM2_DCR     (*(volatile unsigned long *)0x40000048)//DMA���ƼĴ��� 
#define  TIM2_DMAR    (*(volatile unsigned long *)0x4000004C)//����ģʽ��DMA��ַ 

#endif
