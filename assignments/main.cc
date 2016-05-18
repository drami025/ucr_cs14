//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn1/main.cc
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

#include<iostream>
#include "MyList.h"

using namespace std;

int main()
{
    string dashes = "", miniDash = "";
    
    for(unsigned i = 0; i < 80; i++)
    {
        dashes += "-";
    }
    
    for(unsigned i = 0; i < 40; i++)
    {
        miniDash += "-";
    }
    //=========================================================================
    // Declarations and Intialization
    //=========================================================================

    cout << dashes << endl;
    
    cout << "Testing declarations and initialization" << endl;
    cout << dashes << endl << endl;
    
    MyList empty1;
    cout << "Expecting an empty list (empty string): ";
    empty1.print();
    cout << endl;
    
    MyList super("Superman");
    cout << "Expecting \"Superman\" (String parameter constructor): ";
    super.print();
    cout << endl;
    
    cout << "Expecting \"Superman\" (MyList parameter constructor): ";
    MyList superDouble(super);
    superDouble.print();
    cout << endl << endl;
    
    //=========================================================================
    // Mutators
    //=========================================================================
    
    cout << dashes << endl;
    
    cout << "Testing Mutators" << endl;
    cout << dashes << endl << endl;
    
    //--------------------------------------------------------------------------
    // push_front() Method
    //--------------------------------------------------------------------------
    
    cout << miniDash << endl << "push_front()" << endl << miniDash << endl;
    
    cout << "Using \"Superman\" string, push_front an \'x\': ";
    super.push_front('x');
    super.print();
    cout << endl;
    
    cout << "Push_front an \'x\' for the empty list: ";
    empty1.push_front('x');
    empty1.print();
    cout << endl << endl;
    
    //--------------------------------------------------------------------------
    // pop_front() Method
    //--------------------------------------------------------------------------
    cout << miniDash << endl << "pop_front()" << endl << miniDash << endl;
    
    cout << "Pop_front the \'x\' in \"Superman\": ";
    super.pop_front();
    super.print();
    cout << endl;
    
    cout << "Pop_front the string with one character (should now be empty): ";
    empty1.pop_front();
    empty1.print();
    cout << endl;
    
    cout << "Pop_front the empty string: ";
    empty1.pop_front();
    empty1.print();
    cout << endl << endl;
    
    //--------------------------------------------------------------------------
    // push_back() Method
    //--------------------------------------------------------------------------
    cout << miniDash << endl << "push_back()" << endl << miniDash << endl;
    
    cout << "Push_back an \'s\' in Superman: ";
    super.push_back('s');
    super.print();
    cout << endl;
    
    cout << "Push_back an \'x\' to the empty string: ";
    empty1.push_back('x');
    empty1.print();
    cout << endl;
    
    cout << "Push_back again to former emptry string: ";
    empty1.push_back('x');
    empty1.print();
    cout << endl << endl;
    
    //--------------------------------------------------------------------------
    // pop_back() Method
    //--------------------------------------------------------------------------
    cout << miniDash << endl << "pop_back()" << endl << miniDash << endl;
    
    cout << "Pop_back \'s\' in \"Superman\": ";
    super.pop_back();
    super.print();
    cout << endl;
    
    cout << "Pop_back \'x\' in former empty string: ";
    empty1.pop_back();
    empty1.print();
    cout << endl;
    
    cout << "Pop_back again to return to empty string: ";
    empty1.pop_back();
    empty1.pop_back();
    cout << endl;
    
    cout << "Pop_back an empty string: ";
    empty1.pop_back();
    empty1.pop_back();
    cout << endl << endl;
    
    //-------------------------------------------------------------------------
    // swap() Method
    //-------------------------------------------------------------------------
    cout << miniDash << endl << "swap()" << endl << miniDash << endl;
    
    cout << "Swap \'u\' and \'a' in \"Superman\" (Note: will swap back "
        << "after\n every test): ";
    super.swap(1, 6);
    super.print();
    cout << endl;
    super.swap(1, 6);
    
    cout << "Swap first and second letters of \"Superman\": ";
    super.swap(0, 1);
    super.print();
    cout << endl;
    super.swap(0, 1);
    
    cout << "Swap last two letters of \"Superman\": ";
    super.swap(6, 7);
    super.print();
    cout << endl;
    super.swap(6, 7);
    
    cout << "Swap first and last letters: ";
    super.swap(0, 7);
    super.print();
    cout << endl;
    super.swap(0, 7);
    
    cout << "Swap the same letter index: ";
    super.swap(1, 1);
    super.print();
    cout << endl << endl;
    
    
    //--------------------Error Section: swap()---------------------------------
    //-------------Will be commented off to check the rest----------------------
    
    // cout << "Swap contents of an empty string: ";
    // empty1.swap(0, 0);
    // empty1.print();
    // cout << endl << endl;
    
    // cout << "Swap out of range: ";
    // super.swap(-1, 3);
    // super.swap(0, 10);
    // cout << endl << endl;
    
    //--------------------------------------------------------------------------
    // insert_at_pos() Method
    //--------------------------------------------------------------------------
    cout << miniDash << endl << "insert_at_pos()" << endl << miniDash << endl;
    
    MyList batman("Batman");
    
    cout << "New list created: \"Batman\"" << endl << endl;
    
    cout << "Insert \'s\' after \'t\': ";
    batman.insert_at_pos(3, 's');
    batman.print();
    cout << endl;
    
    cout << "Insert \'f\' in the beginning: ";
    batman.insert_at_pos(0, 'f');
    batman.print();
    cout << endl;
    
    cout << "Insert \'d\' at the end: ";
    batman.insert_at_pos(8, 'd');
    batman.print();
    cout << endl;
    
    
    cout << "Insert to beginning of empty string: ";
    empty1.insert_at_pos(0, 'x');
    empty1.print();
    empty1.pop_front();
    cout << endl << endl;
    
    //--------------------Error Section: insert_at_pos()------------------------
    //-------------Will be commented off to check the rest----------------------
    
    // cout << "Insert out of range: ";
    // batman.insert_at_pos(13, 'x');
    // batman.print();
    // cout << endl << endl;
    
    //--------------------------------------------------------------------------
    // reverse() Method
    //--------------------------------------------------------------------------
    cout << miniDash << endl << "reverse()" << endl << miniDash << endl;
    
    cout << "Reversing \"fBatsmand\" string: ";
    batman.reverse();
    batman.print();
    cout << endl;
    
    cout << "Reversing back: ";
    batman.reverse();
    batman.print();
    cout << endl;
    
    cout << "Reversing empty string: ";
    empty1.reverse();
    empty1.print();
    cout << endl << endl;
    
    //==========================================================================
    // Accessors
    //==========================================================================
    cout << dashes << endl;
    cout << "Testing Accessors" << endl;
    cout << dashes << endl << endl;
    
    //--------------------------------------------------------------------------
    // size() Accessor
    //--------------------------------------------------------------------------
    
    cout << miniDash << endl << "size()" << endl << miniDash << endl;
    
    cout << "Size of \"Superman\" should be 8: " << super.size() << endl;
    
    cout << "Size of empty string should be 0: " << empty1.size() << endl
        << endl;
    
    //--------------------------------------------------------------------------
    // find([char]) Accessor (print() Accessor used throughout program.
    //--------------------------------------------------------------------------
    
    cout << miniDash << endl << "find([char])" << endl << miniDash << endl;
    
    cout << "Find \'m\' in \"Superman\" (should be pos 5): " << super.find('m')
        << endl;
    cout << "Find \'x\' in \"Superman\" (should be not found; -1): "
        << super.find('x') << endl;
    cout << "Find anything in empty string (shoulbe be -1): "
        << empty1.find('a') << endl;
        
    //--------------------------------------------------------------------------
    // find([query_str]) Accessor
    //--------------------------------------------------------------------------
    
    cout << miniDash << endl << "find([query_str)]" << endl << miniDash << endl;
    
    MyList hell("hell"), shells("shells");
    MyList sail("sail"), sailing("sailing");
    MyList ball("ball"), football("football"), Hannibal("Hannibal");
    MyList abe("abe"), graba("graba dab abe");
    MyList grapevine("grapevine"), grape ("grape");
    MyList stuff("stuff");
    MyList toy("toy"), icetea("icetea");
    MyList ladee("ladee"), lalala("lalalaladeelalala");
    MyList tata("tata"), data("datadatat");
    
    cout << "Find \"hell\" in \"shells\" (should be 1): " << shells.find(hell)
        << endl;
    cout << "Find \"sail\" in \"sailing\" (should be 0): " << sailing.find(sail)
        << endl;
    cout << "Find \"ball\" in \"football\" (should be 4): " 
        << football.find(ball) << endl;
    cout << "Find \"ball\" in \"Hannibal\" (should be -1): " 
        << Hannibal.find(ball) << endl;
    cout << "Find \"abe\" in \"graba dab abe\" (should be 10): "
        << graba.find(abe) << endl;
    cout << "Find \"grapevine\" in \"grape\" (should be -1): "
        << grape.find(grapevine) << endl;
    cout << "Find \"stuff\" in \"stuff\" (should be 0): " << stuff.find(stuff)
        << endl;
    cout << "Find \"toy\" in \"icetea\" (should be -1): " << icetea.find(toy)
        << endl;
        
    cout << "Find \"ladee\" in lala string (should be 6): "
        << lalala.find(ladee) << endl;
        
    cout << "Find \"tata\" in data-string (should be -1): " << data.find(tata)
        << endl << endl;
        
    //==========================================================================
    // Operator Overloaders
    //==========================================================================
    
    cout << dashes << endl << "Testing Operator Overloaders" << endl << dashes
        << endl << endl;
        
    //--------------------------------------------------------------------------
    // Assignment operator=
    //--------------------------------------------------------------------------
    
    cout << miniDash << endl << "operator=" << endl << miniDash << endl;
    
    cout << "Make \"sail\" = \"hell\" (output should be \"hell\"): ";
    sail = hell;
    sail.print();
    cout << endl;
    
    cout << "Chain \"hell\" = \"ball\" = \"grape\" (all should be \"grape\"): ";
    hell = ball = grape;
    hell.print(); cout << endl;
    ball.print(); cout << endl;
    grape.print(); cout << endl;
    
    cout << "Set to empty string (should be empty): ";
    graba = empty1;
    graba.print();
    cout << endl;
    
    cout << "Check for self-assign \"icetea\" = \"icetea\": ";
    icetea.print();
    cout << endl << endl;
    
    //--------------------------------------------------------------------------
    // Subscript operator[]
    //--------------------------------------------------------------------------
    
    cout << miniDash << endl << "operator[]" << endl << miniDash << endl;
    
    cout << "super[3] should be \'e\': " << super[3] << endl;
    
    cout << "super[0] should be \'S\': " << super[0] << endl;
    
    cout << "super[7] should be \'n\': " << super[7] << endl;
    
    //-------------------------Error Section: operator[]------------------------
    //---------------Will be commented out to check the rest--------------------
    
    //cout << "super[-1] should give an error: " << super[-1] << endl;
    //cout << "super[10] should give an error: " << super[10] << endl;
    
    //--------------------------------------------------------------------------
    // Addition operator+
    //--------------------------------------------------------------------------
    
    cout << miniDash << endl << "operator+" << endl << miniDash << endl;
    
    cout << "\"sail = grape + toy\" should make \"grapetoy\": ";
    sail = grape + toy;
    sail.print();
    cout << endl;
    
    cout << "\"ball = abe + abe\" should make \"abeabe\": ";
    ball = abe + abe;
    ball.print();
    cout << endl;
    
    cout << "\"shells = shells + shells\" should make \"shellsshells\": ";
    shells = shells + shells;
    shells.print();
    cout << endl;
    
    cout << "\"graba = stuff + toy + grape\" should make \"stufftoygrape\": ";
    graba = stuff + toy + grape;
    graba.print();
    cout << endl;
    
    cout << "\"toy = toy + empty1\" should make \"toy\": ";
    toy = toy + empty1;
    toy.print();
    cout << endl;
    
    cout << "\"stuff = empty1 + empty1\" should make an empty string: ";
    stuff = empty1 + empty1;
    stuff.print();
    cout << endl;
    
    cout << dashes << endl << "End Testing" << endl << dashes << endl;

    return 0;    
}
