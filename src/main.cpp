#include <iostream>
#include <string>

#include "config.hpp"
#include "script.hpp"
#include "help.hpp"

std::string configPath, scriptPath, scriptName;
bool exitLoop;
config conf;
help sHelp;

int main (int argc, char *argv[])
{
    if (argc == 1)
    {
        std::cout << "Usage: " << argv[0] << " [subcommand] [script]\n";
        return 0;
    }

    if(!conf.checkForConfig()) { conf.makeConfig(); }
    conf.readConfig();
    configPath = conf.configFile;
    scriptPath = conf.scriptPath;

    char *mainArg = new char[std::string(argv[1]).length() + 1];

    // TODO: convert to switch statement

    if(std::string(argv[1]) == "--help" || "-h" || "help")
    {
        std::cout << "Usage: " << argv[0] << " [config] [script]" << "\n";
        sHelp.Help();
        sHelp.New();
        sHelp.Run();
        sHelp.Edit();
        sHelp.Delete();
        sHelp.List();
        return 0;
    } else if(std::string(argv[1]) == "new" || "-n") { /* TODO: make new command */ }
    else if(std::string(argv[1]) == "list" || "-l")
    {
        std::cout << "List of script files:\n";
        for(auto &file : std::filesystem::directory_iterator("."))
        {
            if(file.path().extension() == ".sfile")
            {
                std::cout << file.path().filename() << "\n";
            }
        }
        return 0;
    }

    script newScript(scriptPath + argv[1] + ".sh");

    // what is this lol

    std::cout << "Welcome to sfile. Type \"s help\" for a listing of commands" << "\n";
    while (!exitLoop)
    {
        std::string _command;

        std::cout << "sfile >> ";
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
        if(_command == "s quit")
        {
            exitLoop = true;
        }
        // system(_command.c_str());
        // newScript.addCommand(_command);
    }
    return 0;
}
