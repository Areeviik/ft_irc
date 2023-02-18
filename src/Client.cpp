#include "../inc/Client.hpp"

Client::Client()
{
    //default constructor

}

Client::~Client()
{   
    //default destructor
}

//seters
void Client::SetNickname(const std::string& nickname)
{
    this->nickname = nickname;
}

void Client::SetUsername(const std::string& username)
{
    this->username = username;    
}

void Client::SetRealname(const std::string& realname)
{
    this->realname = realname;
}

//Getters

std::string Client::GetNickname() const
{
    return this->nickname;    
}

std::string Client::GetUsername() const
{
    return this->username;
}

std::string Client::GetRealname() const
{
    return this->realname;
}




int main()
{
    
}