#include "server.h"

int main()
{
	Server server(8888, "127.0.0.1");
	server.Start();
	return 0;
}