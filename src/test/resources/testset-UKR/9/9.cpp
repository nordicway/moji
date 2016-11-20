// Lab1 // Ilya Dorogin // IS-53

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

int matrinc(string filename, string out)
{	
	ifstream fin;
	ofstream fout;
	fin.open(filename + ".txt");
	fout.open(out + ".txt", ios::app);
	int n, m;
	fin >> n >> m;
	int *v = new int[m];
	int *u = new int[m];
	for (int i = 0; i < m; i++)
	{	
		fin >> v[i] >> u[i];
		v[i]--; u[i]--;
	}
	cout << "Incidence matrix:" << endl;
	fout << "Incidence matrix:" << endl;
	int **minc = new int*[n];
	for (int i = 0; i < n; i++)
		minc[i] = new int[m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			if (i == v[j] && i == u[j])
				minc[i][j] = 2;
			else if (i == v[j])
				minc[i][j] = -1;
			else if (i == u[j])
				minc[i][j] = 1;
			else minc[i][j] = 0;
			cout << setw(2) << minc[i][j];
			fout << setw(2) << minc[i][j];
		}
		cout << endl;
		fout << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] minc[i];
	delete[] minc;
	delete[] v;
	delete[] u;
	return 0;
}

int matrsum(string filename, string out)
{
	ifstream fin;
	ofstream fout;
	fin.open(filename + ".txt");
	fout.open(out + ".txt", ios::app);
	int n, m;
	fin >> n >> m;
	int *v = new int[m];
	int *u = new int[m];
	for (int i = 0; i < m; i++)
	{
		fin >> v[i] >> u[i];
		v[i]--; u[i]--;
	}
	cout << "Adjacency matrix:" << endl;
	fout << "\nAdjacency matrix:" << endl;
	int **msum = new int*[n];
	for (int i = 0; i < n; i++)
		msum[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (i == v[k] && j == u[k])
				{
					msum[i][j] = 1;
					break;
				}
				else msum[i][j] = 0;
			}
			cout << setw(2) << msum[i][j];
			fout << setw(2) << msum[i][j];
		}
		cout << endl;
		fout << endl;
	}

	for (int i = 0; i < n; i++)
		delete[] msum[i];
	delete[] msum;
	delete[] v;
	delete[] u;
	return 0;
}

int main()
{	
	ofstream fout;
	ifstream fin;
	string filename, out;
	cout << "Enter name of your .txt file" << endl;
	getline(cin, filename);
	fin.open(filename + ".txt");
	while (!fin.is_open())
	{
		cout << "Enter correct name of your .txt file" << endl;
		getline(cin, filename);
		fin.open(filename + ".txt");
	}
	cout << "Enter name of .txt file for results" << endl;
	getline(cin, out);
	fout.open(out + ".txt");
	cout << endl;
	matrinc(filename, out);
	cout << endl;
	matrsum(filename, out);
	
	_getch();
	return 0;
}
