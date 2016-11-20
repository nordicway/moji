#include<iostream>
#include<Windows.h>
//#include<GLglut.h>
#include<fstream>
#include<stdio.h>
#include<iomanip>
using namespace std;

typedef int Matrix[25][25];
Matrix S, I;
fstream File;

void Output(Matrix, int, int);
void matrix_sm(Matrix);
void matrix_ints(Matrix);
void Output_in_file(Matrix, int, int);


int main()
{
	system("color A0");
	int n, m;
	setlocale(LC_ALL, "Ukr");

	File.open("1.txt");
	if (File)
	{
		File >> n >> m;
		File.close();
	}
	else cout << "Could not open a file. Please, try again";



	cout << "Матриця сумiжностi:" << endl;
	matrix_sm(S);
	Output(S, n, n);
	File.open("1.txt", ios::app);

	File << endl << "Матриця сумiжностi:" << endl;
	File.close();
	Output_in_file(S, n, n);

	cout << endl << endl << "Матриця iнцидентностi:" << endl;
	matrix_ints(I);
	Output(I, n, m);
	cout << endl;

	File.open("1.txt", ios::app);
	File << endl << endl << "Матриця iнцидентностi:" << endl;
	File.close();
	Output_in_file(I, n, m);

	system("pause");
}



void matrix_sm(Matrix A)
{
	int n, m, v, u;
	File.open("1.txt");
	if (File)
	{
		File >> n >> m;
		for (int i = 0; i < m; i++)
		{
			File >> v >> u;
			A[v - 1][u - 1] = 1;
		}
		File.close();
	}
	else cout << "Could not open a file. Please, try again";
}
void matrix_ints(Matrix A)
{
	int n, m, v, u;
	File.open("1.txt");
	if (File)
	{
		File >> n >> m;
		for (int i = 0; i < m; i++)
		{
			File >> v >> u;
			if (v == u) A[v - 1][i] = 2; else
			{
				A[v - 1][i] = -1;
				A[u - 1][i] = 1;
			}
		}
		File.close();
	}
	else cout << "Could not open a file. Please, try again";
}

void Output(Matrix A, int n, int m)
{
	cout << "     ";
	for (int i = 0; i < m; i++)
		printf("%-3d", i + 1);
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		printf("\n%-3d", i + 1);

		for (int j = 0; j < m; j++)
			printf("%3d", A[i][j]);
	}
}

void Output_in_file(Matrix A, int n, int m)
{
	File.open("1.txt", ios::app);
	File << "     ";
	for (int i = 0; i < m; i++)
	{
		File.unsetf(ios::right);
		File.setf(ios::left);
		File.width(3);
		File << i + 1;
	}
	File << endl;

	for (int i = 0; i < n; i++)
	{
		

		File.width(3);
		File.unsetf(ios::right);
		File.setf(ios::left);
		File << endl << i + 1;


		for (int j = 0; j < m; j++)
			
		{
			File.setf(ios::right);
			File.width(3);
			File << A[i][j];
		}
	}
	File.close();
	
}
