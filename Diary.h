#pragma once
#include<string>

struct Diary
{
	std::string workList;
	std::string* workItem;
	std::string deadline;
	bool status;
	int how;
};

void initialization(Diary* diary, size_t length);



