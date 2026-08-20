#include "../emulator.h"
#include <qt_windows.h>
#include <iostream>

void Emulator::winD(){
    INPUT inputs[4] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = VK_LWIN;

    inputs[1].type = INPUT_KEYBOARD;
    inputs[1].ki.wVk = 'D';

    inputs[2].type = INPUT_KEYBOARD;
    inputs[2].ki.wVk = VK_LWIN;
    inputs[2].ki.dwFlags = KEYEVENTF_KEYUP;

    inputs[3].type = INPUT_KEYBOARD;
    inputs[3].ki.wVk = 'D';
    inputs[3].ki.dwFlags =  KEYEVENTF_KEYUP;


    UINT sent = SendInput(4, inputs, sizeof(INPUT));
    std::cout<< std::endl << "TEST" << std::endl;
    std::cout << sent << std::endl;

    DWORD error = GetLastError();

    std::cout << "GetLastError:" << error;
}

void Emulator::emulateKeyDown(WORD key) {
    INPUT input[1] = {};

    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = key;

    UINT sent = SendInput(1, input, sizeof(INPUT));

    if(sent != 1){
        DWORD error = GetLastError();
        std::cout << "GetLastError:" << error;
    }
}

void Emulator::emulateKeyUp(WORD key) {
    INPUT input[1] = {};

    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = key;
    input[0].ki.dwFlags = KEYEVENTF_KEYUP;

    UINT sent = SendInput(1, input, sizeof(INPUT));

    if(sent != 1){
        DWORD error = GetLastError();
        std::cout << "GetLastError:" << error;
    }
}

void Emulator::comboTester(){
    Emulator::emulateKeyDown(VK_LWIN);
    Emulator::emulateKeyDown('D');
    Emulator::emulateKeyUp(VK_LWIN);
    Emulator::emulateKeyUp('D');
}

