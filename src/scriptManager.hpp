#include <iostream>
#include <string>
#include <vector>

// No need to canonicize the path since main.cpp will do that

class scriptBuilder
{   
    public:
        std::vector<std::string> cmds;
        std::string file;

        void addCommand(std::string command)
        {
            cmds.push_back(command);
        }

        void help()
        {
            std::cout << "sfile help\n";
            std::cout << "s help - Show this menu\n";
            std::cout << "s roll - Erase the most recent command from the write queue\n";
            std::cout << "s write - Write to disk\n";
            std::cout << "s quit - Quit the program\n";
        }

        void rollback()
        {
            if(cmds.size() > 2)
            cmds.pop_back();
        }

        void write()
        {
            std::ofstream script(file);
            for(int i = 0; i < cmds.size(); i++)
            {
                script << cmds[i] << "\n";
            }
            script.close();
            cmds.clear();
        }

        scriptBuilder(std::string _file, bool _editing)
        {
            file = std::string(_file);
            if(!_editing && !std::filesystem::exists(file))
            {
                std::ofstream script(file);
                script.close();

                cmds.push_back("#!/bin/bash");
                cmds.push_back("");
            }
            else if(!_editing && std::filesystem::exists(file))
            {
                std::cout << "File already exists" << std::endl;
            }
            else if(_editing && !std::filesystem::exists(file))
            {
                std::cout << "File does not exist\n";
                exit(1);
            }
            else{
                std::string _cmd = "." + file;
                system(_cmd.c_str());
            }
        }
};

class scriptExecutor
{
    std::string file;

    public:
        scriptExecutor(std::string _file)
        {
            file =_file;
            // TODO: find the script within scriptPath and execute it
        }

        void execute()
        {
            // system("." + file);
        }
};

class scriptDeletor
{
    public:
        scriptDeletor(std::string _file)
        {

        }
        
        void deleteScript()
        {

        }
};

class scriptList
{
    public:
        std::string path;

        scriptList(std::string _path)
        {
            path = _path;
        }

        void listScripts()
        {
            // List directories
            std::filesystem::directory_iterator dir(path);
        }
};