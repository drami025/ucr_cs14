//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn1/MyList.cc
/// @brief Assignment 01 for CS 14 Spring 2014
///
/// @author Daniel Ramirez [drami025@ucr.edu]
/// @date April 15, 2014
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

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "MyList.h"
#include "Node.h"

using namespace std;

// Constructor for a MyList object that is not initialized to anything. Sets the
// head to 0, since there are no objects in the linked list.
MyList::MyList()
    : head(0)
{}

// Constructor for a MyList object that is initialized to another MyList object,
// which is passed in as a parameter. 
MyList::MyList(const MyList& str)
{
    // If the passed in MyList object doesn't have any Nodes in its list, we
    // can simply point the new object's head to 0.
    if(str.head == 0)
    {
        head = 0;
    }
    else
    {
    	
        Node *temp = 0;
        head = new Node(str.head->value);
        Node *j = str.head->next;
        
        // This ensures we do a deep copy of the passed in MyList parameter so
        // that each object will point to different Nodes in the heap.
        for(Node *i = head; j != 0; j = j->next, i = i->next)
        {
            temp = new Node(j->value);
            i->next = temp;
        }
    }
}

// Constructor for a MyList object, which creates a linked list of all the 
// characters in the passed in string. 
MyList::MyList(const char* str)
{
    // This conditional branch checks to see if an empty string was put in.
    // Unlikely, but just to make sure...
    if(strlen(str) != 0)
    {
        Node *temp = 0;
        head = new Node(str[0]);
        Node *j = head;
        
        // Creates new Nodes containing each letter of the passed string.
        for(unsigned i = 1; i < strlen(str); i++, j = j->next)
        {
            temp = new Node(str[i]);
            j->next = temp;
        }
    }
    else
    {
        head = 0;
    }
}

// Destructor for the MyList class. Deallocates dynamically allocated memory by
// utilizing the pop_front() member function.
MyList::~MyList()
{
    while(head != 0)
    {
        pop_front();
    }
}

// Pushes a new Node (esssentially a new character in the string) to the front
// of the linked list. 
void MyList::push_front(char value)
{
    if(head != 0)
    {
        Node *temp = head;
        head = new Node(value);
        head->next = temp;
    }
    else
    {
        head = new Node(value);
    }
}

// Member function pushes a new Node (again, essentially a character) to the 
// back of the linked list.
void MyList::push_back(char value)
{
    if(head != 0)
    {
        // Unfortunately, without a "tail" data member, the need to tranverse
        // the entire linked list is necessary at this point. 
        for(Node *i = head; i != 0; i = i->next)
        {
            // Stops at the last Node in the linked list and points it to a new
            // Node.
            if(i->next == 0)
            {
                Node *temp = new Node(value);
                i->next = temp;
                break;
            }
        }
    }
    else
    {
        // If the linked list is empty, then we can easily utilized the 
        // push_front method.
        push_front(value);
    }
}

// This method pops off the first Node in the linked list (or deletes the first
// character in the string).
void MyList::pop_front()
{
    // If there are no Nodes in the linked list, then we can just return.
	if(head == 0)
	{
		return;
	}
	else
	{
		Node *temp = head->next;
		delete head;
		head = temp;
	}
}

// This method pops off the last Node in the linked list (or the deletes the 
// last character in the string).
void MyList::pop_back()
{
	if(head == 0)
	{
		return;
	}
	else if(head->next == 0)
	{
	    // If there is only one Node, then we can just utilized the pop_front
	    // method again.
		pop_front();
	}
	else
	{
	    // Once again, the absence of a "tail" data member means we need two
	    // temporary Node objects to keep track of indexed Nodes as we traverse
	    // through the loop.
		for(Node *i = head->next, *prev = head; i != 0;
		    i = i->next, prev = prev->next)
		{
			if(i->next == 0)
			{
				delete i;
				prev->next = 0;
				break;
			}
		}
	}
}

// This method swaps the characters contained in two Node objects at desired
// indices.
void MyList::swap(int i, int j)
{
    // This condition checks to see if both inputted indices are within range.
	if(i >= size() || j >= size() || i < 0 || j < 0)
	{
		cout << "\nError: Inputted value(s) is out of range." << endl;
		exit(1);
	}
	else if(i == j)
	{
	    // Of course, if the indices are the same, we should do no work.
	    return;
	}
	else
	{
		Node *temp1 = head, *temp2 = head;
		char tmpChar;
		
		// Using a for-loop, we assign temp1 to the i-th Node.
		for(int a = 0; a < i; a++)
		{
			temp1 = temp1->next;
		}
		
		// Using a for-loop, we assign temp2 to the j-th Node.
		for(int a = 0; a < j; a++)
		{
			temp2 = temp2->next;
		}
		
		// This swaps the two characters of the desired Nodes.
		tmpChar = temp1->value;
		temp1->value = temp2->value;
		temp2->value = tmpChar;
	}
}

// This method inserts a character at the desired index. However, if one needs
// to insert a character at the end of a string, they may used the push_back
// method.
void MyList::insert_at_pos(int i, char value)
{
    int sz = size();
    
	if(i > sz || i < 0)
	{
		cout << "\nError: Out of range position inputted." << endl;
		exit(1);
	}
	else if(i == 0)
	{
		push_front(value);
	}
	else if(i == sz)
	{
	    push_back(value);
	}
	else
	{
		Node *curr = head->next, *prev = head;
		
		// In order to insert a new Node in the list, we have to keep track of
		// the nodes before the index and the old Node at the index.
		for(int j = 0; j < i - 1; curr = curr->next, prev = prev->next, j++)
		{}
		
		Node *temp = new Node(value);
		temp->next = curr;
		prev->next = temp;
	}
}

// This method reverses all characters in the linked list. We can easily use the
// swap method to perform this task.
void MyList::reverse()
{
    // If the string is empty, then just return and do no work.
    if(head == 0)
    {
        return;
    }
    
    // We need to create another list. This method gives us a faster runtime
    // by avoiding using the swap function, which has a couple of loops.
    MyList temp(*this);
    int sz = size();
    
    // delete all elements in implicit List since we have it copied in temp.
    while(head != 0)
    {
        pop_front();
    }
    
    Node* i = temp.head;
    
    // Now we just push_front the value of the temp list as we traverse it,
    // thereby reversing the implicit list.
    for(int j = 0; j < sz; j++, i = i->next)
    {
        push_front(i->value);
    }
}

// This member function returns the size of the linked list.
int MyList::size() const
{
	Node *j = head;
	if(j == 0)
	{
		return 0;
	}
	else
	{
		int i;
		for(i = 0; j != 0; i++, j = j->next)
		{}
		
		return i;
	}
}

// This member function prints out all characters in the linked list.
void MyList::print() const
{
    if(head != 0)
    {
        for(Node *i = head; i != 0; i = i->next)
        {
            cout << i->value;
        }
    }
}

// This member function returns the position of the first occurrence of the 
// passed character. Returns -1 if not found.
int MyList::find(char value) const
{
	if(head == 0)
	{
	    // If the list is empty, then obviously return -1.
		return -1;
	}
	else
	{
	    Node *i = head;
	    
		for(int j = 0; i != 0; i = i->next, j++)
		{
		    if(i->value == value)
		    {
		        return j;
		    }
		}
		
		return -1;
	}
}

// This member function returns the position of the first occurrence of the
// pass MyList object within the implicit MyList object. Returns -1 if it is 
// not found. 
int MyList::find(MyList& query_str) const
{
    if(head == 0 || query_str.size() > size() || query_str.head == 0)
    {
        // If the passed in object is bigger than the implicit object, then
        // we know it can't be found.
        return -1;
    }
    
    // "pos" variable keeps track of the position the query string could 
    // possibly be at, while the "curr" variable keeps track of current index
    // as we traverse the for-loop below. "j" Node variable will traverse the
    // query string.
    int pos = 0, curr = 0;
    Node *j = query_str.head;
    
    // Using one for-loop, I traverse the nodes in the List and look for the
    // first instance of the first letter of the query string.
    for(Node* i = head; i != 0 && j != 0; i = i->next)
    {
        if(i->value != j->value)
        {
            // Reset j to point to head of query string if no match and set
            // pos to next index where a match could possibly be.
            pos = curr + 1;
            j = query_str.head;
            
            // There is a chance that the current index could be the start of a 
            // match, so check for the possibility here.
            if(i->value == j->value)
            {
                j = j->next;
                pos--;
            }
        }
        else
        {
            // We point j to the next value in the query string if the 
            // subsequent value was a match.
            j = j->next;
        }
        
        curr++;
    }
    
    // Found if we traversed entire query string and j points to 0
    return (j == 0) ? pos : -1;
}

// Operator overload for the assignment operator (=).
MyList& MyList::operator=(const MyList& str)
{
    // This checks for self-assignment.
    if(str.head == head)
    {
        return *this;
    }

    // This erases all the Nodes on the LHS so there are no memory leaks.
    while(head != 0)
    {
        pop_front();
    }
    
    // This checks to see if str is an empty string
    if(str.head == 0)
    {
        return *this;
    }
    // This part copies all values in the RHS to the LHS. Makes a deep copy.
    head = new Node(str.head->value);
    Node *j = str.head->next;
    
    for(Node *i = head; j != 0; j = j->next, i = i->next)
    {
        i->next = new Node(j->value);
    }
        
    return *this;
}

// Operator overloader for the subscript operator
char& MyList::operator[](const int i)
{
    // This part checks to see if the index parameter is within range of the
    // list.
    if(i >= size() || i < 0)
    {
        cout << "\nError: Out of range position inputted." << endl;
        exit(1);
    }
    
    // To return the element at the passed index, we can easily use a for-loop
    // and traverse the list till we get to the desired Node, then we return
    // that value.
    Node *j = head;
    for(int x = 0; x < i; x++, j = j->next)
    {}
    
    return j->value;
}

// Operator overloader for the addition operator
MyList& MyList::operator+(const MyList& str)
{
    // Since we need to a reference to a list, we need to create a new list
    // and return it. However, since lists are destroyed by its destructor when
    // we go out of its scope, we need to create a new list in the head and
    // return the address of that list. This function does that.
    Node *i = str.head;
    MyList *L3 = new MyList(*this);
    for(int x = 0; i != 0; i = i->next, x++)
    {
        L3->push_back(i->value);
    }
    
    // Now, we return the list in the heap.
    return *L3;
}