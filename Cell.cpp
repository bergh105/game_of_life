#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include "Cell.h"

using namespace std;

Cell::Cell(){
}
Cell::~Cell(){
}

void Cell::Quit() {
	bool hey = true;
	string input;
	cout << "Game has stabilized. Press 'enter' key to terminate program." << endl;
	while(getline(cin, input)) {
		if (input.empty())
			break;
	}
}

void Cell::printConsole(int **arrB, int w, int h) {

	string gogo;
	int bvar;
	cout << "Press 'enter' key to continue to next generation." << endl;
	getline(cin, gogo);
	for(int i=1; i < (w-1); ++i) {
		for(int j=1; j < (h-1); ++j) {
			if(arrB[i][j] == 1) {
				cout << 'X';
			}
			else if (arrB[i][j] == 0) {
				cout << '-';
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Cell::printFlipConsole(int **arrB, int w, int h) {
	int bvar;
	string gogo;
	cout << "Press 'enter' key to continue." << endl;
	getline(cin, gogo);
	for(int i=1; i < (h-1); ++i) {
		for (int j=1; j < (w-1); ++j) {
			if(arrB[j][i] == 1) {
				cout << 'X';
			}
			else if (arrB[j][i] == 0) {
				cout << '-';
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Cell::printFile(int **arrB, int w, int h, bool looping) {	
	ofstream myFile;
	if (looping)
		myFile.open("output.txt", ios_base::app);
	if(!looping)
		myFile.open("output.txt");
	
	for(int i=1; i < (w-1); ++i) {
		for (int j=1; j < (h-1); ++j) {
			if(arrB[i][j] == 1) {
				myFile << 'X';
			}
			else if (arrB[i][j] == 0) {
				myFile << '-';
			}
		}
		myFile << endl;
	}
	myFile << endl;
	
	myFile.close();
	
}

void Cell::printFlipFile(int **arrB, int w, int h, bool looping) {
	ofstream myFile;
	if (looping)
		myFile.open("output.txt", ios_base::app);
	if(!looping)
		myFile.open("output.txt");
	
	for(int i=1; i < (h-1); ++i) {
		for (int j=1; j < (w-1); ++j) {
			if(arrB[j][i] == 1) {
				myFile << 'X';
			}
			else if (arrB[j][i] == 0) {
				myFile << '-';
			}
		}
		myFile << endl;
	}
	myFile << endl;
	
	myFile.close();
}

void Cell::numNeighborsClassic(int **arr, int **arrB, int w, int h, bool fType, bool out,bool Loop) {
	int neighborCount = 0;
	int stableCount = 0;
	bool stable = false;

	for(int i=1; i<(w-1); ++i) {
		for(int j=1; j<(h-1); ++j) {
			// looks at all surounding cells and counts the number of neighbors
			neighborCount = arr[i-1][j] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j+1] + arr[i+1][j] + arr[i+1][j-1];
			
			if(neighborCount <2 || neighborCount >= 4) {
				arrB[i][j] = 0;
			}
			
			else if(neighborCount == 2) {
				if (arr[i][j] == 0)
					arrB[i][j] = 0;
				else if (arr[i][j] == 1)
					arrB[i][j] = 1;
			}
			else if(neighborCount == 3) {
				arrB[i][j] = 1;
			} 
			if (arr[i][j] != arrB[i][j])
				stableCount++;
			
			neighborCount = 0;
		}
	}
	
	if (stableCount == 0){
		stable = true;
	}

	if(!stable){
		if(!out){	
			if(fType) {
				printConsole(arrB,w,h);
			}
			else if (!fType){
				printFlipConsole(arrB,w,h);
			}
		}
		else if (out) {
			if(fType) {
				printFile(arrB,w,h, Loop);
			}
			else if (!fType){
				printFlipFile(arrB,w,h, Loop);
			}
		}
		numNeighborsClassic(arrB,arr,w,h, fType, out, true);
		
	}
}

void Cell::numNeighborsDonut(int **arr, int **arrB, int w, int h, bool fType, bool out, bool Loop) {
	//edges find neighbors on the opposite side of the board
	int neighborCount = 0;
	int stableCount = 0;
	bool stable = false;
	for(int i=1; i<(w-1); ++i) {
		for(int j=1; j<(h-1); ++j) { 
			//corner 1			
			if( i == 1 && j == 1) {
				neighborCount = arr[w-2][h-2]+arr[w-2][1]+arr[1][h-2]+arr[2][h-2]+arr[w-2][2]+arr[1][2]+arr[2][1]+arr[2][2];
			}
			//corner 2
			else if( i == w-2 && j == 1) {
				neighborCount = arr[w-2][h-2]+arr[1][1] + arr[1][h-2] + arr[w-3][h-2]+ arr[1][2] + arr[w-3][1] + arr[w-3][2] + arr[w-2][1];
			}
			//corner 3
			else if(i == 1 && j== h-2){
				neighborCount = arr[1][1]+arr[1][h-2]+arr[w-2][h-2]+arr[2][1]+arr[w-2][h-3]+arr[2][h-2]+arr[2][h-3]+arr[1][h-3];
			}			
			// corner 4
			else if( i == w-2 && j == h-2) {
				neighborCount = arr[1][h-2]+arr[1][1] + arr[w-2][1] + arr[1][h-3] + arr[w-3][1] + arr[w-3][h-3] + arr[w-2][h-3] + arr[w-3][h-2];
			}
			//side A
			else if( i == 1) {
				neighborCount = arr[w-2][j] + arr[w-2][j-1] + arr[w-2][j+1] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j+1] + arr[i+1][j] + arr[i+1][j-1];
			}
			//side B
			else if( j == 1) {
				neighborCount = arr[i-1][j] + arr[i-1][h-2] + arr[i-1][j+1] + arr[i][j+1] + arr[i][h-2] + arr[i+1][j+1] + arr[i+1][j] + arr[i+1][h-2];
			}
			//side C
			else if( i == w-2) {
				neighborCount = arr[i-1][j] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i][j+1] + arr[i][j-1] + arr[1][j+1] + arr[1][j] + arr[1][j-1];
			}
			//side D
			else if( j == h-2){
				neighborCount = arr[i-1][j] + arr[i-1][j-1] + arr[i-1][1] + arr[i][1] + arr[i][j-1] + arr[i+1][1] + arr[i+1][j] + arr[i+1][j-1];
			}
			//base case works for everything that is not effected by new rules
			else {			
				neighborCount = arr[i-1][j] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j+1] + arr[i+1][j] + arr[i+1][j-1];
			}		
									
			if(neighborCount <2 || neighborCount >= 4) {
				arrB[i][j] = 0;
			}
			else if(neighborCount == 2) {
				//cell state must remain the same. check what current state is, retain that state
				if (arr[i][j] == 0)
					arrB[i][j] = 0;
				else if (arr[i][j] == 1)
					arrB[i][j] = 1;
			}
			else if(neighborCount == 3) {
				arrB[i][j] = 1;
			} 
			if (arr[i][j] != arrB[i][j])
				stableCount++;
			neighborCount = 0;
		}
	}
	if (stableCount == 0)
		stable = true;
	
	if(!stable){
		if(!out){	
			if(fType) {
				printConsole(arrB,w,h);
			}
			else if (!fType){
				printFlipConsole(arrB,w,h);
			}
		}
		else if (out) {
			if(fType) {
				printFile(arrB,w,h, Loop);
			}
			else if (!fType){
				printFlipFile(arrB,w,h, Loop);
			}
		}
		numNeighborsDonut(arrB,arr,w,h, fType, out, true);
	}
}

void Cell::numNeighborsMirror(int **arr, int **arrB, int w, int h, bool fType, bool out, bool Loop){
	//edges find neighbors on the opposite side of the board
	int neighborCount = 0;
	int stableCount = 0;
	bool stable = false;
	for(int i=1; i<(w-1); ++i) {
		for(int j=1; j<(h-1); ++j) { 
			//corner 1			
			if( i == 1 && j == 1) {
				neighborCount = 3*arr[1][1]+ 2*arr[2][1]+ 2* arr[1][2]+arr[2][2];
			}
			//corner 2
			else if( i == w-2 && j == 1) {
				neighborCount = 3*arr[w-2][1]+ 2*arr[w-2][2] + 2*arr[w-3][1] + arr[w-3][2];
			}
			//corner 3
			else if(i == 1 && j== h-2){
				neighborCount = 3*arr[1][h-2]+ 2*arr[1][h-3] + 2*arr[2][h-2] + arr[2][h-3];
			}			
			// corner 4
			else if( i == w-2 && j == h-2) {
				neighborCount = 3*arr[w-2][h-2]+ 2*arr[w-2][h-3] + 2*arr[w-3][h-2] + arr[w-3][h-3];
			}
			//side A
			else if( i == 1) {
				neighborCount = arr[i][j] + 2*arr[i][j+1] + 2*arr[i][j-1] + arr[i+1][j+1] + arr[i+1][j] + arr[i+1][j-1];
			}
			//side B
			else if( j == 1) {
				neighborCount = 2*arr[i-1][j]  + arr[i-1][j+1] + arr[i][j+1] + arr[i+1][j+1] + 2*arr[i+1][j] + arr[i][j];
			}
			//side C
			else if( i == w-2) {
				neighborCount = 2*arr[i][j+1]+2*arr[1][j-1]+arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+arr[i][j];
			}
			//side D
			else if( j == h-2){
				neighborCount = 2*arr[i+1][j]+2*arr[i-1][j]+arr[i-1][j-1]+arr[i][j-1]+arr[i+1][j-1]+arr[i][j];
			}
			//base case works for everything that is not effected by new rules
			else {			
				neighborCount = arr[i-1][j] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j+1] + arr[i+1][j] + arr[i+1][j-1];
			}		
									
			if(neighborCount <2 || neighborCount >= 4) {
				arrB[i][j] = 0;
			}
			else if(neighborCount == 2) {
				//cell state must remain the same. check what current state is, retain that state
				if (arr[i][j] == 0)
					arrB[i][j] = 0;
				else if (arr[i][j] == 1)
					arrB[i][j] = 1;
			}
			else if(neighborCount == 3) {
				arrB[i][j] = 1;
			} 
			if (arr[i][j] != arrB[i][j])
				stableCount++;
			neighborCount = 0;
		}
	}
	if (stableCount == 0)
		stable = true;
	
	if(!stable){
		if(!out){	
			if(fType) {
				printConsole(arrB,w,h);
			}
			else if (!fType){
				printFlipConsole(arrB,w,h);
			}
		}
		else if (out) {
			if(fType) {
				printFile(arrB,w,h, Loop);
			}
			else if (!fType){
				printFlipFile(arrB,w,h, Loop);
			}
		}
		numNeighborsMirror(arrB,arr,w,h, fType, out, true);
	}
}

void Cell::initialPop(int **arr, int w, int h, double d) {

	int totalCells = (h-2)*(w-2);
	//calc how many cells should end up being populated given chosen pop density
	double totalPopulatedCells = totalCells*d;

	int popCells = (int)totalPopulatedCells;
	int count = 0;

		for (int i=1; i<(h-1); ++i) {
			for(int j=1; j<(w-1); ++j) {

				double a = rand() / (RAND_MAX + 1.0);
				if (0<a && a<=d) {
					arr[i][j] = 1;
					count += 1;
					//end population process once desired population is reached
					if (popCells == count) {
						break;
					}
				}
			}
			if(popCells == count)
				break;
		}
}

void Cell::initialPop_file(int **arr, const char* fileName) {

	ifstream file(fileName);
	//file.open(fileName);

	//first two lines of file will be height and width specification
	string titleLine1,titleLine2;
	getline(file, titleLine1);
	getline(file, titleLine2);

	//read in file lines, populate where Xs appear
	string line;
	int lineNumber = 1;

	while(!file.eof()) {
		getline(file, line);
		for(int i=0; i<line.length(); ++i) {
			if(line[i] == 'X') {
				arr[lineNumber][i] = 1;
			}
			cout << arr[lineNumber][i];
		}
		cout << endl;
		++lineNumber;
		cout << lineNumber << endl;
	}

	file.close();
} 

