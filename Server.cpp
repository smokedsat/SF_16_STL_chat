#include "Server.h"

void Server::Register(string login, string password, string username)
{
	base[_currentUser].setLogin(login);
	base[_currentUser].setPassword(password);
	base[_currentUser].setUsername(username);
	_currentUser++;
}

void Server::Register()
{
	cout << "����������, ������� ��� �����: " << endl;
	string login, password, username;
	cin >> login;
	base[_currentUser].setLogin(login);
	cout << "����������, ������� ��� ������: " << endl;
	cin >> password;
	base[_currentUser].setPassword(password);
	cout << "����������, ������� ��� �������: " << endl;  
	cin >> username;
	base[_currentUser].setUsername(username);
	cout << "�� ������� ���������������� ���: " << endl
		<< username << endl;;
	_currentUser++;
}

void Server::login()
{
	string login, password;
	bool checker = false;
	while (checker != true)
	{
		cout << endl << "������� ��� �����:	" << endl;
		cin >> login;

		for (auto i = 0; i < usersCount; i++)
		{
			if (login == base[i].getLogin())
			{
				cout << "������� ��� ������: " << endl;
				cin >> password;
				if (password == base[i].getPassword())
				{
					cout << "������, " << base[i].getUsername();
					_currentUser = i;
					base[_currentUser].showMenu();
					checker = true;
					break;
				}
			}
			if((i = usersCount) && (login != base[i].getLogin()))
			{
				cout << endl << "������������ �� ������, ��������� �������. " << endl;
				break;
			}
		}
	}
}



void startServer()
{
	online = true;

	cout << "����� ���������� � ���������� ���. �� ������ ��������� ��������� ��������: " << endl
		<< "1. ������������������ " << endl
		<< "2. ����� � ������� " << endl
		<< "0. ������� ���������� " << endl;

	Server a;

	char choice = '5';

	while (choice != 0)
	{
		cin >> choice;
		switch (choice)
		{
		case '1':
			a.Register();

			break;
		case '2':
			a.login();

			break;
		case '0':
			return;
			break;

		default:
			cout << "�������� 1, 2 ��� 0" << endl;

			break;
		}
	}

}

void stopServer()
{
	online = false;
}