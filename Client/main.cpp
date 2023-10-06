#include "MainWindow.h"
#include "client.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Client::MainWindow window;
	Application::Run(% window);
	ClientBackEnd client;
}
