#include "Diary.h"

void initialization(Diary* diary, size_t length)
{
	for (size_t i = 0; i < length; i++)
	{	
		diary[i].workItem = new std::string[length];
		diary[i].workItem[0] = "*";
		diary[i].status = false;
	}

}




