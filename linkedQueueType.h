#ifndef LINKEDQUEUETYPE_H
#define LINKEDQUEUETYPE_H


#include <cassert>
#include <iostream>
#include "nodeType.h"
#include "queueADT.h"

using namespace std;

template <class Type>
class linkedQueueType : public queueADT<Type>
{
public:
	const linkedQueueType<Type>& operator= (const linkedQueueType<Type>&);
	//Overload the assignment operator.
	bool isEmptyQueue() const;
	//Function to determine whether the queue is empty.
	//Postcondition: Returns true if the queue is empty,
	// otherwise returns false.
	bool isFullQueue() const;
	//Function to determine whether the queue is full.
	//Postcondition: Returns true if the queue is full,
	// otherwise returns false.
	void initializeQueue();
	//Function to initialize the queue to an empty state.
	//Postcondition: queueFront = nullptr; queueRear = nullptr
	Type front() const;
	//Function to return the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the first
	// element of the queue is returned.
	Type back() const;
	//Function to return the last element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: If the queue is empty, the program
	// terminates; otherwise, the last
	// element of the queue is returned.
	void addQueue(const Type& queueElement);
	//Function to add queueElement to the queue.
	//Precondition: The queue exists and is not full.
	//Postcondition: The queue is changed and queueElement
	// is added to the queue.
	void deleteQueue();
	//Function to remove the first element of the queue.
	//Precondition: The queue exists and is not empty.
	//Postcondition: The queue is changed and the first
	// element is removed from the queue.
	linkedQueueType();
	//Default constructor
	linkedQueueType(const linkedQueueType<Type>& otherQueue);
	//Copy constructor
	~linkedQueueType();
	//Destructor
private:
	nodeType<Type>* queueFront; //pointer to the front of
	//the queue
	nodeType<Type>* queueRear; //pointer to the rear of
	//the queue
};

template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=(const linkedQueueType<Type>& otherQueue)
{
	// Check for self-assignment
	if (this != &otherQueue) {
		// Clear the current queue
		initializeQueue();

		// Create a dummy node
		nodeType<Type>* newNode;
		newNode = new nodeType<Type>;
		newNode->info = ' '; // This value will be overwritten
		newNode->link = nullptr;

		// Copy the other queue into this queue
		queueFront = newNode;
		queueRear = newNode;

		// Traverse the other queue and add its elements to this queue
		nodeType<Type>* current = otherQueue.queueFront;
		while (current != nullptr) {
			addQueue(current->info);
			current = current->link;
		}

		// Remove the dummy node
		deleteQueue();
	}

	return *this;
}

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
	return (queueFront == nullptr);
} //end isEmptyQueue

template <class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
	return false;
} //end isFullQueue

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
	nodeType<Type>* temp;
	while (queueFront != nullptr) //while there are elements
		//left in the queue
	{
		temp = queueFront; //set temp to point to the
		//current node
		queueFront = queueFront->link; //advance first to
		//the next node
		delete temp; //deallocate memory occupied by temp
	}
	queueRear = nullptr; //set rear to nullptr
} //end initializeQueue

template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
	nodeType<Type>* newNode;
	newNode = new nodeType<Type>; //create the node
	newNode->info = newElement; //store the info
	newNode->link = nullptr; //initialize the link
	//field to nullptr
	if (queueFront == nullptr) //if initially the queue is empty
	{
		queueFront = newNode;
		queueRear = newNode;
	}
	else //add newNode at the end
	{
		queueRear->link = newNode;
		queueRear = queueRear->link;
	}
}//end addQueue

template <class Type>
Type linkedQueueType<Type>::front() const
{
	assert(queueFront != nullptr);
	return queueFront->info;
} //end front

template <class Type>
Type linkedQueueType<Type>::back() const
{
	assert(queueRear != nullptr);
	return queueRear->info;
} //end back

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
	nodeType<Type>* temp;
	if (!isEmptyQueue())
	{
		temp = queueFront; //make temp point to the
		//first node
		queueFront = queueFront->link; //advance queueFront
		delete temp; //delete the first node
		if (queueFront == nullptr) //if after deletion the
			//queue is empty
			queueRear = nullptr; //set queueRear to nullptr
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
}//end deleteQueue

template <class Type>
linkedQueueType<Type>::linkedQueueType()
{
	queueFront = nullptr; //set front to nullptr
	queueRear = nullptr; //set rear to nullptr
} //end default constructor

template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue)
{
	// Create a dummy node
	nodeType<Type>* newNode;
	newNode = new nodeType<Type>;
	newNode->info = ' '; // This value will be overwritten
	newNode->link = nullptr;

	// Copy the other queue into this queue
	queueFront = newNode;
	queueRear = newNode;

	nodeType<Type>* current = otherQueue.queueFront;
	while (current != nullptr)
	{
		addQueue(current->info);
		current = current->link;
	}

	// Remove the dummy node
	deleteQueue();
}//end copyConstructor

template <class Type>
linkedQueueType<Type>::~linkedQueueType()
{
	// Call the initializeQueue function to deallocate all nodes
	initializeQueue();
}//end destructor


#endif