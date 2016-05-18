#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<list>
#include "queue.h"

using namespace std;

//Class template for the stack data structure.
//Class uses the STL list's data functions to implement stack's functions.
//Payne allows it.
template<typename Type>
class stack{
	
	private:
		list<Type> stackList;
		
	public:
		stack();
		stack(const stack& rhs);
		Type& top();
		const Type& top() const;
		void pop();
		void push(Type item);
		bool empty() const;
		int size() const;
		stack operator=(const stack& rhs);
};

//Default constructor for the stack class.
template<typename Type>
stack<Type>::stack()
	: stackList(0)
{}

//Copy constructor for the stack class. Simply copies the implicit list to the
// list of the explicit parameter.
template<typename Type>
stack<Type>::stack(const stack& rhs)
{
	stackList = rhs.stackList;
}

//Member function returns the item at the top of the stack. Allows user to 
// alter/change the item at the top of the stack since function returns a ref.
template<typename Type>
Type& stack<Type>::top()
{
	return stackList.front();
}

//Member function returns the item at the top of the stack. Prevents the user
// from altering or changing top of stack since it returns a const ref.
template<typename Type>
const Type& stack<Type>::top() const
{
	return stackList.front();
}

//Member function removes the item from the top of the stack.
template<typename Type>
void stack<Type>::pop()
{
	stackList.pop_front();
}

//Member function pushes a new item to the top of the stack.
template<typename Type>
void stack<Type>::push(Type item)
{
	stackList.push_front(item);
}

//Member function determines whether the stack is empty or not.
template<typename Type>
bool stack<Type>::empty() const
{
	return (stackList.size()) ? true : false;
}

//Member function determines the size of the stack.
template<typename Type>
int stack<Type>::size() const
{
	return stackList.size();
}

//Operator overloader allows one stack to be assigned to another.
template<typename Type>
stack<Type> stack<Type>::operator=(const stack& rhs)
{
	return rhs;
}

#endif

