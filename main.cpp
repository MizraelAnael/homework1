#include <iostream>;
#include "Task 1.h";
#include "Task 2.h";
#include "Task 3.h";


using namespace std;

int main()
{
	cout << "��ࢠ� �����:" << endl; 
	// �ணࠬ��, ����� ����砥� �� ���짮��⥫� ��� �᫠ � �뢮��� �� �� �࠭. �㬬�ࢮ���� ������ ��室��� � �⤥�쭮� �㭪樨

	int a = 0;
	int b = 0;
	cout << "������ 1-� �᫮" << endl;
	cin >> a;
	cout << "������ 2-� �᫮" << endl;
	cin >> b;
	cout << "�� ����� " << a << " � " << b << endl;
	cout << "�� �㬬� ࠢ�� " << sum (a, b) << endl;
	cout << endl;

	cout << "���� �����:" << endl;
	// ��� ���ᨢ �� 楫�� �ᥫ. ������ ��㭪��, ����� ��⠥� � ��� ������⢮ �㫥�

	int arr[] = {0, 20, 15, 6, 0, 10, 36, 89, 90, 45, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "����� ���ᨢ�:" << endl;
		for ( int i = 0; i < size; i++ )
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	shet_nul (arr, size);
	cout << endl;

	cout << "����� �����:" << endl;
	// ��� ���ᨢ �� ᨬ����� (��ப�). �������� � ��� ���-�� �஡���� � ������⢮ ᫮�

	char str[] = " �஢�ઠ  ࠡ��� �ணࠬ��, �����   �����뢠��  ������⢮ �஡����";
	cout << "���� ��ப�: " << str << endl;
	cout << "������⢮ �஡����: " << kol_prob (str, sizeof(str)) << endl;
	char str2[200] = "/0";
	char str3[200] = "/0";
	strcpy (str3, str);
	while ( doubleprob (str3) > 0)
		{
			del_doubleprob(str3, str2);
			strcpy (str3, str2);
		}
	cout << "��ப� ��� ��譨� �஡����: " << str2 << endl;
	int n = kol_prob (str2, sizeof(str2));
	cout << "������⢮ ᫮�: " << kol_slov (str2, n, sizeof(str2)) << endl;
	system ("pause");
}