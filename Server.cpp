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
	cout << "Пожалуйста, введите ваш логин: " << endl;
	string login, password, username;
	cin >> login;
	base[_currentUser].setLogin(login);
	cout << "Пожалуйста, введите ваш пароль: " << endl;
	cin >> password;
	base[_currentUser].setPassword(password);
	cout << "Пожалуйста, введите ваш никнейм: " << endl;  
	cin >> username;
	base[_currentUser].setUsername(username);
	cout << "Вы успешно зарегистрированы как: " << endl
		<< username << endl;;
	_currentUser++;
}

void Server::login()
{
	string login, password;
	bool checker = false;
	while (checker != true)
	{
		cout << endl << "Введите ваш логин:	" << endl;
		cin >> login;

		for (auto i = 0; i < usersCount; i++)
		{
			if (login == base[i].getLogin())
			{
				cout << "Введите ваш пароль: " << endl;
				cin >> password;
				if (password == base[i].getPassword())
				{
					cout << "Привет, " << base[i].getUsername();
					_currentUser = i;
					base[_currentUser].showMenu();
					checker = true;
					break;
				}
			}
			if((i = usersCount) && (login != base[i].getLogin()))
			{
				cout << endl << "Пользователь не найден, повторите попытку. " << endl;
				break;
			}
		}
	}
}



void startServer()
{
	online = true;

	cout << "Добро пожаловать в консольный чат. Вы можете выполнить следующие действия: " << endl
		<< "1. Зарегистрироваться " << endl
		<< "2. Войти в аккаунт " << endl
		<< "0. Закрыть приложение " << endl;

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
			cout << "Выберите 1, 2 или 0" << endl;

			break;
		}
	}

}

void stopServer()
{
	online = false;
}