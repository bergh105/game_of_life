#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include "Cell.h"

using namespace std;

Cell::Cell()
{
	cout << "hi guys";
}
Cell::~Cell()
{
	cout << "destroyed";

}

int Cell::numNeighborsClassic(int **arr, int **arrB, size_t w, size_t h)
{
	int neighborCount = 0;
	int stableCount = 0;
	cout<< 1;
	for(size_t i=1; i<(h-1); ++i) {
		cout << 2;
		for(size_t j=1; j<(w-1); ++j) {
			cout << 3;
			neighborCount = arr[i-1][j] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j+1] + arr[i+1][j] + arr[i+1][j-1];
			
			//even just this causes segmentation fault: 11
			cout << "hey";			
			//if(arr[i][j] == 1)
			//	++neighborCount;

			
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
	  
	return stableCount;
}


void Cell::initialPopClassic(int **arr, int w, int h, double d) {

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

void Cell::initialPopClassic_file(int **arr, string fileName) {

	ifstream file;
	file.open(fileName);

	string titleLine1,titleLine2;
	getline(file, titleLine1);
	getline(file, titleLine2);

	//read in file lines
	string line1, line2, line3, line4, line5;
	getline(file, line1);
	getline(file, line2);
	getline(file, line3);
	getline(file, line4);
	getline(file, line5);
	for(int i=0; i<line1.length(); ++i) {
		if(line1[i] == 'X'){
			arr[1][i] = 1;
		}
	}
	for(int i=0; i<line2.length(); ++i) {
		if(line2[i] == 'X') {
			arr[2][i] = 1;
		}
	}
	for(int i=0; i<line3.length(); ++i) {
		if(line2[i] == 'X') {
			arr[3][i] = 1;
		}
	}
	for(int i=0; i<line4.length(); ++i) {
		if(line2[i] == 'X') {
			arr[4][i] = 1;
		}
	}
	for(int i=0; i<line5.length(); ++i) {
		if(line2[i] == 'X') {
			arr[5][i] = 1;
		}
	}
}

