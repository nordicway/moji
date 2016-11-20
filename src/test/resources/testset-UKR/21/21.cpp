#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
using namespace std;
FILE* f2;
FILE *f1;
int mas[100][100];//матриця
int a[200];//масив для збереження даних
int b[20];
char name[30];//імя файла
int key;
int v ;//к-ть вершин
int e;//к-ть ребер



void Read()//функція зчитування з файла
{
  f1 = fopen("E:\\DM\\DM_lab1\\DM_lab1\\input.txt", "r");
	
	if (!f1)
	{
		printf("Error!\n");
		getchar();

	}
	for (int i = 0; i<2; i++)
		fscanf(f1, "%i", &b[i]);
	int c = 2 * b[1];
	v = b[0];  e = b[1];
	for (int j = 0; j<c; j++)
	{
			fscanf(f1, "%i", &a[j]);
	}
	fclose(f1);
}
void NullMatrix()  //нульова матриця
{  
	for (int i = 0; i <v; i++)
		for (int j = 0; j <v; j++)
			mas[i][j] = 0;
			
}
void out1()//виведення матриці суміжності
{
	puts("Adjacency Matrix ");
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j <v; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	
}
void out2()//виведення матриці інцед
{
	puts("Incidence Matrix ");
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j <e; j++)
			cout << mas[i][j] <<setw(2);
		cout << endl;
	}

}
void AdjacencyMatrix()//матриця суміжності
{
	
	NullMatrix();
	for (int j = 0; j < 2*e; j += 2)
	{  
		int l;
	    int k;
		k = a[j];
		l = a[j + 1];
		mas[k - 1][l - 1] = 1;
	}
	out1();
}
void IncidenceMatrix()
{  
   NullMatrix();
   int n = 0;
   int l;
   int k;
   for (int j = 0; j <2* e; j += 2)
	{
		k = a[j];
		l = a[j + 1];
		if (k == l)
		mas[k - 1][n] = 2;
		else {
			mas[k - 1][n] = -1;
			mas[l - 1][n] = 1;
		}
		n++;
	}
  out2();
}

void write_file()//функція запису в файл
{
	puts("choose name of file");
	puts("enter name of file  for write ");
	fflush(stdin);
	gets(name);
	f2 = fopen(name, "w");
	cout << "Choosen menu item: " << endl;
	cout << "1.Write result  adjacency matrix" << endl;
	cout << "2.Write result incidence matrix" << endl;
	cin >> key;
	system("cls");
	switch (key)
	{
	case 1: {
		AdjacencyMatrix();
		for (int k = 0; k < v; k++)
	{
		for (int l = 0; l < v; l++)
		{
			fprintf(f2, "%d", mas[k][l]);
			fputc('  ', f2);
		}
		fputc('\n', f2);
	}
			fclose(f2);; break; }
	
	
	
	case 2:{
		IncidenceMatrix();
		for (int k = 0; k < v; k++)
	{
		for (int l = 0; l < e; l++)
		{
			fprintf(f2, "%d", mas[k][l]);
			fputc(' ', f2);
		}
		fputc('\n', f2);
	}
		   fclose(f2);; break; }
	}
	
}




int main()
{
	Read();
	while (1)
	{
		system("cls");
		cout << "             MENU \n" << endl;
		cout << "1.Build adjacency matrix" << endl;
		cout << "2.Build the incidence matrix" << endl;
		cout << "3.Result write to file" << endl;
		cout << "4.Exit" << endl;
		cout << endl;
		int key;
		cout << "Choosen menu item: ";
		cin >> key;
		system("cls");
		switch (key)
		{
		case 1: {AdjacencyMatrix(); break; }
		case 2:{IncidenceMatrix(); break; }
		case 3:{write_file(); break; }
		case 4:{exit(0); break; }
		default:{cout << "ERROR!!!....."; getch(); break; }
		}

		system("pause");
	}

}