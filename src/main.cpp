#include <iostream>
#include <string>

#include "config.hpp"
#include "scriptManager.hpp"
#include "help.hpp"

std::string configPath, scriptPath, scriptName;
bool exitLoop;
config conf;
help sHelp;

void writeScript(std::string, bool);

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " [subcommand] [script]\n";
        return 0;
    }

    if(!conf.checkForConfig())
    conf.makeConfig();
    conf.readConfig();
    configPath = conf.configFile;
    scriptPath = conf.scriptPath;
    std::string arg1 = std::string(argv[1]);

    if(arg1 == "--help" || "-h" || "help")
    sHelp.display();
    else if(arg1 == "--list" || "-l" || "list")
    {
        if(argc != 2) { std::cout << "Usage: " << argv[0] << " list\n"; return 0; }
        scriptList(std::string(scriptPath)).listScripts();
    }
    else if(arg1 == "--new" || "-n" || "new" || "--run" || "-r" || "run" || "--edit" || "-e" || "edit" || "--delete" || "-d" || "del" || "delete")
    {
        if(argc != 3) { std::cout << "Usage: " << argv[0] << " " << argv[1] << " [script]\n"; return 0; }
        if (arg1 == "--new" || "-n" || "new")
        writeScript(std::string(argv[2]), false);
        else if (arg1 == "--run" || "-r" || "run")
        scriptExecutor(std::string(argv[2]));
        else if (arg1 == "--edit" || "-e" || "edit")
        scriptEditor(std::string(argv[2]));
        else if (arg1 == "--delete" || "-d" || "del" || "delete")
        scriptDeletor(std::string(argv[2]));
    }
    // TODO: Add make and run certain class from scriptManager for if-else chain

    // writeScript(scriptname, isEditing boolean);

    return 0;
}

void writeScript(std::string scriptName, bool isEditing)
{
    // Create new script
    scriptBuilder script(scriptPath + "foo bar" /* argv[2] */ + ".sh");


    // Iterate through std::cin and add commands to script until the user runs "s quit"
    std::cout << "Welcome to sfile. Type \"s help\" for a listing of commands" << "\n";
    while (!exitLoop)
    {
        std::string _command;

        std::cout << "sfile >> ";
        std::cin >> _command;

        // TODO: offload help stuff to scriptBuilder class

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

        // TODO: make sure this actually fucking works before making these system calls

        // system(_command.c_str());
        // newScript.addCommand(_command);
    }
}