#include <iostream>


using namespace std;

class Cell
{
	public:
		Cell();
		virtual ~Cell();
		
		double popDensity;
		int numCells;
		void numNeighbors(int **arr, int **arrB, size_t w, size_t h);
		void ReadIn();
		void turn(char **bA, char **bB);
		int PlayGame();
};
