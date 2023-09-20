#include "Chat.h"

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
