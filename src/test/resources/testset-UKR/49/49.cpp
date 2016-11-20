#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
int Matrix[100][100];

using namespace std;
 
void MatrixS()
{
	ifstream in("F:\\Graphs\\graph_01.txt");
	ofstream out("F:\\Graphs\\MatrixSn.txt");

	int n, m, i, j, p;
	in >> n >> m;
 
	for (int p = 0; p<m; p++)
	{
		in >> i >> j;
		Matrix[i-1][j-1] = 1;
	}
	 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			out << setw(3) << Matrix[i][j] << " ";
		}
		out << endl;
	}
	cout << "Rezult in file MatrixSn" << endl;

	in.close();
	out.close();
}
void MatrixI()
{
	ifstream in("F:\\Graphs\\graph_01.txt");
	ofstream out("F:\\Graphs\\MatrixIn.txt");
	int n, m, i, j, k,f;
	in>> n>> m;
	for (int k = 0; k < m; k++)
	{
		in >> i >> j;
		Matrix[i - 1][k] = -1;
		Matrix[j - 1][k] = 1;
		if (Matrix[i - 1][k]==Matrix[j - 1][k])
		{
		Matrix[i-1][k] = 2;
		}
	}
	for (int i = 0; i< n; i++)
	{
		for (int j = 0; j < m; j++)
			out << setw(2)<< Matrix[i][j]<<" ";
		out << endl;
	}
	cout << "Rezult in file MatrixIn" << endl;
	in.close();
	out.close();

}

int main()
{
	while (1)
	{
		system("cls");
		cout << "Lab#11 " << endl;
		cout << "Author: Julia Shishman Is-53 " << endl;

		cout << " MENU \n" << endl;

		cout << "1.Adjacency matrix " << endl;

		cout << "2.Incidence matrix" << endl;

		cout << "3. Exit" << endl;

		cout << endl;
		int key;

		cout << "Choosen menu item:";

		cin >> key;

		switch (key){

		case 1: {MatrixS(); break; }

		case 2: {MatrixI(); break; }

		case 3: {exit(0); break; }

		default: {cout << "Try another time..."; _getch(); break; }

		}
	}
		system("pause");
	}
