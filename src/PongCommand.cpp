#include "../inc/Commands.hpp"

PongCommand::PongCommand(Server *server) : Command(server) {}
PongCommand::~PongCommand() {}

void PongCommand::execute(Client *client, std::vector<std::string> args)
{
    if (args.empty())
    {
        client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "PONG"));
        return;
    }
    client->write(RPL_PING(client->getPrefix(), args.at(0)));
}