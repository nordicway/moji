#include <iostream>
#include <iomanip> 
using namespace std;
int n, m;
int matrSym[1000][1000], matrReb[1000][1000],matrInc[1000][1000];
void Sym()
{
	cout << "Matruca smegnosti :" << endl;
	for (int i = 0; i < m; i++)
	{
		matrSym[matrReb[i][0]][matrReb[i][1]] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout <<  setw(2) << matrSym[i][j];
		}
		cout << endl;
	}
}
void Inc()
{
	cout << "Matruca incendentnosti :" << endl;
	for (int i = 0; i < m; i++)
	{
		if (matrReb[i][0] == matrReb[i][1])
		{
			matrInc[matrReb[i][0]][i]=2;
		}
		else
		{
			matrInc[matrReb[i][0]][i] = -1;
			matrInc[matrReb[i][1]][i] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(2) << matrInc[i][j];
		}
		cout << endl;
	}
}
int main()
{
	int k;
	cout << "Vvedite kolichestvo vershun i kolichestvo reber\n";
	cin >> n >> m;
	cout << "Vvedite spisok reber\n";
	for (int i = 0; i < m; i++)
	{
		cin >> matrReb[i][0];
		cin >> matrReb[i][1];
		matrReb[i][0]--;
		matrReb[i][1]--;
	}
	cout << "Vvedite '1' dl9 vuvoda matricu smegnosti"<<endl;
	cout << "Vvedite '2' dl9 vuvoda matricu incedentnosti"<<endl;
	cout << "Vvedite '3' dl9 vuvoda oboih matric "<<endl;
	cin >> k;
	switch (k)
	{
		case 1: 
		{ 
			Sym(); 
			
			break; 
		}
		case 2: 
		{
			Inc(); 
			break;
		}
		case 3:
		{
			Sym(); 
			Inc();
			break;
		}
	}
}