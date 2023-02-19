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
    m_nickname = nickname;
}

void Client::SetUsername(const std::string& username)
{
    m_username = username;    
}

void Client::SetRealname(const std::string& realname)
{
    m_realname = realname;
}

//Getters

std::string Client::GetNickname() const
{
    return m_nickname;    
}

std::string Client::GetUsername() const
{
    return m_username;
}

std::string Client::GetRealname() const
{
    return m_realname;
}




int main()
{
    
}