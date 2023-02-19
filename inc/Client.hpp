#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>
#include <vector>

class Channel;

//server need to have some clinet data thats why we need this class
class Client
{
    public:
    //constructors & Destructors
        Client();
        ~Client();

    //setters
        void SetNickname(const std::string &nickname);
        void SetUsername(const std::string &username);
        void SetRealname(const std::string &realname);

    //getters

        std::string GetNickname() const;
        std::string GetUsername() const;
        std::string GetRealname() const;
    
    //ClientWithChanel connection
    /* it should be implemented with chanell class
    void JoinChanel(Chanel* channel);
    void LeaveChannel(Chanel* channel);
    void SendMessage(string message);
    void reciveMessage(string message);
    */
    
    private: // or can be pribate
        std::string m_nickname;
        std::string m_username;
        std::string m_realname;
        std::string m_hostname;
        int         m_socket; // still don't know why ?
        std::vector <Client*> m_clients;

};

#endif
