#include<iostream>
#include<list>
#include<fstream>
#include<cstdlib>
#include "stack.h"
#include "queue.h"
#include "WordLadder.h"

using namespace std;

//Constructor for word ladder class to put all words from the dictionary file
// into the private member "dictionary" list.
WordLadder::WordLadder(const string listFile)
{
	ifstream inFile;
	inFile.open(listFile.c_str());
	
	if(!inFile.is_open())
	{
			cerr << "Problem opening file. Program will";
			cerr << " now terminate." << endl;
			exit(1);
	}
	
	string word;
	
	//This sets up the dictionary list.
	while(inFile >> word)
	{
			dictionary.push_back(word);
	}
	
	inFile.close();
}

//The main algorithm to find the shortest word ladder occurs in this member
//function. Takes the first and last word and makes a word ladder out of them.
void WordLadder::outputLadder(const string start, const string end)
{
		stack<string> ladder;
		ladder.push(start);
		queue<stack<string> > ladderList;
		ladderList.push(ladder);

		// Iterator to traverse dictionary list. Interesting format.
		list<string>::iterator i;
		
		//While the queue of stacks is not empty, keep finding a word ladder.
		while(!ladderList.empty())
		{
		// This traverses the entire dictionary list.
			for(i = dictionary.begin(); i != dictionary.end(); i++)
			{
				//Comparing word by word, if a word is one letter different
				// and is not the top word on the stack, then...
				if(ladderList.front().top() != *i &&
					isNextString(ladderList.front().top(), *i))
				{
					if(*i == end)
					{
						// If a word equals the final word and is one letter 
						// different, then that means we reached the end
						// of the program. Print the word ladder stack.
						ladderList.front().push(*i);
						printLadder(ladderList.front());
						cout << endl;
						return;
					}
					
					// ...we create a copy of the stack in the front of the 
					// queue of stacks, push the new found word in the copy,
					// and push that stack into the queue.
					stack<string> copy = ladderList.front();
					copy.push(*i);
					ladderList.push(copy);
					i = dictionary.erase(i);
					i--;
				}
			}
			
			//Everytime we find a word that is just one letter different, we
			// create a new stack of words and add it to the queue. At the end
			// of the dictionary, we pop the first stack from the queue since 
			// a copy of it with the next word is pushing onto the stack.
			ladderList.pop();
			
			//If there are no more stacks in the queue, then there is no
			// possible word ladder between the two words.
		}
		
		cout << "No wordladder between " << start << " and " << end <<".\n";
}

//Member function determines whether the word on the stack and the comparison
// word is just one letter different.
bool WordLadder::isNextString(const string& stackWord
								, const string& word) const
{
		int diff = 0;
		
		//This is a formality, since all words in the program are sized 5.
		if(stackWord.size() != word.size())
		{
			return false;
		}
		
		//Runs through both strings and counts the difference in letters.
		for(unsigned i = 0; i < stackWord.size(); i++)
		{
			if(stackWord.at(i) != word.at(i))
			{
				diff++;
				if(diff >= 2)
				{
					//If the difference in letters is 2 or more, not next word.
					return false; 
				}
			}
		}
		
		//Finally, if diff was only 1, then it can be the next word in ladder.
		return (diff == 1) ? true : false;
}

//Member function prints the words in the stack.
void WordLadder::printLadder(stack<string> ladder) const
{
	stack<string> copy;
	
	//Again, another formality, but if the size is 0 then return.
	if(ladder.size() == 0)
		return;
	
	//Created a variable to avoid having to keep calling size function.
	int origSize = ladder.size();
	
	//This part copies the strings in the stack into a copy to reverse order.
	while(origSize >= 1)
	{
		copy.push(ladder.top());
		ladder.pop();
		origSize--;
	}
	
	//Prints the top of stack then pops, does this first so we don't have an
	// extra space in the end.
	cout << copy.top();
	copy.pop();
	
	origSize = copy.size();
	
	//This loop prints out items in the stack.
	while(origSize > 0)
	{
		cout << "\n" << copy.top();
		copy.pop();
		origSize--;
	}
}
