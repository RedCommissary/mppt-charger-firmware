/********************************************************************************
 * project     Solar charge controller with MPPT algorithm                      *
 *                                                                              *
 * file        main.cpp                                                         *
 * author      @RedCommissary                                                   *
 * date        07.05.2020                                                       *
 * copyright   The MIT License (MIT)                                            *
 * brief       Main program body                                                *
 *                                                                              *
 ********************************************************************************/

/********************************************************************************
 * Include 
 ********************************************************************************/

#include "main.hpp"

/********************************************************************************
 * Main program body
 ********************************************************************************/

int main() {
    Periphery::Init();
    Application::Init();

    while(1) {}
}