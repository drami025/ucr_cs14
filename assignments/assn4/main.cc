//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn4/main.cc
/// @brief Assignment 04 for CS 14 Spring 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date May 12, 2014
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
#include "mymap.h"

using namespace std;

int main()
{
	string dashes;
	
	for(unsigned i = 0; i < 79; i++)
	{
		dashes += "-";
	}
	
	cout << dashes << endl;
	cout << "Professor's code: " << endl;
	
	mymap<string, int> ml;
	ml["January"] = 1;
	ml["February"] = 2;
	ml["March"] = 3;
	ml["April"] = 4;
	ml["May"] = 5;
	ml["June"] = 6;
	ml["July"] = 7;
	ml["August"] = 8;
	ml["September"] = 9;
	ml["October"] = 10;
	ml["November"] = 11;
	ml["December"] = 12;
	
	cout << ml.find("April")->second << endl;
	cout << ml.find("Yam")->second << endl;
	
	cout << ml["May"] << endl;
	cout << (ml.find("Yam") == ml.end() ? "miss" : "hit") << endl;
	
	cout << ml["Yam"] << endl;
	cout << (ml.find("Yam") == ml.end() ? "miss" : "hit") << endl;
	
	cout << dashes << endl;
	
	cout << "Creating a new map using copy constructor: " << endl;
	mymap<string, int>m2(ml);
	
	cout << "Copy's \"January\" key value: " << m2["January"] << endl;
	m2["January"] = 10000;
	cout << "Changing value to 10000 for copy. Checking to see if original\n"
		<< "map's value remains unchanged: ";
	cout << m2["January"] << " " << ml["January"] << endl << endl;
	
	m2 = ml;
	
	cout << m2["January"] << endl;
	
	mymap<string, string> test;
	
	test["Hello"] = "world";
	test["I threw"] = "darts";
	test["at a "] = "spinning globe";
	test["swapping out"] = "passport photos";
	
	mymap<string, string> copy(test); 
	
	test["Elephant"] = "shell";
	
	cout << "test's version: " << test["Elephant"] << endl;
	cout << "copy's version: " << copy["Elephant"] << endl;
	
	
	return 0;
}