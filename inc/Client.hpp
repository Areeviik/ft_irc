#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <iostream>
#include <string>

//server need to have some clinet data thats why we need this class
class Client
{
    protected: // or can be pribate
        std::string nickname;
        std::string username;
        std::string realname;
    
    public:
    //setters
        void SetNickname(const std::string &nickname);
        void SetUsername(const std::string &username);
        void SetRealname(const std::string &realname);

    //getters

        std::string GetNickname() const;
        std::string GetUsername() const;
        std::string GetRealname() const;
    
    //constructors
        Client();
        ~Client();
};

#endif
