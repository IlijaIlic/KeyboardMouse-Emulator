#ifndef EMULATOR_H
#define EMULATOR_H

#include <qt_windows.h>

class Emulator
{
public:
    void static emulateKeyDown(WORD k);
    void static emulateKeyUp(WORD k);

    // HELPER FUNCTINS
    void static comboTester();
    void static winD();
};

#endif // EMULATOR_H
