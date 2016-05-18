//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn4/mymap.h
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
#include<set>

using namespace std;

#ifndef MYMAP_H
#define MYMAP_H

/*
	This first section is the program written using inheritance as opposed to
	composition.
*/

// template<typename Key, typename Value>
// class map_pair{

// public:
// 	const Key first;
// 	mutable Value second;
	
// 	map_pair(Key s, Value v) : first(s), second(v) {}
// };

// template<typename Key, typename Value>
// struct classcomp{
// 	typedef map_pair<const Key, Value> Pair;
// 	bool operator() (const Pair& lhs, const Pair& rhs) const
// 	{
// 		return lhs.first < rhs.first;
// 	}
// };

// ////////////////////////

// template<typename Key, typename Value>
// class map : public set<map_pair<const Key, Value>,classcomp<const Key, Value> >{

// public:

// 	typedef map_pair<const Key, Value> Pair;
// 	typedef set<Pair, classcomp<const Key, Value> > PairSet;
	
// 	Value& operator[](const Key x)
// 	{
// 		pair<typename PairSet::iterator, bool> i = insert(Pair(x, Value()));
		
// 		return i.first->second;
// 	}
	
// 	typename map::iterator find(const Key& x) const
// 	{
// 		return PairSet::find(Pair(x, Value()));
// 	}
	
// 	map()
// 	{
// 		typename set<PairSet >::set();
// 	}
	
// 	~map(){}
	
// 	map(map<const Key, Value>& rhs)
// 	{*this = rhs;}
	
// 	map& operator=(map<const Key, Value> rhs)
// 	{
// 		if(this != &rhs)
// 		{
// 			PairSet::operator=(rhs);
// 		}
		
// 		return *this;
// 	}
	
// 	typename map::iterator end()
// 	{
// 		return PairSet::end();
// 	}
	
// };


//This class creates a pair, the first data member being the key and the second
// being the value that the key maps to.
template<typename Key, typename Value>
class map_pair{

public:
	const Key first;
	mutable Value second;
	map_pair(Key s, Value v) : first(s), second(v) {}
};

//This struct creates an object who's sole purpose is to contain a member 
// function to determine which map_pair precedes the other. This boolean 
// function is necessary for the second parameter of the set container class
// since sets use RB trees in order to keep objects sorted, so it needs a way to
// determine whether an object of a certain class precedes another.
template<typename Key, typename Value>
struct classcomp{
	typedef map_pair<const Key, Value> Pair;
	bool operator()(const Pair& lhs, const Pair& rhs) const
	{
		return lhs.first < rhs.first;
	}
};

//Finally the mymap class, which keeps map_pairs in sets in order to have keys
// map to values.
template<typename Key, typename Value>
class mymap{

public:
	typedef map_pair<const Key, Value> Pair;
	typedef set<Pair, classcomp<const Key, Value> > PairSet;
	typedef pair<typename PairSet::iterator, bool> stlPair;
	
	// The set in which the map is based on.
	PairSet theSet;
	
	// Insert function, which returns a pair iterator with two parameters: the
	// first being a pointer to a map_pair object, the second as a bool to 
	// determine whether an item was inserted or whether it was not (not iff 
	// the value already existed in the set).
	pair<typename PairSet::iterator, bool> insert (Pair p)
	{
		return theSet.insert(p);
	}
	
	// Overloaded operator that returns the value that matches the key passed
	// in. However, if the key is not found within set, then a new key is passed
	// into the tree with a value that is the Value's default value.
	Value& operator[](const Key x)
	{
		stlPair i = theSet.insert(Pair(x, Value()));
		return i.first->second;
	}
	
	// Member function that uses set's find function to determine whether a 
	// key is found within the tree. It then returns an iterator pointing to 
	// that node, if found.
	typename PairSet::iterator find(const Key& x) const
	{
		return theSet.find(Pair(x, Value()));
	}
	
	// Default constructor, which calls the default constructor on the set
	// data member.
	mymap()
		: theSet()
	{}
	
	// Destructor, which in this case needs to be only empty since we are not
	// dynamically allocating memory in this class.
	~mymap() {}
	
	// Copy constructor, which merely assigns rhs's set to *this's set.
	mymap(const mymap<const Key, Value>& rhs)
	{
		theSet = rhs.theSet;
	}
	
	// Assignment operator, which like the copy constructor, assignes rhs's set
	// to *this's set.
	mymap& operator=(const mymap<const Key, Value>& rhs)
	{
		if(this != &rhs)
		{
			theSet = rhs.theSet;
		}
		
		return *this;
	}
	
	// end member function to point to the "one past last" in the set class. 
	// Uses set's end function to implement this.
	typename PairSet::iterator end()
	{
		return theSet.end();
	}
};
#endif