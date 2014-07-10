#include <iostream>
#include "Task 3.h"

using namespace std;

int getSpaceCount ( char* str )  // ��।���� ���-�� �஡���� �����
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

int getSpaceCount2 ( char* str )  // ��।���� ���-�� �஡����, �������� ������ �஡���
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

int getWordCount ( char str[] ) // ��⠥� ���-�� ᫮�
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
	cout << "����� �����:" << endl;
    // ��� ���ᨢ �� ᨬ����� (��ப�). �������� � ��� ���-�� �஡���� � ������⢮ ᫮�
	
	char str[] = "�।������� ���  �஢�ન ��⮬";
    cout << "���� ��ப�: " << str << endl;
    cout << "������⢮ �஡����: " << getSpaceCount ( str ) << endl; 
	cout << "������⢮ ᫮�: " << getWordCount ( str ) << endl;
}