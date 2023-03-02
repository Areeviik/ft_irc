#include "../inc/Commands.hpp"

NoticeCommand::NoticeCommand(Server *server) : Command(server){};

NoticeCommand::~NoticeCommand(){};

void NoticeCommand::exec(Client *client, std::vector<std::string> args)
{
    std::string msg;
    std::string point = args.at(0);
    if (args[0].empty() || args[1].empty() || args.size() != 2)
        return;

    for (std::vector<std::string>::iterator it = args.begin() + 1; it != args.end(); it++)
        msg.append(*it + " ");

    if (msg.at(0) == ':')
        msg.substr(1);

    if (point.at(0) == '#')
    {
        Channel *channel = client->getChannel();
        if (!channel)
            return;

        if (channel->isNoExt())
        {
            std::vector<std::string> nicknames(channel->getNicknames());
            std::vector<std::string>::iterator it;

            for (it = nicknames.begin(); it != nicknames.end(); it++)
                if (*it == client->getNickname())
                    break;
            if (it == nicknames.end())
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
        return;

    dest->write(RPL_PRIVMSG(client->getPrefix(), point, msg))
}