#include <iostream>
#include<string>
#include<fstream>
#include <iomanip>
using namespace std;
int value[1000];
int	element[11][22];
ifstream fin;
ofstream fout;
string filename, fileoutname;

void incendmx()
{	
	fin.open(filename+".txt");
	int a, b, k=0, i=1;
	fin>>a>>b;
	for (int j=0; j<a;j++)
	{
		for(int k=0; k<b;k++)
		{
			element[j][k]=0;
		}
	}
	do 
	{
		fin >>value[i]>>value[i+1];
		if (value[i]==value[i+1]) 
			element[value[i]-1] [k]=2;
		else
		{
			element[value[i]-1] [k]=-1;
			element[value[i+1]-1][k]=1;
		}
		i+=2;
		k++;
	}while(!fin.eof());
	fin.close();
	for (int j=0; j<a;j++)
	{
		for(int k=0; k<b;k++)
		{
			if (element[j][k]<0)
			cout<<element[j][k]<<" ";
			else cout<<" "<<element[j][k]<<" ";
		}
		cout<<endl;
	}
}
void adjmx()
{	
	fin.open(filename+".txt");
	int i=1;
	int a,b;
	fin>>a>>b;
	for (int j=0; j<a;j++)
	{
		for(int k=0; k<a;k++)
		{
			element[j][k]=0;
		}
	}
	do 
	{
		fin >>value[i]>>value[i+1];
		element[value[i]-1][value[i+1]-1]++;
		i+=2;
	}while(!fin.eof());
	fin.close();
	for (int j=0; j<a;j++)
	{
		for(int k=0; k<a;k++)
		{
		 cout<<element[j][k]<<" ";
		}
		cout<<endl;
	}

}
int main()
{	
	cout<< "Enter input file name: "<<endl; 
	getline(cin, filename); 
	cout<<"enter output name: "<<endl;
	getline(cin, fileoutname);
	cout<<"\n incendence matrix \n";
	incendmx();
	cout<<"\n adjacency matrix \n";
	adjmx();
	system("pause");
	return 0;
	
}	
	