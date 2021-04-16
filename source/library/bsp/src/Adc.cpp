
/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Adc.hpp"

uint16_t Adc::inputVoltage [Adc::sizeBuffer];
uint16_t Adc::inputCurrent [Adc::sizeBuffer];
uint16_t Adc::outputVoltage [Adc::sizeBuffer];
uint16_t Adc::outputCurrent [Adc::sizeBuffer];

uint8_t Adc::step = 0;

/********************************************************************************
 * Class ADC
 ********************************************************************************/

void Adc::Init() {
    Gpio::Init<0,1,2,3,5>(GPIOA, Gpio::Mode::input);
    RCC->AHBENR |= RCC_AHBENR_ADC12EN;

    /*
    * Start calibration for ADC
    */
    ADC1->CR &= ~ADC_CR_ADVREGEN;
    ADC1->CR |= ADC_CR_ADVREGEN_0;      // Enable Vref
    ADC1->CR &= ~ADC_CR_ADCALDIF;

    ADC1->CR |= ADC_CR_ADCAL;           // Start calibration
    while (ADC1->CR & ADC_CR_ADCAL);    // Wait end calibration

    /*
    * Select channel and event for start conversion
    */
    ADC1->JSQR |= 0x10308167;   // 0 00100 0 00011 0 00010 0 00001 01 1001 11 = 0x10308167
                                // Lenght = 4, Trigger = event 9, Type trigger = rising edge, Channel = IN1, IN2, IN3 and IN4

    /*
    * Enable interrupt for ADC
    */
    ADC1->IER |= ADC_IER_JEOSIE;            // Interrupt enable
    NVIC_EnableIRQ(ADC1_2_IRQn);            // Enable interrupt ADC1 and ADC2

    /*
    * Start ADC
    */
    ADC1->CR |= ADC_CR_ADEN;                // Enable ADC1
    while(!(ADC1->ISR & ADC_ISR_ADRDY));    // Wait ready ADC1
    ADC1->CR |= ADC_CR_JADSTART;            // Enable injector conversion
}

/********************************************************************************
 * ADC handler
 ********************************************************************************/

void sAdc::handler() {
    ADC1->ISR |= ADC_ISR_JEOS;

    Adc::outputVoltage[Adc::step] = ADC1->JDR1;
    Adc::outputCurrent[Adc::step] = ADC1->JDR2;
    Adc::inputVoltage[Adc::step] = ADC1->JDR3;
    Adc::inputCurrent[Adc::step] = ADC1->JDR4;
 
    Adc::step++;
    if (Adc::step > Adc::sizeBuffer) { Adc::step = 0; }
}