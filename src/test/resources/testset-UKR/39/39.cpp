#include <iostream>
using namespace std;
int n, m,u,v;
typedef int matrix[100][100];
matrix a, b;
char ans = 'y';
int answer;
void ReadGraph()
{
	cout << "Please, enter the number of the top and the edges of the graph in the first line and after that enter all of the adges:" << endl;
	cin >> n >> m;
	for (int j = 1; j <= n; j++)
		for (int k = 1; k <= n; k++)
			a[j][k] = 0;
	for (int j = 1; j <= n; j++)
		for (int k = 1; k <= m; k++)
			b[j][k] = 0;
	for (int i = 1; i <= m; i++)
	{

		cin >> v >> u;
		a[v][u] = 1;
		if (u == v) b[u][i] = 2;
		else
		{
			b[v][i] = -1;
			b[u][i] = 1;
		}
	}
}
void OutputMatriX(matrix Mat, int line, int kol)
{
	for (int i = 1; i <= line; i++)
	{
		for (int j = 1; j <= kol; j++)
		{
			if (Mat[i][j] >= 0) cout << " " << Mat[i][j];
			else cout << " " << Mat[i][j];
		}
		cout << endl;
	}
}
int Menu()
{
	int answer1;
	cout << "Menu" << endl;
	cout << "1.Adjacency matrix" << endl;
	cout << "2.incidence matrix" << endl;
	cout << "3.Read new graph" << endl;
	cout << "4.Finish" << endl;
	cout << "Please, choose the operation from menu by ints number: ";
	cin >> answer1;
	return answer1;

}
int main()
{
	do
	{
		answer=Menu();
		if (answer == 3) ReadGraph();
		else if (answer == 1) OutputMatriX(a, n, n);
		else if (answer == 2) OutputMatriX(b, n, m); 
	} while (answer!=4);
	system("pause");

}