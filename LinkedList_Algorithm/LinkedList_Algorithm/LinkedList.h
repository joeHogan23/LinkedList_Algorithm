#pragma once
#include "pch.h"
#include "Node.h"


template<typename T>
class LinkedList {
private:
	Node<T> *head, *tail; //Front and Back 

public:

	LinkedList() 
	{
		//Default head and tail to nullptr
		head = tail = 0;
	};
	
	~LinkedList() 
	{
		while (!isEmpty()) 
		{
			Node<T>* tmp = head->getNext();	 //Set tmp to address of next Node in list
			delete head; //delete the head
			head = tmp;	 //Push head to next Node. When this is null, list is empty
			cout << "Node "<< count() <<" deleted" << endl;
		}
		cout << "List deleted" << endl;
	};	

	//Search which is Used for classes where there is no specific value (int, string) tied to it
	T searchByKey(string key);	

	T popFirstOf(T inData); //Find first element matching data
	T popLastOf(T inData);  //Find last element matching data

	void pushFront(T data, string inKey = ""); //Set Tail	
	void pushBack(T data, string inKey = "");  //Set Head	

	T popFront();	//Return head and remove from list 
	T popBack();	//Return tail and remove from list

	T* toArray();			//Return List as Array
	Node<T>* getFront();	//Get Head
	Node<T>* getBack();		//Get Tail

	void setFront(Node<T>* inHead);	//Set Head
	void setBack(Node<T>* inTail);	//Set Tail

	const int count();		//Get List Count

	bool isEmpty();			//Checks if there are any elements in List
};

//--- Search for Element by Key ---
template<typename T>
inline T LinkedList<T>::searchByKey(string key)
{
	//Look for tmp by iterating through list
	for (Node<T>* tmp = head; tmp != 0; tmp = tmp->getNext()) 
	{
		if (tmp->getKey() == key)	//If key matches current node's key
			return tmp->getData();
	}
	return NULL;
}

// --- Return the First Data in List Matching Search Parameter. Delete Node Containing Data  ---
template<typename T>
inline T LinkedList<T>::popFirstOf(T inData)
{
	if (head != 0) 
	{
		T data = head->getData();

		if (head == tail && head->getData() == inData)
		{
			delete head;	//Delete the head
			head = tail = 0;	//Empty out list
			return data;	//Return data
		}
		else if (head->getData() == inData)
		{
			Node<T>* tmp = head;	
			head = head->getNext();	//Assign new head to next Link
			delete tmp;		//Delete old head
			return data;	//Return data
		}
		else
		{
			Node<T>* prev, *tmp;
			for (prev = head, tmp = head->getNext(); tmp->getData() != inData && tmp != 0; prev = prev->getNext(), tmp = tmp->getNext());

			if (tmp != 0) 
			{
				prev->setNext(tmp->getNext());	//Stitch elements before and after found element together
				if (tmp == tail)
					tail = prev; //If item is at the end of list, push tail back to prev's position
				data = tmp->getData();	//Pass Node data to T data
				delete tmp;		//Delete found Node
				return data;	//Return deleted Node's data
			}
		}
	}
	return NULL;
}

// --- Return the Last Data in List Matching Search Parameter. Delete Node Containing Data ---
template<typename T>
inline T LinkedList<T>::popLastOf(T inData)
{
	if (head != 0)
	{
		T data = head->getData();

		if (head == tail && head->getData() == inData)
		{
			delete head;	//Delete the head
			head = tail = 0;	//Empty out list
			return data;	//Return data
		}
		else
		{
			//The last element with matching data found in list
			Node<T>* prev = nullptr, *tmp = nullptr;

			//Keep track of current and previous element in list
			for (Node<T>* last = head, *curr = head->getNext(); curr != 0; last = last->getNext(), curr = curr->getNext())
			{
				//Assign most recent found Node with matching data
				if (curr->getData() == inData) 
				{
					tmp = curr;		//Current node with matching data
					prev = last;	//Node before Current
				}
			}
			
			if (tmp != 0)
			{
				if (tmp == head)
				{
					Node<T>* tmpHead = head;
					head = head->getNext();	//Assign new head to next Link
					delete tmpHead;		//Delete old head
					return data;	//Return data
				}
				prev->setNext(tmp->getNext());	//Stitch elements before and after found element together
				
				if (tmp == tail)
					tail = prev; //If item is at the end of list, push tail back to prev's position
				
				data = tmp->getData();	//Pass Node data to T data
				delete tmp;		//Delete found Node
				return data;	//Return deleted Node's data
			}
		}
	}
	return NULL;
}

//--- Add Element to Head ---
template<typename T>
inline void LinkedList<T>::pushFront(T data, string inKey)
{
	//Make head a new Node and push old head to the next in link
	head = new Node<T>(data, head, inKey);

	//Link front to back if there is only one element in list
	if (tail == 0)
		tail = head;
}

//--- Add Element to Tail ---
template<typename T>
inline void LinkedList<T>::pushBack(T data, string inKey)
{
	if (tail != 0)
	{
		//Create the new tail as the next element in tail
		tail->setNext(new Node<T>(data, 0, inKey));

		//Push tail down one Link
		tail = tail->getNext();
	}
	else
		//If list is empty, assign head and tail as new node
		tail = head = new Node<T>(data, 0, inKey);
}

//--- Return Head and Remove From LinkedList---
template<typename T>
inline T LinkedList<T>::popFront()
{
	T data = head->getData(); //Get data

	Node<T>* tmp = head; //Node to be deleted

	if (head == tail)
		head = tail = 0;	//Empty out list
	else
		head = head->getNext(); //Move the head down by one Node

	delete tmp;
	return data; //Return data from old head
}

//--- Return Tail and Remove From LinkedList---
template<typename T>
inline T LinkedList<T>::popBack()
{
	T data = tail->getData(); 	//data which will be returned

	if (tail == head) {
		delete head;
		head = tail = 0;	//Empty out list
	}
	else {
		Node<T>* tmp;

		//Iterate until tmp is the Node before tail
		for (tmp = head; tmp->getNext() != tail; tmp = tmp->getNext());

		delete tail; //Delete the current tail
		tail = tmp;	//Assign tmp as the new tail
		tail->setNext(0); //null the previous tail
	}
	return data;	//Return old tail's data
}

//--- Convert List to Array. Return Array ---
template<typename T>
inline T * LinkedList<T>::toArray()
{
	//If no elements
	if (head == 0) return NULL;

	int i = count(); //Set the n index

	//Create array using list size and decrement i for n - 1 indexing 
	T* elements = new T[i--];

	for (Node<T>* tmp = head; tmp != 0; tmp = tmp->getNext())
	{
		//Assign data from tmp to element at index i
		elements[i--] = tmp->getData();
	}
	return elements; //Return array of list elements
}

//--- Get Number of Elements in List ---
template<typename T>
inline const int LinkedList<T>::count()
{
	//Keeps track of count
	int c = 0;

	//Counts how many links there are in list
	for (Node<T>* tmp = head; tmp != 0; tmp = tmp->getNext()) c++;

	//returns count
	return c;
}

//--- Check if List has Elements ---
template<typename T>
inline bool LinkedList<T>::isEmpty()
{
	return head == 0;
}

//--- Get Head ---
template<typename T>
inline Node<T> * LinkedList<T>::getFront() { return head; }

//--- Get Tail ---
template<typename T>
inline Node<T> * LinkedList<T>::getBack() { return tail; }

//--- Set Head ---
template<typename T>
inline void LinkedList<T>::setFront(Node<T>* inHead) { head = inHead; }

//--- Set Tail ---
template<typename T>
inline void LinkedList<T>::setBack(Node<T>* inTail) { tail = inTail; }
