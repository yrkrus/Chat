#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

// менюшка
void menu();
void menuHeader();
void menuAuth();

// выход
void exitNow();

// вход 
void authorization();

// создание нового пользователя
void createNewUser();

// проверка на пароль ( 3 символа цифры и буквы)
bool checkNewPassword(std::string password);

// очистка консоли
void clearconsole();

// проверка есть ли пользователи зарегистрированные
bool checkExistUsersList();

// выход из авторизованных
void exitCurrentUser();

// создвание тестовых пользователей
void createTestUsers();

// отображение сколько пользователей сейчас зарегистрировано
void showUserList();

#endif