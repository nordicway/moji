#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<conio.h>
int n, m; //кількість вершин та ребер графа
int a[100][2], b[100][100], c[100][100]; //масиви списку ребер, матриці інцидентності та матриці суміжності
char key;
FILE *endfile, *startfile;  //початковий та кінцеві файли
// Функція побудови матриці інцидентності
void incidence()
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if ((i+1 == a[j][0]) && (i+1 == a[j][1])) //якщо вершина i - інцидентна ребру j
			b[i][j] = 2; 
		else if (i+1 == a[j][0])  //якщо вершина i - початок ребра j
			b[i][j] = -1;
		else if (i+1 == a[j][1]) //якщо вершина i - кінець ребра j
			b[i][j] = 1;
	}
}
// Функція побудови матриці суміжності
void compability() 
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		if (i + 1 == a[j][0]) //якщо вершина інцидентна ребру
			c[a[j][0] - 1][a[j][1] - 1] = 1;
		if (i + 1 == a[j][1])
			c[a[j][0] - 1][a[j][1] - 1] = 1;
	}
}
// Функція виводу матриць
void arrayout(int m, int a[100][100])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		if (a[i][j]==-1)
			printf("%d ", a[i][j]);
		else printf(" %d ", a[i][j]);
		puts("");
	}
}
// Функція запису матриці до файлу
void arrayfile(FILE *endfile, int m, int a[100][100])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		if (a[i][j] == -1)
			fprintf(endfile, "%d ", a[i][j]);
		else fprintf(endfile, " %d ", a[i][j]);
		fprintf(endfile, "\n");
	}
	fprintf(endfile, "\n");
}
// Головна функція програми
int main()
{
	puts("DM: Lab #1\nName: Ksenia Rastvorova\nGroup : IC - 51\nFaculty :IOT\nVariant : 19\n"); // вивід відомостей про автора на екран
	puts("Reading text file");
	startfile = fopen("startfile.txt", "r");//відкрити файл для читання
	endfile = fopen("endfile.txt", "w");//відкрит файл для запису
	if (startfile != NULL) //якщо файл не пустий
	{
		fscanf(startfile, "%d%d", &n, &m);//Зчитати кількість вершин та ребер з файлу
		printf("Number of peaks:%d ", n); puts("");
		printf("Number of ribs:%d", m); puts("");
		for (int i = 0; i < m; i++)
		for (int j = 0; j < 2; j++)
			fscanf(startfile, "%d", &a[i][j]);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				printf("%d ", a[i][j]);//Виводимо список ребер на екран
			}
			puts("");
		}
		incidence();
		compability();
		do{
			puts("\nMENU:"); //Меню програми
			puts( "1. Display incidence matrix on the screen");
			puts( "2. Record incidence matrix to file.");
			puts( "3. Display compability matrix on the screen");
			puts( "4. Record compability matrix to file.");
			puts( "5. Exit.");
			puts( "");
			puts( "Choose element of menu: ");
			fflush(stdin);
			key = getchar();
			switch (key)
			{
			case '1':{puts("Incidence matrix"); arrayout(m, b); break; }
			case '2':{puts("Incidence matrix recorded to file."); fprintf(endfile, "%s\n", "Incidence matrix"); arrayfile(endfile, m, b); break; }
			case '3':{puts("Compability matrix"); arrayout(n, c); break; }
			case '4':{puts("Compability matrix recorded to file."); fprintf(endfile, "%s\n", "Compability matrix"); arrayfile(endfile, n, c); break; }
			default:{puts("End of program..."); break; }
			}
		} while (key != '5');

	}
	else puts("File not open");
	fclose(startfile);//Закрити файл
	fputc('\n', endfile);
	fclose(endfile);
	_getch();
}