#include "../inc/Channel.hpp"
#include "../inc/Client.hpp"

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
    //add client
}

void Channel::RemoveClient(Client* client)
{
    //remove client
}

void Channel::BroadcastMessage()
{
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
