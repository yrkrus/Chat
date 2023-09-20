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
			cout << "\t" << i + 1 << ". �������� [" << g_userslist[i].getName() << "] (������� ������������, ����� ������ �����������)\n";
		}
		else 
		{
			cout << "\t" << i + 1 << ". �������� [" << g_userslist[i].getName() << "] \n";
		}
		
		
	}

	cout << "\t"<<g_userslist.size() + 1 << ". �����\n\n";
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


// ������� ����� �������� �����������
void menuAuth()
{
	menuHeader();
	
	cout << "������, " << g_currentUser.getName() <<"["<<g_currentUser.getUserID()<<"]\n\n";
	
	// debug ������� ����� �������� ��������� ���� ���� ����� ���� ��������� ���� ��� �� � ����



	cout << "\t 1. �������� ������������\n"
		 << "\t 2. �������� ���� ������������� (" <<g_userslist.size() << ") \n"
		 << "\t 3. �����\n";
	cout << "> ";

	int choise;
	bool exitnow{ false };

	cin >> choise;

	while (!exitnow)
	{
		switch (choise)
		{ 
		case 1: // �������� ������������
			{
			showUserList();
			}
		case 2: // �������� ���� ������������� 
			{
			
			}
		case 3:
		{
			exitnow = true;
		}
		default:
		{
			cout << "��� ����� �������!\n" << "> ";
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

	cout << "\t1. ���� \n"
		<<  "\t2. ����������� \n"
		<<  "\t3. ����� \n";
	cout << "> ";

	cin >> choise;
		
	while (!exitnow) 
	{
		switch (choise)
		{
		case 1: // ����
		{
			authorization();
			break;
		}
		case 2: // �����������
		{
			createNewUser();
			break;
		}
		case 3: // �����
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
			
			cout << "��� ����� �������!\n" << "> ";
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin >> choise;
		}

		}
	}	
	
}


// ������� �������
void clearconsole() 
{
	system("cls");
}


// ����������� 
void authorization()
{
	menuHeader();
	
	if (!checkExistUsersList()) 
	{
		char choise;
		cout << "������! �� ��������������� �� ������ ������������! \n";
		
		cout << "������� ������ ������������? y/n? \n";
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
	bool auth = false;					// �������� �����������

	
	cout << "�����: ";
	cin >> login;
	cout << "������: ";	
	cin >> password;

	
	// �������� �� �����������
	for (size_t i = 0; i < g_userslist.size(); ++i) 
	{
		if (g_userslist[i].getLogin() == login && g_userslist[i].getPassword() == password) 
		{
			auth = true;
			
			// ������� ����������� ������������
			g_currentUser.setName(g_userslist[i].getName());
			g_currentUser.setLogin(login);
			g_currentUser.setPassword(password);		
			g_currentUser.setUserIDManual(g_userslist[i].getUserID());
			break;
		}
	}
	
	if (auth) 
	{
		menuAuth(); // �������� �����������
	}
	else 
	{
		cout << "������! �����/������ ����������� \n";
		cout << "��������� ����? y/n? \n";
		cout << "> ";
		
		char choise;

		cin >> choise;
		if (choise != 'n')
		{
			authorization();
		}

	}
}

// �������� �� ������ ( 3 ������� ����� � �����)
bool checkNewPassword(string password) 
{
	const int size_password = 3;	// ����������� ������ ������
	bool upper_letters = false;		// ��������� �������
	bool lower_letters = false;		// �������� �������
	bool number_letters = false;	// �����


	// �������� �� ����� ������
	if (password.length() < size_password) 
	{
		cout << "����� ������ ������ ���� �� ����� " << size_password << " �������� \n\n";
		return false;		
	}
	
	// �������� �� ��������� � �������� �����
	for (int i = 0; i < password.length(); ++i) 
	{
		if ('A' <= password[i] && password[i] <= 'Z') { upper_letters = true; }
		if ('a' <= password[i] && password[i] <= 'z') { lower_letters = true; }
		if ('1' <= password[i] && password[i] <= '9') { number_letters = true; }
	}
		if (!upper_letters) 
		{
			cout << "������ ������ ��������� ������� ������� ��������.\n\n";
			return false;

		} else if (!lower_letters)
		{
			cout << "������ ������ ��������� ������� �������� ��������.\n\n";
			return false;

		} else if (!number_letters)
		{
			cout << "������ ������ ��������� ���� �� 1 �����.\n\n";
			return false;
		}

	return true;
}


// �������� ������ ������������
void createNewUser()
{
	menuHeader();

	string name, login, password;
	char choise = 'y';	

	cout << "����������� ������ ������������ \n\n";

	cout << "���: ";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ����� �� ������������ �� ����. ������
	getline(cin, name, '\n');

	cout << "�����: ";
	cin >> login;

	cout << "������: ";
	cin >> password;

	// �������� �� ������������ ������
	while (!checkNewPassword(password) || choise == 'n')
	{
		cout << "������ ����������� ��� ���? y/n? \n";
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

	// �������� ������������ ������
	if (!g_userslist.empty()) 
	{
		for (size_t i = 0; i < g_userslist.size(); ++i) 
		{
			if (g_userslist[i].getLogin() == login) 
			{
				cout << "����� �� ��������, ����������� ��� ���? y/n? \n";
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

	// ������� ������ ������������
	User newuser(name, login, password);

	g_userslist.push_back(newuser);
	cout << "������������ " << newuser.getName() << " ������ \n\n";
	
	if (DEBUG) 
	{
		cout << "������� ������ ������������? y/n? \n";
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

// �������� ���� �� ������������ ������������������
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


