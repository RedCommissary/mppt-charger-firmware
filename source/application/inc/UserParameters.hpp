/********************************************************************************
 * class        List with user settings for application                         *
 *                                                                              *
 * file         UserParameters.h                                                        *
 * author       @RedCommissary                                                  *
 * date         31.12.2020                                                      *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include
 ********************************************************************************/

#include <stdint.h>

/********************************************************************************
 * Class UserParameters
 ********************************************************************************/
class UserParameters {
public:
    enum class TypeDevices {
        MPPT_2420_HW_v1,        // HW revision PCB in the aluminum case (2020)
        MPPT_2420_HW_v2,        // HW revision PCB with TO-220 transistor (2021)
        MPPT_4840_HW_v1,        // HW revision 150V input 40A for commercial (2021)
        MPPT_4860_HW_v1         // HW revision 200V input 60A for commercial (2020)
    };

    enum class TypeBattery {
        SLA,                    // Serviced lead battery
        AGM,                    // Maintenance-free lead battery
        GEL,                    // Gel lead battery
        Lithium,                // Li-ion cell 18650 or similar
        LiPo,                   // LiPo battery
        LiFePO,                 // LiFePO battery
        LTO                     // Lithium-titanate battery
    };

    TypeDevices device;
    bool displayConnect;

    TypeBattery battery;
    uint8_t numberOfCells;
    float chargeCurrent;

    struct {
        float inputUVLO;
        float inputOCP;
        float outputOCP;
    } Protection;

    struct {
        bool errorInputUVLO;
        bool enableDevice;
    } Status;
};