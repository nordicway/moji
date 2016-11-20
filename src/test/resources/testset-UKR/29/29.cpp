#include<iostream>
#include<string>
#include<stdio.h>
#include<fstream>
#include<conio.h>

using namespace std;

int i,a, b, k;
int num[500];
int matrix[200][30];
ifstream fin;
ofstream fout;
string filename, fileoutname;




void input()
{
	cout << "Enter input file name: " << endl;
	getline(cin, filename);
	cout << "Enter output name: " << endl;
	getline(cin, fileoutname);
	fin.open(filename + ".txt");
	if (!fin.is_open())
	{
		cout << "No file" << endl;
	}
	fin >> a >> b;
}

void incidence()
{
	system("cls");
	int k = 0;
	int i = 1;
	for (int j = 0; j<a; j++)
	{
		for (int k = 0; k<b; k++)
		{
			matrix[j][k] = 0;
		}
	}
	do
	{
		fin >> num[i] >> num[i + 1];
		if (num[i] == num[i + 1])
			matrix[num[i] - 1][k] = 2;
		else
		{
			matrix[num[i] - 1][k] = -1;
			matrix[num[i + 1] - 1][k] = 1;
		}
		i += 2;
		k++;
	} while (!fin.eof());
	fin.close();
	ofstream fout(fileoutname + ".txt", ios_base::out | ios_base::trunc);

	if (!fout.is_open())
	{
		cout << "Error\n";
		system("pause");
		exit(1);
	}

	for (int j = 0; j<a; j++)
	{
		for (int k = 0; k<b; k++)
		{
			if (matrix[j][k]<0)
				cout << matrix[j][k] << " ";
			else cout << " " << matrix[j][k] << " ";
			fout << matrix[j][k] << " ";
		}
		cout << endl;
		fout << endl;
	}
}

void adjacency()
{
	system("cls");
	for (int j = 0; j<a; j++)
	{
		for (int k = 0; k<a; k++)
		{
			matrix[j][k] = 0;
		}
	}
	do
	{
		fin >> num[i] >> num[i + 1];
		matrix[num[i] - 1][num[i + 1] - 1]++;
		i += 2;
	} while (!fin.eof());
	fin.close();
	ofstream fout(fileoutname+".txt", ios_base::out | ios_base::trunc);

	if (!fout.is_open()) 
	{
		cout << "Error\n"; 
		system("pause");
		exit(1);	
	}
	for (int j = 0; j<a; j++)
	{
		for (int k = 0; k<a; k++)
		{
			cout << matrix[j][k] << " ";
			fout << matrix[j][k] << " ";
		}
		cout << endl;
		fout << endl;
	}
}


void menu()
{
	system("cls");
	cout << "1)Build incidence matrix" << endl;
	cout << "2)Build adjacency matrix" << endl;
	cin >> k;
	switch (k)
	{
	case 1:
	{
		incidence();
		break;
	}
	case 2:
	{
		adjacency();
		break;
	}
	default:					//хибний вибір
	{
		cout << "The number is wrong" << endl;
		system("pause");
		exit(0);
	}

	}
}
void main()
{
	input();
	menu();


	system("pause");
}
