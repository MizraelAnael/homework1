#include "Task 2.h";
#include <iostream>;

using namespace std;

int shet_nul (int* arr, int size)
{
        int nul = 0;
        for ( int i = 0; i < size; i++ )
                { // здесь лишняя табуляция. Можно все строки сдвинуть влево.
                        if (arr[i] == 0)
                                { // здесь лишняя табуляция. Можно все строки сдвинуть влево.
                                        nul++;
                                }
                }
        return nul;
}

int task2()
{
        cout << "Вторая задача:" << endl;
        // Дан массив из целых чисел. Написать функцию, которая считает в нем количество нулей

        int arr[] = {0, 20, 15, 6, 0, 10, 36, 89, 90, 45, 7};
        int size = sizeof(arr) / sizeof(arr[0]);
        cout << "Данные массива:" << endl;
        // здесь лишняя табуляция. Можно весь цикл сдвинуть влево. Просто так удобнее читать код.
                for ( int i = 0; i < size; i++ )
                { // а вот отступы впорядке.
                        cout << arr[i] << " ";
                }
                cout << endl;
        cout << "Количество нулей в массиве: " << shet_nul (arr, size) << endl;
        cout << endl;
        return 0;
}
