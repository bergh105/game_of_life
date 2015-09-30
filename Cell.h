#include <iostream>



using namespace std;

class Cell
{
	public:
		Cell();
		virtual ~Cell();
		
		double popDensity;
		int numCells;
		
		
		

		void Quit();
		void printFlipConsole(int **arrB, int w, int h);
		void printConsole(int **arrB, int w, int h);

		void printFlipFile(int **arrB, int w, int h, bool looping);
		void printFile(int **arrB, int w, int h, bool looping);

		void numNeighborsClassic(int **arr, int **arrB, int w, int h, bool fType, bool out, bool Loop);
		void numNeighborsMirror(int **arr, int **arrB, int w, int h, bool fType, bool out, bool Loop);
		void numNeighborsDonut(int **arr, int **arrB, int w, int h, bool fType, bool out, bool Loop);
		
		void initialPop(int **arr, int w, int h, double d);
		void initialPop_file(int **arr, const char* fileName);

};
