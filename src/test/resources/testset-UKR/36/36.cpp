#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <iomanip> 
using namespace std;
FILE*f;
int n=0;
int m = 0;
int MatrixSum[100][100];
int Value[100];
int Value2[100];
void VertexFile()
{
	
	fopen_s(&f,"Graph2.txt", "r");
	fscanf_s(f, "%d", &n);
	fscanf_s(f, "%d", &m);
	cout << " Vertex: " << n << " ; Edge: " << m << " ;" << endl;

	for (int i = 1; i < 2*m+1; i++)
		fscanf_s(f, "%d", &Value[i]);
	
	for (int i = 1; i < 2*m+1; i=i+2)
	{
		MatrixSum[Value[i]][Value[i+1]] = 1;
		
			
		
	}
	
	for (int i = 1; i <= n; i++)
	{
		cout << endl << setw(5)<< i << ") ";
		for (int j = 1; j <= n; j++)
		{
			
			if (MatrixSum[i][j] != 0)
				cout << MatrixSum[i][j] << " ;";
			else cout << "0" << " ;";

		}
		

	}
	fclose(f);
		
}
void EdgeFile()
{
	int q = 1;
	int Mass[50][50];
	fopen_s(&f, "Graph2.txt", "r");
	fscanf_s(f, "%d", &n);
	fscanf_s(f, "%d", &m);
	cout << " Vertex: " << n << " ; Edge: " << m << " ;" << endl;

	for (int i = 1; i < 2*m+1; i++)
	{

		fscanf_s(f, "%d", &Value2[i]);
	}
	cout << endl;
	for (int i = 1; i <= 2*m; i = i + 2)
	{
		Mass[Value2[i]][q] = 1;
		Mass[Value2[i + 1]][q] = -1;
		q++;

	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (Mass[i][j] != -858993460)
			cout <<setw(5)<< Mass[i][j] << "; ";
			else cout <<setw(5)<< "0" << "; ";

		}
		cout << endl;

	}

}
void main()
{	
	for (int qm = 0; qm <= 5; qm--)
	{
		char check = 'f';
		cout << "Nikolaev Alexandr \n Input: \n -i to find matrix incedent \n -s to find matrix sumich \n";
		cin >> check;
		switch (check)
		{
		case 's':
		{
			VertexFile();
			break;
		}
		case 'i':
		{
			EdgeFile();
			break;
		}
		}
		system("pause");
		system("cls");
	}


}