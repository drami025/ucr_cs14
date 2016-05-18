//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn5/main.cc
/// @brief Assignment 05 for CS 14 Spring 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date May 20, 2014
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
#include "hashmap.h"

using namespace std;

// Cool random string generator that we found online.
static const char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()  // Random string generator function.
{
    return alphanum[rand() % stringLength];
}

string makeString(int length)
{
	string something = "";
	
	for(int i = 0; i < length; i++)
	{
		something+= genRandom();
	}
	
	return something;
}

int main()
{
	hashmap<string> hashy;
	string s;
	
	for(unsigned i = 0; i < 103; i++)
	{
		s = makeString(5);
		hashy[s] = "Weeee!";
	}
	
	
	for(unsigned i = 0; i < 103; i++)
	{
		hashy.printNode(i);
		cout << endl << endl;
	}
	
	cout << "\n\nTesting find: " << endl << endl;
	
	(hashy.find(s) == hashy.end()) ? cout << "Miss" : cout << "Hit";
	cout << endl;
	
	cerr << "Last index of Hashy before change: " << (hashy.find(s))->data 
		<< endl;
	cerr << "After change: ";
	
	(hashy.find(s))->data = "squiggly";
	cout << (hashy.find(s))->data << endl;
	
	// cout << "Inserting while hash table is full: ";
	// hashy["what's up!!!"] = "Oh no!";

	
	
	return 0;
}