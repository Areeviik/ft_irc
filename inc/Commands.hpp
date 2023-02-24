#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>

class Command
{
    private:
    public:
};

class MessageCommand : Command
{
    public:
        MessageCommand();
        ~MessageCommand();
        void exec(std::string arg);
};

class JoinCommand : Command
{
    public:
        JoinCommand();
        ~JoinCommand();
        void exec(std::string arg);
};

class LeaveCommand : Command
{
    public:
        LeaveCommand();
        ~LeaveCommand();
        void exec(std::string arg);
};

class ListCommand : Command
{
    public:
        ListCommand();
        ~ListCommand();
        void exec(std::string arg);
};

#endif