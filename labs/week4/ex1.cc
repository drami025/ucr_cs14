#include<iostream>
#include<vector>

using namespace std;

class Node{
    public:
        Node* next;
        int num;
        Node() : next(0) {};
        Node(int num) : next(0), num(num) {};
};

class List{
    private:
        Node* head;
        Node* tail;
        
    public:
        List() : head(0), tail(0) {};
        void push_front(int num);
        void print() const;
        bool hasCircle() const;
        void makeLoop();
        Node* getHead() const;
};


void List::push_front(int num)
{
    if(head != 0)
    {
        Node* temp = head;
        head = new Node(num);
        head->next = temp;
    }
    else
    {
        head = new Node(num);
    }
}

void List::print() const
{
    for(Node* i = head; i != 0; i = i->next)
    {
        cout << i->num << " ";
    }
    
    cout << endl;
}

bool List::hasCircle() const
{
    Node *f = head, *s = head;
    
    if(head == 0 || head->next == 0)
		return false;
		
	while(s != 0 && s->next != 0)
	{
		f = f->next;
		s = s->next->next;
		
		if(s == f)
			return true;
	}

    return false;
}

void List::makeLoop()
{
    Node *i = 0;
    
    for(i = head; i->next != 0; i = i->next)
    {}
    
    i->next = head->next->next;
}

Node* List::getHead() const
{
    return head;
}

int main()
{
    List L1;
    
    for(int i = 10; i > 0; i--)
    {
        L1.push_front(i);
    }
    
    L1.makeLoop();
    
    if(L1.hasCircle())
    {
        cout << "Loop found!" << endl;
    }
    else
    {
        cout << "No loop!" << endl;
    }
    
    
    return 0;
}
