//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn6/main.cc
/// @brief Assignment 06 for CS 14 Spring 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date May 27, 2014
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
#include<vector>
#include<cstdlib>
// #include<algorithm>

using namespace std;



int mixedNegatives(int x)
{
	int check = rand() % 2;
	
	if(check == 0)
	{
		return -1 * x;
	}
	
	return x;
}

void printVec(const vector<int>& v)
{
	for(unsigned i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	
	cout << endl << endl;
}

//Function that implements the heap-sort algorithm on a vector.
// It is a little convoluted since I packed everything into one function,  but 
// I wasn't sure how it was going to be testing (like if our function would be
// be copied and pasted) so I decided to put everything into one function just 
// in case. I would have rather preferred it to be separate functions though.
void heapSort(vector<int>& v)
{
	if(v.size() == 0 || v.size() == 1)
	{
		return;
	}
	
	int i = 0, j = 0, parent = 0;
	int limit = v.size() - 1;
	bool needsCorrection = false;
	
	//We go through the array, one index at a time, and putting each value into
	// its proper place in the heap.
	while(i <= limit)
	{
		parent = (i - 1) / 2;
		
		//If the newly inserted child, which is the value at the new index, is
		// greater than its parent, found from the equation above, then we must
		// percolate the child up the heap. 
		if(v.at(i) > v.at(parent))
		{
			// j will be the index of the value we are trying to percolate up
			j = i;
			needsCorrection = true;
			
			// Loop continues while the value at index is larger than its parent
			// or, in the roots case, if the value at the parent is equal to the
			// value of the child.
			while(needsCorrection)
			{
				swap(v.at(j), v.at(parent));
				
				j = parent; 
				parent = (j - 1)/2;
				
				if(v.at(j) <= v.at(parent))
				{
					needsCorrection = false;
				}
			}
		}
		
		i++;
	}
	
	// cout << "Vector as a heap: ";
	// for(unsigned i = 0; i < v.size(); i++)
	// {
	// 	cout << v.at(i) << " ";
	// }
	// cout << endl << endl;
	
	int iLeft = 0, iRight = 0;
	j = i - 1;
	
	// Once everything is sorted into the heap, we take the value at the root,
	// which is the highest priority, and set it to the back of the array by 
	// swapping. But in doing so, we have to make sure the heap maintains its
	// true structure with parents being larger than their children.
	while(j > 0)
	{
		i = 0;
		
		// Swap the first element and the jth element(which starts at the end
		// and decrements down). This sorts the vector last-index first.
		swap(v.at(i), v.at(j));
		
		iLeft = (2 * i) + 1; iRight = (2 * i) + 2;
		
		// If either the left child or right child, if there is one in the heap,
		// is greater than its parent, then we must percolate the parent down.
		if((iLeft < j && v.at(iLeft) > v.at(i)) || (iRight < j && 
			v.at(iRight > v.at(i))))
		{
			needsCorrection = true;
		}
		
		// This while loop percolates the parent down to its proper place.
		while(needsCorrection)
		{
			// If the parent is greater than it's left and right child (is a 
			// child exists within the heap), than the heap structure was
			// maintained. 
			if((iLeft >= j || v.at(i) >= v.at(iLeft)) && (iRight >= j || 
				v.at(i) >= v.at(iRight)))
				{
					needsCorrection = false;
					break;
				}
				
			// If a left and right child exist within the heap of a parent and
			// either child was larger than the parent...
			if(iLeft < j && iRight < j)
			{
				// ...if the left child is greater than the right child,
				// than we swap the parent with its left child.
				if(v.at(iLeft) > v.at(iRight))
				{
					swap(v.at(i), v.at(iLeft));
					i = iLeft;
				}
				else
				{
					//Else, we swap with its larger right child.
					swap(v.at(i), v.at(iRight));
					i = iRight;
				}
			}
			else if(iLeft < j)
			{
				//A parent can either have a right and left child or just a 
				// left child (this is the basic structure of a heap). So if
				// its only child is greater than its parent, than swap the 
				// left.
				swap(v.at(i), v.at(iLeft));
			}
			
			// Now the percolated node has new children, which are evaluated 
			// here.
			iLeft = (2 * i) + 1; iRight = (2 * i) + 2;
		}
		
		j--;
	}
}

int main()
{
	srand(time(0));
	
	string dashes(80, '-');
	
	cout << dashes << endl;
	
	vector<int> myVec(15);
	
	cout << "Initializing Vector. Vector prior to head sort: ";
	
	for(unsigned i = 0; i < myVec.size(); i++)
	{
		myVec.at(i) = rand() % 100;
		
		cout << myVec.at(i) << " ";
	}
	
	cout << endl << endl;
	
	heapSort(myVec);
	
	// cout << "Vector as a heap tree array (unsorted): ";
	
	// for(unsigned i = 0; i < myVec.size(); i++)
	// {
	// 	cout << myVec.at(i) << " ";
	// }
	// cout << endl << endl;
	
	
	cout << "Vector sorted by heap-sort: ";
	
	printVec(myVec);
	
//-----------------------------------------------------------------------------

	cout << dashes << endl;
	
	cout << "New vector with negative numbers: ";
	
	vector<int> negatives(15);
	
	for(unsigned i = 0; i < negatives.size(); i++)
	{
		negatives.at(i) = -1 * (rand() % 100);
		cout << negatives.at(i) << " ";
	}
	
	cout << endl << endl;
	
	heapSort(negatives);
	
	cout << "Negative vector sorted: ";
	
	printVec(negatives);
	
//-----------------------------------------------------------------------------

	cout << dashes << endl;
	
	cout << "New vector with mixed integers: ";
	
	vector<int> mixed(15);
	
	for(unsigned i = 0; i < mixed.size(); i++)
	{
		mixed.at(i) = mixedNegatives(rand() % 100);
		cout << mixed.at(i) << " ";
	}
	cout << endl << endl;
	
	heapSort(mixed);
	
	cout << "Mixed vector sorted: ";
	
	printVec(mixed);
	
//-----------------------------------------------------------------------------

	cout << dashes << endl;
	
	cout << "Vector already sorted : ";
	
	vector<int> alreadySorted(15);
	
	for(unsigned i = 0; i < alreadySorted.size(); i++)
	{
		alreadySorted.at(i) = i;
		
		cout << i << " ";
	}
	cout << endl << endl;
	
	heapSort(alreadySorted);
	
	cout << "Already sorted using heap sort : ";
	
	printVec(alreadySorted);
	
//-----------------------------------------------------------------------------

	cout << dashes << endl;
	
	cout << "Reverse sorted vector: ";
	
	vector<int> reverse(15);
	
	for(unsigned i = reverse.size() - 1, j = 0; j < reverse.size(); i--, j++)
	{
		reverse.at(j) = i; 
		
		cout << i << " ";
	}
	
	cout << endl << endl;
	
	heapSort(reverse);
	
	cout << "Heap sort on a reversed vector: ";
	
	printVec(reverse);
	
	
	return 0;
}
