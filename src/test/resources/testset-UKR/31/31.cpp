#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std;
int z[100],st[100],fin[100],matrixI[100][100],matrixS[100][100];
int k=0,j=2;
int s=0,f=1,i=0;
void read(){
	setlocale(LC_ALL, "RUS");
	float n = 0.4;
	int a;
	fstream F;

	//открываем файл в режиме чтения
	F.open("E:\\lab1\\graph_01_1.txt");
	//если открытие файла прошло корректно, то
	if (F)
	{

		while (!F.eof())
		{
			//чтение очередного значения из потока F в переменную a
			F >> a;
			//вывод значения переменной a на экран
			z[k] = a;
					//увеличение количества считанных чисел

			k++;
		}
		//закрытие потока
		F.close();
		//вовод на экран количества считанных чисел
		
	}

	else cout << " Файл не существует" << endl;
	system("pause");
	
}

void read2(){
	while (f <= k){
		st[i] = z[s];
		fin[i] = z[f];
		s+=j;
		f+=j;
		i++;
		
	}
	
}
void matrix1(){
	for (i = 0; i <= k / 2 - 1; i++){
		if (st[i] == fin[i]){
			matrixI[st[i] - 1][i] = 2;
		}
		else{
			matrixI[st[i] - 1][i] = 1;
			matrixI[fin[i] - 1][i] = -1;
		}

	}
}

void writeI(){
	cout << "   ";
	for (i = 0; i <= k / 2 - 1; i++){
		
			cout << "e" << i + 1 << "  ";
	}
	cout << endl;
	for (i = 0; i <= k / 2 - 1; i++){
		if (i + 1 >= 10){
			cout << "v" << i + 1 << " ";
		}
		else{
			cout << "v" << i + 1 << "  ";
		}
		for (j = 0; j <= k / 2 - 1; j++){
			if (j + 1 < 10){
				if (matrixI[i][j] < 0){
					cout << matrixI[i][j] << "  ";
				}
				else{
					cout << matrixI[i][j] << "   ";
				}
			}
			else{
				if (matrixI[i][j] < 0){
					cout << matrixI[i][j] << "   ";
				}
				else{
					cout << matrixI[i][j] << "    ";
				}
			}
		}
		cout << endl;
	}
}

void matrix2(){
	for (i = 0; i <= k / 2 - 1; i++){
		matrixS[st[i]-1][fin[i]-1] = 1;
	}
}

void writeS(){
	cout << "   ";
	for (i = 0; i <= k / 2 - 1; i++){

		cout << "v" << i + 1 << "  ";
	}
	cout << endl;
	for (i = 0; i <= k / 2 - 1; i++){
		if (i + 1 >= 10){
			cout << "v" << i + 1 << " ";
		}
		else{
			cout << "v" << i + 1 << "  ";
		}
		for (j = 0; j <= k / 2 - 1; j++){
			if (j + 1 < 10){
				if (matrixS[i][j] < 0){
					cout << matrixS[i][j] << "  ";
				}
				else{
					cout << matrixS[i][j] << "   ";
				}
			}
			else{
				if (matrixS[i][j] < 0){
					cout << matrixS[i][j] << "   ";
				}
				else{
					cout << matrixS[i][j] << "    ";
				}
			}
		}
		cout << endl;
	}
}
int main()
{
	read();
	read2();
	matrix1();
	cout << "Матрица інцидентності :" << endl;
	writeI();
	matrix2();
	cout << "Матриця сумижностi :" << endl;
	writeS();



	system("pause");
}