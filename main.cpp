#include <iostream>;
#include "Task 1.h";
#include "Task 2.h";
#include "Task 3.h";


using namespace std;

int main()
{
	cout << "Первая задача:" << endl; 
	// Программа, которая получает от пользователя два числа и выводит их на экран. Суммирвоание должно проходить в отдельной функции

	int a = 0;
	int b = 0;
	cout << "Введите 1-е число" << endl;
	cin >> a;
	cout << "введите 2-е число" << endl;
	cin >> b;
	cout << "Вы ввели " << a << " и " << b << endl;
	cout << "Их сумма равна " << sum (a, b) << endl;
	cout << endl;

	cout << "Вторая задача:" << endl;
	// Дан массив из целых чисел. Написат ьфункцию, которая считает в нем количество нулей

	int arr[] = {0, 20, 15, 6, 0, 10, 36, 89, 90, 45, 7};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout << "Данные массива:" << endl;
		for ( int i = 0; i < size; i++ )
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	shet_nul (arr, size);
	cout << endl;

	cout << "Третья задача:" << endl;
	// Дан массив из символов (строка). Подсчитать в ней кол-во пробелов и количество слов

	char str[] = " Проверка  работы программы, которая   показывает  количество пробелов";
	cout << "Дана строка: " << str << endl;
	cout << "Количество пробелов: " << kol_prob (str, sizeof(str)) << endl;
	char str2[200] = "/0";
	char str3[200] = "/0";
	strcpy (str3, str);
	while ( doubleprob (str3) > 0)
		{
			del_doubleprob(str3, str2);
			strcpy (str3, str2);
		}
	cout << "Строка без лишних пробелов: " << str2 << endl;
	int n = kol_prob (str2, sizeof(str2));
	cout << "Количество слов: " << kol_slov (str2, n, sizeof(str2)) << endl;
	system ("pause");
}