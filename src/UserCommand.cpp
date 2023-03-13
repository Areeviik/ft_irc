#include "../inc/Commands.hpp"

UserCommand::UserCommand(Server *server, bool auth) : Command(server, auth) {}

UserCommand::~UserCommand() {}

void UserCommand::exec(Client *client, std::vector<std::string> args)
{
    if (client->isRegistered())
    {
        client->reply(ERR_ALREADYREGISTERED(client->GetNickname()));
        return;
    }

    if (args.size() != 4)
    {
        client->reply(ERR_NEEDMOREPARAMS(client->GetNickname(), "USER"));
        return;
    }
    client->SetNickname(args[0]);
    client->SetRealname(args[3]);
    client->welcome();
}
