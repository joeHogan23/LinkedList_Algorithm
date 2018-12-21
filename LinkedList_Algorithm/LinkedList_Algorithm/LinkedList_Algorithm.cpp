#include "pch.h"
#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int>* intLL = new LinkedList<int>();

	intLL->pushBack(59);
	intLL->pushBack(55);
	intLL->pushBack(67);
	intLL->pushBack(131);
	intLL->pushBack(187);
	intLL->pushBack(67);
	intLL->pushBack(67);
	intLL->pushFront(131);	//Push front
	intLL->pushBack(55);
	intLL->pushBack(30);

	cout << "Starting Count: " <<
		intLL->count() << endl;

	int intPop = intLL->popLastOf(55);

	cout << "Popped: " <<
		intPop << " using popLastOf(55)" << endl <<
		"Current Count: " << intLL->count() << endl << endl;

	intPop = intLL->popFirstOf(131);

	cout << "Popped: " <<
		intPop << " using popFirstOf(131)" << endl <<
		"Current Count: " << intLL->count() << endl << endl;

	intPop = intLL->popFront();

	cout << "Popped: " <<
		intPop << " using popFront()" << endl <<
		"Current Count: " << intLL->count() << endl << endl;

	intPop = intLL->popBack();

	cout << "Popped: " <<
		intPop << " using popBack()" << endl <<
		"Current Count: " << intLL->count() << endl << endl;


	cout << "DELETING..." << endl;
	delete intLL;
	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
