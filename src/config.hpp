#include <iostream>
#include <string>
#include <cstdlib>

#include <filesystem>
#include <fstream>
#include <sys/stat.h>

class config {
    public:
        std::string homeEnvVar;
        std::string configFile;
        std::string scriptPath;

        bool checkForConfig() {
            return std::filesystem::exists(configFile);
        }

        void makeConfig() {
            std::fstream fFile;
            fFile.open(configFile, std::ios::out);
            if(fFile.is_open()) {
                fFile << "script=$HOME/.local/share/sfile/" << std::endl;
                fFile.close();
            }
        }

        void readConfig() {
            std::fstream fFile;
            fFile.open(configFile, std::ios::in);
            if(fFile.is_open()) {
                std::string line;
                while(std::getline(fFile, line)) {
                    if(line.find("script=") != std::string::npos) {
                        scriptPath = homeEnvVar + line.substr(12);
                    }
                }
                fFile.close();
            }

            if(!std::filesystem::exists(scriptPath)) {
                std::filesystem::create_directory(scriptPath);
                std::filesystem::permissions(scriptPath, std::filesystem::perms::all);
            }
        }

        config() {
            homeEnvVar = std::getenv("HOME");
            configFile = homeEnvVar + "/.config/sfile.conf";
        }
};
