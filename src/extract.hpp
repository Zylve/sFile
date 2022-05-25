#include <iostream>
#include "systemCall.hpp"

class extractTarget
{
    public:
        std::string target;

        std::string args;

        extractTarget(std::string _target)
        {
            target = _target;
            args = "-xf";
        }

        void extractArchive()
        {
            std::string command = "bsdtar " + args + " " + target;
            systemCall sCall(command);

            std::cout << "Extracting files..." << std::endl;

            sCall.deliverPayload();
        }
};