#include <iostream>
// #include <vector>
#include "Functions.h"
#include "Chat.h"
#include "User.h"


/*
	Итоговый проект по блоку "Основные конструкции с++"
*/

// глобальные переменные
const int maxcountUser = 3;               // кол-во пользователей 
User usersList[maxcountUser];	          // список с пользователями





int main()
{
	unsigned int choise = 0;
	setlocale(LC_ALL, "");

   
   // debug
    usersList[0].setLogin("0");
    usersList[0].setPassword("0");
    usersList[0].setName("Имя 0");

    usersList[1].setLogin("1");
    usersList[1].setPassword("1");
    usersList[1].setName("ИМя 1");

    usersList[2].setLogin("2");
    usersList[2].setPassword("2");
    usersList[2].setName("ИМя 2");

       
    
    // стартовое сообщение
    greetingWindowInfo();
    std::cin >> choise;


    switch (choise)
    {
    case 1: // вход
        {
        authorization(usersList);
        break;
        }
    case 2: // регистрация
        {
       
        break;
        }
        
    
    default:
        {
        
        break;
        }
        
    }





return 0;
	
	

	
}

