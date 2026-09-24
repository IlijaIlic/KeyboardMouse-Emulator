#ifndef EMULATOR_H
#define EMULATOR_H

#include <qt_windows.h>
#include <set>

class Emulator
{
public:
    void static wait(int s, const std::set<WORD>& pressedKeys);
    void static sleep(int s);
    void static emulateKeyDown(WORD k);
    void static emulateKeyUp(WORD k);
    void static emulateMouseMove(int x, int y);
    void static emulateMouseRightClickDown();
    void static emulateMouseRightClickUp();
    void static emulateMouseLeftClickDown();
    void static emulateMouseLeftClickUp();
    void static emulateMouseMiddleClickDown();
    void static emulateMouseMiddleClickUp();
    void static emulateMouseScroll(bool isUp, int size);

    // HELPER FUNCTINS
    void static comboTester();

    // void static emulateMouseMoveSmoothly(int x, int y, int time);
private:
    void static printError(UINT sent);


};

#endif // EMULATOR_H
