#ifndef ERRORS_HPP
#define ERRORS_HPP

#include <iostream>
#include <string>

#define ERR_NEEDMOREPARAMS(src, cmd) "461 " + src + " " + cmd + " ~Please pass all the required arguments."
#define ERR_TOOMANYCHANNELS(src, channel) "405 " + src + " " + channel + " ~You've already joined too many channels."
#define ERR_CHANNELISFULL(src, channel) "471 " + src + " " + channel + " ~Channel is full, can't join."
#define ERR_BADCHANNELKEY(src, channel) "475 " + src + " " + channel + " ~Bad channel key, can't join."
#define RPL_LEAVE(src, msg) ":" + src + " LEAVE :Leave: " + msg
#define ERR_NOSUCHCHANNEL(src, channel) "403 " + src + " " + channel + " ~Channel doesn't exist"
#define ERR_CANNOTSENDTOCHANNEL(src, channel) "404 " + src + " " + channel + " ~Can't send to channel"
#define RPL_MESSAGE(src, point, msg) ":" + src + " MESSAGE " + point + " :" + msg
#define ERR_NOSUCHUSERNAME(src, username) "401 " + src + " " + username + " ~The username doesn't exist"

#endif