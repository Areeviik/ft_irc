#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <sys/poll.h>
#include <sys/socket.h>
#include "Channel.hpp"

class Channel;
enum ClientState
{
    HANDSHAKE,
    LOGIN,
    REGISTERED,
    DISCONNECTED    
};

//server need to have some clinet data thats why we need this class
class Client
{
    public:
    //constructors & Destructors
//        Client();
        Client(int fd, const std::string& hostname, int port);
        ~Client();

    //setters
        void SetNickname(const std::string &nickname);
        void SetUsername(const std::string &username);
        void SetRealname(const std::string &realname);
        void SetHostname(const std::string &hostname);
        void SetChannel(Channel* chanel);
        void SetState(ClientState state);

    //getters

        std::string GetNickname() const;
        std::string GetUsername() const;
        std::string GetRealname() const;
        std::string GetHostname() const;
        std::string GetPrefix()   const;
        int         GetFd() const;
        int         GetPort() const;
        
        
    
    //ClientWithChanel connection
    // it should be implemented with chanell class
    void JoinChanel(Channel* channel);
    void LeaveChannel(Channel* channel);
    void SendMessage(std::string message);
    void ReciveMessage(std::string message);
    void reply(const std::string &message);
    void write(const std::string &message);
    
    
    
    private: // or can be pribate
        Channel*    m_channel; 
        std::string m_nickname;
        std::string m_username;
        std::string m_realname;
        std::string m_hostname;
        int         m_fd;
        int         m_socket; // still don't know why ?
        int         m_port;
        ClientState m_state;
        std::vector <Client*> m_clients;

};

#endif
