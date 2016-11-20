#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

int n,m;    //n- number of vertices, m- number of edges

void content()
{
	ifstream in("fin.txt");
	cout << "File content is:\n" << endl;
	in >> n >> m;
	cout << " " << n << " " << m << endl;
	for (int i=0; i<m; i++)
	{
		int a,b;
		in >> a >> b;
		cout << " " << a << " " << b << endl;
	}
	in.close();
}

int **zeromat(int n,int m)
{   
	int **mat = new int*[n];   //creating of the first column of matrix

	for (int i = 0; i < n; i++)
		mat[i] = new int[m];       //creating of matrix
	
	for (int i = 0; i < n; i++)        //fill matrix with zeros
		for (int j = 0; j < m; j++)
			mat[i][j] = 0;

	return mat;
}

void Printmat(int **arr,int n,int m)
{
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
			cout << setw(2) << arr[i][j] << " ";		//outputting matrix
		cout << endl;
	}
	cout << endl;		
}

int **adjacencymat(const char *filename)
{
	ifstream in(filename);
	in >> n >> m;			//reading the number of vertices and edges
	int **adjacency = zeromat(n,n);   //creating of zero matrix
	for (int i = 0; i < m; i++)
	{
		int a,b;
		in >> a >> b;			//reading the initial and final vertices of edge 
		adjacency[a-1][b-1] = 1;				//fill the appropriate cell of the matrix 
	}		
	in.close();
	return adjacency;
}

int **incedentmat(const char *filename)
{
	ifstream in(filename);
	in >> n >> m;				//reading the number of vertices and edges
	int **incedent = zeromat(n,m);		//creating of zero matrix
	for (int i = 0; i < m; i++){
		int a,b;
		in >> a >> b;			//reading the initial and final vertices of edge 
		if (a == b)
			incedent[a-1][i] = 2;		//the case of loop
		else {
				incedent[a-1][i] = -1; //fill the appropriate cell of the matrix
				incedent[b-1][i] = 1;
		     } 
	}		
	in.close();
	return incedent;
}

int main(){
	cout << "Lab#1" << endl;
	cout << "Auhtor of program is Belous Mikhail IS-51\n" << endl;
	
	content();

	char key,answer;
		
	int **adj = adjacencymat("fin.txt");
	int **inc = incedentmat("fin.txt");

	do {
		cout << "\nPress '1' for making the adjacency matrix \nor '2' for making the incedent matrix"<<endl;
		cin >> key;
		cout << endl;
		if(key == '1')
			Printmat(adj,n,n); //outputting the adjacency matrix
		else 
			if(key == '2')
				Printmat(inc,n,m);  //outputting the incedent matrix
		cout << "Do you want to try again?(y/n)" << endl;
		cin >> answer;
	} while (answer == 'y');

	system("pause");
}
