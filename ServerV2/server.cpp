#include "server.h"

Server::Server(int port, std::string ipAddress)
	:port(port), ipAddress(ipAddress), serverSocket(INVALID_SOCKET), info{ 0 }, infoLength(sizeof(info)), 
	 serverDataStoragePath("..\\ClientData\\")
{
}

void Server::Init()
{
	info.sin_family = AF_INET;
	info.sin_port = htons(port);
	info.sin_addr.s_addr = inet_addr(ipAddress.c_str());

	int result = 0;

	result = WSAStartup(MAKEWORD(2, 2), &wsa);
	std::cout << "WSA init...\n";
	assert(!result && "Couldn't init wsa");
	std::cout << "WSA success!\n";

	serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
	std::cout << "Creating socket...\n";
	assert(!(serverSocket == SOCKET_ERROR) && "Couldn't create socket");
	std::cout << "Success!\n";

	result = bind(serverSocket, (struct sockaddr*)&info, infoLength);
	std::cout << "Bind socket...\n";
	assert(!result && "Couldn't bind socket");
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
	}
}

void Server::Receive()
{
	receiveLength = recvfrom(serverSocket, buffer, SIZE, 0, (struct sockaddr*)&info, &infoLength);
	if (receiveLength == SOCKET_ERROR)
	{
		std::cout << "Receive() falied...\n";
		std::cout << "Server closed!\n";
		exit(EXIT_FAILURE);
	}
}

void Server::Process()
{
	std::cout << "Packet from:" << inet_ntoa(info.sin_addr) << ":" << ntohs(info.sin_port) << '\n';

	if (buffer[receiveLength - 1] == 'm') //message
	{
		buffer[receiveLength - 1] = '\0';
		message = buffer;
		std::cout << message << ": " << inet_ntoa(info.sin_addr) << ":" << ntohs(info.sin_port) << '\n';
	}

	if (buffer[receiveLength - 1] == 'p') //path
	{
		buffer[receiveLength - 1] = '\0';

		clientPath = serverDataStoragePath + buffer;
		writeInFile.open(clientPath, std::ofstream::app);
	}

	if (buffer[receiveLength - 1] == 'd') //data
	{
		buffer[receiveLength - 1] = '\0';
		clientData = buffer;

		if (!(writeInFile.is_open()))
		{
			std::cout << "Ошибка открытия файла\n";
		}
		else
		{
			writeInFile << clientData << "\n";
			std::cout << "Данные получены и записаны в файл!";
			writeInFile.close();
			std::cout << '\n';
		}
	}
}

Server::~Server()
{
	WSACleanup();
	closesocket(serverSocket);
}
