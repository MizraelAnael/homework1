#include <iostream>
#include "Task 3.h"

using namespace std;

int getSpaceCount ( char* str )  // Определяет кол-во пробелов
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

bool getDoubleSpace ( char* str ) // Проводит проверку на наличие двойных пробелов
{             
	bool i = false;
    while ( *str != '\0' )
		{
			if ( *str == ' ' && *(str+1) == ' ')
				{
					i = true; // тут уже можно завершать функцию. (Как тут завершить функцию, если нам нужно двигать указатель по строке, чтобы цикл шел?)
                }
            str++;  
        }
    return i;
}

void deleteDoubleSpaces ( char* str1, char* str2 ) // Удаляет лишний пробел
{
	while ( *str1 != '\0' )
		{
			if ( *str1 == ' ' && *(str1-1) == ' ' )
				{
					str1++;
                }
            else 
                {
                    *str2 = *str1;
                    str1++;
                    str2++;
                }
        }
    *str2 = '\0';
}

int getWordCount ( char str[] ) // Считает кол-во слов
{
	char str2[200] = "/0";
	if ( getDoubleSpace (str) == false )
		{
			strcpy (str2, str );
		}
	else
		{
			while ( getDoubleSpace (str) != false )
				{
					deleteDoubleSpaces ( str, str2 );
					strcpy (str, str2 );
				}			
		}
	int slova = getSpaceCount ( str2 );
    if ( str2[0] == '\0' )
		{
			slova--;
		}
	if ( str2[0] == ' ') 
		{
			slova--;
        }
	if ( str2[strlen (str2)-1] == ' ')
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