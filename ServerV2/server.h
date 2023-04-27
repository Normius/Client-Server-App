#pragma once
#include <cassert>
#include <iostream>
#include <thread>
#include <string>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define SIZE 1024

class Server
{
private:
	WSADATA wsa;
	SOCKET serverSocket;
	std::string ipAddress;
	int port;
	char buffer[SIZE];
	std::string message;
	struct sockaddr_in info;
	int infoLength;
	int receiveLength;

	void Init();
	void Receive();
	void Process();
	void Send();
public:
	Server(int, std::string);
	~Server();

	void Start();
	//void Stop();
};
