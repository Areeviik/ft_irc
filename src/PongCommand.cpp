#include "../inc/Commands.hpp"

PongCommand::PongCommand(Server *server) : Command(server) {}
PongCommand::~PongCommand() {}

void PongCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.empty())
    {
        client->reply(ERR_NEEDMOREPARAMS(client->GetNickname(), "PONG"));
        return;
    }
    client->write(RPL_PING(client->GetPrefix(), args.at(0)));
}