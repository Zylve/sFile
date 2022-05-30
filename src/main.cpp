#include <iostream>
#include <string>

#include "config.hpp"

std::string mainArg;

int main (int argc, char *argv[])
{
    config conf;
    conf.checkForConfig();
}