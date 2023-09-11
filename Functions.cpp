#include <iostream>
#include "Functions.h"
#include "User.h"




// приветственное окно 
void greetingWindowInfo()
{
	std::cout << "=================================\n";	
	std::cout << "\t1. Вход \n"
			  << "\t2. Регистрация \n"
			  << "\t3. Выход \n";
	std::cout << "=================================\n";
}


// авторизация
//void authorization(User (&allusers)[])
void authorization(User *allusers)
{
	system("cls");
	std::string login,password;

	int arr_size = sizeof(*allusers)/sizeof(allusers[0]);

	std::cout << "Логин: ";
	std::cin >> login;
	std::cout << "Пароль: ";	
	std::cin >> password;

	size_t i = 0;
	// провекрка на авторизацию
	//for (size_t i = 0; i < arr_size; ++i)
	{	
	
	
		if (allusers[i].getLogin() == login && allusers[i].getPassword() == password)
		{
			//	std::cout << "Вход разрешен";
			system("cls");
			(allusers[i].getName()).length() != 0 ? std::cout << "Привет, " << allusers[i].getName() : std::cout << "Успешная авторизация";

			// добавить работу с сообщениями  debug

		
		}
		else
		{
			// проверим что не верно логин или пароль
			std::cout << "ОШИБКА! Логин или пароль не верный /n";
			// authorization()
		}
	
	}

}


// создание нового пользователя (не готово)
void createNewUser(std::string username, std::string login, std::string password) 
{
	
}