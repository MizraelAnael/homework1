#include "Task 2.h";
#include <iostream>;

using namespace std;

int shet_nul (int* arr, int size)
{
	int nul = 0;
	for ( int i = 0; i < size; i++ )
		{
			if (arr[i] == 0)
				{
					nul++;
				}
		}
	cout << "������⢮ �㫥� � ���ᨢ�: " << nul << endl;
	return 0;
}
