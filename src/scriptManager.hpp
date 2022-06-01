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
            system("." + _file);
        }


};


// Literally just the same thing as scriptBuilder. Make sure to make it execute all previous commands first.
class scriptEditor : public scriptBuilder
{
    public:
        scriptEditor(std::string _file)
        {

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
        scriptList()
        {

        }

        void listScripts()
        {

        }
};