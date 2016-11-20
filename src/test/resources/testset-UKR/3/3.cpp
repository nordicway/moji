#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int MAX_V;//maximum value of вершин
int MAX_E;//maximum value of ребер
int m[50][2];// matrix of input connections
ofstream myfile;//initialize a file parameter


int minn()//function for input
{
    cout << "Enter Conections:\n";
    for(int n = 0; n < MAX_E; n++)
    {
        cin >> m[n][0];
        cin >> m[n][1];
    }
    return 0;
}

int mone()//function for the first matrix
{
    for(int i = 1;i<=MAX_V;++i)
    {
        for(int j = 1;j<=MAX_V;++j)
        {
            bool found = false;
            for(int k=0; k<MAX_E; ++k)
            {
                if(m[k][0] == i && m[k][1] == j)
                {
                    found = true;
                    break;
                }
            }
            if( found )
            {   cout << setw(3) << 1;//adding three spaces and input "1"
                myfile << setw(3) << 1;
            }
            else
            {
                cout << setw(3) << 0;
                myfile << setw(3) << 0;
            }

        }
        cout << endl;
        myfile << endl;
    }
}

int mtwo()//function for second matrix
{
    for(int i = 1;i<=MAX_V;++i)
    {
            for(int k=0; k<MAX_E; ++k)
            {
                bool found = false;
                bool foundd = false;
                bool founddd = false;

                if(m[k][0] == i && m[k][1] == i)
                {
                    found = true;
                } else
                {
                    if(m[k][0] == i && m[k][1] != i)
                    {
                        foundd = true;
                    } else
                    {
                        if(m[k][0] != i && m[k][1] == i)
                        {
                            founddd = true;
                        }
                    }
                }

                if( found )
                {
                    cout << setw(3) << 2;
                    myfile << setw(3) << 2;
                }
                else
                {
                    if( foundd )
                    {
                        cout << setw(3) << -1;
                        myfile << setw(3) << -1;
                    }
                    else
                    {
                        if( founddd )
                        {
                            cout << setw(3) << 1;
                            myfile << setw(3) << 1;
                        }
                        else
                        {
                            cout << setw(3) << 0;
                            myfile << setw(3) << 0;
                        }
                    }
                }
            }

            cout << endl;
            myfile << endl;
    }
}


int main()
{
    cout << "Enter v, e:\n";
    myfile.open("DMmatrx.txt");
    cin >> MAX_V;
    cin >> MAX_E;
    minn();
    mone();
    cout << endl;
    mtwo();
    myfile.close();
    return 0;
}
