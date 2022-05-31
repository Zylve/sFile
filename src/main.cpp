#include <iostream>
#include <string>

#include "config.hpp"

std::string configPath;
std::string scriptPath;

int main (int argc, char *argv[])
{
    config conf;
    if(!conf.checkForConfig())
    {
        conf.makeConfig();
    }
    configPath = conf.configFile;
    scriptPath = conf.scriptPath;
}
