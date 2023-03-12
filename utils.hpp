#include <iostream>
#define RPL_PART(source, channel)					":" + source + " PART :" + channel
#define RPL_JOIN(source, channel)					":" + source + " JOIN :" + channel
#define RPL_ENDOFNAMES(source, channel)			"366 " + source + " " + channel + " :End of /NAMES list."
#define RPL_NAMREPLY(source, channel, users)	"353 " + source + " = " + channel + " :" + users
#define RPL_WELCOME(source)						"001 " + source + " :Welcome " + source + " to the ft_irc network"



static inline void ft_log(const std::string &message) {
	time_t rawtime;
	struct tm *timeinfo;
	char buffer[80];

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	std::string str(buffer);
	(void)message;
	std::cout << "[" << buffer << "] " << message << std::endl;
};