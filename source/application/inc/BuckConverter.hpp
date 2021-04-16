/********************************************************************************
 * class        Control power converter on the buck topology                    *
 *                                                                              *
 * file         Application.h                                                   *
 * author       @RedCommissary                                                  *
 * date         23.06.2020                                                      *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Hrpwm.hpp"
#include "Feedback.hpp"
#include "Pid.hpp"

/********************************************************************************
 * 
 * Class Buck
 * 
 ********************************************************************************/

class BuckConverter {
public:
    void Init();
    void Converter();
    void SetReferenceVoltage (float voltage);
    void SetReferenceCurrent (float current);
    void Start();
    void Stop();
    void LoadEnable (bool status);

private:
    uint16_t dutyResult;

    struct {
        float referenceVoltage;
        float referenceCurrent;
    } Parameters;

    struct {
        bool enable;
        bool error;
    } Status;
};