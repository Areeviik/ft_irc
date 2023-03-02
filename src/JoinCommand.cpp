#include "../inc/Commands.hpp"

JoinCommand::JoinCommand(Server *server) : Command(server) {}

JoinCommand::~JoinCommand() {}

void JoinCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.empty())
    {
        client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "PASS"));
        return;
    }

    std::string name = args[0];
    std::string pass = args[1];

    Channel *channel = client->getChannel();
    if (channel)
    {
        client->reply(ERR_TOOMANYCHANNELS(client->getNickname(), name));
        return;
    }
    channel = _server->getChannel(name);
    if (!channel)
        channel = _server->createChannel(name, pass, client);

    if (channel->maxClients() > 0 && channel->numofClients() >= channel->maxClients())
    {
        client->reply(ERR_CHANNELISFULL(client->getNickname(), name));
        return;
    }

    if (channel->getPass() != pass)
    {
        client->reply(ERR_BADCHANNELKEY(client->getNickname(), name));
        return;
    }

    client->join(channel);
}