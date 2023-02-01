#pragma once
#include "User.h"

const string defaultLogin = "defaultLogin"; // То же, что и define?
const string defaultPassword = "defaultPassword";
const string defaultUsername = "defaultUsername";

using namespace std;

static bool online = false;

class Server
{
private:
	User *base = new User[20];
	int _currentUser = 0;

public:
	void Register(string login, string password, string username);
	void Register();
	void login();
};



void startServer();
void stopServer();