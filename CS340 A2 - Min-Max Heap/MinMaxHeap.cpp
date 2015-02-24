#include "Header.h"
#include "MinMaxHeap.h"

/* Accessors */

void MinMaxHeap::printHeap()
{
	for (int i = 0; i < maxSize; i++)
	{
		cout << heap[i];
	}
	cout << endl;
}

int MinMaxHeap::findMin()
{
	int minValue = heap[1];
	return minValue;
}

int MinMaxHeap::findMax()
{
	if (heap[2] < heap[3])
	{
		return  heap[3];
	}
	else
	{
		return heap[2];
	}
}

void MinMaxHeap::deleteMin()
{
	heap[1] = NULL;	//delete minimum value

	// counters incremented for looking at the next minimum depth down
	int depth = determineDepth();
	int aCounter = 2;	
	int bCounter = 3;
	int previousSmallestPosition = 1;

	// checks each minimum depth, grab the minimum value and replace it with the value missing above
	while (bCounter < depth)
	{
		int lowTotal = pow(2, aCounter);
		int highTotal = pow(2, bCounter) - 1;
		int smallestAtDepth = findSmallest(lowTotal, highTotal);

		swapWithSmallest(previousSmallestPosition, heap[smallestAtDepth]);

		aCounter = aCounter + 2;
		bCounter = bCounter + 2;
		previousSmallestPosition = smallestAtDepth;
	}
	// check the current depth for smallest variable and replace the missing min value above
	bCounter = depth;
	aCounter = bCounter - 1;

	int lowTotal = pow(2, aCounter);
	int highTotal = pow(2, bCounter) - 1;

	int smallestAtDepth = findSmallest(lowTotal, highTotal);
	swapWithSmallest(previousSmallestPosition, heap[smallestAtDepth]);


}

void MinMaxHeap::deleteMax()
{
	//delete maximum value
	int maximumPositon = findLargest(2, 3);	
	heap[maximumPositon] = NULL;

	// counters incremented for looking at the next maximum depth down
	int depth = determineDepth();
	int aCounter = 3;		
	int bCounter = 4;

	// checks each maximum depth, grab the maximum value and replace it with the value missing above
	while (bCounter < depth)
	{
		int lowTotal = pow(2, aCounter);
		int highTotal = pow(2, bCounter) - 1;
		int largestAtDepth = findLargest(lowTotal, highTotal);

		swapWithLargest(maximumPositon, heap[largestAtDepth]);

		aCounter = aCounter + 2;
		bCounter = bCounter + 2;
		maximumPositon = largestAtDepth;
	}
	// check the current depth for largest variable and replace the missing min value above
	bCounter = depth;
	aCounter = bCounter - 1;

	int lowTotal = pow(2, aCounter);
	int highTotal = pow(2, bCounter) - 1;

	int largestAtDepth = findLargest(lowTotal, highTotal);
	swapWithLargest(maximumPositon, heap[largestAtDepth]);
}
 
MinMaxHeap::MinMaxHeap()
{
	currentSize = 0; //takes into account the heap-order property that first place in array cant be filled
	maxSize = 32;
	for (int i = 0; i < maxSize; i++)
	{
		integersToHeap[i] = NULL;
	}
	buildMinMaxHeap();
}

/* Private Functions */

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
	checkMaxes(depth);
	checkMins(depth);
}

void MinMaxHeap::insert()
{
	int depth = determineDepth();
	checkMaxes(depth);
	checkMins(depth);
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
		counter++;
	}
}

void MinMaxHeap::checkMaxes(int depth)
{
	// look at current size, determine what the depth of the tree is - ignore that current depth

	//check if larger than positions between 
	int aCounter = 1;
	int bCounter = 2;

	while (bCounter <= depth)
	{
		int lowTotal = pow(2, aCounter);
		int highTotal = pow(2, bCounter) - 1;
		int smallestAtDepth = findSmallest(lowTotal, highTotal);

		if (heap[currentSize] > heap[smallestAtDepth])
		{
			swapWithSmallest(smallestAtDepth, heap[smallestAtDepth]);
				insert();// will need to call insert again to get this to work properly.
		}
		aCounter = aCounter + 2;
		bCounter = bCounter + 2;
	}
}

void MinMaxHeap::checkMins(int depth)
{
	int aCounter = 0;
	int bCounter = 1;

	while (bCounter <= depth)
	{
		int lowTotal = pow(2, aCounter);
		int highTotal = pow(2, bCounter) - 1;
		int largestAtDepth = findLargest(lowTotal, highTotal);

		if (heap[currentSize] < heap[largestAtDepth])
		{
			swapWithLargest(largestAtDepth, heap[largestAtDepth]);
				insert();// will need to call insert again to get this to work properly.
		}
		aCounter = aCounter + 2;
		bCounter = bCounter + 2;
	}
}

void MinMaxHeap::swapWithSmallest(int minimumPosition, int minimum)
{
	
	heap[minimumPosition] = heap[currentSize];
	heap[currentSize] = minimum;
}

void MinMaxHeap::swapWithLargest(int maximumPosition, int maximum)
{
	
	heap[maximumPosition] = heap[currentSize];
	heap[currentSize] = maximum;
}

int MinMaxHeap::findSmallest(int lowerBound, int upperBound)
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
	return minimumPosition;
}

int MinMaxHeap::findLargest(int lowerBound, int upperBound)
{
	int counter = lowerBound;
	int maximum = -9999;
	int maximumPosition;
	for (int counter = lowerBound; counter <= upperBound; counter++)
	{
		if (heap[counter] > maximum)
		{
			maximum = heap[counter];
			maximumPosition = counter;
		}
	}
	return maximumPosition;
}

void MinMaxHeap::addToHeap(int variable)
{
	currentSize++;
	heap[currentSize] = variable;
}

