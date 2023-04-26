#include "server.h"

Server::Server(int port, std::string ipAddress)
	:port(port), ipAddress(ipAddress), serverSocket(INVALID_SOCKET), info{ 0 }, infoLength(sizeof(info))
{
}

void Server::Init()
{
	info.sin_family = AF_INET;
	info.sin_port = htons(port);
	info.sin_addr.s_addr = inet_addr(ipAddress.c_str());

	std::cout << "WSA init...\n";
	assert(!(WSAStartup(MAKEWORD(2, 2), &wsa)) && "Couldn't init wsa");
	std::cout << "WSA success!\n";

	std::cout << "Creating socket...\n";
	assert(!((serverSocket = socket(AF_INET, SOCK_DGRAM, 0)) == SOCKET_ERROR) && "Couldn't create socket");
	std::cout << "Success!\n";

	std::cout << "Bind socket...\n";
	assert(!(bind(serverSocket, (struct sockaddr*)&info, infoLength)) && "Couldn't bind socket");
	std::cout << "Socket binded!\n";

	std::cout << "Server started at:" << inet_ntoa(info.sin_addr) << ":" << ntohs(info.sin_port) << '\n';
}

void Server::Start()
{
	Init();

	for (;;)
	{
		Receive();
		Process();
		Send();
	}
}

void Server::Receive()
{
	if ((receiveLength = recvfrom(serverSocket, buffer, SIZE, 0, (struct sockaddr*)&info, &infoLength)) == SOCKET_ERROR)
	{
		std::cout << "Receive() falied...\n" << WSAGetLastError() << '\n';
		exit(EXIT_FAILURE);
	}
}

void Server::Process()
{
	std::cout << "Packet from:" << inet_ntoa(info.sin_addr) << ":" << ntohs(info.sin_port) << '\n';
	for (unsigned i = 0; i < receiveLength; ++i)
	{
		std::cout << buffer[i];
	}
	std::cout << '\n';
}

void Server::Send()
{
	if ((sendto(serverSocket, buffer, receiveLength, 0, (struct sockaddr*)&info, infoLength)) == SOCKET_ERROR)
	{
		std::cout << "Send() falied...\n" << WSAGetLastError() << '\n';
		exit(EXIT_FAILURE);
	}
}

Server::~Server()
{
	WSACleanup();
	closesocket(serverSocket);
}
