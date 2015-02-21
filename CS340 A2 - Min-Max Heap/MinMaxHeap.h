#include "Header.h"
using namespace std;

class MinMaxHeap
{
public:
	MinMaxHeap();
	~MinMaxHeap(){ };


private:
	int heap[32];	                // MinMaxHeap array
	int currentSize, maxSize;       // Heap current size, Heap max Size
	int integersToHeap[32];

	void buildMinMaxHeap();
	void readIn();
	void insertFirstThree();
	void insert(int i);
	int determineDepth();
	void checkMaxes(int depth);
	void checkMins(int depth);
	void addToHeap(int variable);
	bool isMaxLevel(const int pos);  // Returns true if a position is on maximum level and false if it is not
	// void swap(const int indexOne, const int indexTwo);	// Swaps elements in the Heap array using two positions.
};
