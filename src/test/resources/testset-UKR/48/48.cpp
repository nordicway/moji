# define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
using namespace std;

int l = 0, k[40][2];
int **first = new int*[k[0][0]];
int **second = new int*[k[0][0]];

void opn() 
{
	FILE *f;
	f = fopen("input.txt", "r");

	while (!feof(f)) 
	{
		fscanf(f, "%d", &k[l][0]);
		fscanf(f, "%d", &k[l][1]);
		l++;
	}

	for (int j = 0; j<l; j++)
	{
		cout << k[j][0] << " " << k[j][1];
		cout << endl;
	}

	fclose(f); 
}

void firstandzero()
{
	for (int number = 0; number < k[0][0]; number++)
		first[number] = new int[k[0][1]];

	for (int j = 0; j<k[0][0]; j++) 
	{
		for (int l = 0; l<k[0][1]; l++)
		{
			first[j][l] = 0;
		}
	}

	for (int j = 1; j <= k[0][1]; j++)
	{
		if (k[j][0] - 1 == k[j][1] - 1)
		{
			first[k[j][0] - 1][j - 1] = 2;
		}
		else
		{
			first[k[j][0] - 1][j - 1] = 1;
			first[k[j][1] - 1][j - 1] = -1;
		}
	}
}

void secondandzero()
{
	for (int number = 0; number < k[0][0]; number++)
		second[number] = new int[k[0][0]];

	for (int j = 0; j<k[0][0]; j++)
	{
		for (int l = 0; l<k[0][0]; l++)
		{
			second[j][l] = 0;
		}
	}

	for (int j = 1; j<k[0][0]; j++)   
	{
		second[k[j][0] - 1][k[j][1] - 1] = 1;
	}

	cout << " ";
}

void end1()
{
	cout << " ";
	for (int l = 0; l < k[0][1]; l++)
	{
		cout << setw(2) << "u" << l + 1;
	}

	cout << endl;

	for (int j = 0; j < k[0][0]; j++)
	{
		cout << "v" << j + 1;
		for (int l = 0; l < k[0][1]; l++)
		{
			cout << setw(3) << first[j][l];
		}
		cout << endl;
	}

	cout << endl;
}



void end2()
{
	for (int j = 0; j<k[0][0]; j++)
	{
		cout << "v" << j + 1;
		for (int l = 0; l<k[0][0]; l++)
		{
			cout << setw(3) << second[j][l];
		}
		cout << endl;
	}
}

int main()
{
	system("color F0");
	cout << "\n   Welcome!\n\n   Shevela Igor IS-52\n\n" << endl;
	opn();
	system("pause");
	system("cls");
	firstandzero();
	secondandzero();
	cout << "       Matrix incedentnosty\n";
	end1();
	cout << "       Matrix Cymignosty\n";
	end2();
	system("pause");
	cout << "Bye!" << endl;
	system("pause");
}