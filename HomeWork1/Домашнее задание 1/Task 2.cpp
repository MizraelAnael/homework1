#include "Task 2.h"
#include <iostream>

using namespace std;

int shet_nul ( int* arr, int size )
{
	int nul = 0;
    for ( int i = 0; i < size; i++ )
		{
			if ( arr[i] == 0 )
				{ 
					nul++;
                }
        }
    return nul;
}

void task2()
{
	cout << "Вторая задача:" << endl;
    // Дан массив из целых чисел. Написать функцию, которая считает в нем количество нулей

    int arr[] = {0, 20, 15, 6, 0, 10, 36, 89, 90, 45, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Данные массива:" << endl;
    for ( int i = 0; i < size; i++ )
		{ 
			cout << arr[i] << " ";
        }
    cout << endl;
    cout << "Количество нулей в массиве: " << shet_nul ( arr, size ) << endl;
    cout << endl;
}
