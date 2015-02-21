#include "Header.h"
#include "MinMaxHeap.h"




// Gets the heap structure and heapifies it. 
MinMaxHeap::MinMaxHeap()
{
	currentSize = 1; //takes into account the heap-order property that first place in array cant be filled
	maxSize = 32;
	for (int i = 0; i < maxSize; i++)
	{
		integersToHeap[i] = NULL;
	}
	buildMinMaxHeap();
}


void MinMaxHeap::buildMinMaxHeap()
{
	readIn();
	insertFirstThree();
	for (int i = 3; i <= maxSize && integersToHeap[i] != NULL; i++)
	{
		insert(i);
	}
}



void MinMaxHeap::readIn()
{
	// read in file and place it all into toQueue
	ifstream inData;

	inData.open("input.txt");
	if (!inData)
	{
		cout << "Can't open input.txt" << endl;
		exit(1);
	}
	int toQueue;
	int i = 0;
	while (inData >> toQueue)
	{
		integersToHeap[i] = toQueue;
		i++;
	}
}

void MinMaxHeap::insertFirstThree()
{
	// for the first 3 variables - determine the smallest, enter the other two into the array.

	int a = integersToHeap[0];
	int b = integersToHeap[1];
	int c = integersToHeap[2];

	if (a < b && a < c)
	{
		addToHeap(a);
		addToHeap(b);
		addToHeap(c);
	}
	else if (b < a && b < c)
	{
		addToHeap(b);
		addToHeap(a);
		addToHeap(c);
	}
	else if (c < a && c < b)
	{
		addToHeap(c);
		addToHeap(b);
		addToHeap(a);
	}
}

void MinMaxHeap::insert(int i)
{
	// check if it can switch with any of the maximum values in the heap then check if it can switch 
	// with any of the minimums in the heap

	// take variable from the array and place it into the rear of the heap
	addToHeap(integersToHeap[i]);
	int depth = determineDepth();
	//checkMaxes(depth);
	//checkMins();
}

int MinMaxHeap::determineDepth()
{
	int aCounter = 0;
	int bCounter = 1;
	int counter = 0;

	while (counter <= currentSize)												// need to correct
	{
		int lowTotal = pow(2, aCounter);
		int highTotal = pow(2, bCounter) - 1;
		if (currentSize >= lowTotal && currentSize <= highTotal)
		{
			return aCounter;
		}
		aCounter++;
		bCounter++;
	}
}
void MinMaxHeap::checkMaxes(int depth)
{
	// look at current size, determine what the depth of the tree is - ignore that current depth

	//check if larger than positions between 
	int aCounter = 1;
	int bCounter = 2;
	int counter = 0;

	while (counter < depth)
	{
		int lowTotal = pow(2, aCounter);
		int highTotal = pow(2, bCounter) - 1;
		if (currentSize >= lowTotal && currentSize <= highTotal)
		{
			if (aCounter % 2 == 0) //depending on whether or not aCounter is 
			{
				//swapWithSmallest(lowTotal,highTotal)
			}
		}
		aCounter = aCounter + 2;
		bCounter = bCounter + 2;
	}
}
void MinMaxHeap::checkMins(int depth)
{
	int aCounter = 0;
	int bCounter = 1;
	int counter = 0;

	while (counter < depth)
	{
		int lowTotal = pow(2, aCounter);
		int highTotal = pow(2, bCounter) - 1;
		if (currentSize >= lowTotal && currentSize <= highTotal)
		{
			if (aCounter % 2 == 0) //depending on whether or not aCounter is 
			{
				swapWithSmallest(lowTotal, highTotal);
				// will need to call insert again to get this to work properly.
			}
		}
		aCounter = aCounter + 2;
		bCounter = bCounter + 2;
	}
}
void MinMaxHeap::addToHeap(int variable)
{
	heap[currentSize] = variable;
	currentSize++;
}
/*	- Seaches within the lower and upper bounds to find the lowest value.
	- once value is found, place the value into minimum and its position into minimum position
	- set the heap at the minimum value's location = the new variable at heap[currentSize]
	- set the minimum value at the now old "new variable's" location (heap[currentSize] = minimum;)
*/
void MinMaxHeap::swapWithSmallest(int lowerBound, int upperBound)
{
	int counter = lowerBound;
	int minimum = 9999;
	int minimumPosition;
	for (int counter = lowerBound; counter <= upperBound; counter++)
	{
		if (heap[counter] < minimum)
		{
			minimum = heap[counter];
			minimumPosition = counter;
		}
	}
	// where the swap takes place
	heap[minimumPosition] = heap[currentSize];
	heap[currentSize] = minimum;
}
// places integers seperated by NEWLINES from file into string 
bool MinMaxHeap::isMaxLevel(int pos)
{
	int aCounter = 1;
	int bCounter = 2;
	if (pos == 1)
	{
		return false;
	}
	int counter = 0;
	while (counter <= 5)
	{
		int lowTotal = pow(2, aCounter);
		int highTotal = pow(2, bCounter) - 1;
		if (pos >= lowTotal && pos <= highTotal)
		{
			if (aCounter % 2 == 0) //depending on whether or not aCounter is 
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		aCounter++;
		bCounter++;
	}
}
