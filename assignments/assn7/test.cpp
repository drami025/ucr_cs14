#include <iostream>
#include "prim.h"

using namespace std;

int main() 
{
    // zero
    {
        cerr << "zero" << endl;

        set<Edge> test;
        Graph MST = prim(test);

        for (set<Edge>::iterator it = MST.begin(); it != MST.end(); it++)
        {
            cout << "(" << (*it).end1 << ", " << (*it).end2 << ", " << (*it).weight << ")\n";
        }
    }

    // one
    {
        cerr << "one" << endl;
        Edge AB(1, 2, 1);

        set<Edge> test;
        test.insert(AB);

        Graph MST = prim(test);

        for (set<Edge>::iterator it = MST.begin(); it != MST.end(); it++)
        {
            cout << "(" << (*it).end1 << ", " << (*it).end2 << ", " << (*it).weight << ")\n";
        }
    }

    // two
    {
        cerr << "two" << endl;
        Edge AB(1, 2, 1);
        Edge BD(2, 3, 2);

        set<Edge> test;
        test.insert(AB);
        test.insert(BD);

        Graph MST = prim(test);

        for (set<Edge>::iterator it = MST.begin(); it != MST.end(); it++)
        {
            cout << "(" << (*it).end1 << ", " << (*it).end2 << ", " << (*it).weight << ")\n";
        }
    }

    // test 3
    {
        cerr << "small MST" << endl;
        Edge AB(1, 2, 1);
        Edge BD(2, 3, 2);
        Edge DC(3, 4, 1);
        Edge CA(4, 1, 2);
        Edge BC(2, 4, 1);

        set<Edge> test;
        test.insert(AB);
        test.insert(BD);
        test.insert(DC);
        test.insert(CA);
        test.insert(BC);

        Graph MST = prim(test);

        for (set<Edge>::iterator it = MST.begin(); it != MST.end(); it++)
        {
            cout << "(" << (*it).end1 << ", " << (*it).end2 << ", " << (*it).weight << ")\n";
        }
    }

    // test 3
    {
        cerr << "big MST" << endl;

        Edge AB(1, 2, 1);
        Edge BC(2, 3, 4);
        Edge CD(3, 4, 3);
        Edge DE(4, 5, 8);
        Edge EF(5, 6, 2);
        Edge FG(6, 7, 5);
        Edge GH(7, 8, 1);
        Edge AH(1, 8, 2);
        Edge GA(7, 1, 5);
        Edge DH(4, 8, 6);

        Graph test;
        test.insert(AB);
        test.insert(BC);
        test.insert(CD);
        test.insert(DE);
        test.insert(EF);
        test.insert(FG);
        test.insert(GH);
        test.insert(AH);
        test.insert(GA);
        test.insert(DH);

        Graph MST = prim(test);

        for (set<Edge>::iterator it = MST.begin(); it != MST.end(); it++)
        {
            cout << "(" << (*it).end1 << ", " << (*it).end2 << ", " << (*it).weight << ")\n";
        }
    }

    return 0;
}

