#include "../inc/Commands.hpp"

ModeCommand::ModeCommand(Server *server) : Command(server) {}
ModeCommand::~ModeCommand() {}

coid ModeCommand::exec(Client *client, std::vector<std::string> args)
{
    std::string point = args.at(0);
    if (args.size() != 2)
    {
        client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "MODE"));
        return;
    }

    Channel *channel = _server->getChannel(point);
    if (!channel)
    {
        client->reply(ERR_NOSUCHCHANNEL(client->getNickname(), point));
        return;
    }
    if (chanel->getAdmin() != client)
    {
        client->reply(ERR_CHANOPRIVSNEEDED(client->getNickname(), point));
        return;
    }
    
}