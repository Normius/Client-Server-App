#include "server.h"

//Функция для работы с консолью сервера параллельно с получением данных от клиента (в отдельном потоке)
//Необходима для заверешения сервера при написании exit в консоль
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

	Server server(8888, "127.0.0.1"); //Задаём порт и ip адрес сервера. Этот же порт и адрес затем проверяется в коде клиента
	Server* ptrserver = &server;
	std::thread anotherThread(Exit, ptrserver);
	
	server.Start();
	anotherThread.join();

	return 0;
}