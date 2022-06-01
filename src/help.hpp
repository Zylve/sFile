#include <iostream>
#include <string>

class help
{
    public:
        void New() {
            std::cout << "Usage: sfile new [script] - Create a new script file\n";
        }
        void Run() {
            std::cout << "sfile run [script] - Run a script file\n";
        }
        void Edit() {
            std::cout << "sfile edit [script] - Edit a script file\n";
        }
        void Delete() {
            std::cout << "sfile del [script] - Delete a script file\n";
        }
        void List() {
            std::cout << "sfile list - List all script files\n";
        }
        void Help() {
            std::cout << "sfile help - Show this\n";
        }
};