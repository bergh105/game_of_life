#include <iostream>
//#include <array>
#include "Cell.h"


using namespace std;

int main(int argc, char **argv) {


	Cell c;

	int rows, columns;
	cout << "How many rows? " << endl;
	cin >> rows;
	cout << "How many columns? " << endl;
	cin >> columns;

	//set width and height of board to account for border cells
	
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
	cout << "Width: " << width << " Height: " << height << endl;

	//create board
	int** board = new int*[width];
	for(int i=0; i < width; ++i) {
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
	
	//create copy board
	int** boardB = new int*[width];
	for(int i=0; i<width; ++i) {
		boardB[i] = new int[height];
	}
	
	for (int i =0; i<width; ++i)
	{
	
	}
	cout << "No segmentation error yet!" << endl;
	//check neighbors, alter boardB accordingly
	
	c.numNeighbors(board, boardB, width, height);
	
	//print values of all indexes of boardB to check
	for (int i=0; i<width; ++i) {
		for (int j=0; j<height; ++j) {
			cout << boardB[i][j] << endl;
		}
	}
	for (int i = 0; i<height; ++i)
	{		
		delete board[i];
		delete boardB[i];	
	}
	delete board;
	delete boardB;

	

	return 0;
}
