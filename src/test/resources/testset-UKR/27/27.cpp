#include <iostream>
#include <fstream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
using namespace std;

int   i,i1,i2,i3,i9;
int         j12,j13;
int      k,k1,k2,k3;

char *delimiter=" ";						 //утвоорити лексеми які розділимо символом "пробіл"
char *delimiter1="";
char *delimiter2=" ";
char* p;									 //покажчик р
char* p1;
char* p2;
char* p3;
int abc[100][100];
//////////////////Start of matrix adj///////////
int ma1[10][10]=

	{
		0,0,0,0,1,0,0,0,0,1,
		0,1,1,0,1,0,0,0,0,0,
		0,1,0,0,0,1,0,0,0,0,
		0,0,0,0,1,0,1,1,0,0,
		1,1,0,1,0,0,0,0,0,0,
		0,0,1,0,0,0,0,0,1,0,
		0,0,0,1,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,1,
		0,0,0,0,0,1,0,0,0,0,
		1,0,0,0,0,0,0,1,0,0,
	};
int ma2[10][10]=
{
		0,0,1,1,0,0,0,0,0,0,
		0,0,1,0,0,0,0,1,0,1,
		1,1,1,0,0,1,1,0,1,0,
		1,0,0,0,1,1,0,0,0,0,
		0,0,0,1,0,1,1,0,0,0,
		0,0,1,1,1,0,0,0,0,0,
		0,0,1,0,1,0,0,1,1,0,
		0,1,0,0,0,0,1,1,0,0,
		0,0,1,1,0,0,1,0,0,1,
		0,1,0,0,0,0,0,0,1,0,
};
int ma3[20][20]=
{		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
		0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,
		0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,
		0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,
		0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,
		0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,
		1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
};
int ma4[20][20]=
{		0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,0,1,
		0,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,
		0,0,1,0,0,1,0,1,0,0,0,0,1,1,1,0,0,0,1,0,
		0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,0,0,
		1,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,
		0,1,1,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,0,
		0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1,1,1,0,
		0,0,1,0,0,0,1,0,0,1,1,1,1,1,1,0,1,0,1,0,
		0,1,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,
		1,0,0,1,1,1,0,1,1,1,1,0,1,0,0,0,1,0,0,0,
		0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,1,0,0,1,0,1,1,0,0,0,0,1,1,
		0,0,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,
		0,0,1,0,0,0,1,1,1,0,1,1,0,0,0,0,0,1,1,0,
		0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,
		0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,1,
		0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,
		1,1,0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1,0,
		0,0,1,0,0,1,1,1,0,0,0,1,0,1,1,1,0,1,0,0,
		1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
};
//////////End of matrix of adj//////////////////
int mai1[10][21];
///////////////////////////
char mas[200][200];		 //					 //масив где сохраним лексемы
char mas1[200][200];     //                  //масив где сохраним лексемы каждой строки отдельно
char mas2[200][200];     //                  //масив где сохраним лексемы каждой строки отдельно
char arrword[200][200];  //                  //масив с началими и концами из исходного файла
char start[50][50];      //                  //масив с пробелами между индексами(четные или начальная точка)
char finish[50][50];     //                  //масив с пробелами между индексами(нечетные или конечная точка)
char startf[50][50];     //                  //масив уже без пробелов но еще с типом "char"
char finishf[50][50];    //                  //масив уже без пробелов но еще с типом "char"
int startb[50];          //                  //переведенный в "int" масив с начальными точками
int finishb[50];         //                  //переведенный в "int" масив с конечными точками
///////////////////////////


int r[100];

int num,type;

char  buff[1024][1024];               //масив для перенесення текстового файлу до консолі
char s1[200];            
char s2[200][200];
char s00[200][200];
char s5[200];
char s9[200][200];
char Tops[100],Edges[100];                       //висоти та ребра


void EdgesAndTopss()
{   
		strcpy(s1,buff[1]);
		p=strtok(s1,delimiter);
		while(p!=NULL)
	{
		strcpy(mas[k],p);
		k++;
		p=strtok(NULL,delimiter);
	}
		cout<<"number of words="<<k<<endl;
	strcpy(Tops,mas[0]);
	strcpy(Edges,mas[1]);
}









void StartandEnd()
{		
	{		cout<<"\npochatki1"<<endl;
			for(int i=1;i<2*(atoi(Edges));i++)
			{	p1=strtok(buff[i],delimiter1);
			    strcpy(s2[i],buff[i]);
				cout<<s2[i]<<endl;
			}	
			while(p1!=NULL)
			
			{
				strcpy(mas1[i],p1);
				i++;
				p1=strtok(NULL,delimiter);
			}
	}
	
		
		
	for(int i1=1;i1<2*(atoi(Edges));i1++)
	{
		strcpy(s9[i1],s2[i1]);
		p3=strtok(s9[i1],delimiter2);
		while(p3!=NULL)

		{
			strcpy(arrword[k3],p3);
			k3++;
			p3=strtok(NULL,delimiter2);
		}
	}
		
}
	


//начальная(базовая сортировка)
void sort()
{   
			cout<<endl;
		{
			for(int i1=2,i9=2;i1<47,i9<47;i1++,i9++)
	   
	
			if(i1 %2==0)
			
			{
				strcpy(start[i9],arrword[i1]);
			}
		
		
			else if(i1 %2!=0)
			{
				strcpy(finish[i9],arrword[i1]);
		
			}
		
		}
}
// 2 этап сортировки
void sort2()
{
	for (int i1=2,i9=1;i1<atoi(Edges),i9<atoi(Edges);i1++,i9++)
  {
	strcpy(startf[i9],start[i1]);
	strcpy(finishf[i9],finish[i1]);
		i1++;
  }
for (int i1=3,i9=1;i1<atoi(Edges),i9<atoi(Edges);i1++,i9++)
	{
	strcpy(finishf[i9],finish[i1]);
		i1++;
  }
}
//перевод строк типа "char" "int"
void translate()
{
	for (int i25=1;i25<atoi(Edges);i25++)
		{
		startb[i25]=atoi(startf[i25]);
		finishb[i25]=atoi(finishf[i25]);
		}
}
/////////////////////////////////////////////
/////////////////////////////////////////////
/////////////////////////////////////////////

void twomatrix()// матрицы смежности и марицы индентичности
{	
	cout<<"Select type of matrix 1-adjacency and 2-incidence"<<endl;
	 
	   
			cout<<"This is matrix of adjacency of Graphs (1-4)"<<endl;
//=====================================================	
		cout<<"matrix of adjacency (first Graph)"<<endl;
		for(int j1=0;j1<10;j1++)
	{
		{
			for(int j2=0;j2<10;j2++)
			cout<<" "<<ma1[j1][j2];
		}
			cout<<endl;
	}
		cout<<endl;
//======================================================		
		cout<<"matrix of adjacency (second Graph)"<<endl;
		for(int j1=0;j1<10;j1++)
	{
		{
			for(int j2=0;j2<10;j2++)
			cout<<" "<<ma2[j1][j2];
		}
			cout<<endl;
	}
	cout<<endl;
//======================================================				
		cout<<"matrix of adjacency (second Graph)"<<endl;
		for(int j1=0;j1<10;j1++)
	{
		{
			for(int j2=0;j2<10;j2++)
			cout<<" "<<ma2[j1][j2];
		}
			cout<<endl;
	}
	cout<<endl;
//======================================================
		cout<<"matrix of adjacency (third Graph)"<<endl;
		for(int j1=0;j1<10;j1++)
	{
		{
			for(int j2=0;j2<10;j2++)
			cout<<" "<<ma2[j1][j2];
		}
			cout<<endl;
	}
	cout<<endl;
//=======================================================
		cout<<"matrix of adjacency (fourth Graph)"<<endl;
		for(int j1=0;j1<20;j1++)
	{
		{
			for(int j2=0;j2<20;j2++)
			
				cout<<" "<<ma3[j1][j2];
		}
	cout<<endl;
	}
		cout<<"7----"<<startb[1]<<endl;
	cout<<"7---"<<finishb[1]<<endl;
		}
		
 
	



void maiinput()
	
{	
	{
		for(int j12=1;j12<=atoi(Edges);j12++)
		for(int j13=1;j13<=atoi(Edges);j13++)
		mai1[j12][j13]=0;
	}
	
	for(int j12=1;j12<=atoi(Edges);j12++)
	{	
		if (startb[j12]==finishb[j12])
			{
				mai1[j12][startb[j12]]=2;
			}
		else
			{
				mai1[j12][startb[j12]]=-1;
				mai1[j12][finishb[j12]]=1;
			}
	}
}
	
	

void maioutput1()     //функция вывода мвтрицы смежности №1
{  
	cout<<"matrix of in"<<endl;
	for(int j20=1;j20<=atoi(Tops);j20++)
	{
		for(int j19=1;j19<=atoi(Edges);j19++)
				cout<<"  "<<mai1[j19][j20];
				cout<<setw(2)<<endl;
	
	}
	cout<<endl;
}

 


 





int main ( int argc, char * argv[] ) 
{	
	system("color F0");
    ifstream file;                //reading mode
	cout<<"Enter number of file"<<endl;
	cin>>num;
	
	if (num==1)
		{
			file.open("1.txt");
		}
	else if (num==2)
		{
			file.open("2.txt");
		}
	else if (num==3)
		{
			file.open("3.txt");
		}
	else if (num==4)
		{
			file.open("4.txt");
		}
	else if (num==5)
		{
			file.open("5.txt");
		}
	else
	{
		cout<<"not valid data"<<endl;
		getch;
		exit(1);
	}


	
	         
    while( !file.is_open() ) 
	{
        cerr << "File error!\n";
        cin.ignore();						//udalenie simvolov iz potoka
    }
  

   
    int i=1;
    
    while( !file.eof() )					// цикл, сществует покаместь, не будет конец файла
	{               
        file.getline(buff[i],sizeof(buff)); // записываем в buff, строчку i - файла
        cout <<""<<buff[i];			// выводим на печать(тут можно вывести порядковый номер строки
		++i;
		cout<<endl;
    }
    file.close();
	cin.ignore(); 

	EdgesAndTopss();
	StartandEnd();
	sort();
	sort2();
	translate();
	twomatrix();
	maiinput();
	maioutput1();
	//masum();
	//maioutput2();
	cout<<"tops==="<<Tops<<endl;
	cout<<"edges=="<<Edges<<endl;
	cout<<"7----"<<startb[5]<<endl;
	cout<<"7---"<<finishb[5]<<endl;
	system("pause");
}
