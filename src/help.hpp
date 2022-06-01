#include <iostream>
#include <string>

class help
{
    public:
        void New() {
            std::cout << "sfile new/-n/--new [script] - Create a new script file\n";
        }
        void Run() {
            std::cout << "sfile run/-r/--run [script] - Run a script file\n";
        }
        void Edit() {
            std::cout << "sfile edit/-e/--edit [script] - Edit a script file\n";
        }
        void Delete() {
            std::cout << "sfile delete/del/-d/--delete [script] - Delete a script file\n";
        }
        void List() {
            std::cout << "sfile list/ls/-l/--list - List all script files\n";
        }
        void Help() {
            std::cout << "sfile help/-h/--help - Show this\n";
        }
        void display()
        {
            std::cout << "sfile - A simple script manager\n";
            std::cout << "Usage: sfile [subcommand] [script]\n";
            std::cout << "Subcommands:\n";
            New();
            Run();
            Edit();
            Delete();
            List();
            Help();
        }
};