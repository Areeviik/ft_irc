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
    bool _authRequired;

public:
    explicit Command(Server *server) : _server(server){};
    virtual ~Command(){};

    virtual void exec(Client *client, std::vector<std::string> args) = 0;
    bool authRequired() const { return _authRequired; };
};

class PrivMsgCommand : public Command
{
public:
    PrivMsgCommand(Server *server);
    ~PrivMsgCommand();
    void exec(Client *client, std::vector<std::string> args);
};

class JoinCommand : public Command
{
public:
    JoinCommand(Server *server);
    ~JoinCommand();
    void exec(Client *client, std::vector<std::string> args);
};

class QuitCommand : public Command
{
public:
    QuitCommand(Server *server, bool authRequired);
    ~QuitCommand();
    void exec(Cliet *client, std::vector<std::string> args);
};

class NickCommand : public Command
{
public:
    NickCommand(Server *server, bool authRequired);
    ~NickCommand();

    void exec(Client *client, std::vector<std::string> arguments);
};

class ModeCommand : public Command
{
public:
    ModeCommand(Server *server);
    ~ModeCommand();

    void exec(Client *client, std::vector<std::string> arguments);
};

#endif