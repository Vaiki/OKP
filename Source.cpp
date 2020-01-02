#include "Source.h"


bool check_admin(char* log, char* psw)//функция проверки входа администратора;
{
	ifstream fin("admin.txt");
	char login[30], password[30];
	if (!fin.good())
	{
		cout << "Файл с данными об администраторах не существует!";
		return false;
	}
	else
	{
		while (!fin.eof())
		{
			fin >> login >> password;
			if (!strcmp(login, log) && !strcmp(password, psw))
			{
				fin.close();
				return true;
			}
		}
		fin.close();
		return false;
	}
}
void user_title()//
{
	cout << setw(15) << left << "Логин" << setw(15) << "Пароль" << endl;
}
void print_user()//
{
	ifstream fin("user.txt");
	User user;
	if (!fin.good())
	{
		cout << "\nФайл с данными об пользователях не существует!";
	}
	else
	{
		user_title();
		while (!fin.eof())
		{
			fin >> user.login >> user.psw;
			cout << setw(15) << left << user.login << setw(15) << user.psw << endl;
		}
		fin.close();
	}
}
void save_user(vector<User> users)//функция сохранения данных пользователя;
{
	ofstream fout("user.txt");
	for (int i = 0; i < (int)users.size(); i++)
	{
		if (i == users.size() - 1)
		{
			fout << users[i].login << " " << users[i].psw;
		}
		else
		{
			fout << users[i].login << " " << users[i].psw << endl;
		}
	}
	fout.close();
}
void add_user(User input)//функция добавления информации в базе данных пользователя;
{
	ifstream fin("user.txt");
	User user;
	vector<User> users;
	while (!fin.eof())
	{
		fin >> user.login >> user.psw;
		users.push_back(user);
	}
	users.push_back(input);
	fin.close();
	save_user(users);
}
void edit_user(User input, int index)//функция редактирования информации в базе данных пользователя;
{
	ifstream fin("user.txt");
	User user;
	vector<User> users;
	while (!fin.eof())
	{
		fin >> user.login >> user.psw;
		users.push_back(user);
	}
	users[index] = input;
	fin.close();
	save_user(users);
}
void delete_user(int index)//функция удаления информации в базе данных пользователя;
{
	ifstream fin("user.txt");
	User user;
	vector<User> users;
	while (!fin.eof())
	{
		fin >> user.login >> user.psw;
		users.push_back(user);
	}
	users.erase(users.begin() + index, users.begin() + index + 1);
	fin.close();
	save_user(users);
}
bool check_user(char* log, char* psw)//функция проверки входа для пользователя;
{
	ifstream fin("user.txt");
	char login[30], password[30];
	if (!fin.good())
	{
		cout << "Файл с данными об пользователях не существует!";
		return false;
	}
	else
	{
		bool exist = false;
		while (!fin.eof())
		{
			fin >> login >> password;
			if (!strcmp(login, log))
			{
				exist = true;
			}
			if (!strcmp(login, log) && !strcmp(password, psw))
			{
				fin.close();
				return true;
			}
		}
		if (!exist)
		{
			cin.ignore();
			printf("Такого пользователя не существует!\nВернуться в меню? (y/n)");
		}
		else
		{
			cin.ignore();
			printf("Неверные данные для входа!\nВернуться в меню? (y/n)");
		}
		fin.close();
		return false;
	}
}
TheatreTicket parse_string(char* str)// парсинг
{
	TheatreTicket ticket;

	char* pch = strtok(str, "."); // во втором параметре указан разделитель (запятая)
	//ticket.id = atoi(pch);
	//pch = strtok(NULL, ".");


	ticket.date.d = atoi(pch);
	pch = strtok(NULL, ".");
	ticket.date.m = atoi(pch);
	pch = strtok(NULL, ",");
	ticket.date.y = atoi(pch);
	pch = strtok(NULL, ",");
	strcpy(ticket.theatre, pch);
	pch = strtok(NULL, ",");
	strcpy(ticket.performance, pch);
	pch = strtok(NULL, "\n");
	ticket.count = atoi(pch);
	return ticket;
}
bool open_file_admin(vector<TheatreTicket>& tickets)//функция открытия файла администратора;
{
	ifstream fin("data.txt");
	if (!fin.good())
	{
		ofstream fout("data.txt");
		fout.close();
		return false;
	}
	else
	{
		char str[255];
		TheatreTicket* ticket = new TheatreTicket();
		int i = 0;
		while (!fin.eof())
		{
			fin.getline(str, 255);

			tickets.push_back(parse_string(str));
		}
		movenum(tickets);
		return true;
	}
	fin.close();
}
bool open_file_user(vector<TheatreTicket>& tickets)//функция открытия файла пользователей;
{
	ifstream fin("data.txt");
	if (!fin.good())
	{
		return false;
	}
	else
	{
		char str[255];
		TheatreTicket* ticket = new TheatreTicket();
		int i = 0;
		while (!fin.eof())
		{
			fin.getline(str, 255);

			tickets.push_back(parse_string(str));
		}
		return true;
	}
	fin.close();
}
void print_title()
{
	cout << left << setw(4) << "#" << setw(16) << "Дата" << setw(25) << "Название театра" << setw(26) << "Название спектакля" << setw(29) << "Количество проданных билетов" << endl;
}
void print(TheatreTicket ticket)

{
	cout << left << setw(4) << ticket.id << setw(2) << ticket.date.d << "." << setw(2) << ticket.date.m << "." << setw(10) << ticket.date.y << setw(25) << ticket.theatre << setw(26) << ticket.performance << setw(29) << ticket.count << endl;
}
void print(vector<TheatreTicket> tickets)
{
	movenum(tickets);
	print_title();
	for (auto& j : tickets)
	{
		print(j);
	}
}
void print_check(vector<TheatreTicket> tickets, int month)
{
	for (int i = 0; i < (int)tickets.size(); i++)
	{
		if (tickets[i].date.m == month)
		{
			print(tickets[i]);
		}
	}
}
void save_to_file(vector<TheatreTicket> tickets)//функция сохранения в файл;
{
	ofstream fout("data.txt");
	for (int i = 0; i < (int)tickets.size(); i++)
	{
		if (i != tickets.size() - 1)
		{
			fout << tickets[i].date.d << "." << tickets[i].date.m << "." << tickets[i].date.y << "," <<
				tickets[i].theatre << "," << tickets[i].performance << "," << tickets[i].count << endl;
		}
		else
		{
			fout << tickets[i].date.d << "." << tickets[i].date.m << "." << tickets[i].date.y << "," <<
				tickets[i].theatre << "," << tickets[i].performance << "," << tickets[i].count;
		}
	}
	fout.close();
}
void sort_by_count(vector<TheatreTicket>& tickets)//сортировка по количеству;
{
	for (int i = 0; i < (int)tickets.size(); i++)
	{
		for (int j = 0; j < (int)tickets.size(); j++)
		{
			if (tickets[j].count > tickets[i].count)
			{
				swap(tickets[i], tickets[j]);
			}
		}
	}
}
void sort_by_theatre(vector<TheatreTicket>& tickets)//сортировка по театру;
{
	for (int i = 0; i < (int)tickets.size(); i++)
	{
		for (int j = 0; j < (int)tickets.size(); j++)
		{
			if (strcmp(tickets[i].theatre, tickets[j].theatre) < 0)
			{
				swap(tickets[i], tickets[j]);
			}
		}
	}
}
void sort_by_performance(vector<TheatreTicket>& tickets)//сортировка по спектаклям;
{
	for (int i = 0; i < (int)tickets.size(); i++)
	{
		for (int j = 0; j < (int)tickets.size(); j++)
		{
			if (strcmp(tickets[i].performance, tickets[j].performance) < 0)
			{
				swap(tickets[i], tickets[j]);
			}
		}
	}
}
void search_by_performance(vector<TheatreTicket> tickets, char* performance)//поиск по спектаклям
{
	print_title();
	int index = 0;
	for (int i = 0; i < (int)tickets.size(); i++)
	{
		if (strcmp(tickets[i].performance, performance) == 0)
		{
			print(tickets[i]);
			index++;
		}
	}
	cin.ignore();
	if (index == 0)
	{
		cout << "\nНет такого спектакля!";
	}
}
void search_by_theatre(vector<TheatreTicket> tickets, char* theatre)//поиск по театрам;
{
	print_title();
	int index = 0;
	for (int i = 0; i < (int)tickets.size(); i++)
	{
		if (strcmp(tickets[i].theatre, theatre) == 0)
		{
			print(tickets[i]);
			index++;
		}
	}
	cin.ignore();
	if (index == 0)
	{
		cout << "\nНет такого театра!";
	}
}
void search_by_date(vector<TheatreTicket> tickets, int d, int m, int y)//поиск по дате
{
	print_title();
	int index = 0;
	for (int i = 0; i < (int)tickets.size(); i++)
	{
		if (tickets[i].date.d == d && tickets[i].date.m == m && tickets[i].date.y == y)
		{
			print(tickets[i]);
			index++;
		}
	}
	cin.ignore();
	if (index == 0)
	{
		cout << "\nНет мероприятий на заднную дату!";
	}
}
void more_popular(vector<TheatreTicket> tickets, int month)//самые популярные спектакли.
{
	vector<TheatreTicket> popular_theatre;
	vector<TheatreTicket> popular_performance;
	bool contains;
	for (TheatreTicket ticket : tickets)
	{
		contains = false;
		for (TheatreTicket var : popular_theatre)
		{
			if (!strcmp(var.theatre, ticket.theatre) && ticket.date.m == month)
			{
				contains = true;
			}
		}
		if (!contains)
		{
			popular_theatre.push_back(ticket);
		}
		contains = false;
		for (TheatreTicket var : popular_performance)
		{
			if (!strcmp(var.performance, ticket.performance) && ticket.date.m == month)
			{
				contains = true;
			}
		}
		if (!contains)
		{
			popular_performance.push_back(ticket);
		}
	}
	for (int i = (int)popular_theatre.size() - 1; i >= 0; i--)
	{
		popular_theatre[i].count = 0;
		for (TheatreTicket ticket : tickets)
		{
			if (!strcmp(popular_theatre[i].theatre, ticket.theatre) && ticket.date.m == month)
			{
				popular_theatre[i].count += ticket.count;
			}
		}
	}
	for (int i = (int)popular_performance.size() - 1; i >= 0; i--)
	{
		popular_performance[i].count = 0;
		for (TheatreTicket ticket : tickets)
		{
			if (!strcmp(popular_performance[i].performance, ticket.performance) && ticket.date.m == month)
			{
				popular_performance[i].count += ticket.count;
			}
		}
	}
	sort_by_count(popular_theatre);
	sort_by_count(popular_performance);
	cout << left << setw(20) << "Название театра" << setw(26) << setw(9) << "Количество проданных билетов" << endl;
	for (int i = (int)popular_theatre.size() - 1; i >= 0; i--)
	{
		cout << left << setw(20) << popular_theatre[i].theatre << setw(9) << popular_theatre[i].count << endl;
	}
	cout << left << setw(26) << "\nНазвание спектакля" << setw(9) << "Количество проданных билетов" << endl;
	for (int i = (int)popular_performance.size() - 1; i >= 0; i--)
	{
		cout << left << setw(26) << popular_performance[i].performance << setw(9) << popular_performance[i].count << endl;
	}
}
void movenum(vector<TheatreTicket>& tickets) {
	int i = 0;
	//for (int i = 0; i < (int)tickets.size(); i++)
	for (auto& j : tickets)
	{
		j.id = i + 1;
		i += 1;
		//tickets[i].id = i+1;

	}
}