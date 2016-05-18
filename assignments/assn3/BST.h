//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn3/BST.h
/// @brief Assignment 03 for CS 14 Spring 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date April 29, 2014
///
/// @par Enrollment Notes 
///     Lecture Section: 001
/// @par
///     Lab Section: 022
/// @par
///     TA: Mike Izbicki
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  =============== END ASSESSMENT HEADER ==================


#ifndef BST_H
#define BST_H
//#define TEST

#include<cassert>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<map>
#include<list>
#include<math.h>
#include<stack>


using namespace std;

//Interface of Tree class.
template<typename Type>
class Tree{
    private:

        class Node{
            public:
                Node* left;
                Node* right;
                Type value;
                int level;
                Node(const Type v = Type(), int lev = 1)
                    : left(0), right(0), value(v), level(lev)
                {}
                Type& content();
                bool isExternal() {return left != NULL && right != NULL;}
                bool isInternal () {return left != NULL || right != NULL;}
                bool isLeaf() { return left == NULL && right == NULL;}
                int height();
                int size();
                
            private:
            	
        		int findHeight(Node* i);
				int findSize(Node* i);
        };
        
        Node* root;
        int count;
        
        // These are my private helper functions
        void printPreorder(Node *i) const;
        void printPostorder(Node *i) const;
        void printInorder(Node *i) const;
        void findItem(int& n, bool& found, Node*& item, Node* i);
        
        
    public:
    
    	Tree() : root(NULL), count(0) {}
    	int size();
    	bool empty();
    	void print_node(const Node* n);
    	bool search(Type x);
    	void preorder() const;
    	void postorder() const;
    	void inorder() const;
    	Type& operator[] (int n);
    	void insert(Type x);
    	Node* insert(Type x, Node *i);
    	void remove(Type x);
    	Node* remove(Type x, Node* i);
    	void display();
    	void display(Node *n);
    	bool okay();
    	bool okay(Node *i);
    	void printHeight() const;
};

// Public member function returns value at Node.
template<typename Type>
Type& Tree<Type>::Node::content()
{
	return value;
}

// Public member function returns height/depth of tree. Used a private helper
// function.
template<typename Type>
int Tree<Type>::Node::height()
{
	// If there is no tree, return 0. But if there is a root, at least return
	// 1 for the root.
	return (this == 0) ? 0 : 1 + findHeight(this);
}

//Public member function returns the amount of Nodes in the tree. Used a 
// private helper function.
template<typename Type>
int Tree<Type>::Node::size()
{
	// If there is no tree, return 0. But if there is a root, at least return
	// 1 for the root.
	return (this == 0) ? 0 : findSize(this);
}

//Private member function returns hows deep the tree is after the root. 
template<typename Type>
int Tree<Type>::Node::findHeight(Node *i)
{
	if(isLeaf())
	{
		return 0;
	}
	
	// We'll store the depth of the right and left side in these respective
	// variables.
	int leftHeight = 0, rightHeight = 0;
	
	if(i->left != 0)
	{
		leftHeight = 1 + findHeight(i->left);
	}
	else
	{
		leftHeight = 0;
	}
	
	if(i->right != 0)
	{
		rightHeight = 1 + findHeight(i->right);
	}
	else
	{
		rightHeight = 0;
	}
	
	//Finally, we return the largest height.
	return (leftHeight > rightHeight) ? leftHeight : rightHeight;
	
}

//Private member function to determine all the amount of Nodes in the tree,
// not including the original Node that was passed in.
template<typename Type>
int Tree<Type>::Node::findSize(Node *i)
{
	
	if(i == 0)
		return 0;
		
	return 1 + findSize(i->left) + findSize(i->right);
}

//Returns size of the complete tree. Uses Node's size() function to do so.
template<typename Type>
int Tree<Type>::size()
{
	return root->size();
}

// Returns whether the Tree is empty or not.
template<typename Type>
bool Tree<Type>::empty()
{
	return size() == 0;
}

//Prints the contents of the Node.
template<typename Type>
void Tree<Type>::print_node(const Node* n)
{
	if(n != 0)
		cout << n->value;
}

// Searchs the tree to see if the value is contained within the tree.
template<typename Type>
bool Tree<Type>::search(Type x)
{
	Node *i = root;
	
	//If the tree reaches a null value, or the tree is an empty tree, then item
	// could not be located.
	while(i != 0)
	{
		if(x == i->value)
		{
			return true;
		}
		else if(x > i->value)
		{
			i = i->right;
		}
		else
		{
			i = i->left;
		}
	}
	
	return false;
}

//Public member function to print tree in preorder. Uses a private member 
// function to accomplish this.
template<typename Type>
void Tree<Type>::preorder() const
{
	if(root != 0)
		printPreorder(root);
}

//Private member function to print the tree in preorder. Sequence to print in
// preorder is NODE-LEFT-RIGHT
template<typename Type>
void Tree<Type>::printPreorder(Node *i) const
{
	
	cout << i->value << endl;
	
	if(i->left != 0)
		printPreorder(i->left);
	
	if(i->right != 0)
		printPreorder(i->right);
}

//Public member function to print tree in postorder. Uses a private member
// function to accomplish this.
template<typename Type>
void Tree<Type>::postorder() const
{
	if(root != 0)
		printPostorder(root);
}

// Private member function to print the tree in postorder. Sequence to print in
// postorder is LEFT-RIGHT-NODE
template<typename Type>
void Tree<Type>::printPostorder(Node *i) const
{
	
	if(i->left != 0)
		printPostorder(i->left);
	
	if(i->right != 0)
		printPostorder(i->right);
		
	cout << i->value << endl;
}

//Public member function to print tree in order. Uses a private member function
// to accomplish this.
template<typename Type>
void Tree<Type>::inorder() const
{
	if(root != 0)
		printInorder(root);
}

//Private member function to print tree in order. Sequence to print in order is
// LEFT-NODE-RIGHT
template<typename Type>
void Tree<Type>::printInorder(Node *i) const
{
	
	if(i->left != 0)
		printInorder(i->left);
		
	cout << i->value << endl;
	
	if(i->right != 0)
		printInorder(i->right);
}

//Operator[] overload. Uses private helper function to accomplish this.
template<typename Type>
Type& Tree<Type>::operator[](int n)
{

	// This checks to see whether the inputted value is within bounds.
	if(n < 0 || n >= size())
	{
		cerr << "Index position is out of range. Terminating program.";
		cerr << endl;
		exit(1);
	}

	
	Node* item;				//The index Node will be assigned to item.
	bool found = false;		//Will determine once we find the index.
	
	findItem(n, found, item, root);	
	
	// Returns the value at the found data.
	return item->value;

//------------------------------------------------------------------------------
// Extra practice. I was able to implement this function without using 
// recursion in the following code. I decided to go with recursion, however,
// since it seemed more relevant to trees. It seems to me that both actually
// have the same runtime.
//------------------------------------------------------------------------------
	// Node* temp = root;
	// stack<Node*> parents;
	
	// while(temp->left != 0)
	// {
	// 	parents.push(temp);
	// 	temp = temp->left;
	// }
	
	// n--;
	
	// while(n >= 0)
	// {
	// 	if(temp->right != 0)
	// 	{
	// 		temp = temp->right;
			
	// 		while(temp->left != 0)
	// 		{
	// 			parents.push(temp);
	// 			temp = temp->left;
	// 		}
			
	// 		n--;
	// 		continue;
	// 	}
		
	// 	temp = parents.top();
	// 	parents.pop();
	// 	n--;
	// }
	
	// return temp->value;
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
}

//Private helper function to find the value at given index.
template<typename Type>
void Tree<Type>::findItem(int& n, bool& found, Node*& item, Node* i)
{
	if(i == 0)
	{
		return;
	}
	
	//Travels to the left-most Node, which is the least. The counter, n, 
	// will start to decrement from there.
	findItem(n, found, item, i->left);
	
	n--;
	
	//If the value is found, we want to make sure we don't do anything else,
	// so we will constantly return until the initial call. This is why found
	// was passed by reference.
	if(found)
	{
		return;
	}
	
	//If the counter is still greater than 0, then we must continue traversing
	// the tree to get to the desired index.
	if(n < 0)
	{
		item = i;
		found = true;
		return;
	}
	
	findItem(n, found, item, i->right);
}

// Public function to insert a new node into the tree.
template<typename Type>
void Tree<Type>::insert(Type x)
{
	root = insert(x, root);
}

// Public helper function to insert a new node into the tree. To be honest, I 
// think this function should be private since any attempt to access a Node
// should be restricted from the user.
template<typename Type>
typename Tree<Type>::Node* Tree<Type>::insert(Type x, Node *i)
{
	if(i == NULL) // Once the index gets the the level of the leafs, add Node.
	{
		i = new Node(x);
	}
	else if(x < i->value)
	{
		i->left = insert(x, i->left);
	}
	else if(x > i->value)
	{
		i->right = insert(x, i->right);
	}
	else
	{
		i->value = x;
	}
	
	return i;
}

// Public member function to remove a Node from the tree.
template<typename Type>
void Tree<Type>::remove(Type x)
{
	root = remove(x, root);
}

// Public member helper function to remove a Node from the tree. Once again,
// I think this function should be private.
template<typename Type>
typename Tree<Type>::Node* Tree<Type>::remove(Type x, Node* i)
{
	if(i != NULL)
	{
		//These second level of branches tries to find the Node with the matched
		// value.
		if(x > i->value)
		{
			i->right = remove(x, i->right);
		}
		else if(x < i->value)
		{
			i->left = remove(x, i->left);
		}
		else
		{
			// If the value is found, and the right pointer does not point to
			// NULL, we want to replace the data of the Node we want removed 
			// with the data of it's left most leaf in it's right subtree.
			if(i->right != NULL)
			{
				Node* temp = i->right;
				while(temp->left != NULL)
				{
					temp = temp->left;
				}
				i->value = temp->value;
				i->right = remove(i->value, i->right);
			}
			else if(i->left != NULL)
			{
				// If it didn't have a right subtree, then we replace it with
				// the rightmost value of its left subtree to preserve order.
				Node* temp = i->left;
				while(temp->right != NULL)
				{
					temp = temp->right;
				}
				
				i->value = temp->value;
				i->left = remove(i->value, i->left);
			}
			else
			{
				//If it doesn't have a left or right child, then just delete
				// the Node. This also deletes the original copy if Node was
				// found in the middle of tree.
				delete i;
				i = NULL;
			}
		}
	}
	
	return i;
}

//Public member function to display the tree.
template<typename Type>
void Tree<Type>::display()
{
	display(root);
}

// Public member helper function to display the tree for human readability.
template<typename Type>
void Tree<Type>::display(Node *n)
{
	static int depth = 0;

	depth++;
	
	if(n == NULL)
	{
		return;
	}
	
	if(n->right != NULL)
	{
		display(n->right);
	}
	
	for(int i = 0; i != depth; i++)
	{
		cout << " "; // This prints out the spacing between children.
	}
	
	cout << n->value << "-" << n->level << endl;
	
	if(n->left != NULL)
	{
		display(n->left);
	}
	
	depth--;
}

//Function that we shall fully implement later in the course.
template<typename Type>
bool Tree<Type>::okay() 
{
	return okay(root);
}

// All professor Payne said to do was return whether the left Node is the
// predecessor and right child is the successor. Learned from Mike how to fully
// implement it in lab though. I'll wait till Payne says to implement it 
// however.
template<typename Type>
bool Tree<Type>::okay(Node *i)
{
	if(i->left != 0 && i->left->data > i->data)
		return false;
		
	if(i->right != 0 && i->right->data <= i->data)
		return false;
	
	return true;
}

// Public helper function to print the height of the tree since a function
// like this wasn't included.
template<typename Type>
void Tree<Type>::printHeight() const
{
	cout << "Height is " << root->height() << endl;
}

#endif