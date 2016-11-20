#pragma warning(disable:4996)										//Disables warning error number 4996
#include<iostream>													//Adds input/output library
#include<conio.h>													//Console input/output library
#include<fstream>													//File streaming library
#include<string>													//String library
#include<sstream>													//String streaming library
#include<iomanip>													//Input/output manipulation library
#include<sstream>													//String streaming library
using namespace std;												//Disables the need to add std:: before several commands

//Project directory can be edited in the project's properties

int labnumber, save, temp = -1;
bool cycleexists;

void intro(){														//Introduction to the program
	cout << "Code written by Alexander Samara and Ali Youssef" << endl << "IS-52, 22, 28" << endl;
	switch (labnumber){
	case 1: cout << "Laboratory work 01: 'Graph Representation'" << endl << endl << "This program will open a file containing graph vectors and edges," << endl << "Then show both the adjacency and the incidence matrices, " << endl << "And output them into the console and/or a file." << endl << endl;
		break;
	case 2: cout << "Laboratory work 02: 'Graph Specifications'" << endl << endl << "This program will find the following:" << endl << "1- Find all powers for a graph from a file." << endl << "2- Find and output all isolated and pendant vertices." << endl << "3- Find and output the graph's diameter, radius, center(s), distances, and tiers." << endl << "It will also check if the power is unary, and if so, show the power." << endl << endl;
		break;
	case 3: cout << "Laboratory work 03: 'Operations on Graph Matrices'" << endl << endl << "This program will:" << endl << "1- The distance and reachability matrices of a graph." << endl << "2- Check if there are any simple cycles, if so, output them." << endl << "3- Check graph's connectivity type." << endl << endl;
	}
}

void output(string out){											//Outputs the end result to the console
	if (save == 1 || save == 3){									//Checks save option
		cout << out;
	}
	if (save == 2 || save == 3){
		ofstream result("Result.txt", ios::app);					//Creates a file (if doesn't already exist), and disable overwrite
		result << out;
	}
}

void connectivity(int rm[][200], int n, int am[][200], int dm[][200]){
	bool stronglyconnected = true, disconnected = false;
	int temp = 0;
	stringstream buffer;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (am[i][j] != am[j][i]){
				stronglyconnected = false;
			}
			if (rm[i][j] == 0){
				disconnected = true;
			}
			if (dm[i][j] > temp){
				temp = dm[i][j];
			}
		}
	}
	buffer << "\n" << "This graph is ";
	if (disconnected){
		buffer << "disconnected, ";
	}
	else if (stronglyconnected){
		buffer << "strongly connected, ";
	}
	else{
		buffer << "weakly connected, ";
	}
	if (cycleexists){
		buffer << "cyclic, ";
	}
	else{
		buffer << "acyclic, ";
	}
	buffer << "and ";
	if (stronglyconnected && temp == 1){
		buffer << "complete." << "\n" << "\n";
	}
	else if (stronglyconnected && temp != 1){
		buffer << "incomplete." << "\n" << "\n";
	}
	else{
		buffer << "neither complete nor incomplete (directed)." << "\n" << "\n";
	}
	output(buffer.str());
}

void cycles(int am[][200], int start, int n, int end, int cycle[][200], bool rec, int cycleid[][200], bool checked[][200]){			//Finds if the graph has cycles, if so outputs them
	for (int i = start; i < end; i++){
		for (int j = 0; j < n; j++){
			if (am[i][j] == 1 && i != j && j != temp - 1){
				if (cycle[i][j] == 0){
					cycle[i][j] = 1;
					for (int l = 0; l < 200; l++){					//Several loops and statements and recursion functions to find the cycles
						if (cycleid[0][l] == 0){
							cycleid[0][l] = i + 1;
							cycleid[1][l] = j + 1;
							break;
						}
					}
					temp = i + 1;
					cycles(am, j, n, j + 1, cycle, true, cycleid, checked);
					cycle[i][j] = -1;
				}
				else if (cycle[i][j] == 1){
					cycle[i][j] = 2;
					for (int l = 0; l < 200; l++){
						if (cycleid[0][l] == 0){
							cycleid[0][l] = i + 1;
							cycleid[1][l] = j + 1;
							cycleid[0][l + 1] = 150;
							cycleid[0][l + 1] = 150;
							break;
						}
					}
					for (int k = 0; k < n; k++){
						for (int q = 0; q < n; q++){
							if (cycle[k][q] == 1){
								cycle[k][q] = 0;
							}
						}
					}
					checked[i][j] = true;
					cycleexists = true;
					cycles(am, 0, n, n, cycle, true, cycleid, checked);
				}
			}
		}
	}
	if (rec == false){
		stringstream buffer;
		string sep = "";
		buffer << "This graph has the following cycles: " "\n" << "\n";
		if (cycleexists == true){
			for (int l = 0; l < 200; l++){
				if (cycleid[0][l] == 150){
					buffer << "\n";
					sep = "";
				}
				else if (cycleid[0][l] != 0 && cycleid[0][l] != cycleid[0][l + 1]){
					if (checked[cycleid[0][l] - 1][cycleid[1][l] - 1] || cycleid[0][l - 1] != 150){
						buffer << sep << cycleid[0][l] << "	";
						sep = " -> ";
					}
				}
			}
			buffer << "\n" << "\n";
		}
		else{
			buffer << "There are no cycles in this graph." << "\n" << "\n";
		}
		output(buffer.str());
	}
}

void reachability(int dm[][200], int n, int am[][200]){							//Finds and outputs the reachability matrix of the graph
	int rm[200][200] = { 0 };
	stringstream buffer;
	buffer << "Reachability Matrix:" << "\n" << "\n" << "	";
	for (int q = 1; q < n + 1; q++){
		buffer << setw(3) << q;
	}
	buffer << "\n" << "\n";
	for (int i = 0; i < n; i++){
		buffer << i + 1 << "." << "	";
		for (int j = 0; j < n; j++){
			if (dm[i][j] == 0 && i != j){
				rm[i][j] = 0;
			}
			else{
				rm[i][j] = 1;
			}
			buffer << setw(3) << rm[i][j];
		}
		buffer << "\n";
	}
	buffer << "\n";
	output(buffer.str());
	connectivity(rm, n, am, dm);
}

void charac(int dm[][200], int n){									//Finds center, radius, and diameter of the graph
	int temp, biggestv[200] = { 0 }, smallestv = 200;
	stringstream buffer;
	string separator = "";
	for (int i = 0; i < n; i++){
		temp = 0;													//Restarting the value of this variable after every loop
		for (int j = 0; j < n; j++){
			if (dm[i][j] > temp){									//Finding the biggest value in each line
				temp = dm[i][j];
			}
		}
		biggestv[i] = temp;											//Storing the value in an array
	}
	temp = 0;
	for (int k = 0; k < n; k++){
		if (biggestv[k] < smallestv){								//Finding the smallest value in the array
			smallestv = biggestv[k];
		}
		if (biggestv[k] > temp){									//Finding the biggest value in the array
			temp = biggestv[k];
		}
	}
	buffer << "Graph's center(s) is/are: { ";
	for (int q = 0; q < n; q++){
		if (biggestv[q] == smallestv){
			buffer << separator << q + 1;
			separator = ", ";
		}
	}
	buffer << " }" << "\n" << "\n";
	buffer << "Tiers of all vertices: " << "\n" << "\n";
	for (int i = 0; i < n; i++){
		for (int l = 0; l < temp + 1; l++){
			separator = "";
			if (biggestv[i] >= l){
				buffer << "D(" << i + 1 << ", " << l << "): { ";
			}
			for (int j = 0; j < n; j++){
				if (dm[i][j] == l){
					buffer << separator << j + 1;
					separator = ", ";
				}
			}
			if (biggestv[i] >= l){
				buffer << " }" << "\n";
			}
		}
	}
	buffer << "\n" << "Radius of the graph is: " << smallestv << "\n" << "\n";
	buffer << "Diameter of the graph is: " << temp << "\n" << "\n";
	output(buffer.str());
}

void isopen(int power[200], int n){									//Finds and displays isolated and pendant vertices
	bool iso[200] = { false }, noiso = true, pen[200] = { false }, nopen = true;
	stringstream buffer;
	for (int i = 0; i < n; i++){
		if (power[i] == 0){											//If the power of the current vertex is 0, then the vertex is isolated
			iso[i] = true;
			noiso = false;
		}
		else if (power[i] == 1){									//If the power of the current vertex is 1, then the vertex is pendant
			pen[i] = true;
			nopen = false;
		}
	}
	if (noiso == true){
		buffer << "There are no isolated vertices in this graph." << "\n" << "\n";
	}
	else{
		buffer << "These are the isolated vertices in this graph:" << "\n" << "\n";
		for (int j = 0; j < n; j++){
			if (iso[j] == true){
				buffer << j + 1 << "\n";
			}
		}
		buffer << "\n";
	}
	if (nopen == true){
		buffer << "There are no pendant vertices in this graph." << "\n" << "\n";
	}
	else{
		buffer << "These are the pendant vertices in this graph:" << "\n" << "\n";
		for (int k = 0; k < n; k++){
			if (pen[k] == true){
				buffer << k + 1 << "\n";
			}
		}
	}
	buffer << "\n";
	output(buffer.str());
}

void power(int dm[][200], int n){									//Power function, find the graph's power(s)
	int power[200] = { 0 };											//Defaults every power to 0
	bool unary = true;
	stringstream buffer;
	buffer << "Power(s)" << "\n";
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (dm[i][j] == 1){										//If the distance for the current vertices is 1, it adds 1 value to the current vertex's power
				power[i]++;
			}
		}
	}
	for (int k = 1; k < n; k++){
		if (power[k] != power[k - 1]){								//If there are two different powers then the graph is not unary
			unary = false;
			break;
		}
	}
	if (unary == false){
		buffer << "This graph is not unary, here are all its powers:" << "\n" << "\n";
		for (int q = 0; q < n; q++){
			buffer << q + 1 << ":" << setw(3) << power[q] << "\n";
		}
		buffer << "\n" << "\n";
	}
	else{
		buffer << "This power is unary, and here is its power:" << "\n" << "\n" << power[0] << "\n" << "\n";
	}
	output(buffer.str());
	isopen(power, n);
}

void FloydWAlgorithm(int dm[][200], int n, int am[][200]){							//The Floyd Warshall algorithm for finding the shortest distance between two vertices using the adjacency matrix
	int i, j, k;
	stringstream buffer;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((dm[i][k] * dm[k][j] != 0) && (i != j))
				{
					if ((dm[i][k] + dm[k][j] < dm[i][j]) || (dm[i][j] == 0))
					{
						dm[i][j] = dm[i][k] + dm[k][j];
					}
				}
			}
		}
	}
	buffer << "Distance Matrix:" << "\n" << "\n" << "	";
	for (int q = 1; q < n + 1; q++){
		buffer << setw(3) << q;
	}
	buffer << "\n" << "\n";
	for (i = 0; i < n; i++)
	{
		buffer << i + 1 << "." << "	";
		for (j = 0; j < n; j++)
		{
			buffer << setw(3) << dm[i][j];
		}
		buffer << "\n";
	}
	buffer << "\n";
	output(buffer.str());
	if (labnumber == 2){
		power(dm, n);
		charac(dm, n);
	}
	if (labnumber == 3){
		reachability(dm, n, am);
	}
}

void incidence(int v1[], int v2[]){									//Calculates and outputs the incidence matrix using two passed vectors from the 'input' function, and a save option
	int matrix[200][200] = { 0 };									//Declares the incidence matrix
	stringstream buffer;											//A stream buffer for storing output into a string then sending it to the output function to output it
	for (int i = 1; i < v2[0] + 1; i++){							//Checks the numbers taken from the file line-by-line, the loop will carry on an equal number of times as the second number of the file (which is the number of edges on that graph)
		matrix[v1[i] - 1][i - 1]--;									//Finds and decreases the matrix's element that's equal to the vertex of the current line, and the edge of the current line (same number)
		matrix[v2[i] - 1][i - 1]++;									//Finds and increases the matrix's element that's equal to the vertex of the current line, and the edge of the current line (same number)
		if (v1[i] == v2[i]){
			matrix[v1[i] - 1][i - 1] += 2;
		}
	}
	buffer << "\n" << "Incidence matrix:" << "\n" << "\n";
	for (int i = 0; i < v1[0]; i++){
		for (int n = 0; n < v2[0]; n++){
			buffer << setw(3) << matrix[i][n];						//Displays all matrix elements after the change
		}
		buffer << "\n";
	}
	buffer << "\n";
	output(buffer.str());
}

void adjacency(int v1[], int v2[]){									//Calculates and outputs the adjacency matrix using two passed vectors from the 'input' function, and a save option
	int matrix[200][200] = { 0 };									//Creates a blank matrix for the adjacency
	for (int i = 1; i < v2[0] + 1; i++){
		matrix[v1[i] - 1][v2[i] - 1] = 1;							//Finds the matrix element that holds the vertices in the current line, and increases its value by one
	}
	stringstream buffer;
	buffer << "\n" << "Adjacency matrix:" << "\n" << "\n";
	for (int i = 0; i < v1[0]; i++){
		for (int n = 0; n < v1[0]; n++){
			buffer << setw(3) << matrix[i][n];						//Outputs all matrix elements to the console
		}
		buffer << "\n";
	}
	buffer << "\n";
	output(buffer.str());
	if (labnumber == 3){
		int cycle[200][200] = { 0 }, cycleid[200][200] = { 0 };
		bool checked[200][200] = { false };
		cycles(matrix, 0, v1[0], v1[0], cycle, false, cycleid, checked);
	}
	if (labnumber == 2 || labnumber == 3){
		FloydWAlgorithm(matrix, v1[0], matrix);
	}
}

void input(string name){											//Input function, takes information from the chosen file, including the name of the file chosen
	int vertices, edges, v1[200], v2[200], i = 0;					//Decleration of various int variables
	ifstream myfile(name, ios::app);								//Starts a file using the name passed by the 'choosefile' function
	cout << endl << "[File: " << name << "]" << endl;				//Shows the user the name of the file
	if (myfile.is_open()){											//Opens the file
		while (myfile >> vertices >> edges){						//Stores the information into int variables
			v1[i] = vertices;										//Applies the taken variables into arrays to be passed to other functions
			v2[i] = edges;
			cout << v1[i] << "	" << v2[i] << endl;					//Shows the user what's written in the file
			i++;													//Increases its value so that we keep all the information in different array elements
		}
		myfile.close();												//Closes the file after storing its information in variables
		cout << endl;
	}
	else{
		cout << "Unable to open file" << endl;
		getch();
		terminate();
	}
	cout << "Would you like to show the result in the console(1) ?" << endl << "Save it to an external file(2) ?" << endl << "Or both(3) ?" << endl;
again:																//Label that allows going back to this point in case something went wrong
	cin >> save;													//Takes the user's input deciding what save option to choose
	if (save < 1 || save >3){
		cout << "Please enter a value between 1-3" << endl;
		goto again;													//Goes back to the label if the user chose an invalid save option
	}
	if (labnumber == 1){
		adjacency(v1, v2);											//Passes the two arrays and the save option to the adjacency function and starts it
		incidence(v1, v2);											//Passes the two arrays and the save option to the incidence function and starts it
	}
	else if (labnumber == 2 || labnumber == 3){
		adjacency(v1, v2);
	}
}

void choosefile(){													//A function that lets the user choose the desired file to view
	intro();														//Gives the lab task
	int file;														//Declares a variable to store the number of the file
	string name;													//Declares a string to use the file number as its name upon opening it
	if (labnumber == 1 || labnumber == 2){
		cout << "Which file would you like to open ? 1-4" << endl;
	again:
		cin >> file;													//Takes input from the user
		if (file < 1 || file > 4){
			cout << "Please enter a value between 1 and 4..." << endl;
			goto again;
		}
		name = "graph_01_" + static_cast<ostringstream*>(&(ostringstream() << file))->str() + ".txt";			//Converts int to string and adds it to the rest of the file name
	}
	else if (labnumber == 3){
		cout << "Which file would you like to open ? 1-3" << endl;
	again2:
		cin >> file;													//Takes input from the user
		if (file < 1 || file > 3){
			cout << "Please enter a value between 1 and 3..." << endl;
			goto again2;
		}
		name = "Graph 0" + static_cast<ostringstream*>(&(ostringstream() << file))->str() + ".txt";			//Converts int to string and adds it to the rest of the file name
	}
	input(name);													//Starts the input function and passes the name of the file for opening
}

int main(){															//Main function, start the other functions and the introduction
	system("color f0");												//Changes the colour of the console to white
restart:
	cout << "What would you like to view ? (1-16)" << endl << "Lab 01: Graph Representation (1)" << endl << "Lab 02: Graph Specifications (2)" << endl << "Lab 03: Operations on Graph Matrices (3)" << endl << endl;
	cin >> labnumber;												//Takes input for the lab number
	if (labnumber < 1 || labnumber > 16){
		cout << "Please choose a value between 1 and 16." << endl;
		goto restart;
	}
	else{
		system("cls");
	}
	switch (labnumber){												//Starts whichever lab the user has chosen
	case 1: choosefile();											//Starts the file-choosing function, which in return starts all the other functions
		break;
	case 2: choosefile();
		break;
	case 3: choosefile();
		break;
	case 4: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 5: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 6: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 7: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 8: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 9: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 10: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 11: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 12: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 13: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 14: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 15: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	case 16: cout << endl << "This lab has not yet been written." << endl << endl;
		break;
	}
	cout << "Would you like to restart the program ?" << endl << "Click 'y' to restart, anything else to quit..." << endl;
	if (getch() == 121){
		system("cls");												//Clears the console window before restarting the program
		goto restart;												//Goes to a label which restarts the program
	}
}

//Code written by Alexander Samara and Ali Youssef
//IS-52, 22, 28