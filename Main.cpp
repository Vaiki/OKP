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
		printf("���� � �������\n1 - �������������\n");
		printf("2 - ������������\n");
		printf("3 - �����\n");
		cin >> authorization;
		switch (authorization) // ����� ������ ���� ��� �����������
		{
		case 1:
			system("cls");
			printf("������� ����� : ");
			cin >> login;
			cout << "������� ������ : ";
			cin >> password;
			if (strlen(password) < 6)
			{
				cin.ignore();
				cout << "����� ������ ������ ���� �� ����� 6 ��������.\n";
				printf("��������� � ����? (y/n)");
				scanf("%c", &back_to_menu);
				if (back_to_menu != 'y')
					return 0;
			}
			else if (check_admin(login, password))
			{
				while (admin_menu != 18)
				{
					system("cls");
					printf("����\n1 - �������/������� ����\n");
					printf("----------------�������������� ������ �� �����----------------\n");
					printf("2 - �������� ������\n");
					printf("3 - ������������� ������\n");
					printf("4 - ������� ������\n");
					printf("5 - �������� ���� ������\n");
					printf("-------------------------����������---------------------------\n");
					printf("6 - ���������� �� �������� ������\n");
					printf("7 - ���������� �� �������� ���������\n");
					printf("8 - ���������� �� ���������� ��������� �������\n");
					printf("---------------------------�����------------------------------\n");
					printf("9 - ����� �� �������� ������\n");
					printf("10 - ����� �� �������� ���������\n");
					printf("11 - ����� �� ����\n");
					printf("12 - ��������� ��������� � ����\n");
					printf("13 - �������������� �������\n");
					printf("----------------�������������� ������ �� USER-----------------\n");
					printf("14 - �������� ���� �������������\n");
					printf("15 - �������� ������������\n");
					printf("16 - ������������� ������������\n");
					printf("17 - ������� ������������\n");
					printf("18 - �����\n");
					cin >> admin_menu;
					switch (admin_menu) // ����� ������ ���� ��������������
					{
					case 1:
						system("cls");
						cin.ignore();
						tickets.clear();
						if (open_file_admin(tickets))
						{
							cout << "������ ������� �������!";
						}
						else
						{
							cout << "���� � ������� ������!";
						}
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 2:
						system("cls");
						cin.ignore();
						cout << "���� : ";
						cin >> date;
						ticket.id = (int)tickets.size() + 1;
						ticket.date.d = atoi(date);
						if (ticket.date.d == 0)
						{
							cin.ignore();
							printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							cout << "����� : ";
							cin >> date;
							ticket.date.m = atoi(date);
							if (ticket.date.m == 0)
							{
								cin.ignore();
								printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
								scanf("%c", &back_to_menu);
								if (back_to_menu != 'y')
									return 0;
							}
							else
							{
								cout << "��� : ";
								cin >> date;
								ticket.date.y = atoi(date);
								if (ticket.date.y == 0)
								{
									cin.ignore();
									printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
									scanf("%c", &back_to_menu);
									if (back_to_menu != 'y')
										return 0;
								}
								else
								{
									cout << "�������� ������:\n";
									cin.ignore();
									cin.getline(ticket.theatre, 40);
									cout << "�������� ���������:\n";
									cin.getline(ticket.performance, 40);
									cout << "���������� ��������� ������� : ";
									cin >> ticket.count;
									tickets.push_back(ticket);
									cin.ignore();
									printf("\n������ ������� ���������!\n��������� � ����? (y/n)");
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
						cout << "����� ������ : ";
						cin >> index;
						index -= 1;
						cin.ignore();
						cout << "���� : ";
						cin >> tickets[index].date.d;
						cout << "����� : ";
						cin >> tickets[index].date.m;
						cout << "��� : ";
						cin >> tickets[index].date.y;
						cout << "�������� ������:\n";
						cin.ignore();
						cin.getline(tickets[index].theatre, 40);
						cout << "�������� ���������:\n";
						cin.getline(tickets[index].performance, 40);
						cout << "���������� ��������� ������� : ";
						cin >> tickets[index].count;
						cin.ignore();
						printf("\n������ ������� ��������!\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 4:
						system("cls");
						cin.ignore();
						cout << "����� ������ :";
						cin >> index;
						index -= 1;
						if (index < 0 || index >= (int)tickets.size())
						{
							printf("\n������ ������� �� ������� �������!");
						}
						else
						{
							tickets.erase(tickets.begin() + index, tickets.begin() + index + 1);
							printf("\n������ ������� �������!");

						}
						cin.ignore();
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 5:
						system("cls");
						cin.ignore();
						print(tickets);
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 6:
						system("cls");
						cin.ignore();
						sort_by_theatre(tickets);
						printf("������!\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 7:
						system("cls");
						cin.ignore();
						sort_by_performance(tickets);
						printf("������!\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 8:
						system("cls");
						cin.ignore();
						sort_by_count(tickets);
						printf("������!\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 9:
						system("cls");
						cin.ignore();
						cout << "�������� ������ : ";
						cin.getline(ticket.theatre, 40);
						search_by_theatre(tickets, ticket.theatre);
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 10:
						system("cls");
						cin.ignore();
						cout << "�������� ��������� : ";
						cin.getline(ticket.performance, 40);
						search_by_performance(tickets, ticket.performance);
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 11:
						system("cls");
						cin.ignore();
						cout << "���� : ";
						cin >> date;
						ticket.date.d = atoi(date);
						if (ticket.date.d == 0)
						{
							cin.ignore();
							printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							cout << "����� : ";
							cin >> date;
							ticket.date.m = atoi(date);
							if (ticket.date.m == 0)
							{
								cin.ignore();
								printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
								scanf("%c", &back_to_menu);
								if (back_to_menu != 'y')
									return 0;
							}
							else
							{
								cout << "��� : ";
								cin >> date;
								ticket.date.y = atoi(date);
								if (ticket.date.y == 0)
								{
									cin.ignore();
									printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
									scanf("%c", &back_to_menu);
									if (back_to_menu != 'y')
										return 0;
								}
								else
								{
									search_by_date(tickets, ticket.date.d, ticket.date.m, ticket.date.y);
									printf("\n��������� � ����? (y/n)");
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
						printf("\n������!\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 13:
						system("cls");
						cin.ignore();
						cout << "����� : ";
						cin >> date;
						ticket.date.m = atoi(date);
						if (ticket.date.m == 0)
						{
							cin.ignore();
							printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							more_popular(tickets, ticket.date.m);
							cin.ignore();
							printf("\n������!\n��������� � ����? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						break;
					case 14:
						system("cls");
						cin.ignore();
						print_user();
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 15:
						system("cls");
						cin.ignore();
						cout << "�����: ";
						cin >> user.login;
						cout << "������ : ";
						cin >> user.psw;
						if (strlen(user.psw) < 6)
						{
							cin.ignore();
							cout << "����� ������ ������ ���� �� ����� 6 ��������.\n";
							printf("��������� � ����? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							add_user(user);
							cin.ignore();
							printf("\n������������ ������� ��������!��������� � ����? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						break;
					case 16:
						system("cls");
						cin.ignore();
						cout << "����� ������: ";
						cin >> index;
						cout << "�����: ";
						cin >> user.login;
						cout << "������ : ";
						cin >> user.psw;
						edit_user(user, index - 1);
						cin.ignore();
						printf("\n������ ������� �������������!��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 17:
						system("cls");
						cin.ignore();
						cout << "����� ������: ";
						cin >> index;
						delete_user(index - 1);
						cin.ignore();
						printf("\n������������ ������� ������!��������� � ����? (y/n)");
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
				printf("�������� ������ ��� �����!\n��������� � ����? (y/n)");
				scanf("%c", &back_to_menu);
				if (back_to_menu != 'y')
					return 0;
			}
			break;
		case 2:
			system("cls");
			printf("������� ����� : ");
			cin >> login;
			cout << "������� ������ : ";
			cin >> password;
			if (strlen(password) < 6)
			{
				cin.ignore();
				cout << "����� ������ ������ ���� �� ����� 6 ��������.\n";
				printf("��������� � ����? (y/n)");
				scanf("%c", &back_to_menu);
				if (back_to_menu != 'y')
					return 0;
			}
			else if (check_user(login, password))
			{
				while (user_menu != 10)
				{
					system("cls");
					printf("����\n1 - ������� ����\n");
					printf("2 - �������� ���� ������\n");
					printf("3 - ���������� �� �������� ������\n");
					printf("4 - ���������� �� �������� ���������\n");
					printf("5 - ���������� �� ���������� ��������� �������\n");
					printf("6 - ����� �� �������� ������\n");
					printf("7 - ����� �� �������� ���������\n");
					printf("8 - ����� �� ����\n");
					printf("9 - �������������� �������\n");
					printf("10 - �����\n");
					cin >> user_menu;
					switch (user_menu) // ����� ������ ���� ������������
					{
					case 1:
						system("cls");
						cin.ignore();
						tickets.clear();
						if (open_file_user(tickets))
						{
							cout << "������ ������� �������!";
						}
						else
						{
							cout << "���� � ������� �� ����������!";
						}
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 2:
						system("cls");
						cin.ignore();
						print(tickets);
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 3:
						system("cls");
						cin.ignore();
						sort_by_theatre(tickets);
						printf("������!\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 4:
						system("cls");
						cin.ignore();
						sort_by_performance(tickets);
						printf("������!\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 5:
						system("cls");
						cin.ignore();
						sort_by_count(tickets);
						printf("������!\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 6:
						system("cls");
						cin.ignore();
						cout << "�������� ������ : ";
						cin.getline(ticket.theatre, 40);
						search_by_theatre(tickets, ticket.theatre);
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 7:
						system("cls");
						cin.ignore();
						cout << "�������� ��������� : ";
						cin.getline(ticket.performance, 40);
						search_by_performance(tickets, ticket.performance);
						printf("\n��������� � ����? (y/n)");
						scanf("%c", &back_to_menu);
						if (back_to_menu != 'y')
							return 0;
						break;
					case 8:
						system("cls");
						cin.ignore();
						cout << "���� : ";
						cin >> date;
						ticket.date.d = atoi(date);
						if (ticket.date.d == 0)
						{
							cin.ignore();
							printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							cout << "����� : ";
							cin >> date;
							ticket.date.m = atoi(date);
							if (ticket.date.m == 0)
							{
								cin.ignore();
								printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
								scanf("%c", &back_to_menu);
								if (back_to_menu != 'y')
									return 0;
							}
							else
							{
								cout << "��� : ";
								cin >> date;
								ticket.date.y = atoi(date);
								if (ticket.date.y == 0)
								{
									cin.ignore();
									printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
									scanf("%c", &back_to_menu);
									if (back_to_menu != 'y')
										return 0;
								}
								else
								{
									search_by_date(tickets, ticket.date.d, ticket.date.m, ticket.date.y);
									printf("\n��������� � ����? (y/n)");
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
						cout << "����� : ";
						cin >> date;
						ticket.date.m = atoi(date);
						if (ticket.date.m == 0)
						{
							cin.ignore();
							printf("\n�������� ������ �����.\n��������� � ����? (y/n)");
							scanf("%c", &back_to_menu);
							if (back_to_menu != 'y')
								return 0;
						}
						else
						{
							more_popular(tickets, ticket.date.m);
							cin.ignore();
							printf("\n������!\n��������� � ����? (y/n)");
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