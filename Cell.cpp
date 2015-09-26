#include <iostream>
#include <string>
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


void Cell::initialPop(int **arr, int w, int h, double d) {

	int totalCells = (h-2)*(w-2);
	cout << "total cells: " << totalCells << endl;

	int totalPopulatedCells = totalCells*d;
	cout << "total populated cells should be: " << totalPopulatedCells << endl;

	//counter for number of cells that have been populated by function
	int popCells = 0;

	for (int i=1; i<(h-1); ++i) {
		cout << "Iteration: " << i << endl;
		for(int j=1; j<(w-1); ++j) {

			while(!(popCells == totalPopulatedCells)) {
				double a = rand() / (RAND_MAX + 1.0);
				cout << "Iteration J: " << j << ": a= " << a << endl;
				if (d >= a) {
					cout << "Populate." << endl;
					++popCells;
				}
				else
					cout << "Leave empty." << endl;
			}
			//works but stops populating when desired pop density is reached
			//means that the last several cells will automatically be empty, not even in the running to be populated
			//not *exactly* random
			
		}
	}

}
