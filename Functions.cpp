#include <iostream>
#include "Functions.h"
#include "User.h"




// �������������� ���� 
void greetingWindowInfo()
{
	std::cout << "=================================\n";	
	std::cout << "\t1. ���� \n"
			  << "\t2. ����������� \n"
			  << "\t3. ����� \n";
	std::cout << "=================================\n";
}


// �����������
//void authorization(User (&allusers)[])
void authorization(User *allusers)
{
	system("cls");
	std::string login,password;

	int arr_size = sizeof(*allusers)/sizeof(allusers[0]);

	std::cout << "�����: ";
	std::cin >> login;
	std::cout << "������: ";	
	std::cin >> password;

	size_t i = 0;
	// ��������� �� �����������
	//for (size_t i = 0; i < arr_size; ++i)
	{	
	
	
		if (allusers[i].getLogin() == login && allusers[i].getPassword() == password)
		{
			//	std::cout << "���� ��������";
			system("cls");
			(allusers[i].getName()).length() != 0 ? std::cout << "������, " << allusers[i].getName() : std::cout << "�������� �����������";

			// �������� ������ � �����������  debug

		
		}
		else
		{
			// �������� ��� �� ����� ����� ��� ������
			std::cout << "������! ����� ��� ������ �� ������ /n";
			// authorization()
		}
	
	}

}


// �������� ������ ������������ (�� ������)
void createNewUser(std::string username, std::string login, std::string password) 
{
	
}