#include "server.h"

//������� ��� ������ � �������� ������� ����������� � ���������� ������ �� ������� (� ��������� ������)
//���������� ��� ����������� ������� ��� ��������� exit � �������
void Exit(Server* server)
{
	std::string consoleCommand = "";
	while (std::cin)
	{ 
		
		std::cin >> consoleCommand;
		if (consoleCommand == "exit" || consoleCommand == "Exit" || consoleCommand == "EXIT")
		{
			server->~Server();
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Server server(8888, "127.0.0.1"); //����� ���� � ip ����� �������. ���� �� ���� � ����� ����� ����������� � ���� �������
	Server* ptrserver = &server;
	std::thread anotherThread(Exit, ptrserver);
	
	server.Start();
	anotherThread.join();

	return 0;
}