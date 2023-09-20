#pragma once
#include <string>
#include <iostream>
#include <vector>


// класс Пользователя
class User
{
public:
	// конструктор | деструктор
	User();
	User(std::string login, std::string password);
	User(std::string name, std::string login, std::string password);
	~User();
	
	
	// функции класса
	void setName(std::string name);
	std::string getName() const;

	void setLogin(std::string login);
	std::string getLogin() const;

	void setPassword(std::string password);
	std::string getPassword() const;

	void setUserID();
	void setUserIDManual(int ID);
	int getUserID() const;

	void clear();


private:	
	int userID_;
	std::string name_;			// имя пользователя
	std::string login_;			// логин	
	std::string password_;		// пароль (пока в явнов виде в будущем хэш)
	
};


