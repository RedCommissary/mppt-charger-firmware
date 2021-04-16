/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Application.hpp"

/********************************************************************************
 * Variables 
 ********************************************************************************/

BuckConverter Buck;

float inputVoltageUser = 0.0f;
float outputVoltageUser = 0.0f;
uint16_t adcInputVoltage = 0;
uint16_t adcOutputVoltage = 0;

/********************************************************************************
 * Class Application
 ********************************************************************************/

void Application::Init() {
    Buck.SetReferenceVoltage(15.0f);
    Buck.SetReferenceCurrent(5.0f);
    Buck.Init();
    Buck.Start();
    Buck.LoadEnable(true);

    StartLowSpeedProcessing();
    StartHighSpeedProcessing();
    Led::On(Led::Type::on);
}

/********************************************************************************
 * High speed processing #1
 ********************************************************************************/

void sTim2::handler() {
    Timer::ResetFlagTim2();
    Buck.Converter();
}

/********************************************************************************
 * Low speed processing #1
 ********************************************************************************/

void sTim3::handler() {
    Timer::ResetFlagTim3();
    Led::Toggle(Led::Type::status);

    adcInputVoltage = Adc::inputVoltage[0];
    adcOutputVoltage = Adc::outputVoltage[0];

    inputVoltageUser = Feedback::GetInputVoltage();
    outputVoltageUser = Feedback::GetOutputVoltage();
}

/********************************************************************************
 * Logic for button
 ********************************************************************************/
void sExti::line5Handler() {
    Exti::ResetInterruptFlag();
    Led::Toggle(Led::Type::fault);             
}