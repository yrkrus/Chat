#pragma once
#include <string>
#include <iostream>

// ������������ ����� ������������
class User
{
public:
	// ����������� | ����������
	User();
	User(std::string login, std::string password);
	User(std::string name, std::string login, std::string password);	
	~User();
	
//	int& operator[](int index);


	// ������� ������
	void setName(std::string name);
	std::string getName();

	void setLogin(std::string login);
	std::string getLogin();

	void setPassword(std::string password);
	std::string getPassword();


	


private:
	std::string name_;			// ��� ������������
	std::string login_;			// �����	
	std::string password_;		// ������ (���� � ����� ���� � ������� ���)
	
	
};