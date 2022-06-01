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

        scriptBuilder(std::string _file)
        {
            file = _file;
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

// Literally just the same thing as scriptBuilder. Make sure to make it execute all previous commands first.
class scriptEditor
{
    std::string file;
    public:
        scriptEditor(std::string _file)
        {
            file = _file;
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