#include "../inc/Commands.hpp"

PrivMsgCommand::PrivMsgCommand(Server *server) : Command(server){};

PrivMsgCommand::~PrivMsgCommand(){};

void PrivMsgCommand::exec(Client *client, std::vector<std::string> args)
{
    std::string msg;
    std::string point = args.at(0);
    if (args[0].empty() || args[1].empty() || args.size() != 2)
    {
        client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "MESSAGE"));
        return;
    }

    for (std::vector<std::string>::iterator it = args.begin() + 1; it != args.end(); it++)
        msg.append(*it + " ");

    if (msg.at(0) == ':')
        msg.substr(1);

    if (point.at(0) == '#')
    {
        Channel *channel = client->getChannel();
        if (!channel)
        {
            client->reply(ERR_NOSUCHCHANNEL(channel->getNickname(), point));
            return;
        }

        if (channel->isNoExt())
        {
            std::vector<std::string> usernames(channel->getNicknames());
            std::vector<std::string>::iterator it;

            for (it = usernames.begin(); it != usernames.end(); it++)
                if (*it == client->getNickname())
                    break;
            if (it == usernames.end())
            {
                client->reply(ERR_CANNOTSENDTOCHAN(client->getNickname(), point));
                return;
            }
        }
        channel->broadcast(RPL_PRIVMSG(client->getPrefix(), point, msg), client);
        return;
    }

    Client *dest = _server->getClient(point);
    if (!dest)
    {
        client->reply(ERR_NOSUCHNICK(client->getNickname(), point));
        return;
    }

    dest->write(RPL_PRIVMSG(client->getPrefix(), point, msg))
}