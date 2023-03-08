#ifndef COMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

#include "Commands.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
//include Server

class CommandHandler
{
private:
    Server *_server;
    std::map<std::string, Command *> _cmds;

public:
    CommandHandler(Server *server);
    ~CommandHandler();
    void parser(Client *client, const std::string &msg);
}

#endif