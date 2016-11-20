#include<iostream>
#include<fstream>

int graph[50][3];
int edges;
int vertexes;
int matrix[50][50];
FILE* in;

using namespace std;

bool entry()
{
	cout << "Written by Daniil Drobot IS-5107" << endl;
	cout << "To enter data manually input m/M, to read from file enter f/F" << endl;
	char enter;
	cin >> enter;
	while (enter != 'm' || enter != 'M' || enter != 'f' || enter != 'F')
	{
	if (enter == 'm' || enter == 'M')
	{
		return true;
	}
	else if (enter == 'f' || enter == 'F')
	{
		return false;
	}
	}
}

void fileInput()
{
	in=fopen("input.txt","r");
	int vertexes,edges;
	cin >> vertexes >> edges;
	int i = 0;
	while (!feof(in))
	{
		cin >> graph[i][0]>>graph[i][1];
		i++;
	}
}

void manualInput()
{
	cout << "Enter amount of vertexes" << endl;
	cin >> vertexes;
	cout << "Enter amount of edges" << endl;
	cin >> edges;
	cout << "Enter edges" << endl;
	for (int i = 0; i < edges; i++)
	{
		cin >> graph[i][0];
		cin >> graph[i][1];
	}
}

void incidence()
{
	cout << "Incidence Matrix" << endl;
	for (int i = 0; i < edges; i++)
	{
		if (graph[i][0] == graph[i][1])
		{
			matrix[graph[i][0]-1][i] = 1;
			matrix[graph[i][1]-1][i] = 1;
			continue;
		}
		matrix[graph[i][0]-1][i] = 1;
		matrix[graph[i][1]-1][i] = -1;
	}
	for (int i = 0; i < vertexes; i++)
	{
		for (int j = 0; j < edges; j++)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

void refresh()
{
	for (int i = 0; i < vertexes; i++)
	{
		for (int j = 0; j < edges; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void coverage()
{
	cout << "Coverage Matrix" << endl;
	for (int i = 0; i < edges; i++)
	{
		matrix[graph[i][0]-1][graph[i][1]-1] = 1;
	}
	for (int i = 0; i < vertexes; i++)
	{
		for (int j = 0; j < vertexes; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	if (!entry())
	{
		fileInput();
	}
	else{
		manualInput();
	}
	incidence();
	refresh();
	coverage();
}