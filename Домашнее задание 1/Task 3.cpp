#include <iostream>
#include "Task 3.h"

using namespace std;

int getSpaceCount ( char* str, int size_str ) //Определяет кол-во пробелов
	{
		int i = 0;
		int prob = 0;
        while ( i != size_str )
			{
				if (str[i] == ' ')
					{
						prob = prob++;
                    }
                i++;
            }
        return prob;
    }

bool getDoubleSpace (char* str) // Проводит проверку на наличие двойных пробелов
	{             
		char* temp = str;
        bool i = false;
        while ( *temp != '\0' )
			{
				if ( *temp == ' ' && *(temp+1) == ' ')
					{
						i = true; // тут уже можно завершать функцию. (Как тут завершить функцию, если нам нужно двигать указатель по строке, чтобы цикл шел?)
                    }
                temp++;  
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

int getWordCount ( char* str, int probeli, int size ) // Считает кол-во слов
	{
		int slova = probeli;
        if ( str[0] == '\0' )
			{
				slova--;
			}
		if ( str[0] == ' ') 
			{
				slova--;
            }
		if ( str[size-1] == ' ')
			{
				slova--;
            }
        return ++slova;
	}

void task3()
{
	cout << "Третья задача:" << endl;
    // Дан массив из символов (строка). Подсчитать в ней кол-во пробелов и количество слов
	
	char str[] = "Текст проверки ";
    cout << "Дана строка: " << str << endl;
    cout << "Количество пробелов: " << getSpaceCount ( str, strlen (str) ) << endl; //sizeof
    char str3[200] = "/0";
	char str2[200] = "/0";
	strcpy (str2, str);
	if ( getDoubleSpace (str2) == false )
		{
			strcpy (str3, str );
		}
	else
		{
			while ( getDoubleSpace (str2) != false )
				{
					deleteDoubleSpaces ( str2, str3 );
					strcpy (str2, str3 );
				}
			cout << "Строка без лишних пробелов: " << str3 << endl;
		}
	cout << "Количество слов: " << getWordCount ( str3, getSpaceCount ( str3, strlen (str3) ), strlen(str3) ) << endl;     //sizeof  
}