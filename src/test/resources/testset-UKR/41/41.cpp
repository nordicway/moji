
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
using namespace std;
FILE* input = fopen("data.txt","r");
int main()
{
	cout << "Lab#1 Made by Ponomarenko Artem IS-51" << endl;
	int v, r;
	fscanf(input, "%d%d", &v, &r);
	int** inc = new int*[v];	//
	for (int i = 0; i<v; i++)	//	задання матриці інцидентності і заповнення нулями
		inc[i] = new int[r];	//
	for (int a = 0; a < v; a++)
		for (int b = 0; b < r; b++)
		{
			inc[a][b] = 0;
		}
	int** sum = new int*[v];	//
	for (int i = 0; i<v; i++)	//	задання матриці суміжності і заповнення нулями
		sum[i] = new int[v];	//
	for (int a = 0; a < v; a++)
		for (int b = 0; b < v; b++)
		{
			sum[a][b] = 0;
		}
	int m, n; 
	int e = 0;
	while (!feof(input))	//перебот всіх даних в тексті
	{	
		fscanf(input, "%d%d", &m, &n);		//заповнення матриці
		if (m == n) inc[m - 1][e] = 2;			//інцидентності
		if (m != n){ inc[m - 1][e] = -1; inc[n - 1][e] = 1; }//
		e++;							//
		sum[m - 1][n - 1] = 1; // заповнення матриці суміжності
	}
	cout << "Matrix of incendency (rows => vershini; Columns => rebra)" << endl;
	for (int i = 0; i < v; i++)	
	{
		cout << endl;
		for (int j = 0; j < r; j++)
			cout << inc[i][j] << "	";
	}
	cout << endl << "Matrix of sumizhnosti (rows => vershini pochatku; Columns => vershini kincya)" << endl;
	for (int i = 0; i < v; i++)
	{
		cout << endl;
		for (int j = 0; j < v; j++)
			cout << sum[i][j] << "	";
	}
	_getch();
}