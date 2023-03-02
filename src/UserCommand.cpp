#include "../inc/Commands.hpp"

UserCommand::UserCommand(Server *server, bool auth) : Command(server, auth) {}

UserCommand::~UserCommand() {}

void UserCommand::exec(Client *client, std::vector<std::string> args)
{
    if (client->isRegistered())
    {
        client->reply(ERR_ALREADYREGISTERED(client->getNickname()));
        return;
    }

    if (args.size() != 4)
    {
        client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "USER"));
        return;
    }
    client->setUsername(args[0]);
    client->setRealName(args[3]);
    client->welcome();
}