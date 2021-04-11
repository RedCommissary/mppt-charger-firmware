/********************************************************************************
 * project     Class for initialization timer                                   *
 *                                                                              *
 * file        Timer.hpp                                                        *
 * author      @RedCommissary                                                   *
 * date        11.04.2021                                                       *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "stm32f3xx.h"

/********************************************************************************
 * Class Timer
 ********************************************************************************/
class Timer {
    public:
        static void InitTimer2 (uint16_t prescaler, uint16_t period) {
            RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;     

            TIM2->PSC = prescaler - 1;
            TIM2->ARR = period;
            TIM2->DIER |= TIM_DIER_UIE;
            TIM2->CR1  |= TIM_CR1_CEN;

            NVIC_EnableIRQ(TIM2_IRQn);
        }

        static void InitTimer3 (uint16_t prescaler, uint16_t period) {
            RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;     

            TIM3->PSC = prescaler - 1;
            TIM3->ARR = period;
            TIM3->DIER |= TIM_DIER_UIE;
            TIM3->CR1  |= TIM_CR1_CEN;

            NVIC_EnableIRQ(TIM3_IRQn);
        }

        static void ResetFlagTim2() {
            TIM2->SR &= ~TIM_SR_UIF;
        }

        static void ResetFlagTim3() {
            TIM3->SR &= ~TIM_SR_UIF;
        }
};