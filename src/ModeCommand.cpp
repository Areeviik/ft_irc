#include "../inc/Commands.hpp"

ModeCommand::ModeCommand(Server *server) : Command(server) {}
ModeCommand::~ModeCommand() {}

void ModeCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.size() < 2)
    {
        client->reply(ERR_NEEDMOREPARAMS(client->GetNickname(), "MODE"));
        return;
    }

    std::string point = args.at(0);

    if (point.at(0) == '#')
    {
        Channel *channel = client->getChannel();
        if (!channel)
        {
            client->reply(ERR_NOSUCHCHANNEL(client->GetNickname(), point));
            return;
        }

        if (channel->getAdmin() != client)
        {
            client->reply(ERR_CHANOPRIVSNEEDED(client->GetNickname(), point));
            return;
        }

        int i = 0;
        int p = 2;
        char c;
        while (c == args[1][i])
        {
            char prev = (i == 0 ? '\0' : args[1][i - 1]);
            bool active = prev == '+';

            switch (c)
            {
            case 'n':
                channel->SetNoExt(active);
                channel->BroadcastMessage(RPL_MODE(client->GetPrefix(), channel->GetName(), (active ? "+n" : "-n"), ""));
                break;
            case 'k':
                channel->SetPassword(active ? args[p] : "");
                channel->BroadcastMessage(RPL_MODE(client->GetPrefix(), channel->GetName(), (active ? "+k" : "-k"), (active ? args[p] : "")));
                p += active;
                break;
            case 'l':
                channel->SetMaxClients(active ? std::stoi(args[p]) : 0);
                channel->BroadcastMessage(RPL_MODE(client->GetPrefix(), channel->GetName(), (active ? "+l" : "-l"), (active ? args[p] : "")));
                p += active;
                break;
            default:
                break;
            }
            i++;
        }
    }
}

// don't understand the broadcast and brodcast funs dif

// getchannel from clinet and channels getadmin missing