//Denzell Gibson
//6/10/2017

#include "Header.h"
#include "BTS.h"
#include "Node.h"

void AutomaticTesting();

int main()
{
	/*BTS<int> tree;
	Node<int>* root = NULL;

	root = tree.insertNode(root, 50);
	tree.display(root, 1);*/
	AutomaticTesting();

	system("pause");
	return 0;
}

void AutomaticTesting()
{
	std::cout << "***Test AVL Tree Constructor.***" << std::endl;
	BTS<int> tree;
	if (tree.getRoot() == NULL)
		std::cout << "PASSED - Object created and root set to null." << std::endl;
	else
		std::cout << "FAILED - root is not set to null." << std::endl;

	std::cout << "***Testing delete node function when the tree is empty.***" << std::endl;
	Node<int>* root = NULL;
	root = tree.deleteNode(root, 50);
	if (root == NULL)
		std::cout << "PASSED - null is returned." << std::endl;
	else
		std::cout << "FAILED - there is value." << std::endl;

	std::cout << "***Testing insert node function.***" << std::endl;
	root = tree.insertNode(root, 50);
	if (tree.findMaximum(root)->getData() == 50)
		std::cout << "PASSED - Node exist in tree." << std::endl;
	else
		std::cout << "FAILED - Node does not exist in tree." << std::endl;

	std::cout << "***Testing find maximum value function.***" << std::endl;
	root = tree.insertNode(root, 60);
	root = tree.insertNode(root, 70);
	if (tree.findMaximum(root)->getData() == 70)
		std::cout << "PASSED - Found the node with the highest value." << std::endl;
	else
		std::cout << "FAILED - Did not find the node with the highest value." << std::endl;

	std::cout << "***Testing the deletion of all nodes from the tree.***" << std::endl;
	root = tree.deleteNode(root, 70);
	root = tree.deleteNode(root, 60);
	root = tree.deleteNode(root, 50);
	if (root == NULL)
		std::cout << "PASSED - Tree is empty." << std::endl;
	else
		std::cout << "FAILED - Tree still contains nodes." << std::endl;
	
	std::cout << std::endl;
	std::cout << "***Testing insertion of multiple number of Nodes.***" << std::endl;
	root = tree.insertNode(root, 50);
	root = tree.insertNode(root, 70);
	root = tree.insertNode(root, 30);
	root = tree.insertNode(root, 60);
	root = tree.insertNode(root, 40);
	root = tree.insertNode(root, 80);
	root = tree.insertNode(root, 20);
	if (root != NULL)
		std::cout << "Passed - Tree is not empty and successfully entered all Nodes." << std::endl;
	else
		std::cout << "Failed - There are no Nodes in the tree." << std::endl;

	std::cout << "***Testing display function.***" << std::endl;
	tree.display(root, 1);

	std::cout << "***Testing string tree constructor.***" << std::endl;
	BTS<std::string> sTree;
	if (sTree.getRoot() == NULL)
		std::cout << "PASSED - Object created and root set to null." << std::endl;
	else
		std::cout << "FAILED - root is not set to null." << std::endl;

	std::cout << "***Testing delete node function when the tree is empty.***" << std::endl;
	Node<std::string>* sRoot = NULL;
	root = tree.deleteNode(root, 50);
	if (sRoot == NULL)
		std::cout << "PASSED - null is returned." << std::endl;
	else
		std::cout << "FAILED - there is value." << std::endl;

	std::cout << "***Testing insert node function.***" << std::endl;
	sRoot = sTree.insertNode(sRoot, "Robert");
	if (sTree.findMaximum(sRoot)->getData() == "Robert")
		std::cout << "PASSED - Node exist in tree." << std::endl;
	else
		std::cout << "FAILED - Node does not exist in tree." << std::endl;

	std::cout << "***Testing find maximum value function.***" << std::endl;
	sRoot = sTree.insertNode(sRoot, "Bob");
	sRoot = sTree.insertNode(sRoot, "Miyamoto");
	if (sTree.findMaximum(sRoot)->getData() == "Robert")
		std::cout << "PASSED - Found the node with the highest value." << std::endl;
	else
		std::cout << "FAILED - Did not find the node with the highest value." << std::endl;

	std::cout << "***Testing the deletion of all nodes from the tree.***" << std::endl;
	sRoot = sTree.deleteNode(sRoot, "Miyamoto");
	sRoot = sTree.deleteNode(sRoot, "Bob");
	sRoot = sTree.deleteNode(sRoot, "Robert");
	if (sRoot == NULL)
		std::cout << "PASSED - Tree is empty." << std::endl;
	else
		std::cout << "FAILED - Tree still contains nodes." << std::endl;

	std::cout << "***Testing insertion of multiple number of Nodes.***" << std::endl;
	sRoot = sTree.insertNode(sRoot, "Robert");
	sRoot = sTree.insertNode(sRoot, "Miyazaki");
	sRoot = sTree.insertNode(sRoot, "Kyle");
	sRoot = sTree.insertNode(sRoot, "Denzell");
	sRoot = sTree.insertNode(sRoot, "Cirey");
	sRoot = sTree.insertNode(sRoot, "Kobayashi");
	sRoot = sTree.insertNode(sRoot, "Alphonso");
	if (sRoot != NULL)
		std::cout << "Passed - Tree is not empty and successfully entered all Nodes." << std::endl;
	else
		std::cout << "Failed - There are no Nodes in the tree." << std::endl;

	std::cout << "***Testing display function.***" << std::endl;
	sTree.display(sRoot, 1);
}