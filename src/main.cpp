#include <iostream>
#include <string>

#include "config.hpp"
#include "scriptManager.hpp"
#include "help.hpp"

std::string configPath, scriptPath, scriptName;
bool exitLoop;
config conf;
help sHelp;

void script();

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
    }
    // TODO: Add make and run certain class from scriptManager for switch case

    // Run if case = "new"
    buildScript();

    return 0;
}

void buildScript()
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