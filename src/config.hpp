#include <iostream>
#include <string>
#include <cstdlib>

#include <filesystem>
#include <fstream>
#include <sys/stat.h>

class config
{
    public:
        std::string homeEnvVar;
        std::string configFile;
        std::string scriptPath;

        bool checkForConfig()
        {
            return std::filesystem::exists(configFile);
        }

        void makeConfig()
        {
            std::fstream fFile;
            fFile.open(configFile, std::ios::out);
            if(fFile.is_open())
            {
                fFile << "script=$HOME/.local/share/sfile/" << std::endl;
                fFile.close();
            }
        }

        config()
        {
            homeEnvVar = std::getenv("HOME");
            configFile = homeEnvVar + "/.config/sfile.conf";
            if(!std::filesystem::exists(homeEnvVar + "/.local/share/sfile/"))
            {
                std::filesystem::create_directory(homeEnvVar + "/.local/share/sfile/");
                std::filesystem::permissions(homeEnvVar + "/.local/share/sfile/", std::filesystem::perms::all);
            }
            
        }
};
