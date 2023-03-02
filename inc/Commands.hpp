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
    bool _auth;

public:
    explicit Command(Server *server) : _server(server){};
    virtual ~Command(){};

    virtual void exec(Client *client, std::vector<std::string> args) = 0;
    bool authRequired() const { return _auth; };
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
    QuitCommand(Server *server, bool auth);
    ~QuitCommand();
    void exec(Cliet *client, std::vector<std::string> args);
};

class NickCommand : public Command
{
public:
    NickCommand(Server *server, bool auth);
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

class UserCommand : public Command
{
public:
    UserCommand(Server *server, bool auth);
    ~UserCommand();

    void exec(Client *client, std::vector<std::string> arguments);
};

class PassCommand : public Command
{
public:
    PassCommand(Server *server, bool authRequired);
    ~PassCommand();

    void exec(Client *client, std::vector<std::string> arguments);
};

class PingCommand : public Command
{
public:
    PingCommand(Server *server);
    ~PingCommand();

    void exec(Client *client, std::vector<std::string> arguments);
};

class PongCommand : public Command
{
public:
    PongCommand(Server *server);
    ~PongCommand();

    void exec(Client *client, std::vector<std::string> arguments);
};

#endif