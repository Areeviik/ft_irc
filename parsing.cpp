#include "headers.hpp"

map<string, string>		parser( int n_params, char *params[] ) {

	map<string, string> res;

	if ( n_params != 3) {
		throw eExc("Usage: ./ircserv <port> <password> ");
	}
	res["PORT"] = params[1];
	res["SRV_PWD"] = params[2];

	return res;
}