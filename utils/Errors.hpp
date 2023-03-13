#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <iostream>
#include <string>

#define ERR_NEEDMOREPARAMS(src, cmd) "461 " + src + " " + cmd + " ~Please pass all the required arguments."
#define ERR_TOOMANYCHANNELS(src, channel) "405 " + src + " " + channel + " ~You've already joined too many channels."
#define ERR_CHANNELISFULL(src, channel) "471 " + src + " " + channel + " ~Channel is full, can't join."
#define ERR_BADCHANNELKEY(src, channel) "475 " + src + " " + channel + " ~Bad channel key, can't join."
#define RPL_QUIT(src, msg) ":" + src + " QUIT :Quit: " + msg
#define ERR_NOSUCHCHANNEL(src, channel) "403 " + src + " " + channel + " ~Channel doesn't exist"
#define ERR_CANNOTSENDTOCHAN(src, channel) "404 " + src + " " + channel + " ~Can't send to channel"
#define RPL_PRIVMSG(src, point, msg) ":" + src + " PRIVMSG " + point + " :" + msg
#define ERR_NOSUCHNICK(src, username) "401 " + src + " " + username + " ~The nickname doesn't exist"
#define ERR_NONICKNAMEGIVEN(src) "431 " + src + " ~Please provide a nickname"
#define ERR_NICKNAMEINUSE(src) "433 " + src + " " + src  + " ~Nickname already exists"
#define ERR_ALREADYREGISTERED(src) "462 " + src + " ~User already registered!"
#define ERR_PASSWDMISMATCH(src) "464 " + src + " ~Incorrect password!"
#define RPL_PING(src, token) ":" + src + " PONG :" + token
#define ERR_NOTONCHANNEL(src, channel) "442 " + src + " " + channel + " ~You're not on that channel"
#define ERR_CHANOPRIVSNEEDED(src, channel) "482 " + src + " " + channel + " ~You're not channel admin"
#define RPL_MODE(src, channel, modes, args) ":" + src + " MODE " + channel + " " + modes + " " + args
#define ERR_NOTREGISTERED(src) "451 " + src + " ~You haven't registered yet :("
#define ERR_UNKNOWNCOMMAND(src, cmd) "421 " + src + " " + cmd + " ~Unknown command"

#endif