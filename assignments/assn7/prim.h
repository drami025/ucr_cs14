//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn6/prim.h
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

#include<iostream>
#include<fstream>
#include<set>
#include<queue>

#ifndef PRIM_H
#define PRIM_H

using namespace std;

//I create a use a hashtable that utilizes chaining for collisions to group
// together edges that share a common vertex. Essentially, each index in the
// vector used in my hashtable class will represent a vertex, and each Edge
// connecting to that index will include edges that contain that vertex

template<typename Type>
class hashtable{
	public:
	
	//Internal node class used for collision in this hashtable. In this program
	// the Type will be the Edge struct
	class Node{
		public:
		Type value;
		Node* next;
		
		Node() : value(Type()), next(NULL) {}
	};
	
	// Where the hash table is implemented
	vector<Node*> table;
	
	hashtable() : table() {}
	
	// Destructor to delete dynamically allocated Nodes in each index of the 
	// vector
	~hashtable()
	{
		if(table.size() != 0)
		{
			for(unsigned i = 0; i < table.size(); i++)
			{
				Node* j = table.at(i);
				Node* temp = NULL;
				
				while(j != 0)
				{
					temp = j;
					j = j->next;
					delete temp;
				}
			}
		}
	}
	
	hashtable(int size) : table(size) {}
	
	// Simple hash function to essentially assign a vertex to an index in vector
	int hash(int x)
	{
		if(x < 0)
		{
			x *= -1;
		}
		
		return (13 * x + 7) % table.size();
	}
	
	// Overloaded operator to assign an edge to a Node, and place this new Node
	// in an index in the vector. Chaining occurs here.
	Type& operator[](int index)
	{
		int j = hash(index);

		if(table.at(j) == NULL)
		{
			table.at(j) = new Node();
			return table.at(j)->value;
		}
		
		Node* i = table.at(j);
		
		while(i->next != NULL)
		{
			i = i->next;
		}
		
		i->next = new Node();
		return i->next->value;
	}
	
	// Returns the Node at the index that the vertex is associated with.
	// Only returns the first Node is chaining occurs at this index.
	Node* at(int index)
	{
		int j = hash(index);
		return table.at(j);
	}
	
	// // Function to print index. Not used for this program but useful to have
	// // just in case
	// void printIndex(int index)
	// {
	// 	int i = hash(index);
	// 	Node* j = table.at(i);
		
	// 	while(j != NULL)
	// 	{
	// 		cout << j->value << " ";
	// 		j = j->next;
	// 	}
		
	// 	cout << endl;
	// }
};

// Struct that defines an edge, with end1 and end2 being the vertices at the
// edges endpoints, and weight being the weight of that edge
struct Edge{
	int end1, end2;
	float weight;
	Edge() {}
	Edge(int one, int two, float weight)
		: end1(one), end2(two), weight(weight)
	{}
};

// My own compare class, which is used to sort Edges based on the value of
// their vertices, for example, edge 1-3 will precede edge 3-4 and edge 1-5
class compare{
	public:
	
	bool operator()(const Edge& lhs, const Edge& rhs)
	{
		return (lhs.end1 < rhs.end1 || 
				( lhs.end1 == rhs.end1 && lhs.end2 < rhs.end2));
	}
};

// Professor Payne's compare class, which is used to sort Edges based on weight,
// and then edges if a common weight is found. I tweaked it a little so that
// smallest weight will be at the top of container, meaning it has the largest
// priority
class compareW{
	public:
		
	bool operator()( Edge e1, Edge e2) { 
		return (
			( e1.weight > e2.weight ) ||
	    	( e1.weight == e2.weight && e1.end1 > e2.end2 ) ||
	    	( e1.weight == e2.weight && e1.end1 == e2.end1 && e1.end2 > e2.end2)
	  );
	}
};

// Defines a set that prioritizes Edges based on their endpoint values
typedef set<Edge, compare> Graph;

// Function to print out vertices in a set of vertices. Used to test program,
// not to implement it.
void printVs(const set<int>& vertices)
{
	for(set<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
	{
		cout << "In vertices: " << *it << endl;
	}
	
	cout << endl;
}

// Main function for the assignment. Function returns the Minimal Spanning Tree
// of an undirected connected graph.
Graph prim(const set<Edge>& g)
{
	// Two sets of edges, one to contain the MST, and the other used to keep
	// track of visited edges.
	Graph span, visited; 
	
	// Set of vertices to keep track of all the vertices in the original graph
	set<int> vertices;
	
	// Initialization of the hashtable to contain Edges within them. The size
	// of the table must be at least the same amount of vertices in a graph.
	// I use the function in the constructor to ensure the hashtable has
	// the necessary amount of space.
	hashtable<Edge> table((3 * g.size()) / 2);
	
	// Loop iterates through the original graph, inserting all vertices in
	// vertices set, and adding the edge to both indices of the hashtable that
	// is associated with its endpoints.
	for(set<Edge>::iterator it = g.begin(); it != g.end(); it++)
	{
		vertices.insert(it->end1);
		vertices.insert(it->end2);
		table[it->end1] = *it;
		table[it->end2] = *it;
		// cout << "Edge: ";
		// cout << it->end1 << " " << it->end2 << endl;
	}
	
	// cout << endl;
	
	// hashtable<Edge> table(vertices.size());
	// for(Graph::iterator it = g.begin(); it != g.end(); it++)
	// {
	// 	table[it->end1] = *it;
	// 	table[it->end2] = *it;
	// }
	
	// printVs(vertices);
	
	// Creates a priority queue that prioritizes edges based on their weight
	priority_queue<Edge, vector<Edge>, compareW> pq;
	// The end variable will determine which vertex will be used to inspect
	// the surrounding edges. It is initialized to the first edge's first end
	// point, which will be the starting point of finding the MST
	int end = g.begin()->end1;
	
	//int j = 0;

	// This while loop traverses the original graph until all vertices have
	// been visited, thus completing our MST
	while(!vertices.empty())
	{
		// The for-loop traverses all the Nodes chained at the index, which is
		// the end variable, of the hashtable and adds all those edges to
		// the priority_queue if it hasn't already been visited.
		for(hashtable<Edge>::Node* i = table.at(end);
			i != NULL && vertices.find(end) != vertices.end(); i = i->next)
		{
			//j++;
			if(visited.find(i->value) == visited.end())
			{
				pq.push(i->value);
				visited.insert(i->value);
			}
		}
		
		//This erases the vertex from the vertices set since it has already
		// been visited. The vertex served it purpose by adding all adjacent
		// edges to the priority queue.
		vertices.erase(end);
		
		// If the priority queue is not empty, then we can proceed to 
		// potentially adding an edge to the MST
		if(!pq.empty())
		{
			// If either or both vertices of the edge with the highest priority
			// in the priority queue was not visited, we can add this edge to
			// the MST. However, if both were visited already, this means 
			// smaller edges were found that reached both points, so it is
			// unnecessary to add this edge to the MST
			if(vertices.find(pq.top().end1) != vertices.end() || 
				vertices.find(pq.top().end2) != vertices.end())
			{	
				span.insert(pq.top());
			}
			
			// Now we need to change the value of the end variable to the vertex
			// that was adjacent to it in the edge that was inserted to the
			// spanning tree. However, if this vertex was already visited, then
			// we don't need to look for adjacent edges from that vertex 
			// anymore, thus we can have it be or remain the first endpoint.
			if(vertices.find(pq.top().end2) == vertices.end() &&
				vertices.find(pq.top().end1) != vertices.end())
			{
				end = pq.top().end1;
			}
			else 
				end = pq.top().end2;
			
			// We pop off the edge with the highest priority since it was 
			// add into the MST graph
			pq.pop();
		}
		// cout << end << " ";
	}
	
	// cout << "For loop done " << j << " times." << endl;
	// cout << endl;
	
	// Return the MST graph created above.
	return span;
}

#endif
