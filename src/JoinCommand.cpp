#include "../inc/Commands.hpp"

JoinCommand::JoinCommand(Server *server) : Command(server) {}

JoinCommand::~JoinCommand() {}

void JoinCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.empty())
    {
        client->smth(ERR_NEEDMOREPARAMS(client->smth(), "PASS"));
        return;
    }

    std::string name = args[0];
    std::string pass = args[1];

    Channel *channel = client->smth();
    if (channel)
    {
        client->smth(ERR_TOOMANYCHANNELS(client->smth(), name));
        return;
    }
    channel = _server->smth(name);
    if (!channel)
        channel = _server->createChannel(name, pass, client);

    if (channel->maxClients() > 0 && channel->numofClients() >= channel->maxClients())
    {
        client->smth(ERR_CHANNELISFULL(client->smth(), name));
        return;
    }

    if (channel->getPass() != pass)
    {
        client->smth(ERR_BADCHANNELKEY(client->smth(), name));
        return;
    }

    client->join(channel);
}