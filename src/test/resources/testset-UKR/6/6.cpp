#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int N, K;
int matr[16][16], matr1[16][16];
int ind, i, j;

void OutputS()
{
	cout << '\n';
	cout << "Matrica sumiznosti\n";
	cout << "\n";
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << " ";
			}
			else
			{
				if (i == 0)
				{
					cout << j;
				}
				else
				{
					if (j == 0)
					{
						cout << i;
					}
					else
					{
						cout << matr[i-1][j-1];
					}
				}
			}
		}
		cout << "\n";
	}
}

void OutputI()
{
	cout << "\n";
	cout << "Matrica incidentnosti\n";
	cout << "1 - pochatok, 2 - kinetc, 3 - petlia\n";
	cout << "Horiontal - rebra, wertical - liniyi\n";
	cout << "\n";
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= K; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << " ";
			}
			else
			{
				if (i == 0)
				{
					cout << j;
				}
				else
				{
					if (j == 0)
					{
						cout << i;
					}
					else
					{
						cout << matr1[i - 1][j - 1];
					}
				}
			}
		}
		cout << "\n";
	}
}

int main()
{

	FILE *f;
	char s[4], s1[1], s2[1];
	f = fopen("statements.txt", "r");
	if (f == NULL)
	{
		cout << "File not found!\n";
	}
	else
	{
		while (!feof(f))
		{
			ind++;
			fgets(s, 4, f);
			s1[0] = s[0];
			s2[0] = s[2];
			i = atoi(s1);
			j = atoi(s2);
			if (ind == 1)
			{
				N = i;
				K = j;
			}
			else
			{
				matr[i - 1][j - 1] = 1;
				matr1[i - 1][ind - 2] = 1;
				matr1[j - 1][ind - 2] = 2;
				if (i == j) matr1[ind - 2][i] = 3;
			}
			if (feof(f)) break;
			puts(s);
			fgets(s, 4, f);
		}
		OutputS();
		OutputI();
	}
	fclose(f);
	system("pause");
}