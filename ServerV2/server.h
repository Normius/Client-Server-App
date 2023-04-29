#pragma once
#include <cassert>
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

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

	std::string clientPath;
	std::string clientData;
	std::string serverDataStoragePath;

	std::ofstream writeInFile;

	void Init();
	void Receive(std::string &clientPacket);
	//void Respond(const char* response);
	void Process();
public:
	Server(int, std::string);
	~Server();

	void Start();
};
