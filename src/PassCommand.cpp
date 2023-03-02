#include "../inc/Commands.hpp"

PassCommand::PassCommand(Server *server, bool auth) : Command(server, auth) {}
PassCommand::~PassCommand() {}

void PassCommand::exec(Client *client, std::vector<std::string> args)
{
    if (args.empty())
    {
        client->reply(ERR_NEEDMOREPARAMS(client->getNickname(), "PASS"));
        return;
    }
    if (client->isRegistered())
    {
        client->reply(ERR_ALREADYREGISTERED(client->getNickname()));
        return;
    }
    if (_server->getPassword() != args[0].substr(args[0][0] == ':' ? 1 : 0))
    {
        client->reply(ERR_PASSWDMISMATCH(client->getNickname()));
        return;
    }
    client->setState(LOGIN);
}