#include "../inc/Client.hpp"

Client::Client(int fd, const std::string& hostname, int port)
{
    //contructor 
    m_fd = fd;
    m_hostname = hostname;
    m_port = port;
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
void Client::SetHostname(const std::string &hostname)
{
    m_hostname = hostname;
}

void Client::SetChannel(Channel* channel)
{
    m_channel = channel;
}

void Client::SetState(ClientState state)
{
    m_state = state;
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

std::string Client::GetPrefix() const
{
    //develop after channel;
}

std::string Client::GetHostname() const
{
    return m_hostname;
}

int Client::GetFd() const
{
    return m_fd;
}

int Client::GetPort() const
{
    return m_port;    
}

//Functions related to Chanel
void Client::JoinChanel(Channel* channel)
{
    //impl later   
}

void Client::LeaveChannel(Channel* channel)
{
    //impl later    
}

void Client::SendMessage(std::string message)
{
    //impl later
}

void Client::ReciveMessage(std::string message)
{
    //impl later
}


int main()
{
    std::cout << "Hi its me Im the problem its me" << std::endl;
    
}