//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn1/Node.h
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

#ifndef NODE_H
#define NODE_H

using namespace std;

class Node
{
    public:
        Node* next;
        char value;
        Node() : next(0) {};
        Node(char value) : next(0), value(value){};
};


#endif