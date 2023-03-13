#ifndef PARSING_HPP
# define PARSING_HPP

#include "headers.hpp"

class eExc : public exception {
	
	public:

		eExc(const char * str) : _strerror(str) {};
		const char * what() const throw() { return _strerror; };

	private:

		const char * _strerror;
};

map<string, string> parser( int n_params, char *params[] );

#endif
