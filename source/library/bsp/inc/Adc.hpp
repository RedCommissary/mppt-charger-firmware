/********************************************************************************
 * class        Initialization and read ADC                                     *
 *                                                                              *
 * file         Adc.h                                                           *
 * author       @RedCommissary                                                  *
 * date         15.05.2020                                                      *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "startupF334.hpp"
#include "Gpio.hpp"

/********************************************************************************
 * Class ADC
 * 
 * Pin voltage output   - PA0   - ADC1 IN1
 * Pin current output   - PA1   - ADC1 IN2
 * Pin voltage input    - PA2   - ADC1 IN3
 * Pin current input    - PA3   - ADC1 IN4
 * Pin temperature      - PA5   - ADC2 IN2
 * 
 ********************************************************************************/

class Adc {
    public:
        constexpr static uint8_t sizeBuffer = 10;

        static uint16_t inputVoltage [sizeBuffer];
        static uint16_t inputCurrent [sizeBuffer];
        static uint16_t outputVoltage [sizeBuffer];
        static uint16_t outputCurrent [sizeBuffer];
        static uint8_t step;

        static void Init();
};