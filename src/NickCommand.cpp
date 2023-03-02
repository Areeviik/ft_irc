#include "../inc/Commands.hpp"

NickCommand::NickCommand(Server *server, bool authRequired) : Command(server, authRequired) {}

NickCommand::~NickCommand() {}

void NickCommand::exec(Client *client, std::vector<std::string> args)
{
    std::string nick = args[0];
    if (args.empty())
    {
        client->reply(ERR_NONICKNAMEGIVEN(client->getNickname()));
        return;
    }
    if (_server->getCLient(nick))
    {
        client->reply(ERR_NICKNAMEINUSE(client->getNickname()));
        return;
    }
    client->setNickname(nick);
    client->welcome();
}