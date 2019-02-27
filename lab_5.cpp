// ConsoleApplication124.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>
#include <vector>

using namespace std;

void task1()// номер 6
/* Ввести произвольную строку и символ с клавиатуры. Вывести число раз, которое заданный символ встречается в строке. 
Определить первую и последнюю позицию, когда символ встречается в строке.*/
{
	string s;
	char t;
	cout << "enter a string" << endl;
	getline(cin, s);
	cout << "enter a value" << endl;
	cin >> t;
	int _count = count(s.begin(), s.end(), t);
	cout << _count << endl;
	cout << "The number of first appearance is->" << s.find(t) + 1 << endl << "The number of last appearsnce is->" << s.rfind(t) + 1 << endl;

}
void task2()//номер 8
//Ввести вектор чисел и значение степени. Вывести сумму степеней чисел.
{
	vector <int> s;
	int temp;
	cout << "Fill a vector" << endl;
	cin >> temp;
	s.push_back(temp);
	while ((temp = cin.get()) != '\n')
	{
		cin >> temp;
		s.push_back(temp);
	}
	cout << "Input value of a power" << endl;
	int p;
	cin >> p;
	for_each(s.begin(), s.end(), [p](int &n) {n = pow(n, p);});
	int a = accumulate(s.begin(), s.end(), 0);
	cout << "Sum of the squares of the numbers is equal to " << a << endl;
}

void task3()// номер 14
/*На одометре (прибор для измерения пробега автомобиля) число 15951. Через 2 часа езды он показывает другое число палиндром. Какова средняя скорость? 
Написать программу, позволяющую задать новое значение на одометре (новое число должно быть больше начального (15951) и быть палиндромом) и вычисляющую среднюю скорость.*/
{
	int n_int;
	cout << "Input a number" << endl;
	cin >> n_int;
	int r = n_int;
	int result;
	for (int i = 0;i<10000000;i++)
	{
		n_int = n_int + 1;
		char n_char[256] = "";
		_itoa_s(n_int, n_char, 10);
		string temp = n_char;
		if (equal(temp.begin(), temp.end(), temp.rbegin()))
		{
			result = n_int;
			break;
		}
	}
	cout <<"The nearest palindrome is "<< result << endl;
	cout <<"The average velocity is "<< (result - r) / 2<<endl;

}

int main()
{
	//task1();
	//task2();
	//task3();

	

    return 0;
}

