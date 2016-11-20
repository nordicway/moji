/* Мигаль Дмитро ІС-51 ФІОТ, лабораторна №1 */
#include<iostream>
#include<stdio.h>
using namespace std;

FILE *fin, *fout; //вхідний і вихідний файл
char str[255];	//проміжний рядок
int incMatrix[255][255], sumMatrix[255][255];	//матриця інцидентності, матриця сумісності
int vectors[255][2];	//масив для збереження координат вершин
char n[255], m[255];	//к-сть вершин, к-сть векторів
char tempv[255];		//проміжний вектор

int main()
{
	//Відкриття файлів
	fin = fopen("input.txt", "r");
	fout = fopen("output.txt", "w");

	//Зчитування к-сті вершин і к-сті векторів 
	fgets(str, 100, fin);
	strcpy(n, strtok(str, " "));
	strcpy(m, strtok(NULL, " "));

	//Зчитування координат всіх векторів
	for (int i = 0; i < atoi(m); i++)
	{
		fgets(str, 100, fin);
		strcpy(tempv, strtok(str, " "));
		vectors[i][0] = atoi(tempv);
		strcpy(tempv, strtok(NULL, " "));
		vectors[i][1] = atoi(tempv);
	}

	//Генерування матриці суміжності
	for (int i = 0; i < atoi(m); i++)
	{
		sumMatrix[vectors[i][0]-1][vectors[i][1]-1] = 1;
	}

	//записування матриці суміжності в вихідний файл
	fputs("Матриця суміжності:\n", fout);
	for (int i = 0; i < atoi(n); i++)
	{
		for (int j = 0; j < atoi(n); j++)
		{
			fprintf(fout, "%d ", sumMatrix[i][j]);
		}
		fputs("\n",fout);
	}

	//генерування матриці інцидентності
	for (int i = 0; i < atoi(m); i++)
	{
		incMatrix[vectors[i][0] - 1][i] = -1;
		incMatrix[vectors[i][1] - 1][i] = 1;
		if (vectors[i][0] == vectors[i][1]) incMatrix[vectors[i][0] - 1][i] = 2;
	}

	//записування матриці інцидентності в вихідний файл
	fputs("\nМатриця інцидентності:\n", fout);
	for (int i = 0; i < atoi(n); i++)
	{
		for (int j = 0; j < atoi(m); j++)
		{
			if (incMatrix[i][j] == -1) {
				fprintf(fout, "%d ", incMatrix[i][j]);
			}
			else {
				fprintf(fout, " %d ", incMatrix[i][j]);
			}
		}
		fputs("\n", fout);
	}

	//закриття файлів
	fclose(fin);
	fclose(fout);
}