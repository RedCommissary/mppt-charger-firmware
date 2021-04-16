/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Feedback.hpp"

/********************************************************************************
 * Variables
 ********************************************************************************/

bool Feedback::statusOutputDivider = false;

/********************************************************************************
 * Class Feedback
 ********************************************************************************/

void Feedback::InitGpioDivider() {
    Gpio::Init<6>(GPIOA, Gpio::Mode::output, Gpio::Type::PP);
}

void Feedback::SetOutputDivider (Divider divider) {
    if (divider == Divider::div12V) { 
        GPIOA->BSRR |= GPIO_BSRR_BR_6; 
        statusOutputDivider = false;
    }

    if (divider == Divider::div24V) {
        GPIOA->BSRR |= GPIO_BSRR_BS_6;
        statusOutputDivider = true;
    }
} 

void Feedback::SelectDivider (float voltage) {
    InitGpioDivider();

    if (voltage > 16.0f) {
        Feedback::SetOutputDivider(Feedback::Divider::div24V);
    } else {
        Feedback::SetOutputDivider(Feedback::Divider::div12V);
    }
}

float Feedback::GetInputVoltage() {
    float inputVoltage = FilterWindowMedium::Compute(Adc::inputVoltage, Adc::sizeBuffer, sizeWindow);
    return (inputVoltage * voltageDivInput * sampleStepAdc + staticErrorInputVoltage);
}

float Feedback::GetInputCurrent() {
    float inputCurrent = FilterWindowMedium::Compute(Adc::inputCurrent, Adc::sizeBuffer, sizeWindow);
    return (inputCurrent * sampleStepAdc / gainCurrentSensor / currentShunt);
}

float Feedback::GetOutputVoltage() {
    if (statusOutputDivider) {
        float outputVoltage = FilterWindowMedium::Compute(Adc::outputVoltage, Adc::sizeBuffer, sizeWindow);
        return (outputVoltage * sampleStepAdc * voltageDivOutput24V + staticErrorOutputVoltage);
    } else {
        float outputVoltage = FilterWindowMedium::Compute(Adc::outputVoltage, Adc::sizeBuffer, sizeWindow);
        return (outputVoltage * sampleStepAdc * voltageDivOutput12V + staticErrorOutputVoltage);
    }
}

float Feedback::GetOutputCurrent() {
    float outputCurrent = FilterWindowMedium::Compute(Adc::outputCurrent, Adc::sizeBuffer, sizeWindow);
    return (outputCurrent * sampleStepAdc / gainCurrentSensor / currentShunt);
}