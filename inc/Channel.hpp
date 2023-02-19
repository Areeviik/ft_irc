#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>
#include <vector>
class Client;

class Channel
{
    public:
    //constructor&destructor
    Channel();
    ~Channel();

    //working with clinet
    void AddClient(Client* client);
    void RemoveClient(Client* clinet);
    void BroadcastMessage();

    //getters
    std::string GetName() const;
    std::string GetTopic() const;
    //setters 
    void SetName(const std::string &name);
    void SetTopic(const std::string &topic);

    //members
    private:
    std::string m_name;
    std::string m_topic;
    std::vector <Client*> clients;

};

#endif