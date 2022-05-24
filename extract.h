#include <iostream>
#include <bits/stdc++.h>

class extractTarget
{
    public:
        extractTarget(std::string _target)
        {
            target = _target;
        }

        void extractArchive()
        {
            std::string _str = "bsdtar -xf " + target;
            const char *command = _str.c_str();
            std::cout << "Extracting files" << std::endl;
            system(command);
        }

        std::string target;
};