#pragma once
#include <string>
#include <iostream>
#include <vector>


// ����� ������������
class User
{
public:
	// ����������� | ����������
	User();
	User(std::string login, std::string password);
	User(std::string name, std::string login, std::string password);
	~User();
	
	
	// ������� ������
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
	std::string name_;			// ��� ������������
	std::string login_;			// �����	
	std::string password_;		// ������ (���� � ����� ���� � ������� ���)
	
};


