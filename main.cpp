#include "headers.hpp"

int main( int argc, char *argv[] ) {
    map<string, string> p;

    try {
        p = parser(argc, argv);
        Server irc(p["PORT"], p["SRV_PWD"]);
        irc.initConn();
        irc.run();	
    }
    catch (const exception& e) {
		cerr << e.what() << endl;
		return errno;
	}

	return 0;
}
