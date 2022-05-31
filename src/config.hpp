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
                fFile << "# Scripts are located at $HOME/.local/share/sfile/" << std::endl;
                fFile.close();
            }
        }

        config()
        {
            homeEnvVar = std::getenv("HOME");
            configFile = homeEnvVar + "/.config/sfile.conf";
            if(!std::filesystem::exists(homeEnvVar + "/.local/share/sfile/"))
            {
                system(("mkdir " + homeEnvVar + "/.local/share/sfile/").c_str());
            }
            scriptPath = homeEnvVar + "/.local/share/sfile/";
        }
};
