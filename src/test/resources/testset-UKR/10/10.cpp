#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <iomanip>

using namespace std;

struct graph
{
	int v = 0;                    //вершини графа
	int u = 0;                    //ребра графу
	int MatrixFirst[200][200];
	int MatrixSecond[100][100];
};

graph Graph;
int Arr[5];
int Array[10];
int x, temp;
FILE *f;
char FileName[100];

void ReadFile()
{
	for (int i = 0; i < 2; i++)
	{
		fscanf(f, "%d", &Arr[i]);
	}
	Graph.v = Arr[0];
	Graph.u = Arr[1];
}

void  MatrixInc()
{
	for (int i = 1; i <= Graph.u * 2; i++)
	{
		fscanf(f, "%d", &x);
		if (i % 2 != 0)
		{
			Graph.MatrixFirst[x - 1][i / 2] = -1;
			temp = x;
		}
		else
		{
			if (temp == x)
			{
				Graph.MatrixFirst[temp - 1][(i - 1) / 2] = 2;
			}
			else
			{
				Graph.MatrixFirst[x - 1][(i - 1) / 2] = 1;
			}
		}
	}
}

void MatrixSum()
{
	for (int i = 1; i <= Graph.u * 2; i++)
	{
		fscanf(f, "%d", &Array[(i - 1) % 2]);
		if ((i % 2) == 0)
		{
			Graph.MatrixSecond[Array[0] - 1][Array[1] - 1] = 1;
		}
	}
}

void OutputMatrixF()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.u; j++)
		{
			cout << setw(2) << Graph.MatrixFirst[i][j];
		}
		cout << endl;
	}
}

void OutputMatrixS()
{
	for (int i = 0; i < Graph.v; i++)
	{
		for (int j = 0; j < Graph.v; j++)
		{
			cout << setw(2) << Graph.MatrixSecond[i][j];
		}
		cout << endl;
	}
}

int main()
{
	/*cout << "Enter file name" << endl;
	gets(FileName);*/
	f = fopen("D:\\Study\\semestr2\\DM\\Task\\graph_01_5.txt", "r");
	if (f != NULL)
	{
		ReadFile();
		cout << Graph.v << " " << Graph.u << endl;
		MatrixInc();
		cout << "First matrix" << endl;
		OutputMatrixF();
	}
	else
	{
		cout << "File not open" << endl;
	}
	
	fclose(f);
	f = fopen("D:\\Study\\semestr2\\DM\\Task\\graph_01_5.txt", "r"); 
	if (f != NULL)
	{
		ReadFile();
		MatrixSum();
		cout << "Second matrix" << endl;
		OutputMatrixS();
	}
	else
	{
		cout << "File not open" << endl;
	}
	fclose(f);
	system("pause");
}