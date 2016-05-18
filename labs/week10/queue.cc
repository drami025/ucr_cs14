#include<iostream>
#include<stack>

using namespace std;

template<typename Type>
class queue
{
	private:
	
	stack<Type> st1;
	stack<Type> st2;

	public:
	
	void enqueue(Type s)
	{
		st1.push(s);	
	}

	Type front()
	{
		Type value;

		while(!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}
		
		value = st2.top();
		
		while(!st2.empty())
		{
			st1.push(st2.top());
			st2.pop();
		}

		return value;
	}

	void dequeue()
	{
		Type value;
		
		while(!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}

		st2.pop();

		while(!st2.empty())
		{
			st1.push(st2.top());
			st2.pop();
		}
	}

	void print()
	{
		while(!st1.empty())
		{
			st2.push(st1.top());
			st1.pop();
		}

		while(!st2.empty())
		{
			cout << st2.top() << " ";
			st1.push(st2.top());
			st2.pop();
		}
	}
};

int main()
{
	queue<int> test;

	for(int i = 0; i < 10; i++)
	{
		test.enqueue(i);
	}
	
	cout << endl << "What is in the stack: ";
	test.print();
	
	cout << endl << "Testing front() function: " << test.front() << endl;

	test.dequeue();

	cout << "What is in the stack after dequeue: ";

	test.print();

	cout << endl << endl;

	
	return 0;
}
