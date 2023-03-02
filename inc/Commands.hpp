#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "../utils/Errors.hpp"
// include Server and client
#include <string>
#include <vector>

class Command
{
private:
protected:
    Server *_server;

public:
    explicit Command(Server *server) : _server(server){};
    virtual ~Command(){};

    virtual void exec(Client *client, std::vector<std::string> args) = 0
};

class MessageCommand : public Command
{
public:
    MessageCommand();
    ~MessageCommand();
    void exec(Client *client, std::vector<std::string> args);
};

class JoinCommand : public Command
{
public:
    JoinCommand(Server *server);
    ~JoinCommand();
    void exec(Client *client, std::vector<std::string> args);
};

class LeaveCommand : public Command
{
public:
    LeaveCommand(Server *server);
    ~LeaveCommand();
    void exec(Cliet *client, std::vector<std::string> args);
};

#endif