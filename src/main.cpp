#include <iostream>
#include <string>

#include "config.hpp"
#include "script.hpp"

std::string configPath;
std::string scriptPath;
std::string scriptName;

int main (int argc, char *argv[])
{
    if(argc != 2)
    {
        
    }
    config conf;
    if(conf.checkForConfig())
    {
        configPath = conf.configFile;
    }else{
        configPath = conf.configFile;
        conf.makeConfig();
    }
    scriptPath = conf.scriptPath;
}