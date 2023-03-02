#include "../inc/Commands.hpp"

MessageCommand::MessageCommand(Server *server) : Command(server){};

MessageCommand::~MessageCommand(){};

void MessageCommand::exec(Client *client, std::vector<std::string> args)
{
    std::string msg;
    std::string point = args.at(0);
    if (args[0].empty() || args[1].empty() || args.size != 2)
    {
        client->reply(ERR_NEEDMOREPARAMS(client->smthName(), "MESSAGE"));
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
            client->reply(ERR_NOSUCHCHANNEL(channel->name(), point));
            return;
        }

        if (channel->smthNOTEXIST())
        {
            std::vector<std::string> usernames(channel->getUsername());
            std::vector<std::string>::iterator it;

            for (it = usernames.begin(); it != usernames.end(); it++)
                if (*it == client->getUsername())
                    break;
            if (it == usernames.end())
            {
                client->reply(ERR_CANNOTSENDTOCHANNEL(client->getUsername(), point));
                return;
            }
        }
        channel->broadcast(RPL_MESSAGE(client->getPrefix(), point, msg), client);
        return;
    }

    Client *dest = _server->getClient(point);
    if (!dest)
    {
        client->reply(ERR_NOSUCHUSERNAME(client->getUsername(), point));
        return;
    }

    dest->write(RPL_MESSAGE(client->getPrefix(), point, msg))
}