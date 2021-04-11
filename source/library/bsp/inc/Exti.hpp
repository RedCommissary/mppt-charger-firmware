/********************************************************************************
 * project     Class for initialization EXTI of button                          *
 *                                                                              *
 * file        Exti.hpp                                                         *
 * author      @RedCommissary                                                   *
 * date        12.04.2021                                                       *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f3xx.h"

/********************************************************************************
 * Class EXTI
 * 
 * PB5 - external button OF or OFF controller
 * 
 ********************************************************************************/
class Exti {
public:
    static void Init() {
        RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

        SYSCFG->EXTICR[1] |= SYSCFG_EXTICR2_EXTI5_PB;  // Connect PB5 with EXTI
        EXTI->FTSR |= EXTI_FTSR_TR5;                   // Generation interrupt for falling
        EXTI->IMR  |= EXTI_IMR_MR5;                    // Enable interrupt line

        NVIC_EnableIRQ(EXTI9_5_IRQn);  
    }

    static void ResetInterruptFlag() {
        EXTI->PR |= EXTI_PR_PR5;
    }
};