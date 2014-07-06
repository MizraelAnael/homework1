#include "Task 1.h";
#include <iostream>;

using namespace std;

int sum (int a, int b)
{
	return a+b;
}

int task1()
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
	return 0;
}