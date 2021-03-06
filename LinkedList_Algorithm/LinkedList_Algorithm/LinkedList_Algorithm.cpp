﻿#include "pch.h"
#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList<int>* intLL = new LinkedList<int>();
	
	intLL->pushBack(59);	//Push back
	intLL->pushBack(55);	//Push back
	intLL->pushBack(67);	//Push back
	intLL->pushBack(131);	//Push back
	intLL->pushBack(187);	//Push back
	intLL->pushBack(67);	//Push back
	intLL->pushBack(67);	//Push back
	intLL->pushFront(131);	//Push front
	intLL->pushBack(55);	//Push back
	intLL->pushBack(30);	//Push back

	//Get the item count
	cout << "Starting Count: " <<
		intLL->count() << endl;

	//Get last element of value 55 found in list, assign and remove from list 
	int intPop = intLL->popLastOf(55);

	//Output intPop to console
	cout << "Popped: " <<
		intPop << " using popLastOf(55)" << endl <<
		"Current Count: " << intLL->count() << endl << endl;

	//Get first element of value 131 found in list, assign and remove from list
	intPop = intLL->popFirstOf(131);

	//Output intPop to console
	cout << "Popped: " <<
		intPop << " using popFirstOf(131)" << endl <<
		"Current Count: " << intLL->count() << endl << endl;

	//Pop head 
	intPop = intLL->popFront();

	//Output intPop to console
	cout << "Popped: " <<
		intPop << " using popFront()" << endl <<
		"Current Count: " << intLL->count() << endl << endl;

	//Pop tail
	intPop = intLL->popBack();

	//Output intPop to console
	cout << "Popped: " <<
		intPop << " using popBack()" << endl <<
		"Current Count: " << intLL->count() << endl << endl;

	
	cout << "DELETING..." << endl;
	delete intLL;	//Delete all nodes inside list, then delete list
	system("pause");
}
