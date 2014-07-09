#include <iostream>
#include "Task 3.h"

using namespace std;

int getSpaceCount ( char* str )  // ��।���� ���-�� �஡����
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

bool getDoubleSpace ( char* str ) // �஢���� �஢��� �� ����稥 ������� �஡����
{             
	bool i = false;
    while ( *str != '\0' )
		{
			if ( *str == ' ' && *(str+1) == ' ')
				{
					i = true; // ��� 㦥 ����� �������� �㭪��. (��� ��� �������� �㭪��, �᫨ ��� �㦭� ������� 㪠��⥫� �� ��ப�, �⮡� 横� 襫?)
                }
            str++;  
        }
    return i;
}

void deleteDoubleSpaces ( char* str1, char* str2 ) // ������ ��譨� �஡��
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

int getWordCount ( char str[] ) // ��⠥� ���-�� ᫮�
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
	cout << "����� �����:" << endl;
    // ��� ���ᨢ �� ᨬ����� (��ப�). �������� � ��� ���-�� �஡���� � ������⢮ ᫮�
	
	char str[] = "�।������� ���  �஢�ન ��⮬";
    cout << "���� ��ப�: " << str << endl;
    cout << "������⢮ �஡����: " << getSpaceCount ( str ) << endl; 
    cout << "������⢮ ᫮�: " << getWordCount ( str ) << endl;
}