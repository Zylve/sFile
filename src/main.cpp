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

int main (int argc, char *argv[]) {

    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " [subcommand] [script]\n";
        exit(0);
    }

    if(!conf.checkForConfig())
    conf.makeConfig();
    conf.readConfig();

    configPath = conf.configFile;
    scriptPath = conf.scriptPath;

    if(scriptPath[scriptPath.length() - 1] != '/') {
        scriptPath += "/";
    }

    if(strcmp(argv[1], "help") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        sHelp.display();
    }
    else if(strcmp(argv[1], "list") == 0 || strcmp(argv[1], "-l") == 0 || strcmp(argv[1], "--list") == 0) {
        if(argc != 2) { std::cout << "Usage: " << argv[0] << " list\n"; exit(0); }
        scriptList(std::string(scriptPath));
    }
    else if(strcmp(argv[1], "new") == 0 || strcmp(argv[1], "-n") == 0 || strcmp(argv[1], "--new") == 0) {
        sHelp.usageHelp(argv[0], argv[1], argc);
        writeScript(std::string(scriptPath + argv[2] + ".sh"), false);
    }
    else if(strcmp(argv[1], "run") == 0 || strcmp(argv[1], "-r") == 0 || strcmp(argv[1], "--run") == 0) {
        sHelp.usageHelp(argv[0], argv[1], argc);
        scriptExecutor(std::string(scriptPath + argv[2] + ".sh"));
    }
    else if(strcmp(argv[1], "edit") == 0 || strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "--edit") == 0) {
        sHelp.usageHelp(argv[0], argv[1], argc);
        writeScript(std::string(scriptPath + argv[2] + ".sh"), true);
    }
    else if(strcmp(argv[1], "delete") == 0 || strcmp(argv[1], "del") == 0 || strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--delete") == 0) {
        sHelp.usageHelp(argv[0], argv[1], argc);
        scriptDeletor(std::string(scriptPath + argv[2] + ".sh"));
    }
    exit(0);
}

void writeScript(std::string scriptName, bool isEditing) {
    scriptBuilder sb(scriptName + ".sh", isEditing);

    std::cout << "Welcome to sfile. Type \"s help\" for a listing of commands\n";
    while (!exitLoop)
    {
        bool isSent = false;

        std::string _command;

        std::getline(std::cin, _command);

        if(strcmp(_command.c_str(), "s help") == 0 && !isSent) {
            sb.help();
            isSent = true;
        }
        else if(strcmp(_command.c_str(), "s roll") == 0 && !isSent) {
            sb.rollback();
            isSent = true;
        }
        else if(strcmp(_command.c_str(), "s write") == 0 && !isSent) {
            sb.write();
            isSent = true;
        }
        else if(strcmp(_command.c_str(), "s quit") == 0 && !isSent) {
            exitLoop = true;
            std::cout << "Exiting sfile\n";
            exit(0);
        }
        else if(!isSent) {
            system(_command.c_str());
            sb.addCommand(_command);
        }
    }
}