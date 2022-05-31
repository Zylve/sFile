#include <iostream>
#include <string>
#include <vector>

class script
{
    public:
        std::vector<std::string> cmds;
        std::string file;

        void addCommand(std::string command)
        {
            cmds.push_back(command);
        }

        script(std::string _file)
        {
            file = _file;
        }
};