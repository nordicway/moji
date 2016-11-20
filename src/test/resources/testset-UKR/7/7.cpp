#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>

using namespace std;

void show_matrixs(int** matrix2, int** matrix1, int m, int n)
{

	puts("Adjacency matrix: "); //вывод матрицы смежности
	cout << setw(5) << "u1";
	for (int i = 1; i < n; i++)
		cout << setw(3) << 'u' << i + 1;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << 'v' << setw(1) << i + 1;
		for (int j = 0; j < n; j++)
			cout << setw(4) << matrix1[i][j];
		cout << endl;
	}
	cout << endl;

	puts("Intsidance matrix: "); //вывод матрицы инцидентности
	cout << setw(5) << "e1";
	for (int i = 1; i < m; i++)
		cout << setw(4) << 'e' << i + 1;
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << 'v' << setw(1) << i + 1;
		for (int j = 0; j < m; j++)
		{
			cout  << setw(4) <<matrix2[i][j];
		}
		cout << endl;
	}
}
void save_matrixs(int** matrix2, int** matrix1, int m, int n)
{
	char adjf[50], ints[50];
	puts("Input the name of file to save adjacency matrix:");
	cin.ignore();
	cin.getline(adjf, 50);
	ofstream out(adjf);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			out << matrix1[i][j];
			if (j != n - 1)
				out << ' ';
		}
		if (i != n - 1)
			out << endl;
	}
	out.close();
	out.clear();
	puts("Input the name of file to save intsidance matrix:");
	cin.getline(ints, 50);
	out.open(ints);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			out << matrix2[i][j];
			if (j != m - 1)
				out << ' ';
		}
		if (i != n - 1)
			out << endl;
	}
}
void main()
{
	int n, m, v, u, i, j;
	char filename[50];

	puts("Input file name to open: ");
	cin.getline(filename, 50);;
	ifstream file(filename);
	if (file.is_open())
	{
		file >> n >> m;
		int** matrix1 = new int*[n]; // динамический массив1
		for (int i = 0; i <= n; i++)
			matrix1[i] = new int[n];
		int** matrix2 = new int*[n];; // динамический массив2
		for (int i = 0; i <= n; i++)
			matrix2[i] = new int[m];
		for (int i = 0; i < n; i++) //заполнение массива1 0
			for (int j = 0; j < n; j++)
			{
				matrix1[i][j] = 0;
			}
		for (int i = 0; i < n; i++) //заполнение массива2 0
			for (int j = 0; j < m; j++)
			{
				matrix2[i][j] = 0;
			}

		for (int i = 0; i < m; i++) //заполнение матрицы смежности и инцидентности
		{
			file >> v >> u;
			if (v != u)
			{
				matrix2[v - 1][i] = -1;
				matrix2[u - 1][i] = 1;
				matrix1[v - 1][u - 1]++;
			}
			else
			{
				matrix2[v - 1][i] = 2;
				matrix1[v - 1][u - 1] = 2;
			}
		}


		int selector;
		puts("What do you want to do?");
		puts("1. Show intsidance and adjacency matrixs.");
		puts("2. Save intsidance and adjacency matrixs to files.");
		cin >> selector;
		switch (selector)
		{
		case 1:show_matrixs(matrix2, matrix1, m, n); break;
		case 2: save_matrixs(matrix2, matrix1, m, n); break;
		}
	}
	else puts("File not found!");
	_getch();
}
