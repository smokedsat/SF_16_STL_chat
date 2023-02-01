#pragma once
#include <string>
#include <iostream>
#include "Message.h"

static int usersCount = 0;
using namespace std;

class User: public Message
{
protected: 
	string _login;
	string _password;
	string _username; 
	int _userID;
	string messages[10];

public:
	User()
	{
		_login = "defaultLogin";
		_password = "defaultPassword";
		_username = "defaultUsername";
		_userID = usersCount;
		usersCount++;
	}	

	void showMenu()
	{
		bool userMenuAlive = true;
		while (userMenuAlive)
		{
			char userMenuChoice = '5';
			while (userMenuChoice != '0')
			{
				cout << "Пожалуйста, выберите действия: " << endl
					<< "1. Показать общий чат." << endl
					<< "2. Показать личный чат. " << endl
					<< "3. Написать в общий чат. " << endl
					<< "4. Написать лично. " << endl
					<< "0. Возврат в предыдущее меню. Так же можно ввести любое значение. " << endl;
				cin >> userMenuChoice;
				switch (userMenuChoice)
				{
				case '1':
					showAllMessages();

					break;
				case '2':
					showPrivateMessages();

					break;

				case '3':
					sendMessageToAll();


					break;

				case '4' :
					sendPrivateMessage();


					break;
				case '0':
					userMenuChoice = '0';
					break;

				default:
					break;
				}
			}
		}
	}




	const string& getUsername() const { return _username; }
	const string& getPassword() const { return _password; }
	const string& getLogin() const { return _login; }
	const int& getID() const { return _userID; }


	void setUsername(const string &username) { _username = username; }
	void setLogin(const string &login) { _login = login; }
	void setPassword(const string &password) { _password = password; }

};