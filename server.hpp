#ifndef SERVER_HPP
# define SERVER_HPP

class Server;
# include "headers.hpp"
# include "./inc/Client.hpp"
# include "./inc/Channel.hpp"
# include "./inc/CommandHandler.hpp"

//server class

class Server {

	private:
		int						_status;
		int						_sockfd;
		int						_newfd;
		int						_fd_count;
		string					_port;
		string					_pwd;
		string					_host;
		struct addrinfo 		_hints;
		struct addrinfo			*_servinfo;
		struct pollfd			_poll[5 + 1];
		vector<pollfd>		_pollfds;
        map<int, Client*> _clients;
        vector<Channel *> _channels;
        CommandHandler *_commandHandler;
		vector<User*>			_users;
		vector<Channel*>		_channels;

        void					setServinfo( void );
		int						setSocket( struct addrinfo * p );
		int						bindPort( struct addrinfo * p );
		void					listenHost( void );
		int						sendData( int fd );
		int						receiveData( int i );
		void					acceptConn( void );
		bool					add_to_pfds(int newfd);

    public:
        Server(void);
		Server(string port, string pwd);
		~Server();
		string const &getPort() const;
		string const &getHost() const;
		string const &getPassword() const;
		Client *getClient(const string& nickname);
        Channel *getChannel(const string& channelName);
        Channel *createChannel(const string& channelName, const string& password,Client *client);
		string readMessage(int fd);
		void onClientDisconnect(int fd);
		void onClientConnect();
		void onClientMessage(int fd);
        void initConn(void);
		void run(void);
} ;

#endif