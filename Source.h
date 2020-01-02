#pragma once
#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct TheatreTicket //структура театральных билетов
{
	struct Date //работа с датой
	{
		int d, m, y;
		Date()
		{
			d = m = y = 0;
		}
	};
	int id;
	Date date;
	char theatre[40];
	char performance[40];
	int count;
};
struct User// пользователи системы 
{
	char login[30];
	char psw[30];
};
bool check_admin(char* log, char* psw); //функция проверки входа администратора;
void user_title();// функция работы пользователя;
void print_user();
void save_user(vector<User> users);// функция сохранения данных пользователя;
void add_user(User input); //функция добавления информации в базе данных пользователя;
void edit_user(User input, int index); // функция редактирования информации в базе данных пользователя;
void delete_user(int index); //функция удаления информации в базе данных пользователя;
bool check_user(char* log, char* psw);// функция проверки входа для пользователя;
TheatreTicket parse_string(char* str);
bool open_file_admin(vector<TheatreTicket>& tickets); //функция открытия файла администратора;
bool open_file_user(vector<TheatreTicket>& tickets); //функция открытия файла пользователей;
void print_title();
void print(TheatreTicket ticket);
void print(vector<TheatreTicket> tickets);
void print_check(vector<TheatreTicket> tickets, int month);
void save_to_file(vector<TheatreTicket> tickets); //функция сохранения в файл;
void sort_by_count(vector<TheatreTicket>& tickets);// сортировка по количеству;
void sort_by_theatre(vector<TheatreTicket>& ticket); ///сортировка по театру;
void sort_by_performance(vector<TheatreTicket>& tickets);// сортировка по спектаклям;
void search_by_performance(vector<TheatreTicket> tickets, char* performance);//поиск по спектаклям;
void search_by_theatre(vector<TheatreTicket> tickets, char* theatre);// – поиск по театрам;
void search_by_date(vector<TheatreTicket> tickets, int d, int m, int y);// поиск по дате;
void more_popular(vector<TheatreTicket> tickets, int month);//самые популярные спектакли.
void movenum(vector<TheatreTicket>& tickets);