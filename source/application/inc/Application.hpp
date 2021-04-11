/********************************************************************************
 * class        Control and algorithms for application                          *
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

#include "startupF334.hpp"

#include "UserParameters.hpp"

#include "Clock.hpp"
#include "Led.hpp"
#include "Timer.hpp"

#include "Battery.hpp"

/********************************************************************************
 * Class Application
 * 
 * High speed handler   -   2 kHz
 * Low speed handler    -   1 Hz
 * 
 ********************************************************************************/

class Application {       
    public:
        static void Init();

    private:
        static void StartHighSpeedProcessing() {
            Timer::InitTimer2(36, 500);
        }

        static void StartLowSpeedProcessing() {
            Timer::InitTimer3(36000, 1000);
        }
};