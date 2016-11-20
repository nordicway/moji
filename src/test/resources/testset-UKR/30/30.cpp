#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<stdlib.h>


using namespace std;

int m,n;
int msm[100][100];
int mints[100][100];

void Visualize1();
void Visualize2();

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> n >> m;
	int q1,q2;
	vector < vector<int> > g(n+1);
	for(int i = 0;i < m;i++)
	{
		in >> q1 >> q2;
		g[q1].push_back(q2);
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j < g[i].size();j++)
			msm[i][g[i][j]] = 1;
	}
	Visualize1();

	int t = 0;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 0;j < g[i].size();j++)
		{
			t= t+1;
			mints[i][t] = -1; mints[g[i][j]][t] = 1;
			if (i==g[i][j])
            {
                mints[i][t] = 2;
            }
		}
	}
	Visualize2();
	system("pause");
	return 0;
}

void Visualize1()
{
	cout<<"Матриця сумiжностi : \n";
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
			cout<<setw(3)<<msm[i][j]<<" ";
		cout<<endl;
	}
}

void Visualize2()
{
	cout<<"\n";
	cout<<"Матриця iнцидентностi : \n";
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
		{
			cout<<setw(3)<<mints[i][j]<<" ";
		}
		cout<<endl;
	}
}
