// Exam 24.05.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Минимум для c++
#include <iostream> // стандартная библиотека с функциями
#include <iomanip> /*Манипуляция вводами данных, ввод консоли*/
#include <string> // объявлять переменную строкой
#include <stdlib.h> //содержаться классы (тренеры, векторы)
#include <cmath> //Возведение в степень
#include <windows.h> //доступ к API
#include <conio.h>
#include <dos.h>
#include <math.h>
#include <vector>
#include <sstream>
#include "Diary.h"
using namespace std; // рабочее пространство, чтобы не писать каждый раз std

//изъятие всех цифр в числе и заполнение их в массив
void fillingNum(int number, int* defaultMass, size_t length, int &ptr){
	int count = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (number > 0) {
			defaultMass[i] = number % 10;
			number /= 10;
			count++;
		}
		else if (count > 10) {
			break;
		}
		else
			ptr = count;
		
			
	}
}
void filling(int* mass, size_t length) {
	for (size_t i = 0; i < length; i++)
	{
		mass[i] = rand() % 100;
	}
}
//перенос всех чисел в обратном порядке
void fillingHelp(int* defaultMass, int* mass, size_t length) {
	for (size_t i = 0, j = length - 1; i < length; i++, j--)
	{
		mass[i] = defaultMass[j];
	}
}
//произведение чисел
int op(int* mass, size_t length) {
	int temp = 1;
	for (size_t i = 0; i < length; i++)
	{
		temp *= mass[i];
	}
	return temp;
}
//сложение чисел
int add(int* mass, size_t length) {
	int temp = 0;
	for (size_t i = 0; i < length; i++)
	{
		temp += mass[i];
	}
	return temp;
}
//разность чисел
int diff(int* mass, size_t length) {
	int temp = mass[0];
	for (size_t i = 1; i < length; i++)
	{
		temp -= mass[i];
	}
	return temp;
}
//запись величины всех слов
void lengthWord(string* defaulText, int* mass, size_t length) {
	for (size_t i = 0; i < length; i++)
	{
		mass[i]=defaulText[i].length();
	}
}
//запись длинных слов
void longWord(string* defaulText, int* mass,string* longTextWord, size_t length) {
	int temp = 0;
	for (size_t i = length -1; i > length - 4; i--)
	{	
		
		for (size_t j = 0; j < length; j++)
		{
			if (mass[i] == defaulText[j].length()) {
				longTextWord[temp] = defaulText[j];
			}
		}
		temp++;
	}
}
//обычный вывод чисел
void print(int* mass, size_t length) {
	for (size_t i = 0; i < length; i++)
	{
		cout << mass[i] << " ";
	}
}
//текст с выбором для ценза
void print(string* mass, size_t length) {
	for (size_t i = 0,j=1; i < length; i++,j++)
	{
		cout << "(" << j << ")" << mass[i] << " ";
	}
}
//Текст без выбора слова
void printText(string* mass, size_t length) {
	for (size_t i = 0, j = 1; i < length; i++, j++)
	{
		cout << mass[i] << " ";
	}
}
//вывод четных чисел
void printEven(int* mass, size_t length) {
	for (size_t i = 0; i < length; i++)
	{
		if(mass[i]%2==0)
		cout << mass[i] << " ";
	}
}
//поиск минимальной позиции для сортировки
int smallPos(int* mass, int startPosition, int length)
{
	int smallestPosition = startPosition;

	for (int i = startPosition; i < length; i++)
	{
		if (mass[i] < mass[smallestPosition])
			smallestPosition = i;
	}
	return smallestPosition;
}
//сортировка числа по возрастанию
int* sortSel(int* mass, int length)
{

	for (int i = 0; i < length; i++)
	{
		int smallestPosition = smallPos(mass, i, length);
		swap(mass[i], mass[smallestPosition]);

	}
	return mass;
}
void censor(string* defaulText, int change, int &ptr) {
	string cens = "*";
	int temp = defaulText[change - 1].length();
	ptr++;
	defaulText[change - 1] = cens;
	
	for (size_t i = 1; i < temp; i++)
	{
		defaulText[change - 1] += cens;
	}
}

int main()
{
#pragma region Starterpuck
	SetConsoleOutputCP(1251); //изменение кодировки на другую
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Russian"); //добавление русской локализации в консоль
	srand(time(NULL)); //обнуление рандома
#pragma endregion


#pragma region Task_1
	//int number, temp = 0;
	//int count = 0;
	//int* ptr = &count;
	//size_t length = 10;
	//int* defaultMass = new int[length];	
	//cout << "Введите число, не больше 10 цифр - ", cin >> number;
	//filling(number, defaultMass, length, *ptr);
	//length = count;
	//int* mass = new int[length];
	////ошибка при вводе числа больше 10 цифр
	//if (count > 10)
	//{
	//	cout << "Eror";
	//	exit(0);
	//}
	//fillingHelp(defaultMass, mass, length);
	//print(mass, length);
	//cout << "Какую оперцию вы хотите произвести?\n1 - Произведение\n2 - Сложение\n3 - Разность чисел ", cin >> number;
	//while(number > 3 || number <= 0)
	//	cout << "\nEror - неверное выбор операции\nКакую оперцию вы хотите произвести?\n1 - Произведение\n2 - Сложение\n3 - Разность чисел ", cin >> number;

	//switch (number)
	//{
	//case 1: {
	//	cout << op(mass, length);
	//	break;
	//}
	//case 2: {
	//	cout << add(mass, length);
	//	break;
	//}
	//case 3: {
	//	cout << diff(mass, length);
	//	break;
	//}	
	//}
	//cout << endl;
	//sortSel(mass, length);
	//print(mass, length);
#pragma endregion


#pragma region Task_2
	//size_t length;
	//cout << "Введите величину массива - ",cin >> length;
	//int* mass = new int[length];
	//filling(mass, length);
	//cout << endl;
	//print(mass, length);
	//sortSel(mass, length);
	//cout << endl;
	//print(mass, length);
	//cout << endl;
	//printEven(mass, length);
#pragma endregion

#pragma region Task_3
	//size_t length;
	//cout << "Введите количество слов в тексте - ",cin >> length;
	//string* defaulText = new string[length];
	//string* longTextWord = new string[3];
	//int* mass = new int[length];
	//int change, count = 0;
	//int* ptr = &count;
	//cout << "\nВведите слова - ";
	//for (size_t i = 0; i < length; i++)
	//{
	//	cin >> defaulText[i];
	//}
	//print(defaulText, length);
	//lengthWord(defaulText, mass, length); 
	//sortSel(mass, length);
	//longWord(defaulText, mass, longTextWord, length);
	//cout << endl;
	//cout << "самые длинные слова - ", printText(longTextWord, 3);
	//cout << endl;
	//cout << "Выберите номер слова, которое хотите зацензурить? - ", cin >> change;
	//censor(defaulText, change, *ptr);
	//while (change != 0) {
	//	cout << "Продолжить цензуру? Для выхода введите - 0\n", cin >> change;
	//	if(change != 0)
	//	censor(defaulText, change, *ptr);
	//}
	//cout << endl;
	//printText(defaulText, length);
	//cout << endl << "Количество зацензуренных слов - " << count;
	
#pragma endregion

#pragma region Task_4
	
	size_t length;
	int changeWorkList, changeInList, exit = 1, how, completed;
	/*while (exit != 0) {*/
	cout << "Введите количество дел на завтра\n", cin >> length;
	Diary* diary = new Diary[length];
	initialization(diary, length);
	cout << "Заполните ваш ежедневник\n";
	cin.ignore();
	for (size_t i = 0 ; i < length; i++)
	{			
		getline(cin, diary[i].workList);
	}
	
	for (size_t i =0, j = 1; i < length;i++, j++)
	{
		cout << j << ". " << diary[i].workList << endl;
	}
	/*cout << "Если вы закончили заполнять дневник введите 0, если хотите написать задачи заново нажмите 1\n", cin >> exit;
	}
	cout << endl;
	exit = 1;*/
	while (exit != 0) {
	cout << "В какое дело необходимо внести изменения? - ", cin >> changeWorkList;
	while (changeWorkList > length || changeWorkList <= 0)
		cout << "\nEror 505. Неверный выбор\n", cin >> changeWorkList;
	cout << "\n1 - Внести задачи\n2 - Сроки сдачи\n3 - Статус дела\n", cin >> changeInList;
	while (changeInList > 3 || changeInList <= 0)
		cout << "\nEror 505. Неверный выбор\n", cin >> changeInList;
	cout << endl;
	switch (changeInList) {
	case 1: {
		cout << "Сколько задач вы хотите добавить? - ", cin >> diary[changeWorkList-1].how;
		while (diary[changeWorkList - 1].how <= 0)
			cout << "Eror 505. Неверное количество ", cin >> diary[changeWorkList - 1].how;
		if (diary[changeWorkList - 1].how == 1) {
			cin.ignore();
			cout << "Введите задачу - ", getline(cin, diary[changeWorkList-1].workItem[0]);
			
		}
		else if(diary[changeWorkList - 1].how > 1) {
			
			cout << "Введите задачи - ";
				cin.ignore();
			for (size_t i = 0; i < diary[changeWorkList - 1].how; i++)
			{
				getline(cin, diary[changeWorkList-1].workItem[i]);
			}
		}
			break;
	}case 2: {
		cin.ignore();
		cout << "Напишите дату и время через пробел, когда нужно сдать дело - ";
		getline(cin, diary[changeWorkList-1].deadline);
		cout << "\nПравильно ли выбрана дата и время?\n1 - Нет, изменить\n0 - Да, все верно\n", cin >> exit;
		cout << endl;
		while (exit != 0) {
			cin.ignore();
			getline(cin, diary[changeWorkList-1].deadline);
			cout << "\nПравильно ли выбрана дата и время?\n1 - Нет, изменить\n0 - Да, все верно\n", cin >> exit;
		}
		break;
	}case 3: {
		cout << "Выполнена ли задача?\n1 - Да\n0 - Нет ", cin >> completed;
		while (completed > 1 || completed < 0)
			cout << "Eror 505. Неверный ответ ", cin >> completed;
		if (completed == 1)
			diary[changeWorkList-1].status = true;
		else
			diary[changeWorkList-1].status = false;
		break;
	}
	}
	cout << "\n1 - продолжить редактирование\n0 - закончить работу\n", cin >> exit;
	while (exit > 1 || exit < 0)
		cout << "\nEror 505. Неверный выбор\n", cin >> exit;
	}
	cout << "\nНа текущий момент у вас имеются следующие дела на завтра\n";
	cout << "_______________________________________________________________________________\n";
	for (size_t i = 0, g = 1; i < length; i++,g++)
	{	
		cout << g<<". " << diary[i].workList;
		if (diary[i].workItem[0] != "*") {
		for (size_t j = 0; j < diary[i].how; j++)
		{
			cout << "\n  " << diary[i].workItem[j];
		}
	}
		cout << "\n**************************\n";
		cout << "Выполнить до: " << diary[i].deadline << " || " << "Статус выполнения - " << diary[i].status;
		cout << "\n_______________________________________________________________________________\n";
	}
#pragma endregion


}

