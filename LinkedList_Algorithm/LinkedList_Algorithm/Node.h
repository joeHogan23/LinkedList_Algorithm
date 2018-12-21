#pragma once
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node {
private:

	string key;
	Node<T> *next;
	T data;

public:
	Node<T>(T inData, Node<T>* inNext = 0, string inKey = "");

	void setKey(string inKey);
	string getKey();

	void setNext(Node<T>* inNext);
	Node<T>* getNext();

	void setData(T inData);
	T getData();
};

//Constructor
template<typename T> inline Node<T>::Node(T inData, Node<T>* inNext, string inKey) : data(inData), next(inNext), key(inKey) {};

//Set Key
template<typename T> inline void Node<T>::setKey(string inKey) { key = inKey; }

//Get Key
template<typename T> inline string Node<T>::getKey() { return key; }

//Set Next Node
template<typename T> inline void Node<T>::setNext(Node<T>* inNext) { next = inNext; }

//Get Next Node
template<typename T> inline Node<T>* Node<T>::getNext() { return next; }

//Set Data In Node
template<typename T> inline void Node<T>::setData(T inData) { data = inData; }

//Get Data In Node
template<typename T> inline T Node<T>::getData() { return data; }


