#include "Task 1.h";
#include <iostream>;

using namespace std;

int sum (int a, int b)
{
	return a+b;
}

int task1()
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
	return 0;
}