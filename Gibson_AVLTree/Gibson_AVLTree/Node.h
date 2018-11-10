//Denzell Gibson
//6/10/2017

#ifndef NODE_H_
#define NODE_H_

#include "Header.h"

//Node that contains data of type T, with pointers to the left and right child.
template <class T>
class Node
{
public:
	Node(); //Default Constructor.
	Node(T, Node<T>*, Node<T>*); //Constructor that takes T variable, and two Node pointers.

	void setLeft(Node<T>*); //Sets the left child pointer.
	void setRight(Node<T>*); //Sets the right child pointer.
	Node<T>* getLeft(); //Returns the left child pointer.
	Node<T>* getRight(); //Returns the right child pointer.
	void setData(T); //Sets the data variable.
	T getData(); //Returns the data variable.
private:

	//Data member declarations.
	T data;
	Node<T>* right; //Pointer to right child.
	Node<T>* left; //Pointer to left child.
};

//Node default constructor.
template <class T>
Node<T>::Node()
{
	data = 0; //Sets data to zero.
	balance = 1;

	//Sets both right and left child pointers to NULL.
	right = NULL;
	left = NULL;
}

//Node constructor that takes T data, and pointers to the right and left children, respectively.
template <class T>
Node<T>::Node(T newData, Node<T>* newRight, Node<T>* newLeft)
{
	data = newData; //Sets data to passed in value.

					//Sets the right and left child pointers to the pointers passed in.
	right = newRight;
	left = newLeft;
}

//Setter for the left child pointer.
template <class T>
void Node<T>::setLeft(Node<T>* newLeft)
{
	left = newLeft;
}

//Setter for the right child pointer.
template <class T>
void Node<T>::setRight(Node<T>* newRight)
{
	right = newRight;
}

//Getter for the left child pointer.
template <class T>
Node<T>* Node<T>::getLeft()
{
	return left;
}

//Getter for the right child pointer.
template <class T>
Node<T>* Node<T>::getRight()
{
	return right;
}

//Setter for the data variable.
template <class T>
void Node<T>::setData(T newData)
{
	data = newData;
}

//Getter for the data variable.
template <class T>
T Node<T>::getData()
{
	return data;
}

#endif
