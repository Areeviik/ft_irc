#include "../inc/Commands.hpp"

QuitCommand::QuitCommand(Server *server, bool authRequired) : Command(server, authRequired) {}
QuitCommand::~QuitCommand() {}

void QuitCommand::exec(Client *client, std::vector<std::string> args)
{
    std::string reason;
    if (args.empty())
        reason = "Leaving:(";
    else
        reason = args.at(0);
    if (reason.at(0) == ':')
        reason = reason.substr(1);
    client->print(RPL_QUIT(client->getPrefx(), reason));
}