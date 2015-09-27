#include <iostream>
#include <string>
#include <math.h>
//#include <array>
#include "Cell.h"


using namespace std;

int main(int argc, char **argv) {


	Cell c;

	cout << "Would you like to enter a map file, or be provided a random assignment? (map/random)" << endl;

	string response;
	getline(cin, response);

	if(response == "random") {

		int rows, columns;
		cout << "How many rows? " << endl;
		cin >> rows;
		cout << "How many columns? " << endl;
		cin >> columns;
		
		int width, height;
		//set width and height of board to account for border cells
		if(columns >= rows) {
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
		for(int i=0; i < width; ++i) {
			board[i] = new int[height];
		}

		//initialize all cells to empty
		for (int i=0; i<width; ++i) {
			for (int j=0; j<height; ++j) {
				board[i][j] = 0;
			}
		}

		//prompt population density
		cout << "Enter desired population density (number between 0 and 1): " << endl;
		double popD;
		//set pop density
		cin >> popD;

		//error checking
		while(!(popD>=0 || popD<1)) {
			cout << "Invalid. Re-enter: " << flush;
			cin >> popD;
		}
	
		//populate cells
		c.initialPop(board, width, height, popD);

	
		cout << "No segmentation error yet!" << endl;
		
		//create copy board
		int** boardB = new int*[width];
		for(int i=0; i<width; ++i) {
			boardB[i] = new int[height];
		}
		
		//check neighbors, alter boardB accordingly
		
		c.numNeighborsClassic(board, boardB, width, height);
		
		//print values of all indexes of boardB to check
		for (int i=0; i<width; ++i) {
			for (int j=0; j<height; ++j) {
				cout << boardB[i][j] << endl;
			}
		}

		//Delete arrays to prevent Segmentation Fault	
		for (int i = 0; i<height; ++i)
		{		
			delete board[i];
			delete boardB[i];	
		}
		delete board;
		delete boardB;

	}

	return 0;
}
