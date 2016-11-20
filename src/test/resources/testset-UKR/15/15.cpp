
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
FILE *filer, *filew;
char name[3][20];
int a, b, c[200][200], d[200][200];
void Name()
{
	cout << "Input name of file with data: " << endl;
	fflush(stdin);
	gets(name[0]);
	cout << "Input name of file for answer: " << endl;
	fflush(stdin);
	gets(name[1]);
}
void Read()
{
	filer = fopen(name[0], "r");
	fscanf(filer, "%d", &a);
	fscanf(filer, "%d", &b);
	for (int i = 1; i <= b; i++)
	{
		for (int n = 1; n <= 2; n++)
		{
			fscanf(filer, "%d", &c[i][n]);
		}
	}
	fclose(filer);
}
void Output()
{
	char s[100];
	filer = fopen(name[1], "r");
	fgets(s, 100, filer);
	puts(s);
	while (!feof(filer))
	{
		fgets(s, 100, filer);
		if (feof(filer)) break;
		puts(s);
	}
	fclose(filer);
}
void Incudent()
{
	Name();
	Read();
	filew = fopen(name[1], "w");
	for (int i = 1; i <= b; i++)
	{
		for (int m = 1; m <= a; m++)
		{
			if (c[i][1] == m) d[i][m] = -1;
		}
	}
	for (int i = 1; i <= b; i++)
	{
		for (int m = 1; m <= a; m++)
		{
			if (c[i][2] == m) d[i][m] = 1;
		}
	}
	for (int i = 1; i <= b; i++)
	{
		for (int m = 1; m <= a; m++)
		{
			if (c[i][2] == c[i][1] && c[i][1] == m) d[i][m] = 2;
		}
	}
	for (int i=1; i <= b; i++)
	{
		for (int n=1; n <= a; n++)
		{
			if (d[i][n] != 1 && d[i][n] != -1 && d[i][n] != 2) d[i][n] = 0;
		}
	}
	fputc('   ', filew);
	for (int i = 1; i <= b; i++)
	{
		if (i <= 1) fprintf(filew, "%4c%d", 'e', i);
		else fprintf(filew, "%2c%d", 'e', i);
	}
	fputc('\n', filew);
	for (int i = 1; i <= a; i++){
		if (i <= 9)fprintf(filew, "%c%d%c", 'v', i, ' ');
		else fprintf(filew, "%c%d", 'v', i);
		for (int j = 1; j <= b; j++)
			if (j <= 1) fprintf(filew, "%2d", d[j][i]);
			else if (j <= 10)fprintf(filew, "%3d", d[j][i]);
			else fprintf(filew, "%4d", d[j][i]);
			fputc('\n', filew);
	}
	fclose(filew);
	Output();
	system("pause");
}
void Sumijnist()
{
	Name();
	Read();
	filew = fopen(name[1], "w");
	for (int i = 1; i <= b; i++)
	{
		int j = c[i][1];
		int g = c[i][2];
		d[j][g] = 1;
	}
	for (int i = 1; i <= a; i++)
	{
		for (int n = 1; n <= a; n++)
		{
			if (d[i][n] != 1) d[i][n] = 0;
		}
	}
	fputc('   ', filew);
	for (int i = 1; i <= a; i++)
	{
		if (i <= 1) fprintf(filew, "%4c%d", 'v', i);
		else fprintf(filew, "%2c%d", 'v', i);
	}
	fputc('\n', filew);
	for (int i = 1; i <= a; i++){
		if (i <= 9)fprintf(filew, "%c%d%c", 'v', i, ' ');
		else fprintf(filew, "%c%d", 'v', i);
		for (int j = 1; j <= a; j++)
			if (j <= 1) fprintf(filew, "%2d", d[j][i]);
			else if (j <= 10)fprintf(filew, "%3d", d[j][i]);
			else fprintf(filew, "%4d", d[j][i]);
			fputc('\n', filew);
	}
	fclose(filew);
	Output();
	system("pause");
}
void main()
{
	cout << "     Laba 1\n" << "by Gychkevych Oleh" << endl;
	system("pause");
	while (1)
	{
		system("cls");
		cout << "         MENU   \n" << endl;
		cout << "1. Matrix of incudentnist" << endl;
		cout << "2. Matrix of sumijnist" << endl;
		cout << "3. Exit" << endl;
		cout << endl;
		int key;
		cout << "Choosen menu item: ";
		cin >> key;
		system("cls");
		switch (key)
		{
		case 1: {Incudent(); break; }
		case 2: {Sumijnist(); break; }
		case 3: {exit(0); break; }
		default: {cout << "Try another time..."; break; }
		}
	}
}