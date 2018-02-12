#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <stdint.h>
#include <time.h>
#include "prototipy.h"
#include <stdarg.h>


using namespace std;

int q;
//enum type_number { positive, negative, all };

//#define colCount 5

void main(int args, char*argv[])

{
	setlocale(LC_ALL, "Russian");
	srand(time(0));

	if (args > 1)
	{
		cout << endl;
		for (int i = 0; i < args; i++)
		{
			cout << argv[1];
		}
		cout << endl;
	}

	int nz;

	do
	{
		cout << "Введите номер задания: ";
		cin >> nz;
		switch (nz)
		{
		case 1:
		{
			//1.	Получить все четырехзначные счастливые номера.Счастливым называется номер, у которого 
			//сумма первых двух цифр номера равна сумме последних двух цифр.Использовать функцию для расчета
			//суммы цифр двухзначного числа

			char mas[5];
			int h;
			cout << "введите четырехзначное число, чтобы узнать является ли оно счастивым: ";
			cin >> mas;
			//mas[5] = '\0';
			h = happy(mas);

			if (h == 1)
				cout << "это счастливое число\n";
			else
				cout << "это не счастливое число\n";



		}break;

		case 2:
		{
			//2.	Отсортировать по убыванию заданный массив чисел, используя функцию сортировки.
			int mas[10];
			create(mas, 10, 10, 20, positive);
			print_arr(mas, 10);
			sort(mas, 10, 2);
			cout << "после сортировки\n";
			print_arr(mas, 10);

		}break;

		case 3:
		{
			//3.	Отсортировать по возрастанию заданный массив чисел, исключив отрицательные числа.Использовать функцию сортировки.
			int mas[10];
			create(mas, 10, 10, 20, negative);
			print_arr(mas, 10);
			sort(mas, 10, 2);
			cout << "после сортировки\n";
			print_arr(mas, 10);
		}break;

		case 4:
		{
			//4.	Задан одномерный массив из 16 элементов.Сформировать двухмерный массив 4×4, используя функцию преобразования любого 
			//одномерного массива в двухмерный массив размерностью n×n с добавлением нулевых элементов.
			int mas[16], mas1[4][4];
			create(mas, 16, 10, 80, positive);
			print_arr(mas, 16);

			cout << endl;
			arr_d(mas, mas1, 16);
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					cout << mas1[i][j] << "\t";
				}
				cout << endl;

			}
		}break;

		case 5:
		{
			int mas[5], s;
			create(mas, 5, 0, 50, positive);
			print_arr(mas, 5);
			s = sum(5, *(mas), *(mas + 1), *(mas + 2), *(mas + 3), *(mas + 4));
			cout << s << endl;
		}break;

		case 6:
		{
			//2.	Описать процедуру Smooth(A, N), заменяющую каждый элемент вещественного массива A размера N на его среднее арифметическое 
			//со своими соседями("сглаживание массива").Массив A — входной и выходной параметр, N — входной параметр.С помощью этой процедуры 
			//выполнить пятикратное сглаживание данного массива A размера N, выводя на экран результаты каждого сглаживания.

			//	Ввести с клавиатуры массив, состоящий из n строк и m столбцов.Создать библиотеку, в которой будет содержаться функция, которая
			//производит вычисления согласно заданию, приведенному в таблице.

			int mas[10];
			int k = 5;

			create(mas, 10, 10, 90, positive);
			print_arr(mas, 10);

			smooth(mas, 10, &k);
			print_arr(mas, 10);

		}break;

		case 7:
		{
			//Ввести с клавиатуры массив, состоящий из n строк и m столбцов.Создать библиотеку, в которой будет содержаться функция, которая производит 
			//вычисления согласно заданию, приведенному в таблице.
			int mas[7][4], col = 0, row = 0, max, s;

			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					mas[i][j] = 10 + rand() % 50;
					cout << mas[i][j] << "\t";
				}
				cout << endl;
			}

			s = sum_ind(mas, 4, col, row, max);
			cout << s << ", " << col << ", " << row << ", " <<max<< endl;
			cout << "сумма индексов максимального элемента\n";
		}break;

		case 8:
		{
			cout.precision(2);
			//Вычислить среднее арифметическое элементов матрицы.
			double mas[8][colCount];
			int result;

			createMatrix(mas,8,10.,60.,positive);

			sr_arif(mas, 8);

			print_matrix(mas, 8);
			//cout << "сред арифметическое: " << result << endl;

		}break;

		case 9:
		{
			//Сформировать одномерный массив как сумму элементов столбцов матрицы.
			int mas[4][5], b[colCount] = { 0 };
			createMatrix(mas, 4, 10, 60, positive);
			print_matrix(mas, 4);


			twoInOne(mas, 4, b);
			//print_arr(b, colCount);



		}break;

		}


		cout << "Хотите продолжить 1/0?";
		cin >> q;


		switch (q)
		{
		case 1:
			system("cls");
			break;
		default:
		{
			cout << "ошибка" << endl;
		}
		}
	} while (nz > 0);


}