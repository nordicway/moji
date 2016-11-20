#include<iostream>

using namespace std;

int n, m;
int Dugi[25][2];
int Matr[25][25];

void FuncIn()   //Функція матриці інцидентності
{
	int v, u;
	for (int i = 0; i < m; i++)
	{ 
		v = Dugi[i][0];
		u = Dugi[i][1];
		if (v != u)
		{
			Matr[v - 1][i] = -1;
			Matr[u - 1][i] = 1;
		}
		else Matr[v - 1][i] = 2;
	}
	cout << "Matrix incidenthosti" << endl; //виведення матриці
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (Matr[i][j] == -1)
				cout << " " << Matr[i][j];
			else cout << "  " << Matr[i][j];
			cout << endl;
	}
}

void FuncSum() //Функція матриці суміжності
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Matr[i][j] = 0;
	int v, u;
	for (int i = 0; i < m; i++)
	{
		v = Dugi[i][0];
		u = Dugi[i][1];
		Matr[v - 1][u - 1] = 1;
	}
	cout << "Matrix sumizhnosti" << endl; //виведення матриці
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << "  " << Matr[i][j];
		cout << endl;
	}
}

int main()
{
	char key;
	do{
		cout << "Enter n (vershini grapha): ";
		cin >> n;
		cout << "Enter m (rebra grapha): ";
		cin >> m;
		cout << "Enter begin and end reber grapha" << endl;
		for (int i = 0; i < m; i++)
			cin >> Dugi[i][0] >> Dugi[i][1];
		cout << "Inputed" << endl;
		FuncIn();
		FuncSum();
		cout << "Repeat program? Y/N" << endl;
		cin >> key;
	} while (key != 'n' && key != 'N');
	return 0;
}