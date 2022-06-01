#include <iostream>
#include <string>

#include "config.hpp"
#include "script.hpp"

std::string configPath, scriptPath, scriptName;

bool exitLoop;

int main (int argc, char *argv[])
{
    // TODO: Throw user out if argc = 1 and display a little usage command    

    config conf;
    if(!conf.checkForConfig())
    {
        conf.makeConfig();
    }

    conf.readConfig();

    configPath = conf.configFile;
    scriptPath = conf.scriptPath;
    std::cout << "Script Path: " << scriptPath << std::endl;

    if(argc == 2 && std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h" || std::string(argv[1]) == "help")
    {
        std::cout << "Usage: " << argv[0] << " [config] [script]" << std::endl;
        std::cout << "sfile --help/-h/help - Show this\n";
        std::cout << "sfile new [script] - Create a new script file\n";
        std::cout << "sfile run [script] - Run a script file\n";
        std::cout << "sfile edit [script] - Edit a script file\n";
        std::cout << "sfile del [script] - Delete a script file\n";
        std::cout << "sfile list - List all script files\n";
        return 0;
    }else if(argc == 3 && std::string(argv[1]) == "new" || std::string(argv[1]) == "-n")
    {

    }else if(argc == 2 && std::string(argv[1]) == "list" || std::string(argv[1]) == "-l")
    {
        std::cout << "List of script files:" << std::endl;
        for(auto &file : std::filesystem::directory_iterator("."))
        {
            if(file.path().extension() == ".sfile")
            {
                std::cout << file.path().filename() << std::endl;
            }
        }
        return 0;
    }

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
