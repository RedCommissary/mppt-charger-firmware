/********************************************************************************
 * class        Board gpio periphery                                            *
 *                                                                              *
 * file         Pinout.h                                                        *
 * author       @RedCommissary                                                  *
 * date         31.12.2020                                                      *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "Gpio.hPP"

/********************************************************************************
 * Class Led
 * 
 * PA10 - LED ENABLE - RJ45
 * PB15 - LED ERROR  - RJ45
 * 
 * PB1  - LED ON    - GREEN
 * PB2  - LED STAT  - BLUE
 * PC15 - LED INFO  - YELLOW
 * PB4  - LED OCPi  - RED
 * PB12 - LED TEMP  - RED
 * PB13 - LED FLT   - RED
 * PB14 - LED OVP   - RED
 * PA15 - LED OCPo  - RED
 ********************************************************************************/
class Led {
public:  
    enum class Type {
        on, status, info, fault, temperature, ovp, ocpIn, ocpOut
    };

    static void Init() {
        Gpio::Init<10,15>(GPIOA, Gpio::Mode::output, Gpio::Type::PP);
        Gpio::Init<1,2,4,12,13,14,15>(GPIOB, Gpio::Mode::output, Gpio::Type::PP);
        Gpio::Init<15>(GPIOC, Gpio::Mode::output, Gpio::Type::PP);

        Gpio::Reset<10,15>(GPIOA);
        Gpio::Reset<1,2,4,12,13,14,15>(GPIOB);
        Gpio::Reset<15>(GPIOC);
    }

    static void On (Type led) {
        switch (led) {
        case Type::on:
            Gpio::Set<1>(GPIOB);
            Gpio::Set<10>(GPIOA);
            break;
        case Type::status:
            Gpio::Set<2>(GPIOB);
            break;
        case Type::info:
            Gpio::Set<15>(GPIOC);
            Gpio::Set<15>(GPIOB);
            break;
        case Type::fault:
            Gpio::Set<13>(GPIOB);
            break;
        case Type::temperature:
            Gpio::Set<12>(GPIOB);
            break;
        case Type::ovp:
            Gpio::Set<14>(GPIOB);
            break;
        case Type::ocpIn:
            Gpio::Set<4>(GPIOB);
            break;
        case Type::ocpOut:
            Gpio::Set<15>(GPIOA);
            break;                   
        default:
            break;
        }
    }

    static void Off (Type led) {
        switch (led) {
        case Type::on:
            Gpio::Reset<1>(GPIOB);
            Gpio::Reset<10>(GPIOA);
            break;
        case Type::status:
            Gpio::Reset<2>(GPIOB);
            break;
        case Type::info:
            Gpio::Reset<15>(GPIOC);
            Gpio::Reset<15>(GPIOB);
            break;
        case Type::fault:
            Gpio::Reset<13>(GPIOB);
            break;
        case Type::temperature:
            Gpio::Reset<12>(GPIOB);
            break;
        case Type::ovp:
            Gpio::Reset<14>(GPIOB);
            break;
        case Type::ocpIn:
            Gpio::Reset<4>(GPIOB);
            break;
        case Type::ocpOut:
            Gpio::Reset<15>(GPIOA);
            break;                   
        default:
            break;
        }
    }

    static void Toggle (Type led) {
        switch (led) {
        case Type::on:
            Gpio::Toggle<1>(GPIOB);
            Gpio::Toggle<10>(GPIOA);
            break;
        case Type::status:
            Gpio::Toggle<2>(GPIOB);
            break;
        case Type::info:
            Gpio::Toggle<15>(GPIOC);
            Gpio::Toggle<15>(GPIOB);
            break;
        case Type::fault:
            Gpio::Toggle<13>(GPIOB);
            break;
        case Type::temperature:
            Gpio::Toggle<12>(GPIOB);
            break;
        case Type::ovp:
            Gpio::Toggle<14>(GPIOB);
            break;
        case Type::ocpIn:
            Gpio::Toggle<4>(GPIOB);
            break;
        case Type::ocpOut:
            Gpio::Toggle<15>(GPIOA);
            break;                   
        default:
            break;
        }
    }
};
