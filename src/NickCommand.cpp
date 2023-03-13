#include "../inc/Commands.hpp"

NickCommand::NickCommand(Server *server, bool authRequired) : Command(server, authRequired) {}

NickCommand::~NickCommand() {}

void NickCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.empty()  || args[0].empty())
    {
        client->reply(ERR_NONICKNAMEGIVEN(client->GetNickname()));
        return;
    }
    std::string nick = args[0];
    if (_server->getCLient(nick))
    {
        client->reply(ERR_NICKNAMEINUSE(client->GetNickname()));
        return;
    }
    client->SetNickname(nick);
    client->welcome();
}