#include<iostream>
#include<stdlib.h>
#include<iomanip>

using namespace std;
int b;
int m;
int c[10][10];
int a[100][100] ;
int M, N, x, y;

void author()
{
	cout << "This laboratory work was created by Andrii Metelyuk\n IS-51 group" << endl;
}
void task()
{
	cout << "Task: Build matrix of incedence and adjacency " << endl;
}
void input()
{
	cout << "Enter number of vertex and edges:" << endl;
	cout << "======================================" << endl;
	cin >> b >> m;
	cout << "======================================" << endl;
	cout << "Vertex: " << b << endl;
	cout << "Edges: " << m << endl;
}
void calculation()
{
	cout << "=======================================" << endl;
	cout << "Enter the cordinates" << endl;
	for (int i = 1; i <= m; i++)
	{
		
		a[100][100] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		cin>> x >> y;
		a[x][y] = 1;
	}
	cout << "============Matrix of adjacency====================" <<endl ;
	for(int i = 1; i <= b+1; i++)
	{
		for (int j = 1; j <= b; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << "============Matrix of incidence====================" << endl;
	
	for (int i = 1; i <= m; i++)
	{

		a[100][100] = 0;
	}
	for (int o = 1; o <= m; o++)
	{
		a[x][o] = -1;
		a[y][o] = 1;
		if (x == y) a[y][o] = 2;
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= b; j++)
			cout <<setw(2)<< a[i][j] << " ";
		cout << endl;
	}
}


	int main()
{
	author();
	task();
	input();
	calculation();
}
