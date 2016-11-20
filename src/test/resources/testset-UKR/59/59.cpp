#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
#include<fstream>

using namespace std;

FILE *f;
int c, k;
int Ar[122][2];
int Answer;
int M1[20][122], M2[20][122];

int FileRead()
{       
	k = 0;
	cout << "Select wich file do you want to open (1-4)" << endl;
	cin >> Answer;
	if (Answer == 1)
		f = fopen("graph_01_1.txt", "r");
	else if (Answer == 2)
		f = fopen("graph_01_2.txt", "r");
	else if (Answer == 3)
		f = fopen("graph_01_3.txt", "r");
	else
		f = fopen("graph_01_4.txt", "r");
	if (f == NULL)                 
	{
		cout<<"file not found"<<endl;
		return 1;
	}
	else
		cout << "OK" << endl;

	while (!feof(f))
	{
		fscanf(f, "%d", &Ar[k][0]);
		fscanf(f, "%d", &Ar[k][1]);
		k++;
	}
	system("pause");
	return 0;
}

void FileOutput()
{
	for (int i = 0; i<k; i++)
	{
		for (int j = 0; j<2; j++)
		{
			cout << Ar[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}

void MatrixInt()
{
	for (int i = 0; i<Ar[0][0]; i++)
	{
		for (int j = 0; j<Ar[0][1]; j++)
		{
			if (i+1 == Ar[j+1][0] && i+1 == Ar[j+1][1])
			{
				M1[i][j] = 2;
			}
			else if (i+1 == Ar[j + 1][0])
			{
				M1[i][j] = -1;
			}
			else if (i+1 == Ar[j + 1][1])
			{
				M1[i][j] = 1;
			}
			else
			{
				M1[i][j] = 0;
			}
		}
	}
}

void MatrixSum()
{
	int z = 0;
	for (int i = 0; i<Ar[0][0]; i++)
	{
		for (int j = 0; j<Ar[0][0]; j++)
		{
			for (int m = 0; m < Ar[0][1]+1; m++)
			{
				if (Ar[m + 1][1] == j + 1 && i + 1 == Ar[m + 1][0])
				{
					M2[i][j] = 1;
					z = 1;
				}
				else if (z != 1)
				{
					M2[i][j] = 0;
				}
			}
		}
	}
}

void MatrixIntOut()
{
	cout << setw(6);
	for (int i = 0; i<Ar[0][1]; i++)
	{
		cout << "e" << setw(5);
	}
	cout << endl;
	cout << setw(6);
	for (int i = 0; i<Ar[0][1]; i++)
	{
		cout << i + 1 << setw(5);
	}
	cout << endl;
	for (int i = 0; i<Ar[0][0]; i++)
	{
		cout << setw(0) << "v" << i + 1;
		for (int j = 0; j<Ar[0][1]; j++)
		{
			cout << setw(5) << M1[i][j];
		}
		cout << endl;
	}
	system("pause");
}

void MatrixSumOut()
{
	cout << setw(6);
	for (int i = 0; i<Ar[0][0]; i++)
	{
		cout << "v" << setw(5);
	}
	cout << endl;
	cout << setw(6);
	for (int i = 0; i<Ar[0][0]; i++)
	{
		cout << i + 1 << setw(5);
	}
	cout << endl;
	for (int i = 0; i<Ar[0][0]; i++)
	{
		cout << setw(0) << "v" << i + 1;
		for (int j = 0; j<Ar[0][0]; j++)
		{
			cout << setw(5) << M2[i][j];
		}
		cout << endl;
	}
	system("pause");
}

void InputInFile()
{
	ofstream input;
	input.open("write.txt",ios::app);
	input << "File";
	if (Answer == 1)
		input << 1 <<endl;
	else if (Answer == 2)
		input << 2 << endl;
	else if (Answer == 3)
		input << 3 << endl;
	else
		input << 4 << endl;
	input << "Matrix Intsidentnosti:" << endl;
	for (int i = 0; i < Ar[0][0]; i++)
	{
		for (int j = 0; j < Ar[0][1]; j++)
		{
			input << setw(3) << M1[i][j];
		}
		input << endl;
	}
	input << "Matrix Sumizhnosti:" << endl;
	for (int i = 0; i < Ar[0][0]; i++)
	{
		for (int j = 0; j < Ar[0][0]; j++)
		{
			input << setw(3) << M2[i][j];
		}
		input << endl;
	}
	input.close();
}

int main()
{
	system("color F0");
	int key;
	FileRead();
	while (true)
	{
		MatrixInt();
		MatrixSum();
		system("cls");
		cout << "	Menu" << endl;
		cout << " 1.Output file" << endl;
		cout << " 2.Output matrix intsyndentnosti" << endl;
		cout << " 3.Output matrix sumizhnosti" << endl;
		cout << " 4.Select anouther file" << endl;
		cout << " 5.Input in file" << endl;
		cout << " 6.Exit" << endl;
		cout << " Enter your choose: ";
		cin >> key;
		switch (key)
		{
			case 1:
			{
				FileOutput();
				break;
			}
			case 2:
			{
				MatrixIntOut();
				break;
			}
			case 3:
			{
				MatrixSumOut();
				break;
			}
			case 4:
			{
				FileRead();
				break;
			}
			case 5:
			{
				InputInFile();
				break;
			}
			case 6:
			{
				fclose(f);
				exit(0);
				break;
			}
			default:
			{
				cout << "Please, try again..." << endl;
				system("pause");
				break;
			}
		}
	}
	return 0;
}