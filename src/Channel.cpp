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

void Channel::BroadcastMessage()
{
    //not sure how this should be work
    //brodcast message that will be shown all users.
}

std::string Channel::GetName() const
{
    return m_name;
}

std::string Channel::GetTopic() const
{
    return m_topic;
}

void Channel::SetName(const std::string &name)
{
    m_name = name;
}

void Channel::SetTopic(const std::string &topic)
{
    m_topic = topic;
}
