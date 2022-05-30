#include <iostream>
#include <string>

#include "config.hpp"

std::string configPath;

int main (int argc, char *argv[])
{
    config conf;
    if(conf.checkForConfig())
    {
        configPath = conf.configFile;
    }else{
        configPath = conf.configFile;
        conf.makeConfig();
    }
}