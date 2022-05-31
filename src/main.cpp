#include <iostream>
#include <string>

#include "config.hpp"
#include "script.hpp"

std::string configPath, scriptPath, scriptName;

bool exitLoop;

int main (int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cout << "Please specify a file name / Unknown arguments" << std::endl;
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

    while (!exitLoop)
    {
        std::string _command;

        std::cout << "sfile: ";
        std::cin >> _command;
        system(_command.c_str());
        newScript.addCommand(_command);
    }
}
