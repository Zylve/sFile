#include <iostream>

class systemCall
{
    public:
        std::string payload;
        
        systemCall(std::string call)
        {
            payload = call;
        }

        void deliverPayload()
        {
            const char *command = payload.c_str();
            system(command);
        }
};