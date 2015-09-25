#include <iostream>
//#include "cell.h"

using namespace std;

int main(int argc, char **argv) {

	int rows, columns;
	cout << "How many rows? " << endl;
	cin >> rows;
	cout << "How many columns? " << endl;
	cin >> columns;

	int width, height;
	//set width and height of board to account for border cells
	if(columns > rows) {
		width = columns+2;
		height = rows+2;
		cout << "Width: " << width << " Height: " << height << endl;
	}
	else if (rows > columns) {
		width = rows+2;
		height = columns+2;
		cout << "Width: " << width << " Height: " << height << endl;
	}
	//create board
	int** board = new int*[width];
	for(int i=0; i<width; ++i) {
		board[i] = new int[height];
	}
	
	//initialize all cells to empty
	for (int i=0; i<height; ++i) {
		for (int j=0; j<width; ++j) {
			board[i][j] = 0;
		}
	}

	//populate some cells (indices chosen randomly)
	//in order for these indices to work, input 4 rows, 5 columns
	board[1][2] = 1;
	board[1][4] = 1;
	board[2][2] = 1;
	board[2][4] = 1;
	board[3][1] = 1;
	board[3][2] = 1; 

	//create copy board to populate next gen
	int** boardB = new int*[width];
	for(int i=0; i<width; ++i) {
		boardB[i] = new int[height];
	}
	for (int i=0; i<height; ++i) {
		for (int j=0; j<width; ++j) {
			boardB[i][j] = 0;
		}
	}

	//check neighbors, alter boardB accordingly
	int neighborCount = 0;

	//1 so that first border column and row are skipped. width-1 so that last column skipped, height-1 so that last row skipped
	for(int i=1; i<height-1; ++i) {
		for(int j=1; j<width-1; ++j) {
			
			neighborCount = board[i-1][j] + board[i-1][j-1] + board[i-1][j+1] + board[i][j+1] + board[i][j-1] + board[i+1][j+1] + board[i+1][j] + board[i+1][j-1];
			cout << "neighbor count: " << neighborCount << endl;
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

	for (int i =0; i<height; ++i) {
		delete [] board[i];
		delete [] boardB[i];
	}
	delete [] board;
	delete [] boardB;
	
	return 0;
}
