
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include <clocale>
using namespace std;
int **incd;
int **sumg;
int nv = 0;
int ne = 0;
void out(bool f, bool incd_mode)
{
	FILE *dst;
	int **a;
	if (f)
	{
		char s[30];
		int errcode;
		do
		{
			cout << "Введiть iм'я вихiдного файлу (без пробiлiв) -> ";
			scanf("%s", s);
			errcode = fopen_s(&dst, s, "w");
			if (errcode != 0) cout << "Помилка при вiдкриваннi файлу на запис!" << endl << endl;
		} while (errcode != 0);
		cout << endl;
	}
	else dst = stdout;
	int scd;
	if (incd_mode)
	{
		scd = ne;
		a = incd;
	}
	else
	{
		scd = nv;
		a = sumg;
	}
	for (int i = 0; i<nv; i++)
	{
		for (int j = 0; j < scd; j++)
		{
			if (incd_mode && a[i][j] != -1) fputc(' ', dst);
			fprintf(dst, "%d ", a[i][j]);
		}
		fputc('\n', dst);
	}
	if (f) fclose(dst);
	else cout << endl << endl;
}
void answer()
{
	int c;
	cout << "Виберiть операцiю " << endl;
	cout << "Натиснiть 1, щоб вивести матрицю iнцидентностi на екран" << endl;
	cout << "Натиснiть 2, щоб вивести матрицю сумiжностi на екран" << endl;
	cout << "Натиснiть 3, щоб вивести матрицю iнцидентностi в файл" << endl;
	cout << "Натиснiть 4, щоб вивести матрицю сумiжностi в файл" << endl;
	cout << "Натиснiть пробiл, щоб вийти " << endl << endl;
	do c = _getch(); while (!((c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == ' ')));
	switch (c)
	{
	case '1': out(false, true); answer(); break;
	case '2': out(false, false); answer(); break;
	case '3': out(true, true); answer(); break;
	case '4': out(true, false); answer(); break;
	}
}
int main()
{
	setlocale(LC_CTYPE, "rus");
	FILE *i;

	char fn[30];
	int errcode;
	do
	{
		cout << "Введiть iм'я вхiдного файлу (без пробiлiв) -> ";
		scanf("%s", fn);
		errcode = fopen_s(&i, fn, "r");
		if (errcode != 0) cout << "Помилка при вiдкриваннi файлу на читання!" << endl << endl;
	} while (errcode != 0);
	int v = 0;
	int u = 0;
	int j;
	fscanf_s(i, "%d%d", &nv, &ne);
	incd = new int *[nv];
	for (j = 0; j<nv; j++)
	{
		incd[j] = new int[ne];
		for (int k = 0; k<ne; k++)
			incd[j][k] = 0;
	}

	sumg = new int *[nv];
	for (j = 0; j<nv; j++)
	{
		sumg[j] = new int[nv];
		for (int k = 0; k<nv; k++)
			sumg[j][k] = 0;
	}

	for (j = 0; j<ne; j++)
	{
		fscanf_s(i, "%d%d", &v, &u);
		sumg[v - 1][u - 1] = 1;
		if (v != u)
		{
			incd[v - 1][j] = -1;
			incd[u - 1][j] = 1;
		}
		else incd[v - 1][j] = 2;
	}
	fclose(i);
	answer();
}