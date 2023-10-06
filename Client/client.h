#pragma once
#include <cassert>
#include <iostream>
#include <thread>
#include <string>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>

#pragma comment(lib, "ws2_32.lib")

#define SIZE 1024

class ClientBackEnd
{
private:
	WSADATA wsa;
	SOCKET clientSocket;
	std::string ipAddress; //IP адрес
	int port;			   //Порт
	char buffer[SIZE];
	struct sockaddr_in info;
	int infoLength;
	int receiveLength;

	void Init();
public:
	ClientBackEnd();
	~ClientBackEnd();

	static std::string& ConvertSysStringToStdString(System::String^ sysS, std::string& stdS); //Конвертируем системную строку в стандартную С++

	void Connect();
	void Send(std::string& data);
	void Receive();
	//void Process();

	void SetServerIPAdress(std::string& ipAdress);
	void SetServerPort(std::string& port);
};
