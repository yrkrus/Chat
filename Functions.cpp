#include "Functions.h"
#include "User.h"
#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <cstdlib>


bool DEBUG{ true };

using std::vector;
using std::cout;
using std::string;
using std::cin;


vector<User> g_userslist;
User g_currentUser;


void createTestUsers() 
{
	const int SIZE_USERS = 5;
	
	for (int i = 0; i < SIZE_USERS; ++i) 
	{
		string username="User"+std::to_string(i);
		string login = std::to_string(i);
		string password = std::to_string(i);

		User newuser(username, login, password);

		g_userslist.push_back(newuser);
	}
}


void showUserList()
{
	menuHeader();

	string message;

	for (size_t i = 0; i < g_userslist.size(); ++i) 
	{
		if (g_currentUser.getLogin() == g_userslist[i].getLogin()) 
		{
			cout << "\t" << i + 1 << ". Написать [" << g_userslist[i].getName() << "] (Текущий пользователь, потом убрать отображение)\n";
		}
		else 
		{
			cout << "\t" << i + 1 << ". Написать [" << g_userslist[i].getName() << "] \n";
		}
		
		
	}

	cout << "\t"<<g_userslist.size() + 1 << ". Выход\n\n";
	cout << "> ";

	int choise;	
	cin >> choise;

	cout << g_currentUser.getName() << "[" << g_currentUser.getUserID() << "] --> " << g_userslist[choise-1].getName() <<"["<< g_userslist[choise - 1].getUserID() <<"]" << " : ";

	cin >> message;
}

void exitCurrentUser()
{
	g_currentUser.clear();
}

void exitNow()
{
	exit(0);
}

void menuHeader()
{
	clearconsole();
	cout << "================ C H A T ================ \n\n";
}


// менюшка после успешной авторизации
void menuAuth()
{
	menuHeader();
	
	cout << "Привет, " << g_currentUser.getName() <<"["<<g_currentUser.getUserID()<<"]\n\n";
	
	// debug сделать чтобы писалось сообщение если есть какие либо сообщения пока был не в сети



	cout << "\t 1. Написать пользователю\n"
		 << "\t 2. Написать всем пользователям (" <<g_userslist.size() << ") \n"
		 << "\t 3. Выход\n";
	cout << "> ";

	int choise;
	bool exitnow{ false };

	cin >> choise;

	while (!exitnow)
	{
		switch (choise)
		{ 
		case 1: // Написать пользователю
			{
			showUserList();
			}
		case 2: // Написать всем пользователям 
			{
			
			}
		case 3:
		{
			exitnow = true;
		}
		default:
		{
			cout << "Нет такой команды!\n" << "> ";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> choise;
		}
		}
	}

	exitCurrentUser();
	menu();
	return;

}

void menu()
{
	menuHeader();
	
	int choise;
	int counterr{ 0 };

	bool exitnow{ false };

	cout << "\t1. Вход \n"
		<<  "\t2. Регистрация \n"
		<<  "\t3. Выход \n";
	cout << "> ";

	cin >> choise;
		
	while (!exitnow) 
	{
		switch (choise)
		{
		case 1: // вход
		{
			authorization();
			break;
		}
		case 2: // регистрация
		{
			createNewUser();
			break;
		}
		case 3: // выход
		{
			exitNow();
		}
		default:
		{
			++counterr;

			if (counterr > 3) 
			{
				counterr = 0;
				menu();
			};
			
			cout << "Нет такой команды!\n" << "> ";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> choise;
		}

		}
	}	
	
}


// очистка консоли
void clearconsole() 
{
	system("cls");
}


// авторизация 
void authorization()
{
	menuHeader();
	
	if (!checkExistUsersList()) 
	{
		char choise;
		cout << "ОШИБКА! Не зарегистировано ни одного пользователя! \n";
		
		cout << "Создать нового пользователя? y/n? \n";
		cout << "> ";
		cin >> choise;
		if (choise != 'n')
		{
			createNewUser();
		}		

		menu();
		return;
	}

	std::string name,login,password;
	bool auth = false;					// успешная авторизация

	
	cout << "Логин: ";
	cin >> login;
	cout << "Пароль: ";	
	cin >> password;

	
	// проверка на авторизацию
	for (size_t i = 0; i < g_userslist.size(); ++i) 
	{
		if (g_userslist[i].getLogin() == login && g_userslist[i].getPassword() == password) 
		{
			auth = true;
			
			// текущий залогиненый пользователь
			g_currentUser.setName(g_userslist[i].getName());
			g_currentUser.setLogin(login);
			g_currentUser.setPassword(password);		
			g_currentUser.setUserIDManual(g_userslist[i].getUserID());
			break;
		}
	}
	
	if (auth) 
	{
		menuAuth(); // успешная авторизация
	}
	else 
	{
		cout << "ОШИБКА! логин/пароль некорректны \n";
		cout << "Повторить вход? y/n? \n";
		cout << "> ";
		
		char choise;

		cin >> choise;
		if (choise != 'n')
		{
			authorization();
		}

	}
}

// проверка на пароль ( 3 символа цифры и буквы)
bool checkNewPassword(string password) 
{
	const int size_password = 3;	// минимальная длинна пароля
	bool upper_letters = false;		// заглавные символы
	bool lower_letters = false;		// строчные символы
	bool number_letters = false;	// цифры


	// проверка на длину строки
	if (password.length() < size_password) 
	{
		cout << "Длина пароля должна быть не менее " << size_password << " символов \n\n";
		return false;		
	}
	
	// проверка на заглавные и строчные буквы
	for (int i = 0; i < password.length(); ++i) 
	{
		if ('A' <= password[i] && password[i] <= 'Z') { upper_letters = true; }
		if ('a' <= password[i] && password[i] <= 'z') { lower_letters = true; }
		if ('1' <= password[i] && password[i] <= '9') { number_letters = true; }
	}
		if (!upper_letters) 
		{
			cout << "Пароль должен содержать символы нижнего регистра.\n\n";
			return false;

		} else if (!lower_letters)
		{
			cout << "Пароль должен содержать символы верхнего регистра.\n\n";
			return false;

		} else if (!number_letters)
		{
			cout << "Пароль должен содержать хотя бы 1 цифру.\n\n";
			return false;
		}

	return true;
}


// создание нового пользователя
void createNewUser()
{
	menuHeader();

	string name, login, password;
	char choise = 'y';	

	cout << "Регистарция нового пользователя \n\n";

	cout << "Имя: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // чтобы не перескакивал на след. строку
	getline(cin, name, '\n');

	cout << "Логин: ";
	cin >> login;

	cout << "Пароль: ";
	cin >> password;

	// проверка на правильность пароля
	while (!checkNewPassword(password) || choise == 'n')
	{
		cout << "Хотите попробовать еще раз? y/n? \n";
		cout << "> ";
		cin >> choise;

		if (choise != 'n') 
		{ 
			createNewUser(); 
		}
		else 
		{
			menu();
			return;
		}
	}	

	// проверка уникальности логина
	if (!g_userslist.empty()) 
	{
		for (size_t i = 0; i < g_userslist.size(); ++i) 
		{
			if (g_userslist[i].getLogin() == login) 
			{
				cout << "Логин не уникален, попробовать еще раз? y/n? \n";
				cout << "> ";
				cin >> choise;

				if (choise != 'n')
				{
					createNewUser();
				}
				else
				{
					menu();
					return;
				}
			}
		}
	}

	// создаем нового пользователя
	User newuser(name, login, password);

	g_userslist.push_back(newuser);
	cout << "Пользователь " << newuser.getName() << " создан \n\n";
	
	if (DEBUG) 
	{
		cout << "Создать нового пользователя? y/n? \n";
		cout << "> ";

		cin >> choise;
		cout << "> ";
		if (choise == 'y')
		{
			createNewUser();
		}
		else 
		{
			menu();
			return;
		}
	}

	menu();
	return;
}

// проверка есть ли пользователи зарегистрированные
bool checkExistUsersList()
{
	if (g_userslist.empty()) 
	{ 
		return false; 
	}
	else 
	{
		return true;
	}
}


