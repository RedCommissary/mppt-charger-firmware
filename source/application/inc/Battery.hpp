/********************************************************************************
 * class        Parameters of all type battery                                  *
 *                                                                              *
 * file         Battery.hpp                                                     *
 * author       @RedCommissary                                                  *
 * date         11.04.2021                                                      *
 *                                                                              *
 ********************************************************************************/

#pragma once

/********************************************************************************
 * Include
 ********************************************************************************/

#include <stdint.h>

/********************************************************************************
 * Class Battery
 * 
 * Supported batteries cells:
 *      - Pb                    -   14.4V
 *      - AGM                   -   14.4V
 *      - Gel                   -   14.4V
 *      - Lithium Ion           -   4.2V
 *      - Lithium Polymer       -   4.2V
 *      - LiFePO4               -   3.4V
 *      - Lithium Titanate      -   2.4V
 * 
 ********************************************************************************/

class Battery {
    public:
        struct MaxVoltageCell {
            constexpr static float SLA = 13.6f;
            constexpr static float AGM = 13.6f;
            constexpr static float GEL = 13.6f;
            constexpr static float Lithium = 4.1f;
            constexpr static float LiPo = 4.1f;
            constexpr static float LiFePO = 3.6f;
            constexpr static float LTO = 2.4f;
        };

        struct MinVoltageCell {
            constexpr static float SLA = 10.2f;
            constexpr static float AGM = 10.2f;
            constexpr static float GEL = 10.2f;
            constexpr static float Lithium = 3.2f;
            constexpr static float LiPo = 3.2f;
            constexpr static float LiFePO = 2.9f;
            constexpr static float LTO = 1.6f;
        };
};