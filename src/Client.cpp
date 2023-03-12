#include "../inc/Client.hpp"
#include "../utils.hpp"

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
    channel->AddClient(this);
    m_channel = channel;

    std::string users;
    std::vector<std::string> nicknames = channel->GetNicknames();

    for (std::vector<std::string>::iterator it = nicknames.begin();
    it != nicknames.end(); it++)
    {
        users.append(*it + "");        
    }
    reply(RPL_NAMREPLY(m_nickname, channel->GetName(),users));
    reply(RPL_ENDOFNAMES(m_nickname, channel->GetName()));
    m_channel->BroadcastMessage(RPL_JOIN(GetPrefix(), channel->GetName()));
    //impl later   
}

void Client::LeaveChannel(Channel* channel)
{
    //impl of to leave channel
    if(!m_channel)
        return;
    const std::string ch_name = m_channel->GetName();
    m_channel->BroadcastMessage(RPL_PART(GetPrefix(), m_channel->GetName()));
    m_channel->RemoveClient(this);

    char msg[100];
    sprintf(msg, "%s has left channel %s",
            m_nickname.c_str(), ch_name.c_str());
    ft_log(msg);
}

void Client::write(const std::string& message) //it should be renamed to write
{
    //send message impl
    std::string buff = message + "\r\n";
    ft_log(buff);
    if(send(m_fd, buff.c_str(), buff.length(), 0) < 0)
     {
        throw std::runtime_error("Cannnot send message to the client");
     }
}

void Client::reply(const std::string& message)
{
    write(":" + GetPrefix() + " " + message);
}

void Client::ReciveMessage(std::string message)
{
    //impl later
}

void Client::welcome()
{
    if(m_state != LOGIN || m_nickname.empty() || m_realname.empty()
       || m_username.empty())
       {
        return;
       }   
    m_state = REGISTERED;
    reply(RPL_WELCOME(m_nickname));

    char msg[100];
    sprintf(msg, "%s:%d is now known as %s",
    m_hostname.c_str(), m_port, m_nickname.c_str());
}


int main()
{
    std::cout << "Hi its me Im the problem its me" << std::endl;
    
}