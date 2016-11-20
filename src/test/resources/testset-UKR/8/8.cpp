#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<fstream>
using namespace std;
FILE *flp, *fls;
int a, b, t,h;
int d = 0;
int k = 0;
int l = 0;
int A[50][50], B[50][50], C[50][50];
char fil[40];
char h1[] = "Incedence matrix:";
char h2[] = "Sumishnist matrix:";
void Input()
{
	char fname[40];
	puts("Input the address of reading file");
	gets(fname);
	fls = fopen(fname, "rt");
	fscanf(fls, "%d", &a);
	fscanf(fls, "%d", &b);
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			fscanf(fls, "%d", &A[i][j]);
		}
	}
}
void Solution1()
{
	for (int m = 1; m < a + 1; m++)
	{
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (A[i][j] == m)
				{
					d++;
					t = j;
				}
			}
			if (d != 0)
			{
				if (d == 2)
				{
					B[k][l] = 2;
				}
				else if (d == 1 && t == 1)
				{
					B[k][l] = 1;
				}
				else
				{
					B[k][l] = -1;
				}
			}
			else
			{
				B[k][l] = 0;
			}
			d = 0;
			l++;
		}
		l = 0;
		k++;
	}
	cout << "=============================" << endl;
}
void Screen1()
{
	for (int k = 0; k < a; k++)
	{
		for (int l = 0; l < b; l++)
		{
			if (B[k][l] == -1)
			{
				cout << " " << B[k][l];
			}
			else
			{
				cout << "  " << B[k][l];
			}
		}
		cout << endl;
	}
}
void Text1()
{
		fprintf(flp, "%s", h1);
		fprintf(flp, "\n");
	for (int k = 0; k < a; k++)
	{
		for (int l = 0; l < b; l++)
		{
			if (B[k][l] == -1)
			{
				fprintf(flp, " ");
				fprintf(flp, "%d", B[k][l]);
			}
			else
			{
				fprintf(flp, "  ");
				fprintf(flp, "%d", B[k][l]);
			}
		}
		fprintf(flp, "\n");
	}
}
void Screen1AndText1()
{
	fprintf(flp, "%s", h1);
	fprintf(flp, "\n");
	for (int k = 0; k < a; k++)
	{
		for (int l = 0; l < b; l++)
		{
			if (B[k][l] == -1)
			{
				cout << " " << B[k][l];
				fprintf(flp, " ");
				fprintf(flp, "%d", B[k][l]);
			}
			else
			{
				cout << "  " << B[k][l];
				fprintf(flp, "  ");
				fprintf(flp, "%d", B[k][l]);
			}
		}
		cout << endl;
		fprintf(flp, "\n");
	}
}
void Solution2()
{
	for (int m = 1; m < a + 1; m++)
	{
		for (int i = 0; i < b; i++)
		{
			if (A[i][0] == m)
			{
				C[m - 1][A[i][1] - 1] = 1;
			}
		}
	}
}
void Screen2()
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (C[i][j] != 1)
			{
				C[i][j] = 0;
			}
			cout <<"  "<< C[i][j] ;
		}
		cout << endl;
	}
}
void Text2()
{
	fprintf(flp, "%s", h2);
	fprintf(flp, "\n");
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (C[i][j] != 1)
			{
				C[i][j] = 0;
			}
			fprintf(flp, "  ");
			fprintf(flp, "%d", C[i][j]);
		}
		fprintf(flp, "\n");
	}
}
void Screen2AndText2()
{
	fprintf(flp, "%s", h2);
	fprintf(flp, "\n");
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (C[i][j] != 1)
			{
				C[i][j] = 0;
			}
			cout <<"  "<< C[i][j];
			fprintf(flp, "  ");
			fprintf(flp, "%d", C[i][j]);
		}
		cout << endl;
		fprintf(flp, "\n");
	}
}
int main()
{
	Input();
	fclose(fls);
	puts("Input the address of file for a possible writing");
	gets(fil);
	flp = fopen(fil, "wt");
	Solution1();
	Solution2();
	do
	{
		 h = 1;
		char symbol;
		cout << "Do you want to see result in screen(1), in file(2), in screen and file(3) ?" << endl;
		cin >> symbol;
		switch (symbol)
		{
		case '1':
			cout << "Incedence matrix:" << endl;
			Screen1();
			cout << "===========================" << endl;
			cout << "Sumishnist matrix:" << endl;
			Screen2();
			break;
		case '2':
			Text1();
			Text2();
			break;
		case '3':
			cout << "Incedence matrix:" << endl;
			Screen1AndText1();
			cout << "===========================" << endl;
			cout << "Sumishnist matrix:" << endl;
			Screen2AndText2();
			break;
		default:
			cout << "You were wrong, try again" << endl;
			h = 0;
			break;
		}
	} while (h == 0);
	fclose(flp);
	system("pause");
}