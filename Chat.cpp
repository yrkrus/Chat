#include "Chat.h"
#include <vector>

extern std::vector<Chat> g_chat;			// список с чатом текущего пользователя (написать конкретному пользователю)

Chat::Chat()
{
}

Chat::Chat(int userIDrecipient, int userIDsender, std::string message)
	: _userIDrecipient(userIDrecipient), _userIDsender(userIDsender), _chatMessage(message)
{
}


Chat::~Chat()
{
}

void Chat::sendMessage()
{

}

int Chat::getUserIDrecipient() const
{
	return _userIDrecipient;
}

int Chat::getUserIDsender() const
{
	return _userIDsender;
}

std::string Chat::getMessage() const
{
	return _chatMessage;
}
