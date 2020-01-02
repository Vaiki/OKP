#include "Source.h"


int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	//srand(time(NULL));
	vector<TheatreTicket> tickets;
	TheatreTicket ticket;
	User user;
	char date[20];
	char back_to_menu, login[30], password[30]; // filename[30], code
	int authorization = 0, admin_menu = 0, index, user_menu = 0;// number;
	while (authorization != 3)
	{
		system("cls");
		printf("Вход в систему\n1 - Администратор\n");
		printf("2 - Пользователь\n");
		printf("3 - Выход\n");
		cin >> authorization;
		switch (authorization) // выбор пункта меню для авторизации
		{
		case 1:
			system("cls");
			printf("Введите логин : ");
			cin >> login;
			cout << "Введите пароль : ";
			cin >> password;
			if (strlen(password) < 6)
			{
				cin.ignore();
				cout << "Длина пароля должна быть не менее 6 символов.\n";
				printf("Вернуться в меню? (y/n)");
				scanf("%c", &back_to_menu);
				if (back_to_menu != 'y')
					return 0;
			}
			else if (check_admin(login, password))
			{
				while (admin_menu != 18)
				{
					system("cls");
					printf("Меню\n1 - Создать/открыть файл\n");
					printf("----------------Редактирование данных БД ТЕАТР----------------\n");
					printf("2 - Добавить запись\n");
					printf("3 - Редактировать запись\n");
					printf("4 - Удалить запись\n");
					printf("5 - Просмотр всех данных\n");
					printf("-------------------------Сортировка---------------------------\n");
					printf("6 - Сортировка по названию театра\n");
					printf("7 - Сортировка по названию спектакля\n");
					printf("8 - Сортировка по количеству проданных билетов\n");
					printf("---------------------------Поиск------------------------------\n");
					printf("9 - Поиск по названию театра\n");
					printf("10 - Поиск по названию спектакля\n");
					printf("11 - Поиск по дате\n");
					printf("12 - Сохранить изменения в файл\n");
					printf("13 - Индивидуальное задание\n");
					printf("----------------Редактирование данных БД USER-----------------\n");
					printf("14 - Просмотр всех пользователей\n");
					printf("15 - Добавить пользователя\n");
					printf("16 - Редактировать пользователя\n");
					printf("17 - Удалить пользователя\n");
					printf("18 - Выход\n");
					cin >> admin_menu;
					switch (admin_menu) // выбор пункта меню администратора
					{
					case 1:
						system("cls");
						cin.ignore();
						tickets.clear();
						if (open_file_admin(tickets))
						{
							cout << "Данные успешно считаны!";
						}
						else
						{
							cout << "Файл с данными создан!";
						}
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 2:
						system("cls");
						cin.ignore();
						cout << "День : ";
						cin >> date;
						ticket.id = (int)tickets.size() + 1;
						ticket.date.d = atoi(date);
						if (ticket.date.d == 0)
						{
							cin.ignore();
							printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							cout << "Месяц : ";
							cin >> date;
							ticket.date.m = atoi(date);
							if (ticket.date.m == 0)
							{
								cin.ignore();
								printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
								scanf("%c", &back_to_menu);
								if (back_to_menu != 'y')
									return 0;
							}
							else
							{
								cout << "Год : ";
								cin >> date;
								ticket.date.y = atoi(date);
								if (ticket.date.y == 0)
								{
									cin.ignore();
									printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
									scanf("%c", &back_to_menu);
									if (back_to_menu != 'y')
										return 0;
								}
								else
								{
									cout << "Название театра:\n";
									cin.ignore();
									cin.getline(ticket.theatre, 40);
									cout << "Название спектакля:\n";
									cin.getline(ticket.performance, 40);
									cout << "Количество проданных билетов : ";
									cin >> ticket.count;
									tickets.push_back(ticket);
									cin.ignore();
									printf("\nДанные успешно добавлены!\nВернуться в меню? (y/n)");
									scanf("%c", &back_to_menu);
									if (back_to_menu != 'y')
										return 0;
								}
							}
						}
						break;
					case 3:
						system("cls");
						cin.ignore();
						cout << "Номер записи : ";
						cin >> index;
						index -= 1;
						cin.ignore();
						cout << "День : ";
						cin >> tickets[index].date.d;
						cout << "Месяц : ";
						cin >> tickets[index].date.m;
						cout << "Год : ";
						cin >> tickets[index].date.y;
						cout << "Название театра:\n";
						cin.ignore();
						cin.getline(tickets[index].theatre, 40);
						cout << "Название спектакля:\n";
						cin.getline(tickets[index].performance, 40);
						cout << "Количество проданных билетов : ";
						cin >> tickets[index].count;
						cin.ignore();
						printf("\nДанные успешно изменены!\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 4:
						system("cls");
						cin.ignore();
						cout << "Номер записи :";
						cin >> index;
						index -= 1;
						if (index < 0 || index >= (int)tickets.size())
						{
							printf("\nИндекс выходит за пределы массива!");
						}
						else
						{
							tickets.erase(tickets.begin() + index, tickets.begin() + index + 1);
							printf("\nДанные успешно удалены!");

						}
						cin.ignore();
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 5:
						system("cls");
						cin.ignore();
						print(tickets);
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 6:
						system("cls");
						cin.ignore();
						sort_by_theatre(tickets);
						printf("Готово!\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 7:
						system("cls");
						cin.ignore();
						sort_by_performance(tickets);
						printf("Готово!\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 8:
						system("cls");
						cin.ignore();
						sort_by_count(tickets);
						printf("Готово!\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 9:
						system("cls");
						cin.ignore();
						cout << "Название театра : ";
						cin.getline(ticket.theatre, 40);
						search_by_theatre(tickets, ticket.theatre);
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 10:
						system("cls");
						cin.ignore();
						cout << "Название спектакля : ";
						cin.getline(ticket.performance, 40);
						search_by_performance(tickets, ticket.performance);
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 11:
						system("cls");
						cin.ignore();
						cout << "День : ";
						cin >> date;
						ticket.date.d = atoi(date);
						if (ticket.date.d == 0)
						{
							cin.ignore();
							printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							cout << "Месяц : ";
							cin >> date;
							ticket.date.m = atoi(date);
							if (ticket.date.m == 0)
							{
								cin.ignore();
								printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
								scanf("%c", &back_to_menu);
								if (back_to_menu != 'y')
									return 0;
							}
							else
							{
								cout << "Год : ";
								cin >> date;
								ticket.date.y = atoi(date);
								if (ticket.date.y == 0)
								{
									cin.ignore();
									printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
									scanf("%c", &back_to_menu);
									if (back_to_menu != 'y')
										return 0;
								}
								else
								{
									search_by_date(tickets, ticket.date.d, ticket.date.m, ticket.date.y);
									printf("\nВернуться в меню? (y/n)");
									scanf("%c", &back_to_menu);
									if (back_to_menu != 'y')
										return 0;
								}
							}
						}
						break;
					case 12:
						system("cls");
						cin.ignore();
						save_to_file(tickets);
						printf("\nГотово!\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 13:
						system("cls");
						cin.ignore();
						cout << "Месяц : ";
						cin >> date;
						ticket.date.m = atoi(date);
						if (ticket.date.m == 0)
						{
							cin.ignore();
							printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							more_popular(tickets, ticket.date.m);
							cin.ignore();
							printf("\nГотово!\nВернуться в меню? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						break;
					case 14:
						system("cls");
						cin.ignore();
						print_user();
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 15:
						system("cls");
						cin.ignore();
						cout << "Логин: ";
						cin >> user.login;
						cout << "Пароль : ";
						cin >> user.psw;
						if (strlen(user.psw) < 6)
						{
							cin.ignore();
							cout << "Длина пароля должна быть не менее 6 символов.\n";
							printf("Вернуться в меню? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							add_user(user);
							cin.ignore();
							printf("\nПользователь успешно добавлен!Вернуться в меню? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						break;
					case 16:
						system("cls");
						cin.ignore();
						cout << "Номер записи: ";
						cin >> index;
						cout << "Логин: ";
						cin >> user.login;
						cout << "Пароль : ";
						cin >> user.psw;
						edit_user(user, index - 1);
						cin.ignore();
						printf("\nДанные успешно редактированы!Вернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 17:
						system("cls");
						cin.ignore();
						cout << "Номер записи: ";
						cin >> index;
						delete_user(index - 1);
						cin.ignore();
						printf("\nПользователь успешно удален!Вернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					}
				}
			}
			else
			{
				cin.ignore();
				printf("Неверные данные для входа!\nВернуться в меню? (y/n)");
				scanf("%c", &back_to_menu);
				if (back_to_menu != 'y')
					return 0;
			}
			break;
		case 2:
			system("cls");
			printf("Введите логин : ");
			cin >> login;
			cout << "Введите пароль : ";
			cin >> password;
			if (strlen(password) < 6)
			{
				cin.ignore();
				cout << "Длина пароля должна быть не менее 6 символов.\n";
				printf("Вернуться в меню? (y/n)");
				scanf("%c", &back_to_menu);
				if (back_to_menu != 'y')
					return 0;
			}
			else if (check_user(login, password))
			{
				while (user_menu != 10)
				{
					system("cls");
					printf("Меню\n1 - Открыть файл\n");
					printf("2 - Просмотр всех данных\n");
					printf("3 - Сортировка по названию театра\n");
					printf("4 - Сортировка по названию спектакля\n");
					printf("5 - Сортировка по количеству проданных билетов\n");
					printf("6 - Поиск по названию театра\n");
					printf("7 - Поиск по названию спектакля\n");
					printf("8 - Поиск по дате\n");
					printf("9 - Индивидуальное задание\n");
					printf("10 - Выход\n");
					cin >> user_menu;
					switch (user_menu) // выбор пункта меню пользователя
					{
					case 1:
						system("cls");
						cin.ignore();
						tickets.clear();
						if (open_file_user(tickets))
						{
							cout << "Данные успешно считаны!";
						}
						else
						{
							cout << "Файл с данными не существует!";
						}
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 2:
						system("cls");
						cin.ignore();
						print(tickets);
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 3:
						system("cls");
						cin.ignore();
						sort_by_theatre(tickets);
						printf("Готово!\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 4:
						system("cls");
						cin.ignore();
						sort_by_performance(tickets);
						printf("Готово!\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 5:
						system("cls");
						cin.ignore();
						sort_by_count(tickets);
						printf("Готово!\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 6:
						system("cls");
						cin.ignore();
						cout << "Название театра : ";
						cin.getline(ticket.theatre, 40);
						search_by_theatre(tickets, ticket.theatre);
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 7:
						system("cls");
						cin.ignore();
						cout << "Название спектакля : ";
						cin.getline(ticket.performance, 40);
						search_by_performance(tickets, ticket.performance);
						printf("\nВернуться в меню? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 8:
						system("cls");
						cin.ignore();
						cout << "День : ";
						cin >> date;
						ticket.date.d = atoi(date);
						if (ticket.date.d == 0)
						{
							cin.ignore();
							printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							cout << "Месяц : ";
							cin >> date;
							ticket.date.m = atoi(date);
							if (ticket.date.m == 0)
							{
								cin.ignore();
								printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
								scanf("%c", &back_to_menu);
								if (back_to_menu != 'y')
									return 0;
							}
							else
							{
								cout << "Год : ";
								cin >> date;
								ticket.date.y = atoi(date);
								if (ticket.date.y == 0)
								{
									cin.ignore();
									printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
									scanf("%c", &back_to_menu);
									if (back_to_menu != 'y')
										return 0;
								}
								else
								{
									search_by_date(tickets, ticket.date.d, ticket.date.m, ticket.date.y);
									printf("\nВернуться в меню? (y/n)");
									scanf("%c", &back_to_menu);
									if (back_to_menu != 'y')
										return 0;
								}
							}
						}
						break;
					case 9:
						system("cls");
						cin.ignore();
						cout << "Месяц : ";
						cin >> date;
						ticket.date.m = atoi(date);
						if (ticket.date.m == 0)
						{
							cin.ignore();
							printf("\nНеверный формат ввода.\nВернуться в меню? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							more_popular(tickets, ticket.date.m);
							cin.ignore();
							printf("\nГотово!\nВернуться в меню? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						break;
					}
				}
			}
			else
			{
				scanf("%c", &back_to_menu);
				if (back_to_menu != 'y')
					return 0;
			}
			break;
		}
	}
	return 0;
}