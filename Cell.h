#include <iostream>
#include <fstream>

using namespace std;

class Cell
{
	public:
		Cell();
		virtual ~Cell();
		//bool flip = false;
		double popDensity;
		int numCells;
		void numNeighborsClassic(int **arr, int **arrB, int w, int h);
		void numNeighborsDonut(int **arr, int **arrB, int w, int h);
		void numNeighborsMirror(int **arr, int **arrB, int w, int h);
		void initialPop(int **arr, int w, int h, double d);
		void initialPopFile(int **arr, string fileName);		
		void printConsole(int **arrB, int w, int h);
		void printFlipConsole(int **arrB, int w, int h);
		void printFile(int **arrB, int w, int h, string fileName);
		void Quit();

};
