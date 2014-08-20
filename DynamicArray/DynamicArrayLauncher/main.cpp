#include "DynamicArray.h"
#include <iostream>
//#include "vld.h"

using namespace std;

int main()
{
	DynamicArray d;
	d.push_back(2);
	d.push_back(5);
	d.push_back(7);
	d.pop_back();
	d.pop_back();
	d.push_back(10);
	d.push_back(16);
	d.printArray();
	DynamicArray c;
	c.push_back(16);
	c.push_back(16);
	c.push_back(16);
	c = d;
	cout << endl;
	DynamicArray dynArr;
	int x = 0;
	std::cin >> x;
	if (std::cin.good())
       dynArr.push_back(x);
	else
		throw std::runtime_error ("You should enter only numbers");;
	system ("pause");
	return 0;
}