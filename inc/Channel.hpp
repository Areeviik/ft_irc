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
    void Kick(Client* admin, Client *client, std::string s_reason);
    void BroadcastMessage(const std::string& message);
    void BrodcastMessage(const std::string& message, Client *client);

    //getters
    std::string GetName() const;
    std::string GetTopic() const;
    std::string GetPassword() const;
    int         GetNumberOfClients() const;
    int         GetMaxClients() const;


    //setters 
    void SetName(const std::string &name);
    void SetTopic(const std::string &topic);
    void SetPassword(const std::string &password);
    void SetMaxClients(int max_clients);
    void SetNoExt(bool state);
    std::vector<std::string> GetNicknames();



    //members
    private:
    std::string m_name;
    std::string m_topic;
    std::string m_password;
    int         m_max_clients;
    Client*     m_admin;
    bool        m_noExt;
    std::vector <Client*> m_clients;

};

#endif