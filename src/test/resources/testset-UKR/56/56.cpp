#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
//int **b = new int*[n];
void Incedent();
void Sumis();
int n, m;
FILE *f, *fr;
int main()
{
	while (1)
	{
		system("cls");
		cout << "          MENU        " << endl;
		cout << "1. Vivesti matricu incedentnosti" << endl;
		cout << "2. Vivesti matrice sumizhnosti" << endl;
		cout << "3. Zavershiti programu" << endl;
		int key;
		cout << "Choosen menu item:" << endl;
		cin >> key;
		switch (key)
		{
		case 1:{Incedent(); break; }
		case 2:{Sumis(); break; }
		}
	}
	system("pause");
}
void Incedent()
{
	f = fopen("Graf.txt", "r");
	fr = fopen("Graf.txt", "a");
	fscanf(f, "%d", &n);//kolichestvo vershin
	fscanf(f, "%d", &m);//kolichestvo reber
	int **matrixInc = new int *[n];
	for (int i = 1; i<=n; i++)
		matrixInc[i] = new int[m];
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <=m; j++)
			matrixInc[i][j] = 0;
	for (int i = 1; i <= m; i++){
		int v = 0;
		int u = 0;
		fscanf(f, "%d%d", &v, &u);
		if (v == u)
			matrixInc[v][i] = 2;
		else{
			matrixInc[v][i] = -1;
			matrixInc[u][i] = 1;
		}
	}
	cout << "   ";
	/*for (int i = 1; i <= m; i++)
		printf("%3c%d",'e', i);
	cout << endl;

	cout << "   ";*/
	cout << "Vi hotite zapisat matricu v fail?" << endl;
	char answer;
	cin >> answer;
	if (answer == 'n'){
		cout << "   ";
		for (int i = 1; i <= m; i++)
			printf("%3c%d", 'e', i);
		cout << endl;
		for (int i = 1; i <= n; i++){
			printf(" %1c%d", 'v', i);
			for (int j = 1; j <= m; j++)
				if (j <= 10) printf("%4d", matrixInc[i][j]);
				else printf("%5d", matrixInc[i][j]);
				cout << endl;
		}
	}
	else{
		fputc('\n', fr);
		fputc('   ', fr);
		for (int i = 1; i <= m; i++)
			fprintf(fr,"%3c%d", 'e', i);
		/*fputc ( ' ',fr);*/
		fputc('\n', fr);
		for (int i = 1; i <= n; i++){
			fprintf(fr," %1c%d", 'v', i);
			for (int j = 1; j <= m; j++)
				if (j <= 10) fprintf(fr,"%4d", matrixInc[i][j]);
				else fprintf(fr, "%5d", matrixInc[i][j]);
				fputc('\n', fr);
		}
		fclose(fr);
	}
	system("pause");

}
void Sumis()
{
	cout << "input name of file" << endl;
	/*char name[20] =_gets();*/
	f = fopen("Graf.txt", "r");
	fr = fopen("Graf.txt", "a");
	fscanf(f, "%d", &n);//kolichestvo vershin
	fscanf(f, "%d", &m);//kolichestvo reber
	int **matrixSum = new int *[n];
	for (int i = 1; i<=n; i++)
		matrixSum[i] = new int[n];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			matrixSum[i][j] = 0;
	for (int i = 1; i <= m; i++){
		int v = 0;
		int u = 0;
		fscanf(f, "%d%d", &v, &u);
		matrixSum[v][u] = 1;
	}
	cout << "Vi hotite zapisat matricu v fail?" << endl;
	char answer;
	cin >> answer;
	
	if (answer=='n'){
		cout << "   ";
		for (int i = 1; i <= n; i++)
		printf("%3c%d", 'v', i);
		cout << endl;
		for (int i = 1; i <= n; i++){
			printf(" %1c%d", 'v', i);
			for (int j = 1; j <= n; j++)
				if (j <= 10) printf("%4d", matrixSum[i][j]);
				else printf("%5d", matrixSum[i][j]);
				cout << endl;
		}
	}
	else{
		fputc('\n', fr);
		fputc('   ', fr);
		for (int i = 1; i <= n; i++)
			fprintf(fr, "%3c%d", 'v', i);
		fputc('\n', fr);
		for (int i = 1; i <= n; i++){
			fprintf(fr, " %1c%d", 'v', i);
			for (int j = 1; j <= n; j++)
				if (j <= 10) fprintf(fr, "%4d", matrixSum[i][j]);
				else fprintf(fr, "%5d", matrixSum[i][j]);
				fputc('\n',fr);
		}
		fclose(fr);
	}
	system("pause");
}