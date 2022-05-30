#include <iostream>
#include <string>
#include <cstdlib>

#include <filesystem>
#include <fstream>

class config
{
    public:
        configObject checkForConfig()
        {
            std::string homeEnvVar = std::getenv("HOME");
            std::string configFile = homeEnvVar + "/.config/sfileConf.txt";
            if(std::filesystem::exists(configFile))
            {
                return configObject(true, configFile);
            }else{
                return configObject(false, configFile);
            }
        }
        config()
        {

        }
};

class configObject
{
    public:
        bool exists;
        std::string path;

        configObject(bool _exists, std::string _path)
        {
            exists = _exists;
            path = _path;
        }
};