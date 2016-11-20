#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void incidenceMatrix (const char* filename, int outputType);
void adjacencyMatrix (const char* filename, int outputType);

int main()
{
	system ("clear");

	cout << "===========================	" << endl;

	cout << "Labwork 1" << endl;
	cout << "Kotkova Angelina" << endl;
	cout << "IC-51" << endl;

	cout << "===========================" << endl;	

	int matrixType;
	int outputType;
	int graphNum;

	do
	{
		cout << "What matrix to show?" << endl;
		cout << "1. Incidence matrix" << endl;
		cout << "2. Adjacency matrix" << endl;

		cin >> matrixType;
		system ("clear");
	}
	while (matrixType != 1 && matrixType != 2);

	do
	{
		cout << "Output Type" << endl;
		cout << "1. Screen" << endl;
		cout << "2. File" << endl;

		cin >> outputType;
		system ("clear");
	}
	while (outputType != 1 && outputType != 2);

	do
	{
		cout << "Input graf's number" << endl;

		cin >> graphNum;
		system ("clear");
	}
	while (graphNum < 1 || graphNum > 4);

	char filename[15] = "graph_01_0.txt";
	filename[9] = graphNum + '0';
	cout << "Reading file " << filename << "\n";

	if (matrixType == 1)
	{
		incidenceMatrix (filename, outputType);
	}
	else 
	{
		adjacencyMatrix(filename, outputType);
	}

	system ("bash -c \"echo 'Press any key to continue...' && read -sn 1\"");

	return 0;
}

void incidenceMatrix(const char* filename, int outputType)
{
	ifstream input (filename);
	int v;
	int e;
	int** matrix;
	input >> v >> e;
	matrix = new int* [v];
	for (int i = 0; i < v; ++i)
	{
		matrix[i] = new int[e];
		for (int j = 0; j < e; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < e; i++)
	{
		int a, b;
		input >> a >> b;
		a--;
		b--;
		if (a == b)
		{
			matrix[a][i] = 2;
		}
		else
		{
			matrix[a][i] = -1;
			matrix[b][i] = 1;
		}
	}
	if (outputType == 1)
	{
		cout << "Matrix is:\n   |";
		for (int i = 0; i < e; ++i)
		{
			cout << setw(3) << i + 1 << " |";
		}
		cout << "\n";
		for (int i = 0; i < v; ++i)
		{
			cout << setw(3) << i + 1 << "|";
			for (int j = 0; j < e; ++j)
			{
				cout << setw(3) << matrix[i][j] << " |";
			}
			cout << endl;
		}
	}
	else
	{
		ofstream output ("output.txt");
		output << "   |";
		for (int i = 0; i < e; ++i)
		{
			output << setw(3) << i + 1 << " |";
		}
		output << "\n";
		for (int i = 0; i < v; ++i)
		{
			output << setw(3) << i + 1 << "|";
			for (int j = 0; j < e; ++j)
			{
				output << setw(3) << matrix[i][j] << " |";
			}
			output << endl;
		}
	}
}

void adjacencyMatrix(const char* filename, int outputType)
{
	ifstream input (filename);
	int v;
	int e;
	int** matrix;
	input >> v >> e;
	matrix = new int* [v];
	for (int i = 0; i < v; ++i)
	{
		matrix[i] = new int[v];
		for (int j = 0; j < v; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < e; i++)
	{
		int a, b;
		input >> a >> b;
		a--;
		b--;
		matrix[a][b] = 1;
		//matrix[b][a] = 1;
	}
	if (outputType == 1)
	{
		cout << "Matrix is:\n   |";
		for (int i = 0; i < v; ++i)
		{
			cout << setw(3) << i + 1 << " |";
		}
		cout << "\n";
		for (int i = 0; i < v; ++i)
		{
			cout << setw(3) << i + 1 << "|";
			for (int j = 0; j < v; ++j)
			{
				cout << setw(3) << matrix[i][j] << " |";
			}
			cout << endl;
		}
	}
	else
	{
		ofstream output ("output.txt");
		output << "   |";
		for (int i = 0; i < v; ++i)
		{
			output << setw(3) << i + 1 << " |";
		}
		output << "\n";
		for (int i = 0; i < v; ++i)
		{
			output << setw(3) << i + 1 << "|";
			for (int j = 0; j < v; ++j)
			{
				output << setw(3) << matrix[i][j] << " |";
			}
			output << endl;
		}
	}

}
