#include <iostream>
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
	for(size_t i=1; i<(w-1); ++i) {
		cout << 2;
		for(size_t j=1; j<(h-1); ++j) {
			cout << 3;
			//this line causes segmentation fault (11) **probably too much memory being used
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

