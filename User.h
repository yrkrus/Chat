#pragma once
#include <string>
#include <iostream>

// родительский класс Пользователя
class User
{
public:
	// конструктор | деструктор
	User();
	User(std::string login, std::string password);
	User(std::string name, std::string login, std::string password);	
	~User();
	
//	int& operator[](int index);


	// функции класса
	void setName(std::string name);
	std::string getName();

	void setLogin(std::string login);
	std::string getLogin();

	void setPassword(std::string password);
	std::string getPassword();


	


private:
	std::string name_;			// имя пользователя
	std::string login_;			// логин	
	std::string password_;		// пароль (пока в явнов виде в будущем хэш)
	
	
};