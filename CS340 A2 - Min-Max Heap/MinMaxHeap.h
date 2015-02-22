#include "Header.h"
using namespace std;

class MinMaxHeap
{
public:

	static const int NUMBER_OF_VARIABLES_ENTERED_IN_TEXT_FILE = 32;
	/* Constructor */
	MinMaxHeap();	
	/* Destructor */
	~MinMaxHeap()
	{
		currentSize = NULL; 
		maxSize = 32;
		for (int i = 0; i < maxSize; i++)
		{
			integersToHeap[i] = NULL;
		}
		for (int i = 0; i < maxSize; i++)
		{
			heap[i] = NULL;
		}
	};
	/* Accessors */
	void printHeap();	// prints the heap
	int findMin();		// finds the minimum value of the heap and returns it
	int findMax();		// finds the maximum value of the heap and returns it
	void insertFromUser(int i) { insert(i); };	// inserts the value given by the user
	void deleteMin();	// deletes the minimum value 
	void deleteMax();	// deletes the maximum value

private:
	int heap[NUMBER_OF_VARIABLES_ENTERED_IN_TEXT_FILE];	                // MinMaxHeap array
	int integersToHeap[NUMBER_OF_VARIABLES_ENTERED_IN_TEXT_FILE];		// array of variables to be added to the heap
	int currentSize, maxSize;											// Heap current size, Heap max Size

	void buildMinMaxHeap();			// builds the min-max heap
	void readIn();					// reads in the variables from the text file "input.txt"
	void insertFirstThree();		// inserts the first three variables into the heap with the smallest being at the head
	void insert(int i);				// inserts the variable into the heap
	void insert();					// reinserts a variable when a swap occurs
	int determineDepth();			// determines the depth of the current heap, returns said depth
	void checkMaxes(int depth);		// determines if the current variable can be swaped with any max values
	void checkMins(int depth);		// determines if the current variable can be swaped with any min values
	void swapWithSmallest(int minimumPosition, int minimum); // swaps the given minimum value with the newly inserted value
	void swapWithLargest(int maximumPosition, int maximum);  // swaps the given maximum value with the newly inserted value
	int findSmallest(int lowerBound, int upperBound);	// finds the smallest variable at a "max" depth
	int findLargest(int lowerBound, int upperBound);	// finds the largest variable at a "min" depth
	void addToHeap(int variable);	// adds the variable to the heap
	
};
