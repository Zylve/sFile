#include <iostream>
#include <string>

#include "config.hpp"
#include "script.hpp"

std::string configPath, scriptPath, scriptName;

bool exitLoop;

int main (int argc, char *argv[])
{
    if(argc != 1)
    {
        std::cout << "Unknown arguments" << std::endl;
        return 1;
    }

    config conf;
    if(!conf.checkForConfig())
    {
        conf.makeConfig();
    }
    configPath = conf.configFile;
    scriptPath = conf.scriptPath;

    script newScript(scriptPath + argv[1] + ".sh");

    std::cout << "Welcome to sfile. Type \"s help\" for a listing of commands" << std::endl;
    while (!exitLoop)
    {
        std::string _command;

        std::cout << "sfile: ";
        std::cin >> _command;
        if(_command == "s help")
        {
            std::cout << "sfile help\n";
            std::cout << "s help - Show this\n";
            std::cout << "s new - Create a new script file\n";
            std::cout << "s roll - Remove the last command sent from the write queue\n";
            std::cout << "s write - Write to the script\n";
            std::cout << "s quit - Quit the program\n";
        }
        // system(_command.c_str());
        // newScript.addCommand(_command);
    }
}
