#include "../inc/Commands.hpp"

LeaveCommand::LeaveCommand(Server *server) : Command(server) {}
LeaveCommand::~LeaveCommand() {}

void LeaveCommand::exec(Client *client, std::vector<std::string> args)
{
    std::string reason;
    if (args.empty())
        reason = "Leavind:(";
    else
        reason = args.at(0);
    if (reason.at(0) == ':')
        reason = reason.substr(1);
    client->print(RPL_LEAVE(client->smth(), reason));
}