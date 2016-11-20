#include <iostream>
#include<conio.h>
#include<stdio.h>
#include <iomanip>
using namespace std;
int a, b;
int v[100][100];
int in[100][100], su[100][100];
void input()
{
	cout << "Vvedite chislo vershin i reber" << endl;
	cin >> a;
	cin >> b;
	for (int i = 0; i < b; i++)
		for (int j = 0; j < 2; j++)
			cin >> v[i][j];
}
void CreateIn()
{
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			in[i][j] = 0;
}
void CreateSu()
{
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a; j++)
			su[i][j] = 0;
}

void MatrIn()
{
	for (int i = 0; i < b; i++)
		for (int j = 0; j < 2; j++)
		{
			int z = v[i][j];
			if (j == 0) in[z-1][i] = -1;
			if (j == 1) in[z-1][i] = 1;
			if (v[i][0] == v[i][1]) in[z - 1][i] = 2;
		}

}
void MatrSu()
{
	for (int i = 0; i < b; i++)
		{
			int z = v[i][0];
			int k = v[i][1];
			su[z-1][k-1] = 1;
		
		}
}

void OutIn()
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
			cout <<setw(6)<< in[i][j] << setw(6);
		cout << endl;
	}
}
void OutSu()
{
	for (int i = 0; i < a; i++){

		for (int j = 0; j < a; j++)
			cout << setw(6) << su[i][j] << setw(6);
		cout << endl;
	}
}
int main()
{
	cout << "Creator: Margarita Aslamova IS-52 " << endl;
	input();
	CreateIn();
	CreateSu();
	MatrIn();
	MatrSu();
	cout << "Matrix In is " << endl;
	OutIn();
	cout << "Matrix Su is " << endl;
	OutSu();
	system("pause");

}