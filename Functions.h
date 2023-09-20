#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

// �������
void menu();
void menuHeader();
void menuAuth();

// �����
void exitNow();

// ���� 
void authorization();

// �������� ������ ������������
void createNewUser();

// �������� �� ������ ( 3 ������� ����� � �����)
bool checkNewPassword(std::string password);

// ������� �������
void clearconsole();

// �������� ���� �� ������������ ������������������
bool checkExistUsersList();

// ����� �� ��������������
void exitCurrentUser();

// ��������� �������� �������������
void createTestUsers();

// ����������� ������� ������������� ������ ����������������
void showUserList();

#endif