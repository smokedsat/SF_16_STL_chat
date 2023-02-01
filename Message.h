#pragma once
#include <vector>

using namespace std;

struct Message
{
	vector <string> _allMessages;
	vector <string> _privateMessages;

	void sendMessageToAll()
	{
		string message;
		cout << endl << "Введите сообщение для всех: " << endl;
		cin >> message;
		_allMessages.push_back(message);
	}

	void sendPrivateMessage()
	{
		string toUser, message;
		cout << "Введите логин, кому бы вы хотели отправить сообщение: " << endl;
		cin >> toUser;
		cout << "Напишите сообщение: " << endl;
		cin >> message;
		_privateMessages.push_back(message + " to " + toUser + "\n");
	}



	void showAllMessages()
	{
		int a = 0;
		for (auto i = _allMessages.begin(); i < _allMessages.end(); i++)
		{
			cout << _allMessages.at(a) << endl;
			a++;
		}
	}

	void showPrivateMessages()
	{
		int a = 0;
		for (auto i = _privateMessages.begin(); i < _privateMessages.end(); i++)
		{
			cout << _privateMessages.at(a) << endl;
			a++;
		}
	}
};