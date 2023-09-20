#include "User.h"
#include <vector>;

extern std::vector<User> g_userslist;		// список со всеми пользователями
extern User g_currentUser;					// текущий авторизаванный пользователь

User::User()
{
}

User::User(std::string login, std::string password)
	: login_(login), password_(password)
{
	setUserID();
}

User::User(std::string name, std::string login, std::string password)
	: name_(name),login_(login),password_(password)
{
	setUserID();
}


User::~User()
{
}

void User::setName(std::string name)
{
	name_ = name;
}

std::string User::getName() const
{
	return name_;
}

void User::setLogin(std::string login)
{
	login_ = login;
}

std::string User::getLogin() const
{
	return login_;
}

void User::setPassword(std::string password)
{
	password_ = password;
}

std::string User::getPassword() const
{
	return password_;
}

void User::setUserID()
{
	 userID_ = g_userslist.size();
}

void User::setUserIDManual(int ID)
{
	userID_ = ID;
}

int User::getUserID() const
{
	return userID_;
}

void User::clear()
{
	userID_ = 0;
	login_ = "";
	name_ = "";
	password_ = "";
}





