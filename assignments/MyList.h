//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn1/MyList.h
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

#ifndef MYLIST_H
#define MYLIST_H

#include "Node.h"

using namespace std;

class MyList{
    private:
        Node* head;
        
    public:
        MyList();
        MyList(const MyList& str);
        MyList(const char* str);
        ~MyList();
        void push_front(char value);
        void push_back(char value);
        void pop_front();
        void pop_back();
        void swap(int i, int j);
        void insert_at_pos(int i, char value);
        void reverse();
        int size() const;
        void print() const;
        int find(char value) const;
        int find(MyList& query_str) const;
        MyList& operator=(const MyList& str);
        char &operator[](const int i);
        MyList& operator+(const MyList& str);
};

#endif