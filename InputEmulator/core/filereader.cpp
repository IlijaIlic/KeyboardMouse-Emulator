#include "../filereader.h"
#include "../emulator.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

enum class CommandCode{
    keydown,
    keyup,
    mousemove,
    lclickdown,
    lclickup,
    rclickdown,
    rclickup,
    mclickdown,
    mclickup,
    wheel,
    wait,
    unknown
};

CommandCode hasString(const string& str){
    if (str == "KEY_DOWN") return CommandCode::keydown;
    if (str == "KEY_UP") return CommandCode::keyup;
    if (str == "MOUSE_MOVE") return CommandCode::mousemove;
    if (str == "MOUSE_LEFT_DOWN") return CommandCode::lclickdown;
    if (str == "MOUSE_LEFT_UP") return CommandCode::lclickup;
    if (str == "MOUSE_RIGHT_DOWN") return CommandCode::rclickdown;
    if (str == "MOUSE_RIGHT_UP") return CommandCode::rclickup;
    if (str == "MOUSE_MIDDLE_DOWN") return CommandCode::mclickdown;
    if (str == "MOUSE_MIDDLE_UP") return CommandCode::mclickup;
    if (str == "MOUSE_WHEEL") return CommandCode::wheel;
    if (str == "WAIT") return CommandCode::wait;
    return CommandCode::unknown;
}

WORD getKeyCode(const string& value)
{
    if (value.length() == 1)
        return static_cast<WORD>(value[0]);

    if (value == "ENTER")     return VK_RETURN;
    if (value == "SPACE")     return VK_SPACE;
    if (value == "ESC")       return VK_ESCAPE;
    if (value == "SHIFT")     return VK_SHIFT;
    if (value == "CTRL")      return VK_CONTROL;
    if (value == "ALT")       return VK_MENU;
    if (value == "TAB")       return VK_TAB;
    if (value == "BACKSPACE") return VK_BACK;
    if (value == "DELETE")    return VK_DELETE;

    return 0;
}

FileReader::FileReader() {}


void FileReader::test(){

    ifstream MyFile("C:/Users/Ilija/Desktop/test.txt");
    string text;
    std::set<WORD> pressedKeys;

    while(getline(MyFile,text)){
        string command;
        string value;
        istringstream iss(text);
        iss >> command;

        switch (hasString(command)) {

            case CommandCode::keydown:
                iss >> value;
                {
                    WORD code = getKeyCode(value);
                    Emulator::emulateKeyDown(code);
                    pressedKeys.insert(code);
                }
                break;

            case CommandCode::keyup:
                iss >> value;
                {
                    WORD code = getKeyCode(value);
                    Emulator::emulateKeyUp(code);
                    pressedKeys.erase(code);
                }
                break;

            case CommandCode::mousemove:
                getline(iss >> ws, value);
                break;

            case CommandCode::lclickdown:
                break;

            case CommandCode::lclickup:
                break;

            case CommandCode::rclickdown:
                break;

            case CommandCode::rclickup:
                break;

            case CommandCode::mclickdown:
                break;

            case CommandCode::mclickup:
                break;

            case CommandCode::wheel:
                getline(iss >> ws, value);
                break;

            case CommandCode::wait:

                iss >> value;

                Emulator::wait(stoi(value), pressedKeys);
                break;

            case CommandCode::unknown:
                cout << "Nepoznata komanda"<< endl;
                break;

            default:
                cout << "Greska u HasString() funkciji"<< endl;
                break;
        }
    }
}
