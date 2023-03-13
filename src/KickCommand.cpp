#include "Commands.hpp"

KickCommand::KickCommand(Server *Server) : Command(server) {}
KickCommand::~KickCommand() {}

void KickCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.size() < 2)
    {
        client->reply(ERR_NEEDMOREPARAMS(client->GetNickname(), "KICK"));
        return;
    }
    std::string reason = "The reason isn't described)";
    std::string channelName = args[0];
    std::string point = args[1];
    if (args.size() >= 3 && (args[2][0] != ':' || args[2].size() > 1))
    {
        reason = "";
        for (std::vector<std::string>::iterator it = args.begin() + 2; it != args.end(); it++)
            reason.append(*it + " ");
    }
    Channel *channel = client->getChannel();
    if (!channel || channel->GetName() != channelName)
    {
        client->reply(ERR_NOTONCHANNEL(client->GetNickname(), channelName));
        return;
    }
    if (channel->getAdmin() != client)
    {
        client->reply(ERR_CHANOPRIVSNEEDED(client->GetNickname(), channelName));
        return;
    }

    Client *ordinaryCLient = _server->getClient(point);
    if (!ordinaryCLient)
    {
        client->reply(ERR_NOSUCHNICK(client->GetNickname(), point));
        return;
    }
    if (!ordinaryCLient->getChannel() || client->getChannel() != channel)
        return;

    channel->Kick(client, ordinaryCLient, reason);

    //missing client's getChannel and channel's getAdmin fns
}