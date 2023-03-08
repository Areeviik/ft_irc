#include "../inc/CommandHandler.hpp"

CommandHandler::CommandHandler(Server *server) : _server(server)
{
    _cmds["PRIVMSG"] = new PrivMsgCommand(_server);
    _cmds["JOIN"] = new JoinCommand(_server);
    _cmds["QUIT"] = new QuitCommand(_server);
    _cmds["NICK"] = new NickCommand(_server);
    _cmds["MODE"] = new ModeCommand(_server);
    _cmds["USER"] = new UserCommand(_server);
    _cmds["PASS"] = new PassCommand(_server);
    _cmds["PING"] = new PingCommand(_server);
    _cmds["PONG"] = new PongCommand(_server);
    _cmds["KICK"] = new KickCommand(_server);
    _cmds["PART"] = new PartCommand(_server);
    _cmds["NOTICE"] = new NoticeCommand(_server);
}

CommandHandler::~CommandHandler()
{
    for (std::map<std::string, Command *>::iterator it = _cmds.begin(); it != _cmds.end(); it++)
        delete it->second;
}

std::string CommandHandler::trim(const std::string& str)
{
    
}

CommandHandler::parser(Client *client, const std::string &msg)
{
    std::stringstream ssMsg(msg);
    std::string syntax;

    while(std::getline(ssMsg, syntax))
    {
        syntax = trim (syntax);
        std::string name = syntax.substr(0, syntax.find(' '));

        try{
            Command *cmd = _cmds.at(name);
            std::stringstream ss(syntax.substr(name.length(), syntax.length()));
            std::vector<std::string> args;
            std::string buf;

            while (ss >> buf)
                args.push_back(buf);
            if (!client->isRegistered() && cmd->authRequired())
            {
                client->reply(ERR_NOTREGISTERED(client->getNickname()));
                return ;
            }
            cmd->exec(client, args);
        }
        catch(const std::exception& e)
            client->reply(ERR_UNKNOWNCOMMAND(client->getNickname(), name));


        }
    }
}