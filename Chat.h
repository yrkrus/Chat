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

private:
	std::string _chatMessage;
	int _userIDrecipient;	// получатель
	int _userIDsender;		// отправитель



};