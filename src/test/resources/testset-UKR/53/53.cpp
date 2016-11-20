//Лаборотарная работа №1 с ДМ студента ИС-52 ФИВТ Трухана Григория

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<iomanip>
using namespace std;

int data[100][2]; //Массив для хранения вершин и ребер графа

/*Функция для вывода матриц на экран*/
void matrix_output(int **SomeArray, int Length1, int Length2, char c1, char c2)
{
	cout<<"  ";
	for(int k=0; k<Length2;k++)
	{
		cout<<setw(2)<<c2<<k+1;
	}
	cout<<endl;

	for(int i=0; i<Length1;i++)
	{
		cout<<c1<<i+1;
		for(int k=0; k<Length2;k++)
		{
			cout<<setw(3)<<SomeArray[i][k];
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{

	/*Считывание данных о графе с текстового файла*/
	FILE *f_ptr;
	f_ptr=fopen("D:\\text.txt","r");	
    int k=0;

	while(!feof(f_ptr))
	{
		fscanf(f_ptr,"%d",&data[k][0]);
		fscanf(f_ptr,"%d",&data[k][1]);
		k++;
	}

	for (int i=0; i<k;i++)
	{
		cout<<data[i][0]<<"  "<<data[i][1]<<endl;
	}


	fclose(f_ptr);
	system("pause");

	/*Создание динамических массивов*/
	int **incidence_matrix = new int* [data[0][0]];
    for (int count = 0; count < data[0][0]; count++)
	{
        incidence_matrix[count] = new int [data[0][1]]; 
	}

	int **adjacency_matrix = new int* [data[0][0]]; 
    for (int count = 0; count < data[0][0]; count++)
	{
        adjacency_matrix[count] = new int [data[0][0]]; 
	}

	/*Автозаполнения нолями*/
	for(int i=0; i<data[0][0];i++)
	{
	   for(int k=0; k<data[0][1];k++)
	   {
		incidence_matrix[i][k]=0;
	   }
	}

	for(int i=0; i<data[0][0];i++)
	{
	   for(int k=0; k<data[0][0];k++)
	   {
		   adjacency_matrix[i][k]=0;
	   }
	}

	/*Вставка начал и концов ребер в массив (матрица инцедентности)*/
	for(int i=1; i<=data[0][1];i++)
	{
		if(data[i][0]-1==data[i][1]-1)
		{
			incidence_matrix[data[i][0]-1][i-1]=2;
		}
		else
		{
		    incidence_matrix[data[i][0]-1][i-1]=-1;
		    incidence_matrix[data[i][1]-1][i-1]=1;
        }
	}

	/*Создание второй матрицы (смежности)*/
	for(int i=1; i<=data[0][1];i++)
	{
		adjacency_matrix[data[i][0]-1][data[i][1]-1]=1;
	}

	/*Вывод:*/
	cout<<"Incidence matrix:"<<endl;
	matrix_output(incidence_matrix,data[0][0],data[0][1],'v','e');

    cout<<"Adjacency matrix:"<<endl;
	matrix_output(adjacency_matrix,data[0][0],data[0][0],'v','v');

	system("pause");
}