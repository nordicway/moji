#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int m1[100][100], m2[100][100];
int m,n,length;
int mas[100][2];
int matrix[100][100];
int matrix2[100][100];
int stepin[100][20];
int distan[100][100];
int dosiag[100][100];
int marshrut[100];
bool /*orientov = true,*/ naiavnistCykla,flag;

void mnozhennia();
void matrixdistan();
void matrixsum();
//void orientovanist();
void dosdist();
void zviaznist();
void Poshuk(int v, int i);
void Cykly();
void mnozhennia1(int **m1, int **m2);

void Cykly()
{
	naiavnistCykla = false;
	for(int i = 0; i <= m; i++)
		for(int j = 1; j <= n; j++)
			if (mas[i][0] == j)
			{
				length = 0; 
				marshrut[length] = j;
				Poshuk(j, mas[i][1]);
			}
	if (!naiavnistCykla) cout << "Cykliv nemae" << endl; 
}
void Poshuk(int v, int i)
{
	length++;
	flag = true;
 
	for (int j = 0; j <= m; j++)
		if (mas[j][0] == i)
		{
		marshrut[length] = i;
		for (int k = 1; k <= length+1; k++) 
			if (mas[j][1] == marshrut[k])
			{
				flag = false;
				break;
			}
			if (flag)
			{
				if (mas[j][1] == v)
				{
				naiavnistCykla = true;
				for (int k = 0; k <= length; k++)
				cout << marshrut[k] << "->";
				cout << v << endl;
				/*if (!orientov)
				{
					cout << v;
					for (int k = length; k >= 0; k--)
					cout << "->" << marshrut[k];
					cout << endl;
				}*/
			}
			else Poshuk(v, mas[j][1]);
			}
		}
}
void mnozhennia1(int m1[100][100], int m2[100][100])
{
	int arr[100][100];
	int p;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			p=0;
			for (int k = 1; k <= n; k++)
				p += m1[i][k]*m2[k][j];
			arr[i][j] = p;
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				m1[i][j] = arr[i][j];
}
void zviaznist()
{
	bool flag = true;
	for (int i = 1; i <=n; i++)
		for (int j = 1; j <= n; j++)
			if (dosiag[i][j] != 1)
			{
				flag = false;
				break;
			}
	if (flag) cout << "Graf e sylno zviazanym" << endl;
	else 
	{
		flag = true;
		for (int i = 1; i <=n; i++)
			for (int j = 1; j <= n; j++)
				if ( (dosiag[i][j] + dosiag[j][i]) == 0) 
				{
					flag = false;
					break;
				}
		if (flag) cout << "Graf e odnobichno zviazanym" << endl;
		else
		{
			/*for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
				{
					m1[i][j] = matrix2[j][i] + matrix2[i][j];
					m2[i][j] = m1[i][j];
				}
			for (int i = 1; i <= n; i++) 
			{
				m1[i][i] = 1;
				m2[i][i] = 1;
			}
			for (int i = 1; i < n-1; i++) 
				mnozhennia1(m1,m2);*/
			for (int i = 1; i <= n; i++)
			{
				flag = true;
				for (int j = 1; j <= n; j++)
				{
					int p = 0;
					for (int k = 1; k <= n; k++) 
						p += (matrix[i][k] + matrix[k][j]);
					if (p == 0)
					{
						flag = false;
						break;
					}
				}
			}
			if (flag) cout << "Graf e slabo zviazanym" << endl;
			else cout << "Graf ne e zviazanym" << endl;
		}
	}
}
void dosdist()
{
	FILE *f1;
	cout << "Dlia vyvedennia na ekran narysnit 1" << endl;
	cout << "Dlia zberezhennia u fail narysnit 2" << endl;
	cout << "Shob perejty dali natysnit 3" << endl;
	int key;
	cin >> key;
	do
	{
		switch(key)
		{
			case 1:
				cout << "Matrycia vidstanei:" << endl;
				for(int i = 0; i <= n; i++)
				{
					for (int j = 0; j <= n; j++)
					cout << distan[i][j] <<  "  ";
					cout << endl;
				}
				cout << "Matrycia dosiazhnosti:" << endl;
				for(int i = 0; i <= n; i++)
				{
					for (int j = 0; j <= n; j++)
					cout << dosiag[i][j] <<  "  ";
					cout << endl;
				}
				break;
			case 2:
				char adres[200];
				cout << "VVedit adresu faila dlia zberezhennia" << endl;
				fflush(stdin);
				gets(adres);
				f1=fopen(adres,"w");
				fprintf(f1,"Matrycia vidstanei:\n");
				for(int i = 0; i <= n; i++)
				{
					for (int j = 0; j <= n; j++)	
						fprintf(f1,"%d  ", distan[i][j]);
					fputs("\n",f1);
				}
				fprintf(f1,"Matrycia dosiazhnosti:\n");
				for(int i = 0; i <= n; i++)
				{
					for (int j = 0; j <= n; j++)	
						fprintf(f1,"%d  ", dosiag[i][j]);
					fputs("\n",f1);
				}
				fclose(f1);
				break;
		}
	cout << "Dlia vyvedennia na ekran natysnit 1" << endl;
	cout << "Dlia zberezhennia u fail natysnit 2" << endl;
	cout << "Shob perejty dali natysnit 3" << endl;
	cin >> key;
	}while((key == 1) || (key == 2));
}
void mnozhennia()
{
	int arr[100][100];
	int p;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			p=0;
			for (int k = 1; k <= n; k++)
				p += matrix2[i][k]*matrix[k][j];
			arr[i][j] = p;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			matrix2[i][j] = arr[i][j];
}
void matrixdistan()
{
	bool flag;
	int k=1;
	do
	{
		flag = false;
		mnozhennia();
		k++;
		if (k > m) break;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
			{
				if ((i != j) && (distan[i][j] == 0))
				{
					flag = true;
					if (matrix2[i][j] != 0)
					distan[i][j] = k;
			    }
			}
	}while(flag);
	for(int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
		{
			if ((i > 0) && (j > 0))
				if(distan[i][j] == 0) dosiag[i][j] = 0;
				else dosiag[i][j] = 1;
			else 
				dosiag[i][j] = distan[i][j];
		}
	for(int i = 0; i <= n; i++) dosiag[i][i] = 1;
}
void matrixsum()
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if ((i == 0) || (j == 0))
			{
				matrix[0][0]=0;
				matrix[0][j]=j;
				matrix[i][0]=i;
				matrix2[0][0]=0;
				matrix2[0][j]=j;
				matrix2[i][0]=i;
				distan[0][0]=0;
				distan[0][j]=j;
				distan[i][0]=i;
			}
			else 
			{
				bool flag=true;
				for (int k=0; k<m; k++)
				if ((i == mas[k][0])&&(j == mas[k][1]))
				{
					matrix[i][j]=1;
					matrix2[i][j]=1;
					distan[i][j]=1;
					flag=false;
				}
				if (flag)
				{
					matrix[i][j]=0;
					matrix2[i][j]=0;
					distan[i][j]=0;
				}
			}			
		}
	}
	/*if (!orientov)
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				if (matrix[i][j] == 1) 
				{
					matrix[j][i]=1;
					matrix2[j][i]=1;
					distan[j][i]=1;
				}*/
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";
	}
}

void main()
{
	FILE *f;
	f = fopen("C:\\documents and settings\\C++\\LabD3\\Graf.txt", "r");
	char str[100][10]; 
	fgets(str[0], 10, f);
	n = atoi(strtok(str[0], " "));
	m = atoi(strtok(NULL, " "));
	if (m>100) cout << "Nevirna kilkist reber" << endl;
	bool flag=true;
	int i=0, j;
	while(!feof(f))
	{
		fgets(str[i+1], 10, f);
		mas[i][0] = atoi(strtok(str[i+1], " "));
		mas[i][1] = atoi(strtok(NULL, " "));
		if ((mas[i][0]>n)||(mas[i][1]>n)) 
		{
			flag=false;
			j=i+1;
		}
		i++;
	}
	//orientovanist();
	matrixsum();
	matrixdistan();
	if (i!=m) 
		cout << "Nevirna kilkist reber" << endl;
	else if (flag)
	{
		int key;
		cout << "                   Menu" << endl;
		cout << "1. Vyvesty na ekran abo u fail matryci vadstanei ta dosiazhnosti." << endl;
		cout << "2. Vyvesty na ekran typ zviaznosti grafa." << endl;
		cout << "3. Vyznachyty prosti cykly." << endl;
		cout << "4. Vyhid." << endl;
		cout << "Vyberit punkt menu:" << endl;
		cin >> key;
		while((key == 1) || (key == 2) || (key == 3))
		{
			switch(key)
			{
				case 1: 
					{
						dosdist();
					break;
					}
				case 2:
						zviaznist();
					break;
				case 3:
						Cykly();
					break;
				case 4:
					break;
				default:
					cout << "Nepravulnyi punkt" << endl;
					break;
			}
			cout << "Vyberit punkt menu:" << endl;
			cin >> key;
		}
	}
	else cout << "Invalid file. Pomylka u " << j << " rebri." << endl;
	fclose(f);
	system("pause");
}