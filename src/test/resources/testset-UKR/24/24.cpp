#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string> // подключаем строки
#include <fstream> // подключаем файлы
#include<iomanip>

using namespace std; // используем стандартное пространство имен

const char separator[] = " ";
const int N = 255;
int mass1[N];
int mass2[N];
int matr[N][N];
int matr2[N][N];
char *FName = "graph_01_1.txt";

void init(char S[N])
{
	for (int i = 0; i<N; i++) S[i] = '\0';
}

void vikolupuem()
{
	char *S = new char[N];
	ifstream in1(FName);
	char S1[N];
	char S2[N];
	init(S1);
	init(S2);
	int i = 0, j = 0;
	while (!in1.eof()) //Будем читать информацию пока не дойдем до конца файла
	{
		in1.getline(S, N); //Построчное считывание информации в S
						   //Вывод очередной строки на экран
		char *temp = new char[strlen(S)];
		strcpy(temp, S);
		int count_my_words = 1;
		char *Ptr = NULL;
		Ptr = strtok(S, separator);
		while (Ptr)
		{
			switch (count_my_words)
			{
			case 1: strcpy(S1, Ptr);  //?????? ???????????? ?? ?????????, ?? ???? ???????????? ??????? ?????? ?? ????????, ?? ??? ??
				count_my_words++; //??????????, ??? ? ?????? ????????? ??? ???-?? ????????
				break;            //??. ???? ??? switch
			case 2: strcpy(S2, Ptr);   //??????????
				count_my_words++;
				break;
			}
			Ptr = strtok(0, separator);
		}
		mass1[i] = atoi(S1);
		mass2[j] = atoi(S2);
		i++; j++;
	}
	in1.close();
}

void f1()
{
	//рамка матрици
	int k = 1, l = 1;
	matr[0][0] = 0;
	for (int j = 1; j < mass1[0] + 1; j++)
	{
		matr[0][j] = k;
		k++;
	}
	for (int i = 1; i < mass1[0] + 1; i++)
	{
		matr[i][0] = l;
		l++;
	}

	///*мясо матрици*/
	int q = 1;
	while (q < mass2[0] + 1)
	{
		matr[mass1[q]][mass2[q]] = 1;
		q++;
	}
	for (int i = 1; i < mass1[0] + 1; i++)
	{
		for (int j = 1; j < mass1[0] + 1; j++)
		{
			if (matr[i][j] != 1) matr[i][j] = 0;
		}
	}
}
void vivsym()
{
	for (int i = 0; i < mass1[0] + 1; i++) /*вывод матрици сумижности*/
	{
		for (int j = 0; j < mass1[0] + 1; j++)
		{
			cout << setw(2) << matr[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}
void mat()
{//рамка матрици
	int k = 1, l = 1;
	matr2[0][0] = 0;
	for (int j = 1; j < mass2[0] + 1; j++)
	{
		matr2[0][j] = k;
		k++;
	}
	for (int i = 1; i < mass1[0] + 1; i++)
	{
		matr2[i][0] = l;
		l++;
	}
	///*мясо матрици*/
	int q = 1;
	while (q < mass2[0] + 1)
	{
		matr2[mass1[q]][q] = -1;
		matr2[mass2[q]][q] = 1;
		if (mass1[q] == mass2[q])
		{
			matr2[mass2[q]][q] = 2;
		}
		q++;
	}
}
void vivint()
{
	for (int i = 0; i < mass1[0] + 1; i++) /*вывод матрици інцидентності*/
	{
		for (int j = 0; j < mass2[0] + 1; j++)
		{
			cout << setw(2) << matr2[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}
void pro()
{
	cout << "Kosyak Olexandr" << endl;
	cout << "IS-53" << endl;
	cout << "Zalikivka is5312" << endl;
	system("pause");
}
int main()
{
	vikolupuem();
	f1();
	mat();
	while (1)
	{
		system("cls");
		cout << "          MENY \n" << endl;
		cout << "1. Matrica symiznosti" << endl;
		cout << "2. Matrica incidentnosti" << endl;
		cout << "3. Pro avtora" << endl;
		cout << "4. Vihod" << endl;
		cout << endl;
		int tik;
		cout << "Viberite punkt meny:";
		cin >> tik;
		switch (tik)
		{
		case 1: {system("cls"); vivsym(); break; }
		case 2: {system("cls"); vivint(); break; }
		case 3: {system("cls"); pro(); break; }
		case 4: {exit(0); break; }
		default: {system("cls"); cout << "Vi oshiblis klavishey"; system("pause"); break; }
		}
	}
	return 0;
}


