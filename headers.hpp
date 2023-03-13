#ifndef HEADERS_HPP
# define HEADERS_HPP

# define DEFAULT_HOST       "127.0.0.1"
# define BACKLOG			5
# define MAXCLI				5
# define BUFSIZE			128
# define MAX_CHAN_PER_USR	10
# define MAX_USR_PER_CHAN	10
# define MAX_USR_NICK_LEN	20
# define MAX_CHAN_NAME_LEN	200
# define MAX_CONNECTIONS    1000

# include <iostream>
# include <vector>
# include <map>
# include <string>
# include <exception>
# include <sstream>
# include <iterator>
# include <cerrno>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <algorithm>
# include <fstream>
# include <iomanip>
# include <sys/types.h>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <signal.h>
# include <fcntl.h>
# include <poll.h>
using namespace std;
//our files
# include "server.hpp"
# include "parsing.hpp"

// #include "client.hpp"
// #include "chanel.hpp"
// #include "commandhandler.hpp"

#endif