#include <iostream>;
#include "Task 3.h";

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

int getDoubleSpaceCount (char* str) // Создает счетчик, который показывает, что есть два пробела подряд
        {
                // По идее тебе нужно только узнать есть ли подряд идущие пробелы или нет.
                // Для этого не нужно создавать счетчик. Можно завести bool переменную.
                char* temp = str;
                int i = 0;
                while ( *temp != '\0' )
                        {
                                if ( *temp == ' ' && *(temp+1) == ' ')
                                        {
                                                i++; // тут уже можно завершать функцию.
                                        }
                                temp++;
                        }
        return i;
        }

void deleteDoubleSpaces ( char* str1, char* str2 ) // Удаляет лишний пробел
        {
                char* temp = str1; // В принципе лишний указатель заводить не нужно.
                while ( *temp != '\0' )
                        {
                                // Как-то странно... 
                                // Алгоритм:
                                // 1. Получили текущий символ.
                                // 2. Если предыдущий тоже пробел, то текущий не копируем, и инкрементируем только указатель на исходную строку.
                                // 3. Если предыдущий не пробел, то текущий копируем, и инкрементируем оба указателя.
                                // Хотя, если работает, то оставляй. Мы это позже проверим.
                                if ( *temp == ' ' && *(temp+1) == ' ' )
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

int getWordCount ( char* str, int probeli, int size ) // Считает кол-во слов
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
        cout << "Количество пробелов: " << getSpaceCount ( str, sizeof(str) ) << endl;
        char str2[200] = "/0";
        char str3[200] = "/0";
        strcpy (str3, str);
        while ( getDoubleSpaceCount (str3) > 0 )
                {
                        deleteDoubleSpaces ( str3, str2 );
                        strcpy ( str3, str2 );
                }
        cout << "Строка без лишних пробелов: " << str2 << endl;
        int n = getSpaceCount ( str2, sizeof(str2) );
        cout << "Количество слов: " << getWordCount ( str2, n, sizeof(str2) ) << endl;
        return 0;
}