#include "Point.h"
#include "UniquePoint.h"
#include "vld.h"

using namespace std;

int main()
{
	Point a1(2,5);
	Point a2(2, 5);
	if (a1<a2)
		cout << "<" << endl;
	if (a1>a2)
		cout << ">" << endl;
	if (a1<=a2)
		cout << "<=" << endl;
	if (a1>=a2)
		cout << ">=" << endl;
	Point a3 (a1);
	Point a4 (4, 4);
	a2 = a4;
	UniquePoint uniq (3, 9);
	Point* c = uniq.get();
	Point* y = uniq.release();
	a3.printPoint();
	a2.printPoint();
	delete y;
	system ("pause");
	return 0;
}