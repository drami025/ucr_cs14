//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn5/hashmap.h
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
#include<vector>
#include<cstdlib>

#ifndef HASHMAP_H
#define HASHMAP_H

// Macros created since I used these a lot.
#define hashIn hashTable.at(index)
#define hI hashTable.at(i)

using namespace std;

//Created new variable type to determine the status of a Node
enum status{Free, active, deactivated};

//Default hash table size
const int TABLE_SIZE = 103;

template<typename Type>
class hashmap{
private:

	//Decided to created Node class within hashmap class to keep Node and all
	// its data members from being changed outside of hashmap class.
	class Node{
		string key;	//key is kept private here to prevent it from being changed
					// at all outside of Node class or even at all.
		
	public:

		mutable Type data;
		status nodeStat;
		//Default constructor, makes a Node that is "free" to have key and data
		// inserted in.
		Node() : key(""), data(Type()), nodeStat(Free) {}
		
		//Constructor for Node with a specified key and data
		Node(string k, Type d, status stat) 
			: key(k), data(d), nodeStat(stat) {}
		
		//Allows hashmap class to access the key when needed for comparisons
		string theKey() const
		{
			return key;
		}
	};
	
	// Hash table implemented as a vector. Originally I had it as a vector of
	// Node pointers, which allowed me to have a const key while easily 
	// deleting and pointing Node* to a new dynamically allocated Node in the 
	// heap if the replaced Node had Free or deactivated status. However, this
	// meant when using find, it had to be dereferenced first before accessing
	// Node's data members with the -> operator. Although it worked perfectly I
	// decided to make the hashmap class as generic as possible. 
	vector<Node> hashTable;
public:
	
	// constructor to make hashTable size 103 and filled with defaulted Nodes.
	hashmap() : hashTable(TABLE_SIZE, Node())
	{}
	
	// constructor to make a hash table of the passed in size.
	hashmap(unsigned int size) : hashTable(size)
	{}
	
	// Copy constructor for the hashmap class. Merely copies each vector
	hashmap(const hashmap& copy)
		: hashTable(copy.hashTable){}
	
	// Destructor for hashmap class. Since there was no allocated memory it
	// is empty.
	~hashmap()
	{}
	
	// Hash function to use as an index for the hashTable vector. Decided
	// to use my own variation instead of Professor Payne's. I found it easier.
	unsigned int hash(const string& s)
	{
		unsigned int h = 0;
		for(unsigned i = 0; i < s.size(); i++)
		{
			h = 37*h + s[1];
		}
		
		return h % hashTable.size();
	}
	
	//Overloaded operator function that is used to both insert a key and data
	// pair and to access data from a key.
	Type& operator[](const string& i)
	{
		unsigned int index = hash(i);
		
		//Checks to see if the Node at index is either free or deactivated,
		// in which case a new Node can be inserted with an active status and
		// passed in key.
		if(hashIn.nodeStat == Free || hashIn.nodeStat == deactivated)
		{
			hashIn = Node(i, Type(), active);
			return hashIn.data;
		}
		// If the hashed-passed in key is equal to the index's key, then just return
		// the data.
		else if(hashIn.theKey() == i)
		{
			return hashIn.data;
		}
		// If the hashed-passed in key is not equal to the initial index's key,
		// we have to look for the next available Node that is free. 
		else if(hashIn.theKey() != i)
		{
			// If we get back to the original index, then that means the hash
			// table is full.
			unsigned original = index;
			while(hashIn.nodeStat == active)
			{
				// If we get to an index where the key of that Node is equal
				// to the passed in key, then we return that Node's data member
				if(hashIn.theKey() == i)
				{
					return hashIn.data;
				}
				
				// Rehashing formula
				index = (index + 7) % hashTable.size();
				
				// HashTable is full.
				if(index == original)
				{
					cout << "\nHash table is full. You should remove, but we ";
					cout << "did not provide a remove function since it wasn't";
					cout << " assigned.\nSo I will exit now...\nSorry." << endl;
					exit(1);
					hashIn.data = Type();
					return hashIn.data;
				}
			}
		}
		
		// If HashTable wasn't full, and a vacant Node was found, we insert
		// new Node into that index.
		hashIn = Node(i, Type(), active);
		return hashIn.data;
	}
	
	// Member function returns an iterator pointing to the Node with the 
	// passed in key. Else, it returns an iterator pointing to end().
	typename vector<Node>::iterator find(const string& key)
	{
		typename vector<Node>::iterator it = begin();
		
		for(; it != end(); it++)
		{
			if((it)->theKey() == key)
			{
				return it;
			}
		}

		return it;
	}
	
	// Returns vector's end() for simplicity.
	typename vector<Node>::iterator end()
	{
		return hashTable.end();
	}
	
	// Returns vector's begin() for simplicity.
	typename vector<Node>::iterator begin()
	{
		return hashTable.begin();
	}
	
	// Prints out the Node's data members and its index in the vector for 
	// testing.
	void printNode(unsigned i) const
	{
		cout << "Index: " << i + 1 << endl;
		cout << "Key: " << hashTable.at(i).theKey() << endl;
		cout << "Data: " << hashTable.at(i).data << endl;
		cout << "Status: ";
		
		(hI.nodeStat == Free) ? cout << "Free" : (hI.nodeStat == active) ? 
			cout << "Active" : cout << "Deactivated";
		
		cout << endl;
	}
};

#endif
