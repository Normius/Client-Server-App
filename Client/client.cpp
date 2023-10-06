#include "client.h"

ClientBackEnd::ClientBackEnd()
	:port(0), ipAddress(), clientSocket(INVALID_SOCKET), info{ 0 }, infoLength(sizeof(info))
{
}

void ClientBackEnd::Init()
{
	info.sin_family = AF_INET;
	info.sin_port = htons(port);
	info.sin_addr.s_addr = inet_addr(ipAddress.c_str());

	int result = 0;

	result = WSAStartup(MAKEWORD(2, 2), &wsa);
	std::cout << "WSA init...\n";
	assert(!result && "Couldn't init wsa");
	std::cout << "WSA success!\n";

	clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	std::cout << "Creating socket...\n";
	assert(!(clientSocket == SOCKET_ERROR) && "Couldn't create socket");
	std::cout << "Success!\n";
}

void ClientBackEnd::Connect()
{
	Init();
}

void ClientBackEnd::SetServerIPAdress(std::string& ipAddress)
{
	this->ipAddress = ipAddress;
}
void ClientBackEnd::SetServerPort(std::string& port)
{
	int integerPort = std::stoi(port);
	this->port = integerPort;
}

void ClientBackEnd::Send(std::string& data)
{
	int result = sendto(clientSocket, data.c_str(), static_cast<int>(data.size()), 0, (struct sockaddr*)&info, infoLength);
	if (result == SOCKET_ERROR)
	{
		using namespace System::Windows::Forms;
		MessageBox::Show("Ошибка передачи данных", "Передача данных");
		exit(EXIT_FAILURE);
	}
}

void ClientBackEnd::Receive()
{
	using namespace System::Windows::Forms;
	receiveLength = recvfrom(clientSocket, buffer, SIZE, 0, (struct sockaddr*)&info, &infoLength);
	if (receiveLength == SOCKET_ERROR)
	{
		MessageBox::Show("Ошибка при получении данных сервером", "Передача данных");
		exit(EXIT_FAILURE);
	}
	else
	{
		MessageBox::Show("Данные отправлены успешно!", "Передача данных");
	}
}

//Конвертация System String в std string
std::string& ClientBackEnd::ConvertSysStringToStdString(System::String^ sysS, std::string& stdS)
{
	using namespace System::Runtime::InteropServices;
	const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(sysS)).ToPointer();
	stdS = chars;
	Marshal::FreeHGlobal(System::IntPtr((void*)chars));
	return stdS;
}

ClientBackEnd::~ClientBackEnd()
{
	WSACleanup();
	closesocket(clientSocket);
}


