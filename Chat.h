#pragma once
#include <vector>
#include <string>
#include "User.h"

class Chat 
{
public:
	Chat();
	Chat(int userIDrecipient, int userIDsender, std::string message);

	~Chat();

	void sendMessage();

	int getUserIDrecipient() const;

	int getUserIDsender() const;

	std::string getMessage() const;	

private:
	std::string _chatMessage;
	int _userIDrecipient{ 0 };	// получатель
	int _userIDsender{ 0 };		// отправитель
};