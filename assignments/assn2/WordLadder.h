#ifndef WORDLADDER_H
#define WORDLADDER_H

#include<iostream>
#include<list>
#include "stack.h"
#include "queue.h"

using namespace std;

//Class definition for WordLadder class.
class WordLadder{
	public:
		WordLadder(const string listFile);
		void outputLadder(const string start, const string end);
		
	private:
		bool isNextString(const string& stackWord, const string& word) const;
		void printLadder(stack<string> ladder) const;
		list<string> dictionary;
};
#endif
