#include <fstream> 
#include <iomanip> 
#include <stdlib.h> 
#include <iostream> 

using namespace std;

int s = 0;
int n, m, 
int p, k;
int matrI[100][100];
int matrS[100][100];

char ch;


void Input()
{
	ifstream fin;

	fin.open("f.txt");
	
		fin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			fin >> p >> k;
			k++;
			p++;
			
		}
		fin.close();
}


void Sm()
	
{
		for (int i = 0; i < m; i++)
		{
			matrI[p - 1][k - 1] = 1;
			p++;
			k++;
		}
		puts("Матриця сумiжностi:");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				puts (matrI[i][j]);

		}
}


void Ints()
{
		for (int i = 0; i < m; i++)
		{
			matr[*p - 1][i] = -1;
			matr[*k - 1][i] = 1;
			if (*p == *k) matr[*p - 1][i] = 2;
			p++;
			k++;
		}


}

void Output()
{

	FILE *f = fopen("f.txt", "w");
	fout << "Матриця iнцедентностi:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			fout << setw(3) << m1[i][j];
		fout << endl;
	}
	fout << "Матриця сумiжностi:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fout << setw(3) << m2[i][j];
		fout << endl;
	}
	fclose(f);
}
int main()
{
	Input();
	Sm();
	Ints();
	Output();
	_getch();

}