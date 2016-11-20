#pragma warning(disable: 4996)
#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>

using namespace std;

#define endl "\n"

const int N = 100, M = 1000;

int main()
{
	freopen("InPut.txt","r",stdin);
	//freopen("OutPut.txt","w",stdout);
	int n, m;
	int x, y;
	int c[N][N], v[N][M];
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			c[i][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			v[i][j] = 0;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		c[x][y] = 1;
		v[x][i] = -1;
		v[y][i] = 1;
		if (x == y) v[x][i] = 2;
	}
	cout << "matrix sumijna" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << c[i][j] << ' ';
		cout << endl;
	}
	cout << "matrix incedentnosti" << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout <<setw(3)<< v[i][j];
		cout << endl;
	}
}