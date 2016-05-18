//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn3/main.cc
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


#include<iostream>

#include "BST.h"

using namespace std;

int main()
{
	
	Tree<int> test;
	
	// Inserts random numbers to test the Tree and Node classes.
	cout << "Inserting the following numbers in the following order into test ";
	cout << "tree:\n50 76 21 4 32 64 15 52 14 100 83 2 3 70 87 80" << endl;
	
	test.insert(50);
	test.insert(76);
	test.insert(21);
	test.insert(4);
	test.insert(32);
	test.insert(64);
	test.insert(15);
	test.insert(52);
	test.insert(14);
	test.insert(100);
	test.insert(83);
	test.insert(2);
	test.insert(3);
	test.insert(70);
	test.insert(87);
	test.insert(80);
	
	
	string dashes;
	for(int i = 0; i < 80; i++)
	{
		dashes += "-";
	}
	
	Tree<int> test1;
	
	cout << dashes << endl;
	cout << "Testing inorder traversal here." << endl;
	cout << "Should be 2 3 4 14 15 21 32 50 52 64 70 76 80 83 87 100" << endl;
	test.inorder();
	
	cout << endl << dashes << endl;
	
	cout << "Testing postorder traversal here." << endl;
	cout << "Should be 3 2 14 15 4 32 21 52 70 64 80 87 83 100 76 50" << endl;
	test.postorder();
	
	
	cout << endl << dashes << endl;

	cout << "Testing preorder traversal here." << endl;
	cout << "Should be 50 21 4 2 3 15 14 32 76 64 52 70 100 83 80 87" << endl;
	test.preorder();
	
	cout << endl << dashes << endl;
	
	cout << "Testing print functions of empty tree: " << endl;
	test1.inorder(); cout << endl;
	test1.preorder(); cout << endl;
	test1.postorder(); cout << endl;
	
	cout << endl << dashes << endl;
	cout << "Testing size() function of the entire tree here." << endl;
	cout << "Should be 16: " << test.size() << endl;
	
	cout << "Testing size() function on an empty tree (should be 0): ";
	cout << test1.size() << endl;
	
	cout << "Testing size() function with just a root (should be 1): ";
	test1.insert(1);
	cout << test1.size() << endl;
	test1.remove(1);
	
	cout << endl << dashes <<  endl;
	
	cout << "Testing operator[] here." << endl;
	cout << "test[6] should be 32: " << test[6] << endl;
	cout << "test[test.size() - 1] should be 100: ";
	cout << test[test.size() - 1] << endl;
	cout << "test[0] should be 2: ";
	cout << test[0] << endl;
	cout << endl << dashes << endl;
	
	cout << "Testing display function here: " << endl;
	test.display();
	
	cout << endl << dashes << endl;
	
	cout << "Removing 100 from the tree: " << endl;
	test.remove(100);
	test.inorder();
	cout << endl;
	cout << "Size after removal should be 15: " << test.size();
	cout << endl << dashes << endl;
	
	cout << "Printing height of the tree. Should be 5: ";
	test.printHeight();
	cout << endl;
	
	cout << "Printing height of an empty tree: ";
	test1.printHeight(); 
	cout << endl;
	
	test1.insert(1);
	cout << "Printing height of a tree with just a root: ";
	test1.printHeight();
	test1.remove(1);
	cout << endl << dashes << endl;
	
	cout << "Attempting to find 76 in the list (should be 1): ";
	cout << test.search(76) << endl;
	
	cout << "Attempting to find 109 in the tree (should be 0): ";
	cout << test.search(109) << endl;
	
	cout << "Attempting to search anything in empty tree (should be 0): ";
	cout << test1.search(2) << endl;
	
	cout << endl << dashes << endl;
	
	cout << "Error testing here." << endl;
	

	
	// cout << "Out of bounds for [] operator: " << endl << test[-1];
	// cout << "Out of bounds for [] operator: " << endl << test[100];
	// cout << "Out of bounds for [] operator: " << endl << test[test.size()];
	// cout << "Out of bounds for empty tree [] operator: " << endl << test1[0];
	
	
	cout << endl << dashes << endl;
	
	return 0;
}