/********************************************************************************
 * class        Filtering and conversion ADC result                             *
 *                                                                              *
 * file         Feedback.h                                                      *
 * author       @RedCommissary                                                  *
 * date         23.06.2020                                                      *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Adc.hpp"
#include "Gpio.hpp"

#include "FilterWindowMedium.hpp"

/********************************************************************************
 * Class Feedback
 * 
 * Divider input voltage: 100 kOhm / 5.1 kOhm + 1 = 20.6078431
 * Divider output voltage to 12V: 39 kOhm / 10 kOhm + 1 = 4.9
 * Divider output voltage to 24V: 39 kOhm / 5 kOhm + 1 = 8.8
 * 
 * Pin control divider - PA6
 * 
 * Gain current sensor: 75 kOhm / 1 kOhm = 75
 * Current shunt: 0.00 Ohm
 * 
 ********************************************************************************/

class Feedback {
public:
    enum class Divider {
        div12V, div24V
    };

    static bool statusOutputDivider;
    constexpr static uint16_t sizeWindow = 4;

public:
    static void SelectDivider (float voltage);

    static float GetInputVoltage();
    static float GetInputCurrent();
    static float GetOutputVoltage();
    static float GetOutputCurrent();

private:
    static void InitGpioDivider();
    static void SetOutputDivider (Divider divider);

private:
    constexpr static float sampleStepAdc = 0.0008057f;
    constexpr static float gainCurrentSensor = 75.0f;
    constexpr static float currentShunt = 0.002f;
    constexpr static float voltageDivInput = 20.6078431f;
    constexpr static float voltageDivOutput12V = 4.9f;
    constexpr static float voltageDivOutput24V = 8.8f;
    constexpr static float staticErrorInputVoltage = 0.0f;
    constexpr static float staticErrorOutputVoltage = 0.0f;
};