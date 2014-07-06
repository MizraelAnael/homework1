#include <iostream>;
#include "Task 3.h";

using namespace std;

int getSpaceCount ( char* str, int size_str ) //��।���� ���-�� �஡����
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

int getDoubleSpaceCount (char* str) // ������� ���稪, ����� �����뢠��, �� ���� ��� �஡��� �����
        {
                // �� ���� ⥡� �㦭� ⮫쪮 㧭��� ���� �� ����� ���騥 �஡��� ��� ���.
                // ��� �⮣� �� �㦭� ᮧ������ ���稪. ����� ������ bool ��६�����.
                char* temp = str;
                int i = 0;
                while ( *temp != '\0' )
                        {
                                if ( *temp == ' ' && *(temp+1) == ' ')
                                        {
                                                i++; // ��� 㦥 ����� �������� �㭪��.
                                        }
                                temp++;
                        }
        return i;
        }

void deleteDoubleSpaces ( char* str1, char* str2 ) // ������ ��譨� �஡��
        {
                char* temp = str1; // � �ਭ樯� ��譨� 㪠��⥫� �������� �� �㦭�.
                while ( *temp != '\0' )
                        {
                                // ���-� ��࠭��... 
                                // ������:
                                // 1. ����稫� ⥪�騩 ᨬ���.
                                // 2. �᫨ �।��騩 ⮦� �஡��, � ⥪�騩 �� �����㥬, � ���६����㥬 ⮫쪮 㪠��⥫� �� ��室��� ��ப�.
                                // 3. �᫨ �।��騩 �� �஡��, � ⥪�騩 �����㥬, � ���६����㥬 ��� 㪠��⥫�.
                                // ����, �᫨ ࠡ�⠥�, � ��⠢��. �� �� ����� �஢�ਬ.
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

int getWordCount ( char* str, int probeli, int size ) // ��⠥� ���-�� ᫮�
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
        cout << "����� �����:" << endl;
        // ��� ���ᨢ �� ᨬ����� (��ப�). �������� � ��� ���-�� �஡���� � ������⢮ ᫮�

        char str[] = " �஢�ઠ  ࠡ��� �ணࠬ��, �����   �����뢠��  ������⢮ �஡����";
        cout << "���� ��ப�: " << str << endl;
        cout << "������⢮ �஡����: " << getSpaceCount ( str, sizeof(str) ) << endl;
        char str2[200] = "/0";
        char str3[200] = "/0";
        strcpy (str3, str);
        while ( getDoubleSpaceCount (str3) > 0 )
                {
                        deleteDoubleSpaces ( str3, str2 );
                        strcpy ( str3, str2 );
                }
        cout << "��ப� ��� ��譨� �஡����: " << str2 << endl;
        int n = getSpaceCount ( str2, sizeof(str2) );
        cout << "������⢮ ᫮�: " << getWordCount ( str2, n, sizeof(str2) ) << endl;
        return 0;
}