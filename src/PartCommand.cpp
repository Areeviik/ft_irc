#include "Commands.hpp"

PartCommand::PartCommand(Server *server) : Command(server) {}

PartCommand::~PartCommand() {}

void PartCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.empty())
    {
        client->reply(ERR_NEEDMOREPARAMS(client->GetNickname(), "PART"));
        return;
    }

    std::string channelName = args[0];
    Channel *channel = _server->getChannel(channelName);
    if (!channel)
    {
        client->reply(ERR_NOSUCHCHANNEL(client->GetNickname(), channelName));
        return;
    }

    if (!client->getChannel() || client->getChannel()->getName() != channelName)
    {
        client->reply(ERR_NOTONCHANNEL(client->GetNickname(), channelName));
        return;
    }

    client->LeaveChannel(channel);
}
//missing client's getChannel