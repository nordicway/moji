#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>

using namespace std;
	
#pragma warning(disable : 4996)

FILE * FileCreateOrOpen();
char * GetInput();
void PrintLine(FILE *file, char *input);
void SaveWordInFile(char *word);
void SaveFindCount(int count);


int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Гуппа ИС-53 \n";
	cout << "Корнев Антон\n";
	cout << "Лабораторная работа №1\n";

	FILE *fileTxt; // переменная для записи файла	

	fileTxt = FileCreateOrOpen(); // открываем файл или считываем
	PrintLine(fileTxt, GetInput()); // Выводим на экран наши найденные строки 

	fclose(fileTxt); // Закрываем файл
	system("pause");
}

void SaveWordInFile(char *word)
{
	FILE* file = fopen("Lab11_save.txt", "a"); // открываем файл для сохранения строки
	fputs(word, file); // сохранили строку
	fclose(file); // закрыли файл
}

void SaveFindCount(int count)
{
	FILE *file = fopen("Lab11_save.txt", "a"); // открываем файл
	fputs("\nНайдено строк: ", file); // добавили строку

	char *findCount = new char[64]; // преобразовываем число в строку
	itoa(count, findCount, 10); // 10 - десятичная систсема счисления
	fputs(findCount, file); // дописываем в конец наше число

	fclose(file); // закрываем файл
}

FILE *FileCreateOrOpen()
{
	FILE * file; // переменная чтоб вернуть файл
	file = fopen("Lab11.txt", "r"); // открываем файл с правами "Чтения"
	cout << "Файл 'Lab11.txt' готов к работе!" << endl;
	return file; // возвращаем файл
}

char *GetInput()
{
	cout << "Введите вашу строку: ";
	char *myString = new char[512]; // создаем переменную для хранения нашей строки
	gets_s(myString, 512); // записываем строку в переменную
	return myString; // возвращаем строку
}

void PrintLine(FILE *file, char *input)
{
	int findCount = 0; // переменная для количества строк в которые входит наша строка
	while (!feof(file)) // перебираем строки в файле
	{
		char *newString = new char[512]; // сюда будем записывать строку
		fgets(newString, 512, file); // записываем строку
		if (strstr(newString, input)) // если строка содержит наше слово
		{
			findCount++; // увеличиваем количество найденных строк на 1
			puts(newString); // выводим строку на экран
			SaveWordInFile(newString); // Сохраняем строку в отделный файл
		}
	}
	SaveFindCount(findCount); // После окончания работы цикла записываем количество найденных строк в файл
}