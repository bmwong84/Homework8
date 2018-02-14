
//Bryant Wong
//CSCI 2421 Homework 8

#include "Node.h"
#include "BSTree.h"


int main()
{
	BSTree leafyTreefy;							//create an instance of class BSTree

	leafyTreefy.addNode(300);		//add 300 as root
	leafyTreefy.addNode(100);		//add 100
	leafyTreefy.addNode(200);
	leafyTreefy.addNode(400);
	std::cout << "Preorder print:" << std::endl;
	leafyTreefy.printPreorder(leafyTreefy.Root());		//print the preorder of the tree
	std::cout << "Inorder print:" << std::endl;
	leafyTreefy.printInorder(leafyTreefy.Root());		//print tree inorder
	std::cout << "Postorder print" << std::endl;
	leafyTreefy.printPostorder(leafyTreefy.Root());		//print tree postorder
	(leafyTreefy.findNode(500, leafyTreefy.Root()));		//attempt to find the node containing data "500"
	(leafyTreefy.findNode(600, leafyTreefy.Root()));		

	std::cout << "Min = " << (leafyTreefy.min(leafyTreefy.Root())->Key()) << std::endl;		//the min value in the tree is...
	std::cout << "Max = " << (leafyTreefy.max(leafyTreefy.Root())->Key())<< std::endl;

	std::cout << "Successor to 300 = " << (leafyTreefy.successor(300, leafyTreefy.Root())->Key()) << std::endl;		//the successor to 300 is...
	std::cout << "Predecessor to 300 = " << (leafyTreefy.predecessor(300, leafyTreefy.Root())->Key()) << std::endl;		//the predecessor to 300 is	

	leafyTreefy.deleteNode(300);		//delete the root

	std::cout << "Preorder print:" << std::endl;		
	leafyTreefy.printPreorder(leafyTreefy.Root());			//print tree in preorder after removing root node

	std::cin.get();
	return 0;
}