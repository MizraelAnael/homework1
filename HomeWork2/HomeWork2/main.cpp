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
	cout << "Удалим 3-й элемент" << endl;
	List1.Remove(3);
	List1.GetInfoList();
	cout << "Первый элемент: " << List1.GetFirstElement() << endl;
	cout << "Последний элемент: " << List1.GetLastElement() << endl;
	cout << "Количество элементов: " << List1.GetCountElements() << endl;
	system ("pause");
}
