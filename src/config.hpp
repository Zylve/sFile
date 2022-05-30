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

        bool checkForConfig()
        {
            if(std::filesystem::exists(configFile))
            {
                return true;
            }else{
                return false;
            }
        }

        void makeConfig()
        {
            std::fstream fFile;
            fFile.open(configFile, std::ios::out);
            if(fFile.is_open())
            {
                system("mkdir $HOME/.local/share/sfile");
                fFile << "scriptPath=" + homeEnvVar + "/.local/share/sfile/";
                fFile.close();
            }
        }

        config()
        {
            homeEnvVar = std::getenv("HOME");
            configFile = homeEnvVar + "/.config/sfileConf.txt";
        }
};