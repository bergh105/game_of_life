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
		
		void initialPopClassic(int **arr, int w, int h, double d);
		void initialPopClassic_file(int **arr, string fileName);

};
