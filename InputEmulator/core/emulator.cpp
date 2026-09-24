#include "../emulator.h"
#include <qt_windows.h>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void Emulator::wait(int milliseconds, const std::set<WORD>& pressedKeys)
{
    if (pressedKeys.empty()){
        Emulator::sleep(milliseconds);
        return;
    }

    const int delay = 500;
    const int step = 50;

    if (milliseconds <= delay){
        Emulator::sleep(milliseconds);
        return;
    }

    Emulator::sleep(delay);
    int elapsed = delay;

    while (elapsed < milliseconds){
        for (WORD key: pressedKeys){
            emulateKeyDown(key);
        }

        Emulator::sleep(step);
        elapsed += step;
    }
}

void Emulator::sleep(int milliseconds){
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void Emulator::emulateKeyDown(WORD key) {
    INPUT input = {};

    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}

void Emulator::emulateKeyUp(WORD key) {
    INPUT input = {};

    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = KEYEVENTF_KEYUP;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}

void Emulator::emulateMouseMove(int x, int y){
    INPUT input = {};

    input.type = INPUT_MOUSE;
    input.mi.dx = x;
    input.mi.dy = y;
    input.mi.mouseData = 0;
    input.mi.time = 0;
    input.mi.dwFlags = MOUSEEVENTF_MOVE;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}

void Emulator::emulateMouseLeftClickDown(){
    INPUT input = {};

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}

void Emulator::emulateMouseLeftClickUp(){
    INPUT input = {};

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}

void Emulator::emulateMouseRightClickDown(){
    INPUT input = {};

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}

void Emulator::emulateMouseRightClickUp(){
    INPUT input = {};

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}


void Emulator::emulateMouseScroll(bool isUp, int size){
    INPUT input = {};

    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_WHEEL;
    input.mi.mouseData = (isUp ? 120 : -120) * size;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}

void Emulator::emulateMouseMiddleClickDown(){
    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}

void Emulator::emulateMouseMiddleClickUp(){
    INPUT input = {};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;

    UINT sent = SendInput(1, &input, sizeof(INPUT));
    Emulator::printError(sent);
}

void Emulator::printError(UINT sent){
    if(sent != 1){
        DWORD error = GetLastError();
        std::cout << "GetLastError:" << error;
    }
}

void Emulator::comboTester(){

}

