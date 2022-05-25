#include <iostream>
#include "extract.hpp"

int main (int argc, char *argv[])
{
    std::string targetArchive = argv[argc - 1];
    extractTarget tar(targetArchive);
    tar.extractArchive();
}