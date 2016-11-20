#include<iostream>
#include <stdio.h>
#include<iomanip>
using namespace std;
int n, m;
int v, u;
int i, j;
int m1[100][100], m2[100][100];
char key, answer;
FILE *f, *t;
void menu()
{
	cout << "         MENU          " << endl;
	cout << "1. Make an adjacency matrix and input it in a file" << endl;
	cout << "2. Make an incidence matrix and input it in a file" << endl;
}
void ReadData1()
{
	f = fopen("lab1.txt", "r");
	fscanf(f, "%d%d", &n, &m);
	while (!feof(f))
	{
		fscanf(f, "%d%d", &v, &u);
		m1[v][u] = 1;
	}
	fclose(f);
}
void AdjacencyMatrix()
{
	cout << "Adjacency matrix:" << endl;
	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
			cout << m1[i][j]<<" ";
		cout << endl;
	}
}
void WriteData1()
{
	t = fopen("lab1n.txt", "w");
	fprintf(t, "Adjacency matrix:");
	fputc('\n', t);
	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < n + 1; j++)
		{
			fprintf(t, "%d ", m1[i][j]);
		}
	fputc('\n', t);
	}
	cout << "Matrix inputted in file" << endl;
	fclose(t);
}
void ReadData2()
{
	f = fopen("lab1.txt", "r");
	fscanf(f, "%d%d", &n, &m);
	j = 1;
	while (!feof(f))
	{
		fscanf(f, "%d%d", &v, &u);
			m2[v][j] = -1;
			m2[u][j] = 1;
			if (v == u)
			{
				m2[v][j] = 2;
			}
			j++;
	}
	fclose(f);
}
void IncidenceMatrix()
{
	cout << "Incidence matrix:" << endl;
	for (i = 1; i < n+1; i++)
	{
		for (j = 1; j < m+1; j++)
			cout << m2[i][j] << "   ";
		cout << endl;
	}
}
void WriteData2()
{
	t = fopen("lab1n.txt", "a");
	fprintf(t, "Incidence matrix:");
	fputc('\n', t);
	for (i = 1; i < n + 1; i++)
	{
		for (j = 1; j < m + 1; j++)
		{
			fprintf(t, "%d   ", m2[i][j]);
		}
		fputc('\n', t);
	}
	cout << "Matrix inputted in file" << endl;
	fclose(t);
}
int main()
{
	system("color F0");
	cout << "Lab 1 Executor: Dvornyk Victoris IS-53" << endl;
	cout << "Build adjacency and incidence matrix" << endl;
	do
	{
		menu();
		cout << "Choose menu item:" << endl;
		cin >> key;
		switch (key)
		{
		case '1':
		{
			ReadData1();
			AdjacencyMatrix();
			WriteData1();
			break;
		}
		case '2':
		{
			ReadData2();
			IncidenceMatrix();
			WriteData2();
			break;
		}
		default: cout << "Try another time..." << endl;
		}
		cout << "Continue? y/n" << endl;
		cin >> answer;
	} while (answer != 'n');
	system("pause");
}