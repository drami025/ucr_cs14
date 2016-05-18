#include<iostream>
#include "WordLadder.h"
#include "stack.h"
#include "queue.h"

using namespace std;

//Main function takes in command-line arguments
int main(int argc, char* argv[])
{
	if(argc != 4)
	{
		cerr << endl << "Usage: main.out dictionary.txt start_word end_word";
		cerr << endl << endl;
		
		return 1;
	}
	
	//cout << "Opening " << argv[1] << endl;
	
	WordLadder mainLadder(argv[1]);
	
	//cout << "\nYour starting word \"" << argv[2] << "\" and ending word \"";
	//cout << argv[3] << "\" has the following word latter: " << endl << endl;
	
	cout << endl;
	
	mainLadder.outputLadder(argv[2], argv[3]);
	cout << endl;
	
	return 0;
}