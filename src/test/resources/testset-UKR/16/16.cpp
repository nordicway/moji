#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
void nol(int a[][50])
{
	for (int i(0); i < 50; i++)
	{
		for (int j(0); j < 50; j++)
		{
			a[i][j] = 0;
		}
	}
}
void outmatrix(int a[][50],int n,int m,FILE* p)
{
	for (int i(0); i < n; i++)
	{
		for (int j(0); j < m; j++)
		{
			cout << setw(5) << a[i][j];
			fprintf(p, "%4d", a[i][j]);
		}
		cout << endl;
		fprintf(p, "\n");
	}
}
void Inc(FILE* f)
{
	FILE* p;
	char str[40];
	cout << "Input way for save file" << endl;
	fflush(stdin);
	gets(str);
	p = fopen(str, "a");
	int i,j,a[50][50],k,e;
	nol(a);
	if (f != NULL)
	{
		fscanf(f, "%d%d", &i, &j);
		cout << i << endl;
		cout << j << endl;
		for (int l(0); l < j; l++)
		{
			fscanf(f, "%d", &k);
			fscanf(f, "%d", &e);
			if (k == e)
				a[k-1][l] = 2;
			else
			{
				a[k - 1][l] = -1;
				a[e - 1][l] = 1;
			}
		}
		outmatrix(a,i,j,p);
		fclose(p);
	}
	else
		cout << "Error!" << endl;
}
void Sumizh(FILE* f)
{
	FILE* p;
	char str[40];
	cout << "Enter way of new file" << endl;
	fflush(stdin);
	gets(str);
	p = fopen(str,"a");
	int i,j,k,e,a[50][50];
	if (f != NULL)
	{
		fscanf(f, "%d", &i);
		fscanf(f, "%d", &j);
		nol(a);
		for (int l(0); l < j; l++)
		{
			fscanf(f, "%d", &k);
			fscanf(f, "%d", &e);
			a[k - 1][e - 1] = 1;
		}
		outmatrix(a, i, i, p);
		fclose(p);
	}
	else
		cout << "Error" << endl;
}
void main()
{
	system("color F0");
	cout << "Bohdan Golubets Is 52 lab_1" << endl;
	cout << "Input adress of file" << endl;
	FILE* f;
	char str[30];
	int key;
	gets(str);
	f = fopen(str, "r");
	cout << "If you want incident matrix enter 1,If sumizhna matrix enter 2" << endl;
	cin >> key;
	switch (key)
	{
	case 1 : Inc(f); break;
	case 2: Sumizh(f); break;
	}
	fclose(f);
	system("pause");
}