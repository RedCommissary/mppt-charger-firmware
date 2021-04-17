/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Application.hpp"

/********************************************************************************
 * Variables 
 ********************************************************************************/

BuckConverter Buck;
UserParameters User;

float inputVoltage = 0.0f;
float outputVoltage = 0.0f;

/********************************************************************************
 * Class Application
 ********************************************************************************/

void Application::Init() {
    User.Status.enableDevice = false;
    User.Protection.inputUVLO = 15.0f;

    Buck.Stop();
    Buck.SetReferenceVoltage(14.4f);
    Buck.SetReferenceCurrent(5.0f);
    Buck.Init();
    Buck.LoadEnable(true);

    StartLowSpeedProcessing();
    StartHighSpeedProcessing();
}

/********************************************************************************
 * High speed processing #1
 ********************************************************************************/

void sTim2::handler() {
    Timer::ResetFlagTim2();

    bool errorConverter = User.Status.errorInputUVLO;
    
    if (errorConverter || (!User.Status.enableDevice)) {
        Buck.Stop();
        Led::On(Led::Type::fault);
    } else {
        Buck.Start();
        Led::Off(Led::Type::fault);
    }

    Buck.Converter();
}

/********************************************************************************
 * Low speed processing #1
 ********************************************************************************/

void sTim3::handler() {
    Timer::ResetFlagTim3();
    Led::Toggle(Led::Type::status);

    // Monitoring real-time
    inputVoltage = Feedback::GetInputVoltage();
    outputVoltage = Feedback::GetOutputVoltage();

    // UVLO input voltage
    if (inputVoltage > User.Protection.inputUVLO) {
        User.Status.errorInputUVLO = false;
        Led::Off(Led::Type::ovp);
    } else {
        User.Status.errorInputUVLO = true;
        Led::On(Led::Type::ovp);
    }
    
}

/********************************************************************************
 * Logic for button
 ********************************************************************************/
void sExti::line5Handler() {
    Exti::ResetInterruptFlag();

    User.Status.enableDevice = !User.Status.enableDevice;
    if (User.Status.enableDevice) {
        Led::On(Led::Type::on);
    } else {
        Led::Off(Led::Type::on);
    }          
}