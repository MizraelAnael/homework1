#include <iostream>
#include "List.h"

using namespace std;

int main()
{
	List List1;
	List1.AddFirstElement(20);
	List1.AddLastElement (14);
	List1.EnterElement(74, 2);
	List1.EnterElement(4, 2);
	List1.EnterElement(7, 2);
	List1.GetInfoList();
	cout << "������ 3-� �����" << endl;
	List1.Remove(3);
	List1.GetInfoList();
	cout << "���� �����: " << List1.GetFirstElement() << endl;
	cout << "��᫥���� �����: " << List1.GetLastElement() << endl;
	cout << "������⢮ ����⮢: " << List1.GetCountElements() << endl;
	system ("pause");
}
