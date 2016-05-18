//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn6/main.cc
/// @brief Assignment 07 for CS 14 Spring 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date June 6, 2014
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
#include "prim.h"

using namespace std;

int main()
{
	Edge e;
	Graph g, mst;
	
	ifstream inFile;
	char input[] = "final";
	
	inFile.open(input);
	
	for(int i = 0; i < 8; i++)
	{
		cout << "Input edge " << i + 1 << ", end1: ";
		inFile >> e.end1;
		cout << e.end1 << endl;
		
		cout << "Input edge " << i + 1 << ", end2: ";
		inFile >> e.end2;
		cout << e.end2 << endl;
		
		cout << "Weight: ";
		inFile >> e.weight;
		cout << e.weight << endl;
		
		g.insert(e);
		cout << endl;
	}
	
	mst = prim(g);
	
	//mst = prim(mst);
	cout << "Spanning tree includes these edges: " << endl;
	
	for(Graph::iterator it = mst.begin(); it != mst.end(); it++)
	{
		cout << "Edge: " << it->end1 << "-" << it->end2 << endl;
	}
	
	cout << endl;
	
	inFile.close();
	return 0;
}
