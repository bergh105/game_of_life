#include <iostream>
//#include "cell.h"

using namespace std;

int main(int argc, char **argv) {

	int rows, columns;
	cout << "How many rows? " << endl;
	cin >> rows;
	cout << "How many columns? " << endl;
	cin >> columns;

	//set width and height of board to account for border cells
	int width = rows+2;
	int height = columns+2;
	cout << "Width: " << width << " Height: " << height << endl;

	//create board
	int** board = new int*[width];
	for(int i=0; i<width; ++i) {
		board[i] = new int[height];
	}

	//initialize all cells to empty
	for (int i=0; i<width; ++i) {
		for (int j=0; j<height; ++j) {
			board[i][j] = 0;
		}
	}
	
	cout << "No segmentation error yet!" << endl;

	//populate some cells (indices chosen randomly)
	//in order for these indices to work, input 4 rows, 5 columns
	board[1][2] = 1;
	board[1][4] = 1;
	board[2][2] = 1;
	board[2][4] = 1;
	board[4][1] = 1;
	board[4][2] = 1;

	//create copy board
	int** boardB = new int*[width];
	for(int i=0; i<width; ++i) {
		boardB[i] = new int[height];
	}
	
	cout << "No segmentation error yet!" << endl;
	//check neighbors, alter boardB accordingly

	int neighborCount = 0;
	
	for(int i=1; i<width; ++i) {
		for(int j=1; j<height; ++i) {

			//this line causes segmentation fault (11) **probably too much memory being used
			neighborCount = board[i-1][j] + board[i-1][j-1] + board[i-1][j+1] + board[i][j+1] + board[i][j-1] + board[i+1][j+1] + board[i+1][j] + board[i+1][j-1];
			
			//even just this causes segmentation fault: 11
			if(board[i-1][j] == 1)
				++neighborCount;

			
			if(neighborCount <2 || neighborCount >= 4) {
				boardB[i][j] = 0;
			}
			else if(neighborCount == 2) {
				//cell state must remain the same. check what current state is, retain that state
				if (board[i][j] == 0)
					boardB[i][j] = 0;
				else if (board[i][j] == 1)
					boardB[i][j] = 1;
			}
			else if(neighborCount == 3) {
				boardB[i][j] = 1;
			} 
			
		}
	}
	
	//print values of all indexes of boardB to check
	for (int i=0; i<width; ++i) {
		for (int j=0; j<height; ++j) {
			cout << boardB[i][j] << endl;
		}
	}

	//program produces runtime Segmentation Fault. Stack Overflow:
	/*Segmentation fault is a specific kind of error caused by accessing memory that “does not belong to you.” 
	It’s a helper mechanism that keeps you from corrupting the memory and introducing hard-to-debug memory bugs. 
	Whenever you get a segfault you know you are doing something wrong with memory – accessing variable that has 
	already been freed, writing to a read-only portion of the memory, etc. */

	return 0;
}
