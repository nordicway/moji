#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;


int **CreateArray(int p,int l)  
{
	int **arr = new int*[p];           
	for (int i = 0; i < p; i++)
		arr[i] = new int[l];       
	return arr;
}


int **MatrixInc(int n, int m,int **arr,int **arrb)
{
	for (int i = 0; i < n;i++)
	for (int j = 0; j < m; j++)
		arrb[i][j] = 0;
	for (int i = 0; i < m; i++)
	
		if ((arr[i][0]-1) == (arr[i][1]-1)) 	arrb[arr[i][0]-1][i] = 2;
		else
			{
				arrb[arr[i][0]-1][i] = 1;
				arrb[arr[i][1]-1][i] = -1;
			}
	return arrb;
}



int **MatrixSmej(int n, int m,int **arr, int **arrc)
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		arrc[i][j] = 0;
	for (int i = 0; i < m; i++)
	{
		arrc[arr[i][0] - 1][arr[i][1] - 1] = 1;
		arrc[arr[i][1] - 1][arr[i][0] - 1] = 1;
	}
	return arrc;
}

void OutputArr(int **arr, int n, int m)
{
	for (int j = 0; j < m; j++)
		printf("\tb%d", j+1);
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("a%d\t", i+1);
		for (int j = 0; j < m; j++)
			printf("%d\t", arr[i][j]);
		printf("\n");
	}

}

int main()
{
	int n, m;
	int count = 0;
	char ch[50];
	setlocale(0, "");
	ifstream gr;
	gr.open("E:\\DM\\graph.txt", ios::in);
	gr >> n;
	gr >> m;
	int i = 0;
	int **a = CreateArray(m, 2);
	int **b = CreateArray(n, m);
	int **c = CreateArray(n, n);
	while (!gr.eof())
	{
		gr >> a[i][0];
		gr >> a[i][1];
		i++;
	}
	b = MatrixInc(n, m, a, b);
	c = MatrixSmej(n, m, a, c);
	printf("Lab#1 by George Gapanyuk, IS-51\n----------------------\n");
	printf("1.Таблица инцедентности\n2.Таблица смежности\n3.Ввести таблицу инцидентности в файл.\n4.Ввести таблицу смежности в файл\n5.Exit\n");
	while (count != 5)
	{
		cin >> count;
	switch(count)
	{
	case 1:
	{
			  printf("\nТаблица инцедентности:\n----------------------\n");
			  OutputArr(b, n, m);
			  break;
	}
	case 2:
	{
			  printf("\nТаблица смежности:\n--------------------------\n");
			  OutputArr(c, n, n);
			  break;
	}
	case 3:
	{
			  printf("Введите адрес: ");

			  cin >> ch;
			  ofstream grOut(ch, ios::out);
			  for (int i = 0; i < n; i++)
			  {
				  for (int j = 0; j < m; j++)
					  grOut << b[i][j]<<" ";
				  grOut << endl;
			  }
			  grOut.close();
			  break;
	}
	case 4:
	{
			  printf("Введите адрес: ");
			  cin >> ch;
			  ofstream grOut(ch, ios::out);
			  for (int i = 0; i < n; i++)
			  {
				  for (int j = 0; j < n; j++)
					  grOut << c[i][j] << " ";
				  grOut << endl;
			  }
			  grOut.close();
			  break;
	}
	case 5: break;
	default: printf("Nevernii vvod\n");
		break;
	}
}

	gr.close();
	system("pause");
}