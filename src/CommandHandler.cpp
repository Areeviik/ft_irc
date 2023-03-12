#include "../inc/CommandHandler.hpp"

CommandHandler::CommandHandler(Server *server) : _server(server)
{
    _cmds["PRIVMSG"] = new PrivMsgCommand(_server);
    _cmds["JOIN"] = new JoinCommand(_server);
    _cmds["QUIT"] = new QuitCommand(_server, false);
    _cmds["NICK"] = new NickCommand(_server, false);
    _cmds["MODE"] = new ModeCommand(_server);
    _cmds["USER"] = new UserCommand(_server, false);
    _cmds["PASS"] = new PassCommand(_server, false);
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

std::string CommandHandler::trim(const std::string &str)
{
    std::string WHITESPACE = " \n\r\t\f\v";
    std::string res = "";

    size_t start = str.find_first_not_of(WHITESPACE);
    if (start != std::string::npos)
        res = str.substr(start);

    size_t end = res.find_last_not_of(WHITESPACE);
    if (end != std::string::npos)
        res = res.substr(0, end + 1);

    return res;
}

void CommandHandler::parser(Client *client, const std::string& msg)
{
    std::stringstream ssMsg(msg);
	std::string syntax;

    while(std::getline(ssMsg, syntax))
    {
        syntax = trim(syntax);
        std::string name = syntax.substr(0, syntax.find(' '));

        try
        {
            Command *cmd = _cmds.at(name);
            std::vector<std::string> args;
            std::string buf;
            std::stringstream ss(syntax.substr(name.length(), syntax.length()));

            while (ss >> buf)
            {
                args.push_back(buf);
            }
            if (!client->isRegistered() && cmd->authRequired())
            {
                client->reply(ERR_NOTREGISTERED(client->GetNickname()));
                return;
            }
            cmd->exec(client, args);
        }
        catch(const std::exception& e)
        {
            client->reply(ERR_UNKNOWNCOMMAND(client->GetNickname(), name));
        }
        
    }
}