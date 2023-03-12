#include "../inc/Commands.hpp"

PingCommand::PingCommand(Server *server) : Command(server) {}
PingCommand::~PingCommand() {}

void PingCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.empty())
    {
        client->reply(ERR_NEEDMOREPARAMS(client->GetNickname(), "PING"));
        return;
    }
    client->write(RPL_PING(client->GetPrefix(), args.at(0)));
}
