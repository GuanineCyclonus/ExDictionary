#include <iostream>

#include "src/CommandFunctions/CommandFunctions.h"
#include "ExDictionaryConfig.h"

extern int commandCode;

int main(int argc, char* argv[]) 
{

    std::cout << "Welcome to ExDictionary!" << std::endl;
    #if USING_RELEASE_MODE
    std::cout << "Version: " << EXDICTIONARY_VERSION_MAJOR << "." << EXDICTIONARY_VERSION_MINOR;
    std::cout << "." << EXDICTIONARY_VERSION_PATCH << std::endl;
    #else
    std::cout << "Build date: " << __DATE__ << " " << __TIME__ << std::endl;
    #endif
    std::cout << "Load successfully." << std::endl;
    while (true) {
        // std::cout << "Reading CommandCode..." << std::endl;
        GetCommand();
        // std::cout << "CommandCode is " << commandCode << std::endl;
        JumpToCertainMode();
        if (commandCode == -1) {
            break;
        }
    }
    return 0;
}