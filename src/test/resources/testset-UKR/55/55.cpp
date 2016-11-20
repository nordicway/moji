#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	FILE *graph;
	//FILE *file;
	graph = fopen("C:\\graph.txt", "r");
	int** matrix;
	int n, m;
	fscanf(graph, "%d %d", &n, &m);
	matrix = new int* [n];
	int** matr = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[m];
		matr[i] = new int[n];
		for (int j = 0; j < m; ++j)
			matrix[i][j] = 0;
		for (int j = 0; j < n; ++j)
			matr[i][j] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		fscanf(graph, "%d %d", &a, &b);
		matrix[a - 1][i] = -1;
		matrix[b - 1][i] = 1;
		if (a == b) matrix[a - 1][i] = 2;
		matr[a - 1][b - 1] = 1;
	}
	cout<<"Incidence matrix\n\n"<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (matrix[i][j] != -1) cout << " ";
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	cout << "\n";
	cout<<"Adjacency matrix\n\n"<<endl;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << matr[i][j] << "  ";
		}
		cout << "\n";
	}

	fclose(graph);
	return 0;
}