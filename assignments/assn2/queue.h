#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<list>
#include"stack.h"

using namespace std;


//Class template for a queue.
// All member functions in queue class uses member functions provided by the
// STL list class. Payne said it was allowed.
template<typename Type>
class queue{
	private: 
		list<Type> queueList;
		
	public:
		queue();
		queue(const queue& copy);
		Type& front();
		const Type& front() const;
		Type& back();
		const Type& back() const;
		void push(Type item);
		void pop();
		bool empty() const;
		int size() const;
};

//Default constructor for queue class.
template<typename Type>
queue<Type>::queue()
	:queueList(0)
{}

//Copy constructor. Sets list in implicit parameter to copy's list.
template<typename Type>
queue<Type>::queue(const queue& copy)
{
	queueList = copy.queueList;
}

//Member function returns the item in the front of the queue. This function
// also allows the user to change/alter the object in the front of the queue
// since it is returned by reference.
template<typename Type>
Type& queue<Type>::front()
{
	return queueList.front();
}

//Member function returns the item in the front the queue. This function 
// prevents the user from changing/altering object in front of the queue.
template<typename Type>
const Type& queue<Type>::front() const
{
	return queueList.front();
}

//Member function returns the item in the back of the queue. This function 
// also allows the user to change/alter the object in the back of the queue
// since it is returned by reference.
template<typename Type>
Type& queue<Type>::back()
{
	return queueList.back();
}

//Member function returns the item in the back of the queue. This function 
// prevents the user from changing/altering the object in back of the queue.
template<typename Type>
const Type& queue<Type>::back() const
{
	return queueList.back();
}

//Member function pushes a new item in the back of the queue.
template<typename Type>
void queue<Type>::push(Type item) 
{
	queueList.push_back(item);
}

//Member function takes out the first item in the queue.
template<typename Type>
void queue<Type>::pop()
{
	queueList.pop_front();
}

//Member function determines whether the queue is empty or not.
template<typename Type>
bool queue<Type>::empty() const
{
	return (queueList.size() == 0) ? true : false;
}

//Member function determines the size of the list.
template<typename Type>
int queue<Type>::size() const
{
	return queueList.size();
}

#endif
