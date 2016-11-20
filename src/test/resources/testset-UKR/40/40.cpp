#include <iostream>
#include <iomanip>
using namespace std;
int ver, reb, a[50][50], b[50][50], q = 0, j = 0, l, x, z,p;
int h[50][50];

int main()
{
	cout << "Input how much verwin, reber" << endl;
	cin >> ver >> reb;
	l = reb;
	x = l;
	z = l;
	for (int k = 0; k < ver; k++)
	{
		for (int m = 0; m < ver; m++)
		{
			b[k][m] = 0;
		}
	
	}
	do
	{
		for (int a = 0; a < ver; a++)
		{
			h[a][x] = 0;
		}
		x--;
	} while (x=0);
	cout << endl;
	for (int i= 0; i < reb; i++)
	{		
	cin >> a[0][i] >> a[0][i + 1];
	q=a[0][i];
	p=j=a[0][i + 1];
	for (int m = 0; m < reb; m++)
	{
	b[q-1][j-1] = 1;
	}			
	do
	{
	for (int m = 0; m < ver; m++)
	{
		h[m][z] = 0;
	}
	z--;
	} while (z = 0);
	for (int j = 0; j < ver; j++)
	{
		if (q==p)
		{
			h[i][q] = 2;
			h[i][p] = 2;
		}
		else
		{
			h[i][q] = -1;
			h[i][p] = 1;
		}
	}
			
	} 
	cout <<"Adjacency matrix" << endl;//Matrix sumiwnosti
	for (int k = 0; k < ver; k++)
	{
		for (int m = 0; m < ver; m++)
		{
			
			cout << b[k][m];
		}
			cout << endl;
	}
	
	cout << endl;
	cout << "incidence matrix" << endl;//Matrix insidentnosti
	for (int k = 1; k < ver+1; k++)
	{
		for (int m = 0; m < reb; m++)
		{
				cout <<setw(2)<< h[m][k];

		}
		cout << endl;
	}
	system("pause");
	
}
