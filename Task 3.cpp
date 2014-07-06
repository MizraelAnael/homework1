#include <iostream>;
#include "Task 3.h";

using namespace std;

int kol_prob (char* str, int size_str) //Определяет кол-во пробелов
	{
		int i = 0;
		int prob = 0;
		while (i != size_str)
			{
				if (str[i] == ' ')
				{
					prob = prob++;
				}
			i++;
			}
		return prob;
	}

int doubleprob (char* str) // Создает счетчик, который показывает, что есть два пробела подряд
	{
		char* temp = str;
		int i = 0;
		while (*temp != '\0')
			{
				if (*temp == ' ' && *(temp+1) == ' ')
					{
						i++;
					}
				temp++;
			}
	return i;
	}

void del_doubleprob (char* str1, char* str2) // Удаляет лишний пробел
	{
		char* temp = str1;
		while (*temp != '\0')
			{
				if (*temp == ' ' && *(temp+1) == ' ')
					{
						temp++;
						*str2 = *temp;
						str2++;
						temp++;
					}
				else 
					{
						*str2 = *temp;
						temp++;
						str2++;
					}
			}
	*str2 = '\0';
	}

int kol_slov (char* str, int probeli, int size) // Считает кол-во слов
	{
		int slova = probeli;
		if ( str[0] == ' ') 
		{
			slova = slova - 1;
		}
	if ( str[size] == ' ')
		{
			slova = slova - 1;
		}
	return ++slova;
	}

int task3()
{
	cout << "Третья задача:" << endl;
	// Дан массив из символов (строка). Подсчитать в ней кол-во пробелов и количество слов

	char str[] = " Проверка  работы программы, которая   показывает  количество пробелов";
	cout << "Дана строка: " << str << endl;
	cout << "Количество пробелов: " << kol_prob (str, sizeof(str)) << endl;
	char str2[200] = "/0";
	char str3[200] = "/0";
	strcpy (str3, str);
	while ( doubleprob (str3) > 0)
		{
			del_doubleprob(str3, str2);
			strcpy (str3, str2);
		}
	cout << "Строка без лишних пробелов: " << str2 << endl;
	int n = kol_prob (str2, sizeof(str2));
	cout << "Количество слов: " << kol_slov (str2, n, sizeof(str2)) << endl;
	return 0;
}