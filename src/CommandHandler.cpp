#include "../inc/CommandHandler.hpp"

CommandHandler::CommandHandler(Server *server) : _server(server)
{
    list, leave.msgjoin
              _cmds["JOIN"] = new JoinCommand(_server);
    _cmds["LEAVE"] = new LeaveCommand(_server);
    _cmds["MESSAGE"] = new MessageCommand(_server);
}

CommandHandler::~CommandHandler()
{
    for (std::map<std::string, Command *>::iterator it = _cmds.begin(); it != _cmds.end(); it++)
        delete it->second;
}

CommandHandler::invoke(Client *client, const std::string &msg)
{
    
}