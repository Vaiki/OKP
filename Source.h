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

struct TheatreTicket //��������� ����������� �������
{
	struct Date //������ � �����
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
struct User// ������������ ������� 
{
	char login[30];
	char psw[30];
};
bool check_admin(char* log, char* psw); //������� �������� ����� ��������������;
void user_title();// ������� ������ ������������;
void print_user();
void save_user(vector<User> users);// ������� ���������� ������ ������������;
void add_user(User input); //������� ���������� ���������� � ���� ������ ������������;
void edit_user(User input, int index); // ������� �������������� ���������� � ���� ������ ������������;
void delete_user(int index); //������� �������� ���������� � ���� ������ ������������;
bool check_user(char* log, char* psw);// ������� �������� ����� ��� ������������;
TheatreTicket parse_string(char* str);
bool open_file_admin(vector<TheatreTicket>& tickets); //������� �������� ����� ��������������;
bool open_file_user(vector<TheatreTicket>& tickets); //������� �������� ����� �������������;
void print_title();
void print(TheatreTicket ticket);
void print(vector<TheatreTicket> tickets);
void print_check(vector<TheatreTicket> tickets, int month);
void save_to_file(vector<TheatreTicket> tickets); //������� ���������� � ����;
void sort_by_count(vector<TheatreTicket>& tickets);// ���������� �� ����������;
void sort_by_theatre(vector<TheatreTicket>& ticket); ///���������� �� ������;
void sort_by_performance(vector<TheatreTicket>& tickets);// ���������� �� ����������;
void search_by_performance(vector<TheatreTicket> tickets, char* performance);//����� �� ����������;
void search_by_theatre(vector<TheatreTicket> tickets, char* theatre);// � ����� �� �������;
void search_by_date(vector<TheatreTicket> tickets, int d, int m, int y);// ����� �� ����;
void more_popular(vector<TheatreTicket> tickets, int month);//����� ���������� ���������.
void movenum(vector<TheatreTicket>& tickets);