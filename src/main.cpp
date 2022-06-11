#include <iostream>
#include <string>
#include <cstring>

#include "config.hpp"
#include "scriptManager.hpp"
#include "help.hpp"

std::string configPath, scriptPath, scriptName;
bool exitLoop = false;
config conf;
help sHelp;

void writeScript(std::string, bool);

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " [subcommand] [script]\n";
        exit(0);
    }

    if(!conf.checkForConfig())
    conf.makeConfig();
    conf.readConfig();

    configPath = conf.configFile;
    scriptPath = conf.scriptPath;

    if(strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        sHelp.display();
    }
    
    else if(strcmp(argv[1], "list") == 0 || strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0)
    {
        if(argc != 2) { std::cout << "Usage: " << argv[0] << " list\n"; exit(0); }

        scriptList(std::string(scriptPath));
    }

    if(strcmp(argv[1], "new") == 0 || strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "--new") == 0)
    {
        sHelp.usageHelp(argv[0], argv[1], argc);
        writeScript(std::string(scriptPath + argv[2]), false);
    }
    else if(strcmp(argv[1], "run") == 0 || strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--run") == 0)
    {
        sHelp.usageHelp(argv[0], argv[1], argc);
        scriptExecutor(std::string(scriptPath + argv[2]));
    }
    else if(strcmp(argv[1], "edit") == 0 || strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "--edit") == 0)
    {
        sHelp.usageHelp(argv[0], argv[1], argc);
        writeScript(std::string(scriptPath + argv[2]), true);
    }
    else if(strcmp(argv[1], "delete") == 0 || strcmp(argv[1], "del") == 0 || strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--delete") == 0)
    {
        sHelp.usageHelp(argv[0], argv[1], argc);
        scriptDeletor(std::string(scriptPath + argv[2]));
    }
    exit(0);
}

void writeScript(std::string scriptName, bool isEditing)
{
    scriptBuilder sb(scriptName, isEditing);

    std::cout << "Welcome to sfile. Type \"s help\" for a listing of commands\n";
    while (!exitLoop)
    {
        std::string _command;

        std::cout << "[sfile]$ ";
        std::cin >> _command;

        if(_command == "s help")
        sb.help();
        else if(_command == "s roll")
        sb.rollback();
        else if(_command == "s write")
        sb.write();
        else if(_command == "s quit") {
            exitLoop = true;
            std::cout << "Exiting sfile\n";
            exit(0);
        }else{
            system(_command.c_str());
            sb.addCommand(_command);
        }
    }
}