#include <iostream>
#include "Task 3.h"

using namespace std;

int getSpaceCount ( char* str )  // Определяет кол-во пробелов вообще
{
	int prob = 0;
    while ( *str != '\0' )
		{
			if (*str == ' ')
				{
					prob = prob++;
                }
            *str++;
        }
    return prob;
}

int getSpaceCount2 ( char* str )  // Определяет кол-во пробелов, игнорируя двойные пробелы
{
	int prob = 0;
    while ( *str != '\0' )
		{
			if (*str == ' ' && *(str - 1) == ' ')
				{
					*str++;					
                }
			else
				{
					if (*str == ' ')
						{
							prob++;
							*str++;
						}
					else *str++;
				}
        }
    return prob;
}

int getWordCount ( char str[] ) // Считает кол-во слов
{
	int slova = getSpaceCount2 ( str );
    if ( str[0] == '\0' )
		{
			slova--;
		}
	if ( str[0] == ' ') 
		{
			slova--;
        }
	if ( str[strlen (str)-1] == ' ')
		{
			slova--;
        }
    return ++slova;
}

void task3()
{
	cout << "Третья задача:" << endl;
    // Дан массив из символов (строка). Подсчитать в ней кол-во пробелов и количество слов
	
	char str[] = "Предложение для  проверки тестом";
    cout << "Дана строка: " << str << endl;
    cout << "Количество пробелов: " << getSpaceCount ( str ) << endl; 
	cout << "Количество слов: " << getWordCount ( str ) << endl;
}