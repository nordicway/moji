
#include <stdlib.h> 
#include <iostream> 
#include <fstream> 
#include <iomanip> 
using namespace std;
int n, m, A[20], B[20], check;
typedef int Matrix[20][20];
Matrix I, S;
char answer;

void gr_input(int*l, int*k) //Введення графу із текстового файлу 
{
	ifstream fin;
	fin.open("input.txt");
	fin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		fin >> *l >> *k;
		l++;
		k++;
	}
	fin.close();
}
void gr_check(int*l, int*k) //Перевірка введеного графу на правильність 
{
	if ((m>0) && (n > 0) && (m < 30) && (n < 30)) check = 1; else check = 0;
	for (int i = 0; i < m; i++)
	{
		if ((*l>0) && (*k > 0) && (*l <= n) && (*k <= n)) check = 1;
		else
		{
			check = 0;
			break;
		}
		l++;
		k++;
	}
}
void gr_output(int*l, int*k) //Виведення графу на екран 
{
	cout << "Заданий граф." << endl;
	cout << "Кiлькiсть вершин: " << n << endl;
	cout << "Кiлькiсть ребер: " << m << endl;
	for (int i = 0; i < m; i++)
	{
		cout << "Ребро " << i + 1 << ": " << *l << " " << *k << endl;
		l++;
		k++;
	}
}
void matr_ints(Matrix matr, int*l, int*k) //Матриця інцедентності 
{
	for (int i = 0; i < m; i++)
	{
		matr[*l - 1][i] = -1;
		matr[*k - 1][i] = 1;
		if (*l == *k) matr[*l - 1][i] = 2;
		l++;
		k++;
	}
}
void matr_sum(Matrix matr, int*l, int*k) //Матриця суміжності 
{
	for (int i = 0; i < m; i++)
	{
		matr[*l - 1][*k - 1] = 1;
		l++;
		k++;
	}
}
void out_screen(Matrix m1, Matrix m2) //Виведення на екран 
{
	cout << "Матриця iнцедентностi:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << setw(3) << m1[i][j];
		cout << endl;
	}
	cout << "Матриця сумiжностi:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(3) << m2[i][j];
		cout << endl;
	}
}
void out_file(Matrix m1, Matrix m2) //Виведення у файл 
{
	ofstream fout;
	fout.open("output.txt");
	fout << "Матриця iнцедентностi:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			fout << setw(3) << m1[i][j];
		fout << endl;
	}
	fout << "Матриця сумiжностi:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fout << setw(3) << m2[i][j];
		fout << endl;
	}
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "Ukrainian");
	gr_input(A, B); //Введення графу із текстового файлу 
	gr_check(A, B); //Перевірка введеного графу на правильність 
	if (check == 1)
	{
		gr_output(A, B); //Виведення графу на екран 
		matr_sum(S, A, B); //Матриця суміжності 
		matr_ints(I, A, B); //Матриця інцедентності 
		cout << "Вивести результат на екран? (Y\\N): "; //Запит на виведення матриць на екран 
		cin >> answer;
		if ((answer == 'Y') || (answer == 'y')) out_screen(I, S); //Виведення на екран 
		cout << "Записати результат у файл? (output.txt) (Y\\N): "; //Запит на виведення матриць у файл 
		cin >> answer;
		if ((answer == 'Y') || (answer == 'y')) out_file(I, S); //Виведення у файл 
	}
	else cout << "Помилка. Граф заданий невiрно" << endl; //Виведення повідомлення про помилку 
	system("pause");
	return 0;
}