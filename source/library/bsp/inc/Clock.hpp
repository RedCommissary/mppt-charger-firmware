/********************************************************************************
 * project     Class for initialization clock system                            *
 *                                                                              *
 * file        Clock.h                                                          *
 * author      @RedCommissary                                                   *
 * date        15.05.2020                                                       *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f3xx.h"

/********************************************************************************
 * Class Clock
 *
 * Initialization for the clock's system
 * Source - external crystall
 * Frequency external crystal   - 8 000 000 Hz
 * Frequency for system clock   - 72 000 000 Hz
 * Divider for ADC clock system - 10
 * 
 ********************************************************************************/

class Clock {
public:
    static void Init() {
        RCC->CR |= RCC_CR_HSEON;                                    // Enable system for external crystall
        while (!(RCC->CR & RCC_CR_HSERDY));                         // Waiting flag about enable
        FLASH->ACR |= FLASH_ACR_LATENCY_1;                          // Latency for internal flash memory
        RCC->CFGR  |= RCC_CFGR_PLLMUL9;                             // Select multiplier frequency for PLL x9
        RCC->CFGR  |= RCC_CFGR_PLLSRC;                              // Select source external crystall
        RCC->CFGR2 |= RCC_CFGR2_ADCPRE12_DIV10;                     // Select divider for ADC = AHB/10
        RCC->CR |= RCC_CR_PLLON;                                    // Enable PLL system
        while((RCC->CR & RCC_CR_PLLRDY) == 0){}                     // Waiting flag about enable
        RCC->CFGR |= RCC_CFGR_SW_PLL;                               // Select source SYSCLK = PLL
        while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {}      // Waiting flag about enable
    };
};