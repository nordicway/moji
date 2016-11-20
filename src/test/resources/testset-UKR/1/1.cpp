#include<iostream>
#include<stdio.h>
#pragma warning (disable: 4996)
using namespace std;
FILE *data, *output;//показчики на вхідний та вихідний файли
char inname[20], outname[20];//назви вхідного та вихідного файлів
int msum[100][100];
int mint[100][100];
int n, m;
void work();
void vidp();
void intend();
inline void sumis(int i1, int j1);
void intend(int i1, int j1, int l1);
void filewrite1();
void filewrite2();
int main()
{
	cout << "Laboratory work #1 'Demonstration of graphs'" << endl;
	work();
	filewrite1();
	filewrite2();
	system("pause");
}
void work()
{
	cout << "Input name of your data file!" << endl;
	cin >> inname;
	data = fopen(inname, "r");
	if (data == NULL)
		cout << "File not found!" << endl;
	else
		vidp();
}
void vidp()
{
	int i, j;
	char numb[10];
	fgets(numb, 10, data);
	sscanf(numb, "%d %d", &n, &m);
	for (int l = 0; l < n; l++)
	{
		for (int s = 0; s < n; s++)
		{
			msum[l][s] = 0;
		}
		cout << endl;
	}
	for (int l = 0; l < m; l++)
	{
		fgets(numb, 10, data);
		sscanf(numb, "%d %d", &i, &j);
		sumis(i, j);
		intend(i, j, l);
	}
	for (int l = 0; l < n; l++)
	{
		for (int s = 0; s < n; s++)
		{
			cout << msum[l][s];
		}
		cout << endl;
	}
	for (int l = 0; l < n; l++)
	{
		for (int s = 0; s < m; s++)
		{
			cout << mint[l][s];
		}
		cout << endl;
	}
	fclose(data);
}
inline void sumis(int i1, int j1)
{
	msum[i1 - 1][j1 - 1] = 1;
}
void intend(int i1, int j1, int l1)
{
	if (i1 == j1)
		mint[i1-1][l1-1] = 2;
	else
	{
		mint[i1-1][l1-1] = -1;
		mint[j1-1][l1-1] = 1;
	}
}
void filewrite1()
{
	char filename[20];
	cout << "Enter name of file for compeir table" << endl;
	cin >> filename;
	output = fopen(filename, "w");
	if (output == NULL)
		cout << "Error of file creating!" << endl;
	else
	{
		for (int l = 0; l < n; l++)
		{
			for (int s = 0; s < n; s++)
			{
				fprintf(output, "%d", msum[l][s]);
			}
			fputc('\n', output);
		}
		fclose(output);
	}
}
void filewrite2()
{
	char filename[20];
	cout << "Enter name of file for intendent table" << endl;
	cin >> filename;
	output = fopen(filename, "w");
	if (output == NULL)
		cout << "Error of file creating!" << endl;
	else
	{
		for (int l = 0; l < n; l++)
		{
			for (int s = 0; s < m; s++)
			{
				fprintf(output, "%d", mint[l][s]);
			}
			fputc('\n', output);
		}
		fclose(output);
	}
}