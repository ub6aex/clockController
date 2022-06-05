#ifndef _STM32F103_H_
#define _STM32F103_H_ 
 
//0x4002 2000 - 0x4002 23FF  Flash记忆体接口寄存器 /////////////////////
#define  FLASH_ACR          (*(volatile unsigned long *)0x40022000) //FLASH访问控制寄存器  
#define  FLASH_KEYR         (*(volatile unsigned long *)0x40022004) //FLASH FPECKEY 寄存器
#define  FLASH_OPTKEYR      (*(volatile unsigned long *)0x40022008) //FLASH OTPKEY 寄存器
#define  FLASH_SR           (*(volatile unsigned long *)0x4002200C) //FALSH状态寄存器
#define  FLASH_CR           (*(volatile unsigned long *)0x40022010) //FLASH控制寄存器
#define  FLASH_AR           (*(volatile unsigned long *)0x40022014) //FLASH地址寄存器
#define  Reserved           (*(volatile unsigned long *)0x40022018) //保留
#define  FLASH_OBR          (*(volatile unsigned long *)0x4002201C) //FLASH字选择寄存器
#define  FLASH_WRPR         (*(volatile unsigned long *)0x40022020) //FLASH写保护寄存器    

            

//0x4002 1000 - 0x4002 13FF 复位和时钟控制///////////////////// 

#define  RCC_CR         (*(volatile unsigned long *)0x40021000) //时钟控制寄存器 
#define  RCC_CFGR       (*(volatile unsigned long *)0x40021004) //时钟配置寄存器 
#define  RCC_CIR        (*(volatile unsigned long *)0x40021008) //时钟中断寄存器  
#define  RCC_APB2RSTR   (*(volatile unsigned long *)0x4002100c) //APB2 外设复位寄存器 
#define  RCC_APB1RSTR   (*(volatile unsigned long *)0x40021010) //APB1 外设复位寄存器 
#define  RCC_AHBENR     (*(volatile unsigned long *)0x40021014) //AHB外设时钟使能寄存器 
#define  RCC_APB2ENR    (*(volatile unsigned long *)0x40021018) //APB2 外设时钟使能寄存器 
#define  RCC_APB1ENR    (*(volatile unsigned long *)0x4002101c) //APB1 外设时钟使能寄存器 
#define  RCC_BDCR       (*(volatile unsigned long *)0x40021020) //备份域控制寄存器 
#define  RCC_CSR        (*(volatile unsigned long *)0x40021024) //控制/状态寄存器 
//0x4002 0000 - 0x4002 03FF DMA//////////////////////////////// 

#define  DMA_ISR        (*(volatile unsigned long *)0x40020000)//DMA中断状态寄存器 
#define  DMA_IFCR       (*(volatile unsigned long *)0x40020004)//DMA中断标志清除寄存器 
#define  DMA_CCR1       (*(volatile unsigned long *)0x40020008)//DMA通道配置寄存器1 
#define  DMA_CCR2       (*(volatile unsigned long *)0x4002001C)//DMA通道配置寄存器2 
#define  DMA_CCR3       (*(volatile unsigned long *)0x40020030)//DMA通道配置寄存器3 
#define  DMA_CCR4       (*(volatile unsigned long *)0x40020044)//DMA通道配置寄存器4 
#define  DMA_CCR5       (*(volatile unsigned long *)0x40020058)//DMA通道配置寄存器5 
#define  DMA_CCR6       (*(volatile unsigned long *)0x4002006C)//DMA通道配置寄存器6 
#define  DMA_CCR7       (*(volatile unsigned long *)0x40020080)//DMA通道配置寄存器7 
#define  DMA_CNDTR1     (*(volatile unsigned long *)0x4002000C)//DMA通道传输数量寄存器1 
#define  DMA_CNDTR2     (*(volatile unsigned long *)0x40020020)//DMA通道传输数量寄存器2 
#define  DMA_CNDTR3     (*(volatile unsigned long *)0x40020034)//DMA通道传输数量寄存器3 
#define  DMA_CNDTR4     (*(volatile unsigned long *)0x40020048)//DMA通道传输数量寄存器4 
#define  DMA_CNDTR5     (*(volatile unsigned long *)0x4002005C)//DMA通道传输数量寄存器5 
#define  DMA_CNDTR6     (*(volatile unsigned long *)0x40020070)//DMA通道传输数量寄存器6 
#define  DMA_CNDTR7     (*(volatile unsigned long *)0x40020054)//DMA通道传输数量寄存器7 
#define  DMA_CPAR1      (*(volatile unsigned long *)0x40020010)//DMA通道外设地址寄存1 
#define  DMA_CPAR2      (*(volatile unsigned long *)0x40020024)//DMA通道外设地址寄存2 
#define  DMA_CPAR3      (*(volatile unsigned long *)0x40020038)//DMA通道外设地址寄存3 
#define  DMA_CPAR4      (*(volatile unsigned long *)0x4002004C)//DMA通道外设地址寄存4 
#define  DMA_CPAR5      (*(volatile unsigned long *)0x40020060)//DMA通道外设地址寄存5 
#define  DMA_CPAR6      (*(volatile unsigned long *)0x40020074)//DMA通道外设地址寄存6 
#define  DMA_CPAR7      (*(volatile unsigned long *)0x40020088)//DMA通道外设地址寄存7 
#define  DMA_CMAR1      (*(volatile unsigned long *)0x40020014)//DMA通道存储器地址寄存器1 
#define  DMA_CMAR2      (*(volatile unsigned long *)0x40020028)//DMA通道存储器地址寄存器2 
#define  DMA_CMAR3      (*(volatile unsigned long *)0x4002003C)//DMA通道存储器地址寄存器3 
#define  DMA_CMAR4      (*(volatile unsigned long *)0x40020050)//DMA通道存储器地址寄存器4 
#define  DMA_CMAR5      (*(volatile unsigned long *)0x40020064)//DMA通道存储器地址寄存器5 
#define  DMA_CMAR6      (*(volatile unsigned long *)0x40020078)//DMA通道存储器地址寄存器6 
#define  DMA_CMAR7      (*(volatile unsigned long *)0x4002008C)//DMA通道存储器地址寄存器7 


//0x4001 3800 - 0x4001 3BFF USART1///////////////////////////// 
#define USART1_SR        (*(volatile unsigned long *)0x40013800)//状态寄存器 
#define USART1_DR        (*(volatile unsigned long *)0x40013804)//数据寄存器 
#define USART1_BRR       (*(volatile unsigned long *)0x40013808)//波特比率寄存器 
#define USART1_CR1       (*(volatile unsigned long *)0x4001380C)//控制寄存器1 
#define USART1_CR2       (*(volatile unsigned long *)0x40013810)//控制寄存器2 
#define USART1_CR3       (*(volatile unsigned long *)0x40013814)//控制寄存器3 
#define USART1_GTPR      (*(volatile unsigned long *)0x40013818)//保护时间和预分频寄存器 

//0x4001 3000 - 0x4001 33FF SPI1/////////////////////////////// 
#define  SPI1_CR1        (*(volatile unsigned long *)0x40013000)//SPI控制寄存器1 
#define  SPI1_CR2        (*(volatile unsigned long *)0x40013004)//SPI控制寄存器2
#define  SPI1_SR         (*(volatile unsigned long *)0x40013008)//SPI状态寄存器
#define  SPI1_DR         (*(volatile unsigned long *)0x4001300C)//SPI数据寄存器
#define  SPI1_CRCPR      (*(volatile unsigned long *)0x40013010)//SPI CRC多项式寄存器
#define  SPI1_RXCRCR     (*(volatile unsigned long *)0x40013014)//SPI CRC Rx寄存器
#define  SPI1_TXCRCR     (*(volatile unsigned long *)0x40013018)//SPI CRC Tx寄存器


//0x4001 2C00 - 0x4001 2FFF TIM1时钟/////////////////////////// 
#define  TIM1_CR1      (*(volatile unsigned long *)0x40012C00)//控制寄存器1 
#define  TIM1_CR2      (*(volatile unsigned long *)0x40012C04)//控制寄存器2 
#define  TIM1_SMCR     (*(volatile unsigned long *)0x40012C08)//从模式控制寄存器 
#define  TIM1_DIER     (*(volatile unsigned long *)0x40012C0C)//DMA/中断使能寄存器 
#define  TIM1_SR       (*(volatile unsigned long *)0x40012C10)//状态寄存器 
#define  TIM1_EGR      (*(volatile unsigned long *)0x40012C14)//事件产生寄存器 
#define  TIM1_CCMR1    (*(volatile unsigned long *)0x40012C18)//捕获/比较模式寄存器1 
#define  TIM1_CCMR2    (*(volatile unsigned long *)0x40012C1C)//捕获/比较模式寄存器2 
#define  TIM1_CCER     (*(volatile unsigned long *)0x40012C20)//捕获/比较使能寄存器 
#define  TIM1_CNT      (*(volatile unsigned long *)0x40012C24)//计数器 
#define  TIM1_PSC      (*(volatile unsigned long *)0x40012C28)//预分频器 
#define  TIM1_ARR      (*(volatile unsigned long *)0x40012C2C)//自动重装载寄存器 
#define  TIM1_RCR      (*(volatile unsigned long *)0x40012C30)//周期计数寄存器 
#define  TIM1_CCR1     (*(volatile unsigned long *)0x40012C34)//捕获/比较寄存器1 
#define  TIM1_CCR2     (*(volatile unsigned long *)0x40012C38)//捕获/比较寄存器2 
#define  TIM1_CCR3     (*(volatile unsigned long *)0x40012C3C)//捕获/比较寄存器3 
#define  TIM1_CCR4     (*(volatile unsigned long *)0x40012C40)//捕获/比较寄存器 
#define  TIM1_BDTR     (*(volatile unsigned long *)0x40012C44)//刹车和死区寄存器 
#define  TIM1_DCR      (*(volatile unsigned long *)0x40012C48)//DMA控制寄存器 
#define  TIM1_DMAR     (*(volatile unsigned long *)0x40012C4C)//连续模式的DMA地址 

//0x4001 2800 - 0x4001 2BFF ADC2/////////////////////////////// 
#define  ADC2_SR        (*(volatile unsigned long *)0x40012400)//ADC状态寄存器 
#define  ADC2_CR1       (*(volatile unsigned long *)0x40012404)//ADC控制寄存器1 
#define  ADC2_CR2       (*(volatile unsigned long *)0x40012408)//ADC控制寄存器2 
#define  ADC2_SMPR1     (*(volatile unsigned long *)0x4001240C)//ADC采样时间寄存器1 
#define  ADC2_SMPR2     (*(volatile unsigned long *)0x40012410)//ADC采样时间寄存器2 
#define  ADC2_JOFR1     (*(volatile unsigned long *)0x40012414)//ADC注入通道数据偏移寄存器1 
#define  ADC2_JOFR2     (*(volatile unsigned long *)0x40012418)//ADC注入通道数据偏移寄存器2 
#define  ADC2_JOFR3     (*(volatile unsigned long *)0x4001241C)//ADC注入通道数据偏移寄存器3 
#define  ADC2_JOFR4     (*(volatile unsigned long *)0x40012420)//ADC注入通道数据偏移寄存器4 
#define  ADC2_HTR       (*(volatile unsigned long *)0x40012424)//DC看门狗高阀值寄存器 
#define  ADC2_LRT       (*(volatile unsigned long *)0x40012428)//ADC看门狗低阀值寄存器 
#define  ADC2_SQR1      (*(volatile unsigned long *)0x4001242C)//ADC规则序列寄存器1 
#define  ADC2_SQR2      (*(volatile unsigned long *)0x40012430)//ADC规则序列寄存器2 
#define  ADC2_SQR3      (*(volatile unsigned long *)0x40012434)//ADC规则序列寄存器3 
#define  ADC2_JSQR      (*(volatile unsigned long *)0x40012438)//ADC注入序列寄存器 
#define  ADC2_JDR1      (*(volatile unsigned long *)0x4001243C)//ADC 注入数据寄存器1 
#define  ADC2_JDR2      (*(volatile unsigned long *)0x40012440)//ADC 注入数据寄存器2 
#define  ADC2_JDR3      (*(volatile unsigned long *)0x40012444)//ADC 注入数据寄存器3 
#define  ADC2_JDR4      (*(volatile unsigned long *)0x40012448)//ADC 注入数据寄存器4 
#define  ADC2_DR        (*(volatile unsigned long *)0x4001244C)//ADC规则数据寄存器 

//0x4001 2400 - 0x4001 27FF ADC1/////////////////////////////// 
#define  ADC1_SR        (*(volatile unsigned long *)0x40012400)//ADC状态寄存器 
#define  ADC1_CR1       (*(volatile unsigned long *)0x40012404)//ADC控制寄存器1 
#define  ADC1_CR2       (*(volatile unsigned long *)0x40012408)//ADC控制寄存器2 
#define  ADC1_SMPR1     (*(volatile unsigned long *)0x4001240C)//ADC采样时间寄存器1 
#define  ADC1_SMPR2     (*(volatile unsigned long *)0x40012410)//ADC采样时间寄存器2 
#define  ADC1_JOFR1     (*(volatile unsigned long *)0x40012414)//ADC注入通道数据偏移寄存器1 
#define  ADC1_JOFR2     (*(volatile unsigned long *)0x40012418)//ADC注入通道数据偏移寄存器2 
#define  ADC1_JOFR3     (*(volatile unsigned long *)0x4001241C)//ADC注入通道数据偏移寄存器3 
#define  ADC1_JOFR4     (*(volatile unsigned long *)0x40012420)//ADC注入通道数据偏移寄存器4 
#define  ADC1_HTR       (*(volatile unsigned long *)0x40012424)//DC看门狗高阀值寄存器 
#define  ADC1_LRT       (*(volatile unsigned long *)0x40012428)//ADC看门狗低阀值寄存器 
#define  ADC1_SQR1      (*(volatile unsigned long *)0x4001242C)//ADC规则序列寄存器1 
#define  ADC1_SQR2      (*(volatile unsigned long *)0x40012430)//ADC规则序列寄存器2 
#define  ADC1_SQR3      (*(volatile unsigned long *)0x40012434)//ADC规则序列寄存器3 
#define  ADC1_JSQR      (*(volatile unsigned long *)0x40012438)//ADC注入序列寄存器 
#define  ADC1_JDR1      (*(volatile unsigned long *)0x4001243C)//ADC 注入数据寄存器1 
#define  ADC1_JDR2      (*(volatile unsigned long *)0x40012440)//ADC 注入数据寄存器2 
#define  ADC1_JDR3      (*(volatile unsigned long *)0x40012444)//ADC 注入数据寄存器3 
#define  ADC1_JDR4      (*(volatile unsigned long *)0x40012448)//ADC 注入数据寄存器4 
#define  ADC1_DR        (*(volatile unsigned long *)0x4001244C)//ADC规则数据寄存器 


// 0x4001 1800 - 0x40011BFF GPIOE/////////////////////////////// 
#define GPIOE_CRL       (*(volatile unsigned long *)0x40011800) //端口E配置低寄存器 
#define GPIOE_CRH       (*(volatile unsigned long *)0x40011804) //端口E配置高寄存器 
#define GPIOE_IDR        (*(volatile unsigned long *)0x40011808) //端口E输入数据寄存器 
#define GPIOE_ODR        (*(volatile unsigned long *)0x4001180c) //端口E输出数据寄存 
#define GPIOE_BSRR        (*(volatile unsigned long *)0x40011810) //端口E位设置/复位寄存器 
#define GPIOE_BRR        (*(volatile unsigned long *)0x40011814) //端口E位复位寄存 
#define GPIOE_LCKR      (*(volatile unsigned long *)0x40011818) //端口E配置锁定寄存器 

//0x4001 1400 - 0x4001 17FF GPIOD////////////////////////////// 
#define GPIOD_CRL       (*(volatile unsigned long *)0x40011400) //端口D配置低寄存器 
#define GPIOD_CRH       (*(volatile unsigned long *)0x40011404) //端口D配置高寄存器 
#define GPIOD_IDR        (*(volatile unsigned long *)0x40011408) //端口D输入数据寄存器 
#define GPIOD_ODR        (*(volatile unsigned long *)0x4001140c) //端口D输出数据寄存 
#define GPIOD_BSRR        (*(volatile unsigned long *)0x40011410) //端口D位设置/复位寄存器 
#define GPIOD_BRR        (*(volatile unsigned long *)0x40011414) //端口D位复位寄存 
#define GPIOD_LCKR      (*(volatile unsigned long *)0x40011418) //端口D配置锁定寄存器 

//0x4001 1000 - 0x4001 13FF GPIOC////////////////////////////// 
#define GPIOC_CRL       (*(volatile unsigned long *)0x40011000) //端口C配置低寄存器 
#define GPIOC_CRH       (*(volatile unsigned long *)0x40011004) //端口C配置高寄存器 
#define GPIOC_IDR        (*(volatile unsigned long *)0x40011008) //端口C输入数据寄存器 
#define GPIOC_ODR        (*(volatile unsigned long *)0x4001100c) //端口C输出数据寄存 
#define GPIOC_BSRR        (*(volatile unsigned long *)0x40011010) //端口C位设置/复位寄存器 
#define GPIOC_BRR        (*(volatile unsigned long *)0x40011014) //端口C位复位寄存 
#define GPIOC_LCKR      (*(volatile unsigned long *)0x40011018) //端口C配置锁定寄存器 

//0X4001 0C00 - 0x4001 0FFF GPIOB ////////////////////////////// 
#define GPIOB_CRL       (*(volatile unsigned long *)0x40010C00) //端口B配置低寄存器 
#define GPIOB_CRH       (*(volatile unsigned long *)0x40010C04) //端口B配置高寄存器 
#define GPIOB_IDR        (*(volatile unsigned long *)0x40010C08) //端口B输入数据寄存器 
#define GPIOB_ODR        (*(volatile unsigned long *)0x40010C0c) //端口B输出数据寄存 
#define GPIOB_BSRR        (*(volatile unsigned long *)0x40010C10) //端口B位设置/复位寄存器 
#define GPIOB_BRR        (*(volatile unsigned long *)0x40010C14) //端口B位复位寄存 
#define GPIOB_LCKR      (*(volatile unsigned long *)0x40010C18) //端口B配置锁定寄存器 

//0x4001 0800 - 0x4001 0BFF GPIOA////////////////////////////// 
#define GPIOA_CRL       (*(volatile unsigned long *)0x40010800) //端口A配置低寄存器 
#define GPIOA_CRH       (*(volatile unsigned long *)0x40010804) //端口A配置高寄存器 
#define GPIOA_IDR        (*(volatile unsigned long *)0x40010808) //端口A输入数据寄存器 
#define GPIOA_ODR        (*(volatile unsigned long *)0x4001080c) //端口A输出数据寄存 
#define GPIOA_BSRR        (*(volatile unsigned long *)0x40010810) //端口A位设置/复位寄存器 
#define GPIOA_BRR        (*(volatile unsigned long *)0x40010814) //端口A位复位寄存 
#define GPIOA_LCKR      (*(volatile unsigned long *)0x40010818) //端口A配置锁定寄存器 

//0x4001 0400 - 0x4001 07FF EXTI//////////////////////////////// 
#define  EXTI_IMR       (*(volatile unsigned long *)0x40010400)//中断屏蔽寄存器 
#define  EXTI_EMR       (*(volatile unsigned long *)0x40010404)//事件屏蔽寄存 
#define  EXTI_RTSR      (*(volatile unsigned long *)0x40010408)//上升沿触发选择寄存器 
#define  EXTI_FTSR      (*(volatile unsigned long *)0x4001040C)//下降沿触发选择寄存器 
#define  EXTI_SWIER     (*(volatile unsigned long *)0x40010410)//软件中断事件寄存 
#define  EXTI_PR        (*(volatile unsigned long *)0x40010414)//挂起寄存器 

//0x4001 0000 - 0x4001 03FF AFIO//////////////////////////////// 
#define  AFIO_EVCR      (*(volatile unsigned long *)0x40010000)//事件控制寄存 
#define  AFIO_MAPR      (*(volatile unsigned long *)0x40010004)//复用重映射和调试I/O配置寄存器 
#define  AFIO_EXTICR1   (*(volatile unsigned long *)0x40010008)//外部中断配置寄存器1 
#define  AFIO_EXTICR2   (*(volatile unsigned long *)0x4001000C)//外部中断配置寄存器2 
#define  AFIO_EXTICR3   (*(volatile unsigned long *)0x40010010)//外部中断配置寄存器3 
#define  AFIO_EXTICR4   (*(volatile unsigned long *)0x40010014)//外部中断配置寄存器3 
//#define      (*(volatile unsigned long *)0x40010000)// 
//#define      (*(volatile unsigned long *)0x40010000)// 

//0x4000 7000 - 0x4000 73FF 电源控制//////////////////////////// 
#define PWR_CR          (*(volatile unsigned long *)0x40007000) //电源控制寄存 
#define PWR_CSR         (*(volatile unsigned long *)0x40007004) //电源控制/状态寄存器 


//0x4000 6C00 - 0x4000 6FFF 后备寄存器(BKP)///////////////////// 
#define   BKP_DR0      (*(volatile unsigned long *)0x40006C04)//备份数据寄存器0 
#define   BKP_DR1      (*(volatile unsigned long *)0x40006C08)//备份数据寄存器1 
#define   BKP_DR2      (*(volatile unsigned long *)0x40006C0C)//备份数据寄存器2 
#define   BKP_DR3      (*(volatile unsigned long *)0x40006C10)//备份数据寄存器3 
#define   BKP_DR4      (*(volatile unsigned long *)0x40006C14)//备份数据寄存器4 
#define   BKP_DR5      (*(volatile unsigned long *)0x40006C18)//备份数据寄存器5 
#define   BKP_DR6      (*(volatile unsigned long *)0x40006C1C)//备份数据寄存器6 
#define   BKP_DR7      (*(volatile unsigned long *)0x40006C20)//备份数据寄存器7 
#define   BKP_DR8      (*(volatile unsigned long *)0x40006C24)//备份数据寄存器8 
#define   BKP_DR9      (*(volatile unsigned long *)0x40006C28)//备份数据寄存器9 
#define   BKP_RTCCR    (*(volatile unsigned long *)0x40006C2C)//RTC时钟校准寄存器 
#define   BKP_CR       (*(volatile unsigned long *)0x40006C30)//备份控制寄存器 
#define   BKP_CSR      (*(volatile unsigned long *)0x40006C34)//备份控制/状态寄存器 

//0x4000 6000 - 0x4000 63FF USB/CAN 共享的SRAM 512字节////////// 

//0x4000 6400 - 0x4000 67FF bxCAN/////////////////////////////// 
#define   CAN_MCR     (*(volatile unsigned long *)0x40006400)//CAN 主控制寄存器 
#define   CAN_MSR     (*(volatile unsigned long *)0x40006404)//CAN 主状态寄存器 
#define   CAN_TSR     (*(volatile unsigned long *)0x40006408)//CAN发送状态寄存器 
#define   CAN_RF0R    (*(volatile unsigned long *)0x4000640C)//CAN接收FIFO 0 寄存器 
#define   CAN_RF1R    (*(volatile unsigned long *)0x40006410)//CAN接收FIFO 1 寄存器 
#define   CAN_IER     (*(volatile unsigned long *)0x40006414)//CAN 中断允许寄存器 
#define   CAN_ESR     (*(volatile unsigned long *)0x40006418)//CAN 错误状态寄存器 
#define   CAN_BTR     (*(volatile unsigned long *)0x4000641C)//CAN 位时间特性寄存器 
#define   CAN_TI0R    (*(volatile unsigned long *)0x40006580)//发送邮箱标识符寄存器0 
#define   CAN_TI1R    (*(volatile unsigned long *)0x40006590)//发送邮箱标识符寄存器1 
#define   CAN_TI2R    (*(volatile unsigned long *)0x400065A0)//发送邮箱标识符寄存器2 
#define   CAN_TDT0R   (*(volatile unsigned long *)0x40006584)//发送邮箱数据长度和时间戳寄存器0 
#define   CAN_TDT1R   (*(volatile unsigned long *)0x40006594)//发送邮箱数据长度和时间戳寄存器1 
#define   CAN_TDT2R   (*(volatile unsigned long *)0x400065A4)//发送邮箱数据长度和时间戳寄存器2 
#define   CAN_TDL0R   (*(volatile unsigned long *)0x40006588)//发送邮箱低字节数据寄存器0 
#define   CAN_TDL1R   (*(volatile unsigned long *)0x40006598)//发送邮箱低字节数据寄存器1 
#define   CAN_TDL2R   (*(volatile unsigned long *)0x400065A8)//发送邮箱低字节数据寄存器2 
#define   CAN_TDH0R   (*(volatile unsigned long *)0x4000658C)//发送邮箱高字节数据寄存器0 
#define   CAN_TDH1R   (*(volatile unsigned long *)0x4000659C)//发送邮箱高字节数据寄存器1 
#define   CAN_TDH2R   (*(volatile unsigned long *)0x400065AC)//发送邮箱高字节数据寄存器2 
#define   CAN_RI0R    (*(volatile unsigned long *)0x400065B0)//接收FIFO邮箱标识符寄存器0 
#define   CAN_RI1R    (*(volatile unsigned long *)0x400065C0)//接收FIFO邮箱标识符寄存器1 
#define   CAN_RDT0R   (*(volatile unsigned long *)0x400065BC)//接收FIFO邮箱数据长度和时间戳寄存器0 
#define   CAN_RDT1R   (*(volatile unsigned long *)0x400065C4)//接收FIFO邮箱数据长度和时间戳寄存器1 
#define   CAN_RDL0R   (*(volatile unsigned long *)0x400065B8)//接收FIFO邮箱低字节数据寄存器0 
#define   CAN_RDL1R   (*(volatile unsigned long *)0x400065C8)//接收FIFO邮箱低字节数据寄存器1 
#define   CAN_RDH0R   (*(volatile unsigned long *)0x400065BC)//接收FIFO邮箱高字节数据寄存器0 
#define   CAN_RDH1R   (*(volatile unsigned long *)0x400065CC)//接收FIFO邮箱高字节数据寄存器1 
#define   CAN_FMR     (*(volatile unsigned long *)0x40006600)//CAN 过滤器主控寄存器 
#define   CAN_FM0R    (*(volatile unsigned long *)0x40006604)//CAN 过滤器模式寄存器 
#define   CAN_FS0R    (*(volatile unsigned long *)0x4000660C)//CAN 过滤器位宽寄存器 
#define   CAN_FFA0R   (*(volatile unsigned long *)0x40006610)//CAN 过滤器FIFO关联寄存器 
#define   CAN_FA0R    (*(volatile unsigned long *)0x4000661C)//CAN 过滤器激活寄存器 
#define   CAN_F0R     (*(volatile unsigned long *)0x40006640)//CAN 过滤器组0寄存器 
#define   CAN_F1R     (*(volatile unsigned long *)0x400066AC)//CAN 过滤器组1寄存器 

//0x4000 5800 - 0x4000 57FF I2C2//////////////////////////////// 
#define I2C2_CR1       (*(volatile unsigned long *)0x40005800)//控制寄存器1 
#define I2C2_CR2       (*(volatile unsigned long *)0x40005804)//控制寄存器2 
#define I2C2_OAR1      (*(volatile unsigned long *)0x40005808)//自身地址寄存器1 
#define I2C2_OAR2      (*(volatile unsigned long *)0x4000580C)//自身地址寄存器2 
#define I2C2_DR        (*(volatile unsigned long *)0x40005810)//数据寄存器 
#define I2C2_SR1       (*(volatile unsigned long *)0x40005814)//状态寄存器1 
#define I2C2_SR2       (*(volatile unsigned long *)0x40005818)//状态寄存器2 
#define I2C2_CCR       (*(volatile unsigned long *)0x4000581C)//时钟控制寄存器 
#define I2C2_TRISE     (*(volatile unsigned long *)0x40005820)//TRISE寄存器 
//0x4000 5400 - 0x4000 57FF I2C1//////////////////////////////// 
#define I2C1_CR1       (*(volatile unsigned long *)0x40005400)//控制寄存器1 
#define I2C1_CR2       (*(volatile unsigned long *)0x40005404)//控制寄存器2 
#define I2C1_OAR1      (*(volatile unsigned long *)0x40005408)//自身地址寄存器1 
#define I2C1_OAR2      (*(volatile unsigned long *)0x4000540C)//自身地址寄存器2 
#define I2C1_DR        (*(volatile unsigned long *)0x40005410)//数据寄存器 
#define I2C1_SR1       (*(volatile unsigned long *)0x40005414)//状态寄存器1 
#define I2C1_SR2       (*(volatile unsigned long *)0x40005418)//状态寄存器2 
#define I2C1_CCR       (*(volatile unsigned long *)0x4000541C)//时钟控制寄存器 
#define I2C1_TRISE     (*(volatile unsigned long *)0x40005420)//TRISE寄存器 



//0x4001 3800 - 0x4001 3BFF USART2////////////////////////////// 
#define USART1_SR        (*(volatile unsigned long *)0x40013800)//状态寄存器 
#define USART1_DR        (*(volatile unsigned long *)0x40013804)//数据寄存器 
#define USART1_BRR       (*(volatile unsigned long *)0x40013808)//波特比率寄存器 
#define USART1_CR1       (*(volatile unsigned long *)0x4001380C)//控制寄存器1 
#define USART1_CR2       (*(volatile unsigned long *)0x40013810)//控制寄存器2 
#define USART1_CR3       (*(volatile unsigned long *)0x40013814)//控制寄存器3 
#define USART1_GTPR      (*(volatile unsigned long *)0x40013818)//保护时间和预分频寄存器 

//0x4000 4400 - 0x4000 47FF USART2////////////////////////////// 
#define USART2_SR        (*(volatile unsigned long *)0x40004400)//状态寄存器 
#define USART2_DR        (*(volatile unsigned long *)0x40004404)//数据寄存器 
#define USART2_BRR       (*(volatile unsigned long *)0x40004408)//波特比率寄存器 
#define USART2_CR1       (*(volatile unsigned long *)0x4000440C)//控制寄存器1 
#define USART2_CR2       (*(volatile unsigned long *)0x40004410)//控制寄存器2 
#define USART2_CR3       (*(volatile unsigned long *)0x40004414)//控制寄存器3 
#define USART2_GTPR      (*(volatile unsigned long *)0x40004418)//保护时间和预分频寄存器 

//0x4000 4800 - 0x4000 4BFF USART3////////////////////////////// 
#define USART3_SR        (*(volatile unsigned long *)0x40004800)//状态寄存器 
#define USART3_DR        (*(volatile unsigned long *)0x40004804)//数据寄存器 
#define USART3_BRR       (*(volatile unsigned long *)0x40004808)//波特比率寄存器 
#define USART3_CR1       (*(volatile unsigned long *)0x4000480C)//控制寄存器1 
#define USART3_CR2       (*(volatile unsigned long *)0x40004810)//控制寄存器2 
#define USART3_CR3       (*(volatile unsigned long *)0x40004814)//控制寄存器3 
#define USART3_GTPR      (*(volatile unsigned long *)0x40004818)//保护时间和预分频寄存器 

//0x4000 3800 - 0x4000 3BFF SPI2//////////////////////////////// 

//0x4000 3000 - 0x4000 33FF 独立看门狗(IWDG)//////////////////// 
#define  IWDG_KR        (*(volatile unsigned long *)0x40003000)//键值寄存器 
#define  IWDG_PR        (*(volatile unsigned long *)0x40003004)//预分频寄存器 
#define  IWDG_RLR       (*(volatile unsigned long *)0x40003008)//重装载寄存器 
#define  IWDG_SR        (*(volatile unsigned long *)0x4000300C)//状态寄存器 
//0x4000 2C00 - 0x4000 2FFF 窗口看门狗(WWDG)//////////////////// 
#define  WWDG_CR        (*(volatile unsigned long *)0x40002C00)//控制寄存器 
#define  WWDG_CFR       (*(volatile unsigned long *)0x40002C04)//配置寄存器 
#define  WWDG_SR        (*(volatile unsigned long *)0x40002C08)//状态寄存器 
//0x4000 2800 - 0x4000 2BFF RTC///////////////////////////////// 
#define  RTC_CRH       (*(volatile unsigned long *)0x40002800)//RTC控制寄存器高位 
#define  RTC_CRL       (*(volatile unsigned long *)0x40002804)//RTC控制寄存器低位 
#define  RTC_PRLH      (*(volatile unsigned long *)0x40002808)//RTC预分频装载寄存器高位 
#define  RTC_PRLL      (*(volatile unsigned long *)0x4000280C)//RTC预分频装载寄存器低位 
#define  RTC_DIVH      (*(volatile unsigned long *)0x40002810)//RTC预分频分频因子寄存器高位 
#define  RTC_DIVL      (*(volatile unsigned long *)0x40002814)//RTC预分频分频因子寄存器低位 
#define  RTC_CNTH      (*(volatile unsigned long *)0x40002818)//RTC 计数器寄存器高位 
#define  RTC_CNTL      (*(volatile unsigned long *)0x4000281c)//RTC计数器寄存器低 
#define  RTC_ALRH      (*(volatile unsigned long *)0x40002820)//RTC闹钟寄存器高 
#define  RTC_ALRL      (*(volatile unsigned long *)0x40002824)//RTC闹钟寄存器低位 
//0x4000 0800 - 0x4000 0BFF TIM4定时器////////////////////////// 
#define  TIM4_CR1     (*(volatile unsigned long *)0x40000800)//控制寄存器1 
#define  TIM4_CR2     (*(volatile unsigned long *)0x40000804)//控制寄存器2 
#define  TIM4_SMCR    (*(volatile unsigned long *)0x40000808)//从模式控制寄存器 
#define  TIM4_DIER    (*(volatile unsigned long *)0x4000080C)//DMA/中断使能寄存器 
#define  TIM4_SR      (*(volatile unsigned long *)0x40000810)//状态寄存器 
#define  TIM4_EGR     (*(volatile unsigned long *)0x40000814)//事件产生寄存器 
#define  TIM4_CCMR1   (*(volatile unsigned long *)0x40000818)//捕获/比较模式寄存器 
#define  TIM4_CCMR2   (*(volatile unsigned long *)0x4000081C)//捕获/比较模式寄存器2 
#define  TIM4_CCER    (*(volatile unsigned long *)0x40000820)//捕获/比较使能寄存器 
#define  TIM4_CNT     (*(volatile unsigned long *)0x40000824)//计数器 
#define  TIM4_PSC     (*(volatile unsigned long *)0x40000828)//预分频器 
#define  TIM4_ARR     (*(volatile unsigned long *)0x4000082C)//自动重装载寄存器 
#define  TIM4_CCR1    (*(volatile unsigned long *)0x40000834)//捕获/比较寄存器1 
#define  TIM4_CCR2    (*(volatile unsigned long *)0x40000838)//捕获/比较寄存器2 
#define  TIM4_CCR3    (*(volatile unsigned long *)0x4000083C)//捕获/比较寄存器3 
#define  TIM4_CCR4    (*(volatile unsigned long *)0x40000840)//捕获/比较寄存器4 
#define  TIM4_DCR     (*(volatile unsigned long *)0x40000848)//DMA控制寄存器 
#define  TIM4_DMAR    (*(volatile unsigned long *)0x4000084C)//连续模式的DMA地址 
//0x4000 0400 - 0x4000 07FF TIM3定时器////////////////////////// 
#define  TIM3_CR1     (*(volatile unsigned long *)0x40000400)//控制寄存器1 
#define  TIM3_CR2     (*(volatile unsigned long *)0x40000404)//控制寄存器2 
#define  TIM3_SMCR    (*(volatile unsigned long *)0x40000408)//从模式控制寄存器 
#define  TIM3_DIER    (*(volatile unsigned long *)0x4000040C)//DMA/中断使能寄存器 
#define  TIM3_SR      (*(volatile unsigned long *)0x40000410)//状态寄存器 
#define  TIM3_EGR     (*(volatile unsigned long *)0x40000414)//事件产生寄存器 
#define  TIM3_CCMR1   (*(volatile unsigned long *)0x40000418)//捕获/比较模式寄存器 
#define  TIM3_CCMR2   (*(volatile unsigned long *)0x4000041C)//捕获/比较模式寄存器2 
#define  TIM3_CCER    (*(volatile unsigned long *)0x40000420)//捕获/比较使能寄存器 
#define  TIM3_CNT     (*(volatile unsigned long *)0x40000424)//计数器 
#define  TIM3_PSC     (*(volatile unsigned long *)0x40000428)//预分频器 
#define  TIM3_ARR     (*(volatile unsigned long *)0x4000042C)//自动重装载寄存器 
#define  TIM3_CCR1    (*(volatile unsigned long *)0x40000434)//捕获/比较寄存器1 
#define  TIM3_CCR2    (*(volatile unsigned long *)0x40000438)//捕获/比较寄存器2 
#define  TIM3_CCR3    (*(volatile unsigned long *)0x4000043C)//捕获/比较寄存器3 
#define  TIM3_CCR4    (*(volatile unsigned long *)0x40000440)//捕获/比较寄存器4 
#define  TIM3_DCR     (*(volatile unsigned long *)0x40000448)//DMA控制寄存器 
#define  TIM3_DMAR    (*(volatile unsigned long *)0x4000044C)//连续模式的DMA地址 
//0x4000 0000 - 0x4000 03FF TIM2定时器////////////////////////// 
#define  TIM2_CR1     (*(volatile unsigned long *)0x40000000)//控制寄存器1 
#define  TIM2_CR2     (*(volatile unsigned long *)0x40000004)//控制寄存器2 
#define  TIM2_SMCR    (*(volatile unsigned long *)0x40000008)//从模式控制寄存器 
#define  TIM2_DIER    (*(volatile unsigned long *)0x4000000C)//DMA/中断使能寄存器 
#define  TIM2_SR      (*(volatile unsigned long *)0x40000010)//状态寄存器 
#define  TIM2_EGR     (*(volatile unsigned long *)0x40000014)//事件产生寄存器 
#define  TIM2_CCMR1   (*(volatile unsigned long *)0x40000018)//捕获/比较模式寄存器 
#define  TIM2_CCMR2   (*(volatile unsigned long *)0x4000001C)//捕获/比较模式寄存器2 
#define  TIM2_CCER    (*(volatile unsigned long *)0x40000020)//捕获/比较使能寄存器 
#define  TIM2_CNT     (*(volatile unsigned long *)0x40000024)//计数器 
#define  TIM2_PSC     (*(volatile unsigned long *)0x40000028)//预分频器 
#define  TIM2_ARR     (*(volatile unsigned long *)0x4000002C)//自动重装载寄存器 
#define  TIM2_CCR1    (*(volatile unsigned long *)0x40000034)//捕获/比较寄存器1 
#define  TIM2_CCR2    (*(volatile unsigned long *)0x40000038)//捕获/比较寄存器2 
#define  TIM2_CCR3    (*(volatile unsigned long *)0x4000003C)//捕获/比较寄存器3 
#define  TIM2_CCR4    (*(volatile unsigned long *)0x40000040)//捕获/比较寄存器4 
#define  TIM2_DCR     (*(volatile unsigned long *)0x40000048)//DMA控制寄存器 
#define  TIM2_DMAR    (*(volatile unsigned long *)0x4000004C)//连续模式的DMA地址 

#endif
