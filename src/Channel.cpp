#include "../inc/Channel.hpp"
#include "../inc/Client.hpp"
#include <algorithm>

Channel::Channel()
{
    //default constructor 

}

Channel::~Channel()
{
    //default destructor
}
 

//getters
std::string Channel::GetName() const
{
    return m_name;
}

std::string Channel::GetTopic() const
{
    return m_topic;
}

std::string Channel::GetPassword() const
{
    return m_password;    
}

int Channel::GetNumberOfClients() const
{ 
    // get_number
}

int Channel::GetMaxClients() const
{
    return m_max_clients;
}

//setters
void Channel::SetName(const std::string &name)
{
    m_name = name;
}

void Channel::SetTopic(const std::string &topic)
{
    m_topic = topic;
}

void Channel::SetPassword(const std::string &key)
{
    m_password = key;
}

void Channel::SetMaxClients(const int max_clients)
{
    m_max_clients = max_clients;
}

// working with clinets
void Channel::AddClient(Client* client)
{
        //Adding client
        m_clients.push_back(client);
}

void Channel::RemoveClient(Client* client)
{
    //remove client
    std::vector<Client*>::iterator it = std::find(m_clients.begin(), m_clients.end(), client);
    if(it != m_clients.end())
    {
        m_clients.erase(it);
        std::string s_message = "PRIVMSG" + client->GetRealname() + ":" + client->GetNickname() + " has left the chanel";
        //SendMessageToClient(message);
    } 
}

void Channel::BroadcastMessage(const std::string& message)
{
    //not sure how this should be work
    //brodcast message that will be shown all users.
}

void Channel::BrodcastMessage(const std::string& message, Client *client )
{
    //brodcast message that will be shown for all users.
}

void Channel::Kick(Client* admin, Client *client, std::string s_reason)
{
    //kick from channel
}