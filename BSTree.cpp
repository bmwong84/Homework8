
//Bryant Wong
//CSCI 2421 Homework 8


#include "BSTree.h"

// Constructor
BSTree::BSTree() {
    root = nullptr;
}

// Destructor
BSTree::~BSTree() {
	std::cout << "Deleting entire tree pointer" << std::endl;
    if (root !=nullptr)
        freeNode(root);
	std::cin.get();
}

// Free the node
void BSTree::freeNode(Node* leaf)
{
    if ( this->Root() == leaf)
    {
        
    }
    else if ( leaf != nullptr )
   
        {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        delete leaf;
        }
    
}

// Add a node
void BSTree::addNode(int key)
{
    // No elements. Add the root
    if ( root == nullptr ) {
        Node* n = new Node();
        n->setKey(key);
        root = n;
		//Bryant Wong
		std::cout << "Root set to " << n->Key() << std::endl;
    }
    else {
        addNode(key, root);
    }
}

// Add a node (private)
void BSTree::addNode(int key, Node* leaf) {
    if ( key <= leaf->Key() )
    {
		if (leaf->Left() != nullptr)
		{
			addNode(key, leaf->Left());
		}
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setLeft(n);
			//Bryant Wong
			std::cout << "Adding " << n->Key() << std::endl;;
        }
    }
    else
    {
        if ( leaf->Right() != nullptr )
            addNode(key, leaf->Right());
        else {
            Node* n = new Node();
            n->setKey(key);
            n->setParent(leaf);
            leaf->setRight(n);
			//Bryant Wong
			std::cout << "Adding " << n->Key() << std::endl;;
        }
    }
}

// Find a node
//Bryant Wong
Node* BSTree::findNode(int key, Node* node)		//passed root node and value you want to search for
{
	Node * temp = node;
	if (temp == nullptr)		//if tree is empty, return nullptr
	{
		std::cout << "Node " << key << " not found" << std::endl;
		return nullptr;
	}
	while (temp != nullptr)
	{
		if (temp->Key() == key)		//if the value we are searching for is equal to the value in the root node, return the root node
		{
			std::cout << "Node " << key << " found at address " << temp << std::endl;
			return temp;
		}
		else if (key > temp->Key())		//if the value is greater than the value we are searching for, traverse right
		{
			if (temp->Right() == nullptr)		//if the value in the node is greater than the value we are searching for and there is nothing greater than this node's value, return nullptr because value is not in tree
			{
				std::cout << "Node " << key << " not found" << std::endl;
				return nullptr;			
			}
			else           //else traverse right
			{
				temp = temp->Right();
			}
		}
		else if (key < temp->Key())	//if the value is less than the value we are searching for, traverse left
		{
			if (temp->Left() == nullptr)	//if there is nothing to the left of this node and the value is smaller, value is not in tree, return nullptr
			{
				std::cout << "Node " << key << " not found" << std::endl;
				return nullptr;
			}
			else					//else traverse left
			{
				temp = temp->Left();
			}
		}
	}
}

// Print the BSTree
//Bryant Wong
void BSTree::printPreorder(Node* node)
{
	if (node != nullptr)
	{
		std::cout << node->Key() << std::endl;			//prints the node it is currently at
		printPreorder(node->Left());			//then finds the smallest value in the left tree
		printPreorder(node->Right());			//then the largest value of that subtree
	}
}

//Bryant Wong
void BSTree::printInorder(Node* node)
{
	if (node != nullptr)		//if the root node exists, i.e. not empty tree
	{
		printInorder(node->Left());		//recurs this function for the left node until no more left nodes (smallest value)
		std::cout << node->Key() << std::endl;		//prints the data in the node
		printInorder(node->Right());		//recurs function for right most node, (highest value in the left most tree)
	}    
}

//Bryant Wong
void BSTree::printPostorder(Node* node)
{
    if ( node != nullptr)
    {
		printPostorder(node->Left());		//traverses to the smallest value node 
		printPostorder(node->Right());		//then to the largest value node in that subtree
		std::cout << node->Key() << std::endl;		//prints the data in the current node
    }
}

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
Node* BSTree::min(Node* node)
{
    Node* tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Left() )
    {
        tempNode = min(node->Left());
    }
    else
        tempNode = node;
    
    return tempNode;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
Node* BSTree::max(Node* node)
{
    Node * tempNode = node;
    if ( node == nullptr )
        tempNode = nullptr;
    else if ( node->Right() )
        tempNode = max(node->Right());
    else
        tempNode = node;
    
    return tempNode;
}

// Find successor to a node
// Find the node, get the node with max value
// for the right sub-BSTree to get the successor
Node* BSTree::successor(int key, Node *node)
{
    

    Node *successor = nullptr;
    Node *current  = root;
    if(root == nullptr)
        return NULL;
    
    while(current->Key() != key){
        /* If node value is greater than the node which are looking for, then go to left sub tree
         Also when we move left, update the successor pointer to keep track of lst left turn */
        
        if(current->Key() >key){
            successor = current;
            current= current->Left();
        }
        /* Else take right turn and no need to update successor pointer */
        else
            current = current->Right();
    }
    /*Once we reached at the node for which inorder successor is to be found, check if it has right sub tree, if yes then find the minimum in that right sub tree and return that node
     
     Else last left turn taken node is already stored in successor pointer and will be returned*/
    if(current && current->Right()){
        successor = min(current->Right());
    }
    return successor;
}

// Find predecessor to a node
// Find the node, get the node with max value
// for the left sub-BSTree to get the predecessor
Node* BSTree::predecessor(int key, Node *node)
{
    
    Node* current = findNode(key, node);

    if (current == nullptr)
        { return nullptr; }
    
    if (current->Left() !=nullptr)
    {
        return max(current->Left());
    } else
    
    {
        Node *tempParent = current->Parent();
        while (tempParent !=nullptr) {
            if (current == tempParent->Right() ){
                break;
            }
            current = tempParent;
            tempParent = current->Parent();
        }
        return tempParent;
    }
}


void BSTree::deleteNode(int key)
{
	std::cout << "Deleting " << key << std::endl;
    if (deleteNode(Root(), key) == nullptr)
        setRoot(nullptr);
}

//deleteNode (Private)
Node* BSTree::deleteNode(Node* root,int key)
{
   
    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */

    
        if(root == nullptr) return root;
        else if(key < root->Key())
            root->setLeft( deleteNode(root->Left(),key));
        else if(key > root->Key())
            root->setRight( deleteNode(root->Right(), key) );
        else {
            // Case 1: No Child
            if(root->Left() == nullptr && root->Right() == nullptr){
                delete root;
                root = nullptr;
                // Case 2: one child
            } else if(root->Left() == nullptr){
                Node *temp = root;
                root = root->Right();
                delete temp;
            } else if(root->Right() == nullptr){
                Node *temp = root;
                root = root->Left();
                delete temp;
            } else{
                Node *temp = min(root->Right());
                root->setKey(temp->Key() );
                root->setRight(  deleteNode(root->Right(), temp->Key() ) );
            }
        }
        return root;
    
}
