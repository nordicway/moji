/*
лабораторна робота номер 1
виконав ст. 1 курсу, групи is-52
Кочубей Ілля Ю.
*/
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream> 
#include<stdio.h> 
#include<conio.h> 
#include<iomanip> 
#include<stdlib.h> 
#include<iostream> 
#include<fstream> 

using namespace std;
int key;
FILE *file;
int perev = 1;
int v[800];
int n[800];
int cym[800][800];
int inz[800][800];
int  k = 0;
int Ar[122][2];


void cymijinocti()
{
	int z = 0;
	cout << setw(3) << endl;
	for (int i = 0; i < v[0]; i++)
	{
		cout << "v" << i + 1 << "  ";
	}
	cout << endl;
	
	for (int i = 0; i < v[0]; i++)
	{
		cout << "v" << i + 1 << " ";
		for (int j = 0; j < v[0]; j++)
		{
			for (int o = 0; o < n[0]; o++)
			{
				if (((v[o + 1]) == (i + 1)) && ((n[o + 1]) == (j + 1)))
				{
					cym[i][j] = 1;
					z = 1;
				}
				else if (z != 1)
				{
					cym[i][j] = 0;
					
				}
				
			}
		cout << cym[i][j] << " ";
		}
		cout << endl;
	}
}

void inzudentnicti()
{
	for (int i = 0; i < n[0]; i++)
	{
		cout << "e" << i + 1 << " ";
	}cout << endl;
	for (int i = 0; i<v[0]; i++)
	{
		cout << setw(0) << "v" << i + 1;
		for (int j = 0; j<n[0]; j++)
		{
			
			if (n[j + 1] == i + 1 && v[j + 1] == i + 1)
			{
				inz[i][j] = 2;
				cout <<"  "  << inz[i][j];
			}
			else if (v[j + 1] == i + 1  )
			{
				inz[i][j] = -1;
				cout << " " << inz[i][j];
			}
			else if (n[j + 1] == i + 1 )
			{
				inz[i][j] = 1;
				cout << "  " << inz[i][j];
			}
			else
			{
				inz[i][j] = 0;
				cout << "  " << inz[i][j];
			}

		}
		cout << endl;
	}
	system("pause");

}
void inside() //Виведення у файл 
{
	ofstream fout;
	fout.open("t.txt");
	fout << "Матриця iнцедентностi:" << endl;
	for (int i = 0; i < v[0]; i++)
	{
		for (int j = 0; j < n[0]; j++)
			fout << setw(3) << inz[i][j];
		fout << endl;
	}
	
	fout << "Матриця сумiжностi:" << endl;
	for (int i = 0; i < v[0]; i++)
	{
		for (int j = 0; j < v[0]; j++)
			fout << setw(3) << cym[i][j];
		fout << endl;
	}
	fout.close();
}

void perevirka()
{
	file = fopen("graph_01_4.txt", "r+");
	if (file == NULL)
	{
		cout << "file don`t open" << endl;
		system("pause");
		system("cls");

	}
	else{
		cout << "file in the disk!" << endl;
		system("pause");
		system("cls");

	}


	while (!feof(file))
	{
		fscanf(file, "%d", &v[k]);
		fscanf(file, "%d", &n[k]);
		k++;
	}
	fclose(file);

}
void infirmation()
{
	for(int i = 0; i<k; i++)
	{
		cout << v[i] << " " << n[i]<< endl;;
	}
	system("pause");

}
int main()
{
	system("color F0");
	cout << " Autor Kochubey Illia " << endl;
	cout << "  Group IS-52 " << endl;			//вивід повідомлення
	cout << " laboratory work number 1 " << endl;
	cout << "" << endl;
	cout << "" << endl;

	if (perev == 1)
	{
		//вивід повідомлення
		cout << "Perevirka na file " << endl;
		perevirka();
		perev++;
		main();
	}

	cout << "1. Output infirmation about txt file " << endl;
	cout << "2. Output matrix cymij`nocti?" << endl;
	cout << "3. Output matrix inzudentnocti" << endl;
	cout << "4. Exit. " << endl << endl;
	cout << "Select the menu item dear to continue program : ";
	cin >> key;
	switch (key)
	{
	case 1:	{
		cout << "infirmation about txt file" << endl;
		infirmation();
		system("pause");
		system("cls");
		main();
		break;
	}
	case 2:{
		cout << "matrix cymij`nocti" << endl;
		cymijinocti();
		inside();
		system("pause");
		system("cls");
		main();
		break;
	}
	case 3:{
		cout << "================================= list" << endl;
		inzudentnicti();
		inside();
	
		system("cls");
		main();
		
		break;
	}
	case 4:{
		cout << "goodbay" << endl;
		break;
	}

	default: {
		cout << " Try again, you don`t chose any appropriate key " << endl;
		main();
		break;
	}
	}
	inside();
}

