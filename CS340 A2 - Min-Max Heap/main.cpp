#include "Header.h"
#include "MinMaxHeap.h"

int main()
{
	MinMaxHeap heap;

	cout << "Heap has been created, here is the heap: " << endl;
	heap.printHeap();
	cout << "Please enter what you would like to do:" << endl
		 << "A: print the minimum element" << endl
		 << "B: print the maximum element" << endl
		 << "C: insert a value into the heap" << endl
		 << "D: delete the minimum value" << endl
		 << "E: delete the maximum value" << endl
		 << "F: print the table again" << endl
		 << "X: exit the program" << endl;
	char input = 'z';
	while (input != 'x' || input != 'X')
	{
		cout << " Please enter what you would like to do: " << endl;
		cin >> input;
		if (input == 'a' || input == 'A')
		{
			heap.findMin();
		}
		else if (input == 'b' || input == 'B')
		{
			heap.findMax();
		}
		else if (input == 'c' || input == 'C')
		{
			int integer;
			cout << "please enter an integer to add to the heap" << endl;
			cin >> integer;
			heap.insertFromUser(integer);
		}
		if (input == 'd' || input == 'D')
		{
			heap.deleteMin();
		}
		else if (input == 'e' || input == 'E')
		{
			heap.deleteMax();
		}
		else if (input == 'f' || input == 'F')
		{
			heap.printHeap();
		}
		else if (input == 'x' || input == 'X')
		{
			break;
		}
		else
		{
			cout << "please enter a correct input" << endl;
		}
	}
}


