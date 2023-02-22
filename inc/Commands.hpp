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
    MessageCommand();
    ~MessageCommand();
    void exec(std::string arg);
};

class JoinCommand : Command
{
    JoinCommand();
    ~JoinCommand();
    void exec(std::string arg);
};

class LeaveCommand : Command
{
    LeaveCommand();
    ~LeaveCommand();
    void exec(std::string arg);
};

class ListCommand : Command
{
    ListCommand();
    ~ListCommand();
    void exec(std::string arg);
};

#endif