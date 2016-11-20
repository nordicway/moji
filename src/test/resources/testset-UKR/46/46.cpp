#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
using namespace std;
char filename[25], filename1[25];
FILE *f;
FILE *f1;
int matrix[200][200];
int n, m, k, l;
char key;
void Scan()
{
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);
}
void PrintM(int c, int v)
{
	for (int i = 1; i < c+1; i++)
	{
		cout << endl;
		for (int j = 1; j < v+1; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
	}
}
void Clear()
{
	for (int i = 0; i < m + 1; i++)
	{
		for (int j = 0; j < m + 1; j++)
		{
			matrix[i][j]=0;
		}
	}
	cout << endl;
}
void AdjMatrix()
{
	for (int i = 0; i < m+1; i++)
	{
		fscanf(f, "%d",&k);
		fscanf(f, "%d", &l);
		matrix[k][l] = 1;
	}
	cout <<"Adjacency matrix:"<< endl;
	PrintM(n,n);
}
void WrAdjMatrix()
{
	cout << "Enter destination file name:" << endl;
	gets(filename1);
	f1 = fopen(filename1, "w");
	fprintf(f1, "Adjacency matrix:");
	for (int i = 1; i < n + 1; i++)
	{
		fputc('\n', f1);
		for (int j = 1; j < n + 1; j++)
		{
			fputc(' ', f1);
			fprintf(f1, "%3d", matrix[i][j]);
		}
	}
	cout << "DONE! The file is written." << endl;
}

void InsMatrix()
{
	for (int i = 1; i < m + 1; i++)
	{
		fscanf(f, "%d", &k);
		matrix[k][i] = -1;
		fscanf(f, "%d", &l);
		matrix[l][i] = 1;
		if (k == l)
		{
			matrix[k][i] = 2;
			matrix[l][i] = 2;
		}
	}
	cout << "Incidense matrix:" << endl;
	PrintM(n,m);
}
void WrInsMatrix()
{
	cout << "Enter destination file name:" << endl;
	gets(filename1);
	f1 = fopen(filename1, "w");
	fprintf(f1, "Incidense matrix:");
	for (int i = 1; i < n + 1; i++)
	{
		fputc('\n', f1);
		for (int j = 1; j < m + 1; j++)
		{
			fputc(' ', f1);
			fprintf(f1, "%3d", matrix[i][j]);
		}
	}
	cout << "DONE! The file is written." << endl;

}
int main()
{
	system("colorF0");
	cout << "DM Lab 1" << endl;
	cout << "Sameer Kak IS-52 FICT KPI" << endl;
	cout << "--------------------------" << endl;
	cout <<"press any key to continue..."<< endl;
	getch();
	puts("Enter source file name");
	gets(filename);
	f = fopen(filename, "r");
	if (f == 0	)
		puts("file not found");
	else
		puts("file opened for reading.");
	fclose(f);
	cout << "press any key to continue..." << endl;
	getch();
	cout <<"---------source file:"<<filename<<"------------"<<endl;




	do		//вибір запитів
	{

		system("cls");
		cout << "DM Lab 1" << endl;
		cout << "Sameer Kak IS-52 FICT KPI" << endl;
		cout << "---------source file:" << filename << "------------" << endl;
		puts("Choose command:");
		puts("1. To view Adjacency matrix: on screen");
		puts("2. To view Incidense matrix on screen");
		puts("3. To write an Adjacency matrix to file");
		puts("4. To write an Incidense matrix to file");
		puts("or Choose ESC to exit");
		puts("================================================================");

		key = getch();	
		switch (key)
		{
		case '1':f = fopen(filename, "r"); Scan(); AdjMatrix(); fclose(f); getch(); Clear(); break;	
		case '2':f = fopen(filename, "r"); Scan(); InsMatrix(); fclose(f); getch(); Clear(); break;	
		case '3':f = fopen(filename, "r"); Scan(); AdjMatrix(); cout << endl; fclose(f); WrAdjMatrix(); getch(); Clear(); break;
		case '4': f = fopen(filename, "r"); Scan(); InsMatrix(); cout << endl; fclose(f); WrInsMatrix(); getch(); Clear(); break;
		}
	} while (key != 27);	//доки не натиснута клавіша ESC
	
	getch();
}