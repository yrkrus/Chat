﻿#include "Functions.h"
#include "Chat.h"
#include "User.h"
#include <iostream>
#include <vector>

using std::vector;


extern vector<User> g_userslist;
extern User g_currentUser;


int main()
{
	setlocale(LC_ALL, ""); 
	system("chcp 1251");
    
	createTestUsers(); // тестовое создание пользователей	
	menu();

	return 0;	
}

