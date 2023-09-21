# Chat
Итоговое решение по модулю "основные конструкции с++"

# Команда
Юрий Петров

# Классы
class Chat \
void sendMessage() \
int getUserIDrecipient() const \
int getUserIDsender() const \
string getMessage() const

class User \
void setName(string name) \
string getName() const \
setLogin(string login) \
string getLogin() const \
void setPassword(std::string password) \
string getPassword() const \
void setUserID() \
void setUserIDManual(int ID) \
int getUserID() const \
void clear() \

# Функции \
// меню \
void menu() \
void menuHeader() \
void menuAuth() \
// выход \
void exitNow() \
// вход \
void authorization() \
// создание нового пользователя + личных сообщений (предустановленные) \
void createNewUser() \
void createTestMessage()
// проверка на пароль ( 3 символа цифры и буквы) \
bool checkNewPassword(string password) \
// очистка консоли \
void clearconsole() \
// проверка есть ли пользователи зарегистрированные \
bool checkExistUsersList() \
// выход из авторизованных \
void exitCurrentUser() \
// создвание тестовых пользователей \
void createTestUsers() \
// отображение сколько пользователей сейчас зарегистрировано \
void showUserList() \
// отображение информации о тестовых пользователях \
void viewTestUsersInfo() \
// отправка сообщения пользователь --> пользователь \
void sendMessage(int userIDrecipient) \
// отправка сообщения пользователь --> все \
void sendMessage() \
// проверка сообщений (для текущего пользователя) \
void showCountMessageCurrentUser() \
// отображение моих сообщений \
void showMyMessage()





