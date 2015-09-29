#include <iostream>
#include <fstream>


using namespace std;

class Cell
{
	public:
		Cell();
		virtual ~Cell();
		
		double popDensity;
		int numCells;
		int numNeighborsClassic(int **arr, int **arrB, size_t w, size_t h);
		void ReadIn();
		void turn(char **bA, char **bB);

		void Quit();
		void printFlipConsole(int **arrB, int w, int h);
		void printConsole(int **arrB, int w, int h);

		void numNeighborsClassic(int **arr, int **arrB, int w, int h);
		void numNeighborsMirror(int **arr, int **arrB, int w, int h);
		void numNeighborsDonut(int **arr, int **arrB, int w, int h);
		
		void initialPop(int **arr, int w, int h, double d);
		void initialPop_file(int **arr, string fileName);

};
