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
        sHelp.display();
    }else if(std::string(argv[1]) == "--new" || "-n" || "new")
    {
        if(argc == 3)
        {
            scriptName = std::string(argv[2]);
            writeScript(scriptName, false);
        }else{
            std::cout << "Usage: " << argv[0] << " new [script]\n";
        }
    }else if(std::string(argv[1]) == "--run" || "-r" || "run")
    {
        if(argc == 3)
        {
            scriptName = std::string(argv[2]);
            scriptExecutor(std::string(scriptName));
        }else{
            std::cout << "Usage: " << argv[0] << " run [script]\n";
        }
    }else if(std::string(argv[1]) == "--edit" || "-e" || "edit")
    {
        if(argc == 3)
        {
            scriptName = std::string(argv[2]);
            scriptEditor(std::string(scriptName));
        }else{
            std::cout << "Usage: " << argv[0] << " edit [script]\n";
        }
    }else if(std::string(argv[1]) == "--delete" || "-d" || "del" || "delete")
    {
        if(argc == 3)
        {
            scriptName = std::string(argv[2]);
            scriptDeletor(std::string(scriptName));
        }else{
            std::cout << "Usage: " << argv[0] << " del [script]\n";
        }
    }else if(std::string(argv[1]) == "--list" || "-l" || "list")
    {
        // Why the fuck does this error
        if(std::string(argc == 2))
        {
            scriptList(std::string(scriptPath)).listScripts();
        }else{
            std::cout << "Usage: " << argv[0] << " list\n";
        }
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