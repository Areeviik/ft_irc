#include "headers.hpp"

Server::Server( void ) {}

Server::Server(string port, string pwd) :
		_status(1),
		_port(port), 
		_pwd(pwd),
		_host(DEFAULT_HOST),
		_servinfo(NULL)
{
	_commandHandler = new CommandHandler(this);
}

Server::~Server()
{
	delete _commandHandler;

	for (size_t i = 0; i < _channels.size(); i++)
       delete _channels[i];
}

string const 				&Server::getPort() const {
	return _port;
}

string const 				&Server::getPassword() const {
	return _pwd;
}

string const 				&Server::getHost() const {
	return _host;
}

Client *Server::getClient(const string& nickname) {
    for (map<int, Client*>::iterator it = _clients.begin();
                                it != _clients.end(); it++)
    {
        if (!nickname.compare(it->second->getNickname()))
            return it->second;
    }
    return nullptr;
}

Channel *Server::getChannel(const string& name) {
    for (vector<Channel*>::iterator it = _channels.begin();
                                it != _channels.end(); it++)
    {
        if (it.operator*()->getName() == name)
            return it.operator*();
    }
    return nullptr;
}

Channel *Server::createChannel(const string& channelName, const string& password, Client *client) {
    Channel *channel = new Channel(channelName, password, client);
    _channels.push_back(channel);
    return channel;
}

ostream & operator<<(ostream & stream, Server &Server) {
	stream << "port: " << Server.getPort() << endl;
	stream << "pwd: " << Server.getPassword() << endl;
	stream << "host: " << Server.getHost() << endl;
	return stream;
}

int   Server::setSocket(struct addrinfo * p) {
    int sk = 1;
	cout << "Creating socket...";
	_sockfd = socket(p->ai_family,
						p->ai_socktype,
						p->ai_protocol);  //socket_descriptor
	if (_sockfd == -1) {
		cout << "CHOK" << endl;
		return 1;
	}
	if (setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR, &sk, sizeof(int)) == -1) {
		cout << "CHOK" << endl;
		throw eExc(strerror(errno));
	} //server can start liestening for messages righ away after it restarted
	if (fcntl(_sockfd, F_SETFL, O_NONBLOCK) == -1) {
		cout << "CHOK" << endl;
		throw eExc(strerror(errno));
	} // make the connection "non-blocking"
	cout << "OK" << endl;
	return 0;
}

int	Server::bindPort( struct addrinfo * p ) {
	cout << "Binding port " << _port << "...";
	if (bind(_sockfd, p->ai_addr, p->ai_addrlen) == -1) {
		cout << "CHOK" << endl;
		close(_sockfd);
		return 1;
	}
	cout << "OK" << endl;
	return 0;
}

 void				Server::listenHost() {
	cout << "listenning...";
	if (listen(_sockfd, BACKLOG) == -1) {
		cout << "CHOK" << endl;
		throw eExc(strerror(errno));
	}
	cout << "OK" << endl;
}

void	Server::setServinfo() {
	cout << "Server informations...";
	memset(&_hints, 0, sizeof _hints);
	_hints.ai_family = AF_INET;    // for internet protocol version6
	_hints.ai_socktype = SOCK_STREAM; // TCP transport
	_hints.ai_flags = AI_PASSIVE; // help to randomly choose available port number
	if ((_status = getaddrinfo(_host.c_str(), _port.c_str(), &_hints, &_servinfo)) != 0) {
		cout << "CHOK" << endl;
		errno = _status;
		throw eExc("getaddrinfo: nodename nor servname provided, or not known");
	}
	cout << "OK" << endl;
}

void	Server::initConn() {

	struct addrinfo * p;
    this->setServinfo();
	for ( p = _servinfo; p != NULL; p = p->ai_next ) {
		if (this->setSocket(p))
			continue ;
		if (this->bindPort(p))
			continue ;
		break ;
	}
	freeaddrinfo(_servinfo);
	if ( !p )
		throw eExc("server: failed to bind");
	this->listenHost();
	cout << "Server init success" << endl;
	cout << "Listening for clients ..." << endl;
}

void	Server::run() {
	pollfd server_fd = {_sockfd, POLLIN, 0}; 
	_pollfds.push_back(server_fd); //listening sockfdy queue

	while (_status) 
    {
		if (poll(_pollfds.begin().base(), _pollfds.size(), -1) < 0)
			throw eExc("Error while polling from fd.");
        for (vector<pollfd>::iterator it = _pollfds.begin(); it != _pollfds.end(); it++)
        {
			if (it->revents == 0)
				continue;
			if ((it->revents & POLLHUP) == POLLHUP)
            {
				onClientDisconnect(it->fd);
				break;
			}
			if ((it->revents & POLLIN) == POLLIN)
            {
				if (it->fd == _sockfd) {
					onClientConnect();
					break;
				}
				onClientMessage(it->fd);
			}
		}
	}
}


void Server::onClientDisconnect(int fd)
{
    try
    {
        Client *client = _clients.at(fd);
        client->leave();
        char message[1000];
        sprintf(message, "%s:%d has disconnected.", client->getHostname().c_str(), client->getPort());
        ft_log(message);

        _clients.erase(fd);
        for (vector<pollfd>::iterator it = _pollfds.begin(); it != _pollfds.end(); it++)
        {
            if (it->fd == fd)
            {
                _pollfds.erase(it);
                close(fd);
                break;
            }
        }
        delete client;
    }
    catch(const out_of_range& e) {}
}

void Server::onClientConnect()
{
    int fd;
    sockaddr_in s_address = {};
    socklen_t s_size = sizeof(s_address);
    fd = accept(_sockfd, (sockaddr *) &s_address, &s_size);
    if (fd < 0)
        throw eExc(strerror(errno));

    pollfd pollfd = {fd, POLLIN, 0};
    _pollfds.push_back(pollfd);

    char hostname[NI_MAXHOST];
    if (getnameinfo((struct sockaddr *)&s_address, s_size, hostname, NI_MAXHOST, NULL, 0, NI_NUMERICSERV) != 0)
		throw eExc("Error while getting hostname on a new client.");
    
    Client *client = new Client(fd, hostname, ntohs(s_address.sin_port));
    _clients.insert(make_pair(fd, client));

    char message[1000];
    sprintf(message, "%s:%d has connected.", client->getHostname().c_str(), client->getPort());
    ft_log(message);
}

void Server::onClientMessage(int fd)
{
    try
    {
        Client *client = _clients.at(fd);
        _commandHandler->invoke(client, readMessage(fd));
    }
    catch(const out_of_range& e)
    {
        cerr << e.what() << '\n';
    }
    
}

string Server::readMessage(int fd) {
    string message;
    char buffer[100] = {0};
    
    while (message.find("\r\n") == string::npos) {
        memset(buffer, 0, 100);
        if (recv(fd, buffer, 100, 0) < 0) {
            if (errno != EWOULDBLOCK)
				throw eExc("Error while reading buffer from client.");
        }
        message.append(buffer);
    }
    return message;
}