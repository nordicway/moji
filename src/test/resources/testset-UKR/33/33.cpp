#include <conio.h>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class graph
{
private:
	int n;						// Кількість вершин
	int m;						// Кількість ребер
	vector<int> start;			// Ребра
	vector<int> end;			//
	vector<vector<int>> V;		// Матриця
	multimap<int, int> lines;	// Множина ребер
	string path;				// Файл
	ifstream fin;				// Поток виводу з файла
	ofstream fout;				// Поток вводу в файл
public:

	void setInputFile(string file)	// Вибір файлу
	{
		fin.open(file + ".txt");	
	}

	void setOutputFile(string file)
	{
		fout.open(file + ".txt");
	}

	void InMatrix()
	{
		int cv, cu;								// Теперішні змінні
		fin >> n >> m;							// Ввід даних з файлу
		
		V.resize(n);							// Резервація пам'яті для матриці
		for (int i = 0; i < n; i++)		
			V[i].resize(m);
		for (int i(0); i < n; i++)				// Ініціалізація нулями
			for (int j(0); j < m; j++)			
				V[i][j] = 0;					
	
		for (int i = 0; i < m; i++)				// Зчитування з файлу графа
		{
			fin >> cv >> cu;
			start.push_back(cv);
			end.push_back(cu);
		}

		int i = 0;								
		for (auto it = start.begin(), it1 = end.begin(); it != start.end(); it++, it1++)	// Заповнення матриці інцендентності
		{
			if (*it - 1 != *it1- 1)
			{
				V[*it - 1][i] = -1;
				V[*it1 - 1][i++] = 1;
			}
			else V[*it1 - 1][i++] = 2;
		}

		for (int j(0); j < n; j++)								// Вивід матриці
		{
			for (int k(0); k < m; k++)
			{
				if (V[j][k] != -1)
				{
					cout << ' ' << V[j][k] << ' ';
					fout << ' ' << V[j][k] << ' ';
				}
				else
				{
					cout << V[j][k] << ' ';
					fout << V[j][k] << ' ';
				}
			}
			cout << endl;
			fout << endl;
		}
	}

	void AdMatrix()
	{
		int cv, cu;								// Теперішні змінні
		fin >> n >> m;							// Ввід даних з файлу

		V.resize(n);							// Резервація пам'яті для матриці
		for (int i = 0; i < n; i++)
			V[i].resize(n);
		for (int i(0); i < n; i++)				// Ініціалізація нулями
			for (int j(0); j < n; j++)
				V[i][j] = 0;

		for (int i = 0; i < m; i++)				// Зчитування з файлу графа
		{
			fin >> cv >> cu;
			lines.insert(pair<int, int>(cv, cu));
		}

		for (auto it : lines)					// Ініціалізація матриці
			V[it.first-1][it.second-1]++;

		for (int j(0); j < n; j++)				// Вивід матриці
		{
			for (int k(0); k < n; k++)
			{
				cout << ' ' << V[j][k] << ' ';
				fout << ' ' << V[j][k] << ' ';
			}
			cout << endl;
			fout << endl;
		}
	}

	void clear()
	{
		fin.close();											// Закрити файл
		fout.close();
		V.clear();												// Удалити дані
		start.clear();											//
		end.clear();											//
		lines.clear();
	}
};

int main()
{
	string filename; // файл вводу
	string filename1;// файл виводу
	graph G;		 // граф 
	bool end(false); //
	char answer;	 //
	
	while (!end)
	{
		cout << "Enter input file name: ";
		getline(cin, filename);
		cout << "Enter output file name: ";
		getline(cin, filename1);

		G.setInputFile(filename); 
		G.setOutputFile(filename1);

		cout << "Incendental Matrix: " << endl;
		G.InMatrix();
		G.clear();
		G.setInputFile(filename);
		G.setOutputFile(filename1+"2");
		cout << "Adjacency Matrix: " << endl;
		G.AdMatrix();
		G.clear();

		cout << "Another file? (y\\n)";
		answer = _getch();
		(answer == 'y' || answer == 'Y') ? end = false: end = true;
		cout << endl;
	}
	return 0;
}