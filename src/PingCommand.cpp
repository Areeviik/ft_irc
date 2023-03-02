#include "../inc/Commands.hpp"

PingCommand::PingCommand(Server *server) : Command(server) {}
PingCommand::~PingCommand() {}

void PingCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.empty())
    {
        client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "PING"));
        return;
    }
    client->write(RPL_PING(client->getPrefix(), args.at(0)));
}
