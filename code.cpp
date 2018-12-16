#include "stdafx.h"
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int** zapolnenie(int** arr, int poruadok)
{
	arr = new int *[poruadok];
	for (int i = 0; i < poruadok; i++)
	{
		arr[i] = new int[poruadok];
	}

	for (int i = 0; i < poruadok; i++)
	{
		for (int j = 0; j < poruadok; j++)
		{
			printf("Введите элемент матрицы %d %d\n", i + 1, j + 1);
			while (scanf_s("%d", &arr[i][j]) != 1)
			{
				printf("Введено некорректное значение. Попробуйте еще раз:");
				scanf_s("%*[^\n]");
				scanf_s("%*c");
			}
		}
	}
	return arr;
}

int** romdom(int** arr, int poruadok)
{
	arr = new int *[poruadok];
	for (int i = 0; i < poruadok; i++)
	{
		arr[i] = new int[poruadok];
	}

	for (int i = 0; i < poruadok; i++)
	{
		for (int j = 0; j < poruadok; j++)
		{
			arr[i][j] = rand();
		}
	}
	return arr;
}

int** obrabotka(int**arr, int poruadok)
{
	int sector1 = 0;
	int sector2 = 0;
	int firstX = 0;
	int firstY = 0;
	int secondY = 0;
	int secondX = 0;
	int zamena = 0;

	printf_s("Какой сектор матрицы вы хотите заменить?");
	while (scanf_s("%d", &sector1) != 1 || sector1 > 4 || sector1 < 1)
	{
		printf("Введено некорректное значение. Попробуйте еще раз:");
		scanf_s("%*[^\n]");
		scanf_s("%*c");
	}

	printf_s("На какой сектор матрицы вы хотите заменить?");
	while (scanf_s("%d", &sector2) != 1 || sector1 > 4 || sector1 < 1)
	{
		printf("Введено некорректное значение. Попробуйте еще раз:");
		scanf_s("%*[^\n]");
		scanf_s("%*c");
	}

	for (int i = 0; i < poruadok / 2; i++)
	{
		for (int j = 0; j < poruadok / 2; j++)
		{
			switch (sector1)
			{
			case 1:
				firstX = j + poruadok / 2;
				firstY = i;
				break;
			case 2:
				firstX = j + poruadok / 2;
				firstY = i + poruadok / 2;
				break;
			case 3:
				firstX = j;
				firstY = i + poruadok / 2;
				break;
			case 4:
				firstX = j;
				firstY = i;
				break;
			}
			switch (sector2)
			{
			case 1:
				secondX = j + poruadok / 2;
				secondY = i;
				break;
			case 2:
				secondX = j + poruadok / 2;
				secondY = i + poruadok / 2;
				break;
			case 3:
				secondX = j;
				secondY = i + poruadok / 2;
				break;
			case 4:
				secondX = j;
				secondY = i;
				break;
			}
			zamena = arr[firstY][firstX];
			arr[firstY][firstX] = arr[secondY][secondX];
			arr[secondY][secondX] = zamena;
		}
	}
	return arr;
}
int main()
{
	setlocale(LC_ALL, "rus");

	srand(time(0));
	int menu = 0;
	int **arr = NULL;
	int poruadok = 0;
	int vvod_dan = 0;

	do
	{
		printf_s("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
		printf_s("| Меню пользователя:                    |\n");
		printf_s("|1)Ввод массива                         |\n");
		printf_s("|2)Обработка данных                     |\n");
		printf_s("|3)Вывод массива на экран               |\n");
		printf_s("|4)Заполнение массива случайными числами|\n");
		printf_s("|5)Выход                                |\n");
		printf_s("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");

		while (scanf_s("%d", &menu) != 1 || menu < 1 || menu > 5)
		{
			printf("Введено некорректное значение. Попробуйте еще раз:");
			scanf_s("%*[^\n]");
			scanf_s("%*c");
		}

		switch (menu)
		{
		case 1:
			for (int i = 0; i < poruadok; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;

			printf("Введите порядок матрицы: ");
			while (scanf_s("%d", &poruadok) != 1 || poruadok % 2 != 0)
			{
				printf("Введено некорректное значение. Попробуйте еще раз:");
				scanf_s("%*[^\n]");
				scanf_s("%*c");
			}
			arr = zapolnenie(arr, poruadok);

			vvod_dan = 1;
			break;

		case 2:

			if (vvod_dan != 1)
				printf("Неверный пункт меню\n");
			else
			{
				arr = obrabotka(arr, poruadok);
			}
			break;

		case 3:
			if (vvod_dan != 1)
				printf("Неверный пункт меню\n");
			for (int i = 0; i < poruadok; i++)
			{
				for (int j = 0; j < poruadok; j++)
					printf("%d  ", arr[i][j]);
				printf("\n");
			}
			break;

		case 4:
			for (int i = 0; i < poruadok; i++)
			{
				delete[] arr[i];
			}
			delete[] arr;

			printf("Введите порядок матрицы: ");
			while (scanf_s("%d", &poruadok) != 1 || poruadok % 2 != 0)
			{
				printf("Введено некорректное значение. Попробуйте еще раз:");
				scanf_s("%*[^\n]");
				scanf_s("%*c");
			}

			arr = romdom(arr, poruadok);
			vvod_dan = 1;

		}
	} while (menu != 5);

	for (int i = 0; i < poruadok; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}
