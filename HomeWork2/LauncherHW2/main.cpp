#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	ListOfElement List1;	
	List1.AddFirstElement (20);
	List1.AddLastElement (14);
	List1.AddLastElement (15);
	List1.AddFirstElement (4);
	List1.GetInfoList ();
	cout << "������ ���� � ��᫥���� ������" << endl;
	List1.removeFirstElement ();
	List1.removeLastElement ();
	List1.GetInfoList ();
	cout << "���� �����: " << List1.GetFirstElement() << endl;
	cout << "��᫥���� �����: " << List1.GetLastElement() << endl;
	cout << "������⢮ ����⮢: " << List1.GetCountElements() << endl;
	system ("pause");
}
