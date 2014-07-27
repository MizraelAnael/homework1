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
	cout << "Удалим первый и последний элементы" << endl;
	List1.removeFirstElement ();
	List1.removeLastElement ();
	List1.GetInfoList ();
	cout << "Первый элемент: " << List1.GetFirstElement() << endl;
	cout << "Последний элемент: " << List1.GetLastElement() << endl;
	cout << "Количество элементов: " << List1.GetCountElements() << endl;
	system ("pause");
}
