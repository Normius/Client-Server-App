#include "MainWindow.h"
#include "client.h"

using namespace System;
using namespace System::Windows::Forms;

ClientBackEnd client;
///////////////////// ���������� ��� ��������� System:String^ � std::string ////////////////////////

std::string port = "";
std::string ipAdress = "";
std::string path = "";
std::string data = "";

System::Void Client::MainWindow::aboutProgrammToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	MessageBox::Show("��������� ��� ����������� � ������� � �������� ������ �� ������.", "� ���������");
	return System::Void();
}

System::Void Client::MainWindow::buttonConnect_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBoxIP->Text == serverIP && textBoxPort->Text == serverPort)
	{
		
		ClientBackEnd::ConvertSysStringToStdString(serverIP, ipAdress);
		ClientBackEnd::ConvertSysStringToStdString(serverPort, port);
	
		client.SetServerIPAdress(ipAdress);
		client.SetServerPort(port);
		MessageBox::Show("����������� �������!", "����������� � �������");
		client.Connect();

		std::string clientMessage = "Client connected";
		client.Send(clientMessage + "m"); //add "m" to send string with message so server will know it is message
	}
	else if (textBoxIP->Text != "" && textBoxPort->Text != "")
	{
		MessageBox::Show("IP ����� ��� ���� ��� ����������� � ������� ������� �������.", "����������� � �������");
	}

	if (textBoxIP->Text == "")
	{
		MessageBox::Show("������� IP ����� �������!", "����������� � �������");
	}

	else if (textBoxPort->Text == "")
	{
		MessageBox::Show("������� ���� ��� ����������� � �������!", "����������� � �������");
	}
	
	return System::Void();
}

System::Void Client::MainWindow::buttonSend_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (textBoxPath->Text == "")
	{
		MessageBox::Show("������� ���� � ����� � ��� �����!", "�������� ������");
	}

	else if (textBoxData->Text == "")
	{
		MessageBox::Show("������� ������!", "�������� ������");
	}
	else
	{
		ClientBackEnd::ConvertSysStringToStdString(textBoxPath->Text, path);
		ClientBackEnd::ConvertSysStringToStdString(textBoxData->Text, data);

		client.Send(path + "p"); //add "p" to send string with path so server will know it is path
		client.Send(data + "d"); //add "d" to send string with data so server will know it is data
		MessageBox::Show("������ ������� ����������!", "�������� ������");
	}
	return System::Void();
}
