#include <iostream>
#include "User.h"

User::User()
{
}

User::User(std::string login, std::string password)
	: login_(login), password_(password)
{
}

User::User(std::string name, std::string login, std::string password)
	: name_(name),login_(login),password_(password)
{
}


User::~User()
{
}



void User::setName(std::string name)
{
	name_ = name;
}

std::string User::getName()
{
	return name_;
}

void User::setLogin(std::string login)
{
	login_ = login;
}

std::string User::getLogin()
{
	return login_;
}

void User::setPassword(std::string password)
{
	password_ = password;
}

std::string User::getPassword()
{
	return password_;
}





