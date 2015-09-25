#include <iostream>
#include "Cell.h"

using namespace std;

Cell::Cell()
{
	//cout << "hi guys";
}
Cell::~Cell()
{
	//cout << "destroyed";

}

int Cell::numNeighborsClassic(int **arr, int **arrB, size_t w, size_t h)
{
	int neighborCount = 0; //holds the number of neighbor each cell has
	int stableCount = 0; //holds number of lives and deaths, if zero, program terminates
	for(size_t i=1; i<(w-1); ++i) {
		
		for(size_t j=1; j<(h-1); ++j) {
			
			neighborCount = arr[i-1][j] + arr[i-1][j-1] + arr[i-1][j+1] + arr[i][j+1] + arr[i][j-1] + arr[i+1][j+1] + arr[i+1][j] + arr[i+1][j-1];
		
			//cell tribunal
			if(neighborCount <2 || neighborCount >= 4) {
				arrB[i][j] = 0;
			}
			
			//cell death
			else if(neighborCount == 2) {
				//cell state must remain the same. check what current state is, retain that state
				if (arr[i][j] == 0)
					arrB[i][j] = 0;
				else if (arr[i][j] == 1)
					arrB[i][j] = 1;
			}
			
			//YAY
			else if(neighborCount == 3) {
				arrB[i][j] = 1;
			} 
			
			//checks if something happens
			if (arr[i][j] != arrB[i][j])
				stableCount++;
				
			//gets ready for the spot on the board
			neighborCount = 0;
			
		}
	}
	// makes it so that board is stepped forward and the info in boardB is no longer needed
	board = boardB;
	return stableCount;
}

