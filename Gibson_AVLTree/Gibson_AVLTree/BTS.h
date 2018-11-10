//Denzell Gibson
//6/10/2017

#ifndef BTS_H_
#define BTS_H_

#include "Header.h"
#include "Node.h"

//Binary Search Tree class that contains and manages Nodes.
template <class T>
class BTS
{
public:
	BTS(); //Default constructor.

	Node<T>* insertNode(Node<T>*, T); //Allows for the creation of a Node, using the value passed in, at the correct location in the tree, rebalances the tree afterwards.
	Node<T>* deleteNode(Node<T>*, T); //Deletes a Node from the tree, restructures the tree.
	Node<T>* findMaximum(Node<T>*); //Find and returns the maximum value contain in any of the Nodes in the tree.
	Node<T>* findMinimum(Node<T>*); //Finds the node with the lowest value in the right subtree.
	void display(Node<T>*, int);

	void setRoot(Node<T>*);
	Node<T>* getRoot();
private:
	Node<T>* root; //Pointer to the first Node in the tree.

	Node<T>* rotateLeft(Node<T>*); //Rotates the node, the node's right child, and the right child's left child to the left direction.
	Node<T>* rotateRight(Node<T>*); //Rotates the node, the node's left child, and the left child's right hcild to the right direction.
	Node<T>* leftRightRotation(Node<T>*); //Performs a double rotation, rotating right, then left.
	Node<T>* rightLeftRotation(Node<T>*); //Performs a double rotation, rotating left, then right.
	Node<T>* rebalance(Node<T>*); //Checks if the balance is greater than one in either direction, and rotates the node in the appropriate direction.

	int max(int, int); //returns the higher value.
	int getHeight(Node<T>*); //Returns the node's height, while checking if pointer is null.
	int heightDifference(Node<T>*); //Finds the balance through finding the difference in height.

};

//Default constructor, makes first point to NULL.
template <class T>
BTS<T>::BTS()
{
	root = NULL;
}

//Inserts a new node and rebalances the tree.
template <class T>
Node<T>* BTS<T>::insertNode(Node<T>* currentNode, T newData)
{
	if (currentNode == NULL)
	{
		currentNode = new Node<T>(newData, NULL, NULL);
		return currentNode;
	}
	else if (newData < currentNode->getData())
	{
		currentNode->setLeft(insertNode(currentNode->getLeft(), newData));
		currentNode = rebalance(currentNode);
	}
	else if (newData >= currentNode->getData())
	{
		currentNode->setRight(insertNode(currentNode->getRight(), newData));
		currentNode = rebalance(currentNode);
	}
	return currentNode;
}

//Deletes a node from the tree, restructures the tree.
template <class T>
Node<T>* BTS<T>::deleteNode(Node<T>* currentNode, T data)
{
	if (currentNode == NULL)
	{
		return currentNode;
	}
	else if (data < currentNode->getData())
	{
		currentNode->setLeft(deleteNode(currentNode->getLeft(), data));
	}
	else if (data > currentNode->getData())
	{
		currentNode->setRight(deleteNode(currentNode->getRight(), data));
	}
	else
	{
		if (currentNode->getLeft() == NULL && currentNode->getRight() == NULL)
		{
			delete(currentNode);
			currentNode = NULL;
		}
		else if (currentNode->getLeft() == NULL)
		{
			Node<T>* temp = currentNode;
			currentNode = currentNode->getRight();
			delete temp;
		}
		else if (currentNode->getRight() == NULL)
		{
			Node<T>* temp = currentNode;
			currentNode = currentNode->getLeft();
			delete temp;
		}
		else
		{
			Node<T>* temp = findMinimum(currentNode->getRight());
			currentNode->setData(temp->getData());
			currentNode->setRight(deleteNode(currentNode->getRight(), temp->getData()));
			currentNode = rebalance(currentNode);
		}
	}
	return currentNode;
}

//Finds the node with the lowest value, and returns the pointer.
template <class T>
Node<T>* BTS<T>::findMinimum(Node<T>* currentNode)
{
	Node<T> *temp; //Make temp pointer.
	temp = currentNode;

	if (currentNode->getLeft() != NULL)
	{
		currentNode = findMinimum(currentNode->getLeft());
	}
	return currentNode;
}

//Find the maximum value contained in the tree, and returns the value.
template <class T>
Node<T>* BTS<T>::findMaximum(Node<T>* currentNode)
{
	Node<T>* temp = currentNode;//Make temp pointer.

	if (temp->getRight() != NULL) //if right child is not NULL...
	{
		temp = findMaximum(temp->getRight()); //Continue to go down the right subtree.
	}

	return temp; //Returns the pointer of the highest value node.
}

//Left Left Rotation Case.
template <class T>
Node<T>* BTS<T>::rotateLeft(Node<T>* currentNode)
{
	Node<T>* temp;
	temp = currentNode->getLeft();
	currentNode->setLeft(temp->getRight());
	temp->setRight(currentNode);
	return temp;
}

//Right Right Rotation Case.
template <class T>
Node<T>* BTS<T>::rotateRight(Node<T>* currentNode)
{
	Node<T>* temp;

	temp = currentNode->getRight();
	currentNode->setRight(temp->getLeft());
	temp->setLeft(currentNode);
	return temp;
}

//Left Right Rotation of Nodes.
template <class T>
Node<T>* BTS<T>::leftRightRotation(Node<T>* currentNode)
{
	Node<T>* temp;
	temp = currentNode->getLeft();
	currentNode->setLeft(rotateRight(temp));
	return rotateLeft(currentNode);
}

//Right Left Rotation of Nodes.
template <class T>
Node<T>* BTS<T>::rightLeftRotation(Node<T>* currentNode)
{
	Node<T>* temp;
	temp = currentNode->getRight();
	currentNode->setRight(rotateLeft(temp));
	return rotateRight(currentNode);
}

//Checks for balance and does the appropriate rotation of nodes in the correct direction.
template <class T>
Node<T>* BTS<T>::rebalance(Node<T>* currentNode)
{
	int balance;
	balance = heightDifference(currentNode);

	//If Balance is greater than one...
	if (balance > 1)
	{
		//Left Left Rotation Case.
		if (heightDifference(currentNode->getLeft()) > 0)
		{
			currentNode = rotateLeft(currentNode);
		}
		//Left Right Rotation Case.
		else
		{
			currentNode = leftRightRotation(currentNode);
		}
	}
	//If Balance is less than -1...
	else if (balance < -1)
	{
		//Right Left Rotation Case.
		if (heightDifference(currentNode->getRight()) > 0)
		{
			currentNode = rightLeftRotation(currentNode);
		}
		//Right Right Rotation Case.
		else
		{
			currentNode = rotateRight(currentNode);
		}
	}
	return currentNode;
}

//Returns the bigger value.
template <class T>
int BTS<T>::max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
		return b;
}

//Calculates the height of the node.
template <class T>
int BTS<T>::getHeight(Node<T>* currentNode)
{
	int height, leftHeight, rightHeight, maxHeight;
	height = 0;

	if (currentNode != NULL)
	{
		if (currentNode->getLeft() != NULL)
		{
			leftHeight = getHeight(currentNode->getLeft());
		}
		else
		{
			leftHeight = 0;
		}

		if (currentNode->getRight() != NULL)
		{
			rightHeight = getHeight(currentNode->getRight());
		}
		else
		{
			rightHeight = 0;
		}
		maxHeight = max(leftHeight, rightHeight);
		height = maxHeight + 1;
	}
	else
	{
		height = 0;
	}
	return height;
}

//Finds the balance of the node by find the height and subtracting right subtree from left subtree height.
template <class T>
int BTS<T>::heightDifference(Node<T>* currentNode)
{
	int leftHeight, rightHeight, balance;

	if (currentNode->getLeft() != NULL)
	{
		leftHeight = getHeight(currentNode->getLeft());
	}
	else
	{
		leftHeight = 0;
	}
	
	if (currentNode->getRight() != NULL)
	{
		rightHeight = getHeight(currentNode->getRight());
	}
	else
	{
		rightHeight = 0;
	}
	balance = leftHeight - rightHeight;
	return balance;
}

//Displays the tree to the console sideways.
template <class T>
void BTS<T>::display(Node<T>* currentNode, int level)
{
	int i;
	if (currentNode != NULL)
	{
		display(currentNode->getRight(), level + 1);
		printf("\n");
		if (currentNode == root)
			std::cout << "Root -> ";
		for (i = 0; i < level && currentNode != root; i++)
			std::cout << "        ";
		std::cout << currentNode->getData();
		display(currentNode->getLeft(), level + 1);
	}
}

//Setter for root Node pointer.
template <class T>
void BTS<T>::setRoot(Node<T>* newRoot)
{
	root = newRoot;
}

//Getter for root Node pointer.
template <class T>
Node<T>* BTS<T>::getRoot()
{
	return root;
}

#endif