## Firmware for solar charge controller with MPPT algorithm

The charge controller is controlled by a dedicated STM32F334C8T6 microcontroller with a High Resolution PWM (HRPWM) on board. The use of this device is possible a devkit for studying the algorithms for finding the maximum power point (TMM) and as a device for working in an solar power plant with a capacity of up to 3000 W.

## Features:

* Use 32-bit ARM MCU STM32F334C8 with HRPWM
* Type battery: *SLA, AGM, GEL, Li-ion, LiFePo4, LTO*
* Overvoltage
* Undervoltage
* Overcurrent
* Overheat
* PV short circuit
* PV reverse polarity
* Battery reverse polarity

## Hardware

* [MPPT solar charge 12/24V 20A](https://github.com/RedCommissary/mppt-2420-hw)

## License

All source files for the project are distributed under the [MIT](./LICENSE "Text license") license and you can use the project for commercial activities. But you need remembering that the author of the project does not give any guarantees for the operability of the device or parts of the project and also does not bear no liability for claims or damages.
