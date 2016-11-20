
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

string fileWay = "D:\\lab1\\";

struct Vertex
{
	int begin;
	int end;
};

class ReadGraph
{
public:

	int numberOfEdges;
	int numberOfVertexes; 
	Vertex vertexes[200];

	ReadGraph(int numberTxtFile)
	{
		ifstream file;
		string sAllNumber = "";
		char currentChar;
		int currentPartOfTxtFile = 0;
		int currentNumberVertex = 0;
		string way = fileWay + to_string(numberTxtFile) + ".txt";
		file.open(way);
		do
		{
			file.get(currentChar);
			if (currentChar == 10 || currentChar == 32 || file.eof())
			{
				currentPartOfTxtFile++;
				if (currentPartOfTxtFile == 1) numberOfEdges = atoi(sAllNumber.c_str());
				else if (currentPartOfTxtFile == 2) numberOfVertexes = atoi(sAllNumber.c_str());
				else if (currentPartOfTxtFile % 2 == 1) vertexes[currentNumberVertex].begin = atoi(sAllNumber.c_str());
				else if (currentPartOfTxtFile % 2 == 0) vertexes[currentNumberVertex].end = atoi(sAllNumber.c_str());
				if (currentPartOfTxtFile % 2 == 0 && currentPartOfTxtFile != 2) currentNumberVertex++;
				sAllNumber = "";
				continue;
			}
			sAllNumber += currentChar;
		} while (!file.eof());
		file.close();
	}
};

class IncidenceGraph : public ReadGraph
{
public:
	int matrixIncidence[200][200];

	IncidenceGraph(int iTxtFile) : ReadGraph(iTxtFile)
	{
		for (int i = 0; i < 200; i++)
		{
			for (int j = 0; j < 200; j++)
			{
				matrixIncidence[i][j] = 404;
			}
		}
		for (int i = 0; i < numberOfEdges; i++)
		{
			for (int j = 0; j < numberOfVertexes; j++)
			{
				matrixIncidence[i][j] = 0;
			}
		}
		for (int i = 0; i < numberOfVertexes; i++)
		{
			matrixIncidence[vertexes[i].begin - 1][i] = -1;
			matrixIncidence[vertexes[i].end - 1][i] = 1;
		}
	}

	void showMatrixIncidence()
	{
		cout << "   ";
		for (int i = 1; i < numberOfVertexes + 1; i++)
		{
			cout << setw(3) << i;
		}
		for (int i = 0; i < numberOfVertexes; i++)
		{
			cout << "   ";
		}
		cout << endl;
		for (int i = 0; i < numberOfEdges; i++)
		{
			cout << setw(2) << i + 1;
			cout << ' ';
			for (int j = 0; j < numberOfVertexes; j++)
			{
				cout << setw(3) << matrixIncidence[i][j];
			}
			cout << ' ' << endl;
		}
	}
};

class AdjacencyGraph : public ReadGraph
{
public:
	int matrixAdjacency[200][200];

	AdjacencyGraph(int iTxtFile) : ReadGraph(iTxtFile)
	{
		for (int i = 0; i < 200; i++)
		{
			for (int j = 0; j < 200; j++)
			{
				matrixAdjacency[i][j] = 404;
			}
		}
		for (int i = 0; i < numberOfEdges; i++)
		{
			for (int j = 0; j < numberOfEdges; j++)
			{
				matrixAdjacency[i][j] = 0;
			}
		}
		for (int i = 0; i < numberOfVertexes; i++)
		{
			matrixAdjacency[vertexes[i].end - 1][vertexes[i].begin - 1] = 1;
		}
	}

	void showMatrixAdjacency()
	{
		cout << "   ";
		for (int i = 1; i < numberOfEdges + 1; i++)
		{
			cout << setw(3) << i;
		}
		for (int i = 0; i < numberOfEdges; i++)
		{
			cout << "   ";
		}
		cout << endl;
		for (int i = 0; i < numberOfEdges; i++)
		{
			cout << setw(2) << i + 1;
			cout << ' ';
			for (int j = 0; j < numberOfEdges; j++)
			{
				cout << setw(3) << matrixAdjacency[i][j];
			}
			cout << ' ' << endl;
		}
	}

};

void main()
{
system("color f0");
setlocale(LC_ALL, "RUS");
int ways = 1;
while (ways != 0)
{
cout << "Меню:" << endl;
cout << "1.Показать матрицу смежности" << endl;
cout << "2.Показать матрицу инцидентности:" << endl;
cout << "0.Выйти" << endl;
cin >> ways;
if (ways == 1)
{
cout << "Введите номер текстового документа" << endl;
int numberTxtFile = 1;
cin >> numberTxtFile;
AdjacencyGraph GraphCon(numberTxtFile);
GraphCon.showMatrixAdjacency();
}
else if (ways == 2)
{
cout << "Введите номер текстового документа" << endl;
int numberTxtFile = 1;
cin >> numberTxtFile;
IncidenceGraph GraphInc(numberTxtFile);
GraphInc.showMatrixIncidence();
}

if (ways == 0)
{
return;
}
system("pause");
system("cls");
}
system("pause");
}