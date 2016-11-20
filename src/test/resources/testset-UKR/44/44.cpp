#include <iostream>
#include <iomanip>

using namespace std;

int n, m, mas1[115][1122], mas2[115][115];

int main()
{
	int x, y;
	int flagstart;
	cout << "Graph or-1, neor-2" << endl;
	cin >> flagstart;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y;
		mas2[x][y] = 1;
		if (flagstart == 2) 
			mas2[y][x] = 1;
		mas1[x][i] = -1;
		mas1[y][i] = 1;
		if (flagstart == 2) mas1[x][i] = 1;
		if (x == y) mas1[x][i] = 2;
	}
	int flag;
	cout << "inz = 1 , smej = 2" << endl;
	cin >> flag;
	if (flag == 2)  {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cout << setw(3) << mas2[i][j];
			cout << endl;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cout << setw(3) << mas1[i][j];
			cout << endl;
		}
	}
	system("pause");
}