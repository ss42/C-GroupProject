#include <iostream>
#include "linkedList.h"
using namespace std;
/*
List() ::  is the default constructor for the class List.
It sets the pointers back and front to Null.
*/
template<class T>
T List::List()
{
    front = NULL;
    back = NULL;
}
/*
 List() ::  is the copy constructor for the class List.

 */
template<class T>
T List::List(T data)
{
    val = data; //copy ** Need to fix this**
}
/*
empty() ::  is an boolean accessor that indicates whether the Blist is empty.
True if empty else false
*/
template<class T>
bool empty::List(T data)
{
    return(size == 0)
}
//test

/*
push_front(T a ):: is the method in the class list.
It adds data in the front of the linked list
*/
template<class T>
void LIST<T>::push_front(T addData);
{
	BNode<S> *temp = front;  //creates a pointer
	front = new Node<T>;  //creates a new node
	front -> val = addData;      //sets the value for the node
	front -> next = temp;   //points the next pointer to the previously front
    //delete temp;    //Dont know if this is necessary
}
/*
pop_front(T data) pops the data from the front of the linked list.
We assume that the blist is not empty so we don't check for NULL.
*/
template<class T>
T LIST<T>::pop_front()
{
    BNode<S> *temp = front;  //creates a pointer
    front = front -> next;  //assignes front pointer to the next pointer
    int data = temp -> val; //assign temporary before deleting temp
    delete temp; 
    return data;
}
/*
push_back(T addData) adds data in the end of the list.
*/
template<class T>
void LIST<T>::push_back(T a);
{
	if(back == NULL) //if the back pointer is empty
	{
		front = back = new Node<T>;  //creates new pointer front
		front -> val = addData;  //assigns value to the pointer
		front -> next = NULL;    //points the next to NULL
		return;
	}
	BNode<S> *temp = new Node<T>;   //assignes new pointer temp and a new node
	temp -> val = addData;
	temp -> next = NULL;
	back -> next = temp;
	back = temp;
    //delete temp; //May be??
}
/*
 pop_back() returns data from the end.
*/
template<class T>
T LIST <T>::pop_back()
{
    BNode<S> *temp = back -> prev;//creates a node previous to the last node
    temp ->next = NULL;  //points next to null;
    temp ->val = back ->val; //sets value of temp to value of the last node
    delete back; //deletes the last node
    back = temp;  //sets temp as the back
    //size--;  //*****need to do this in every method ********
    return value;
    
}
/*
~List is the destructor
 */
template<class T>
T List<T>::~List();
{
    delete next, prev;
}
    /*
	Bnode<T> *temp-> val;
	if(front == back)
		front = back = NULL;
	else
	{
		front = front-> next;
		front -> prev = NULL;
	}
	delete temp;
	return;
/*
}
\
//p loacates the node the value
//inserted after

Node<T> temp = p->next; //(*p).next //
p -> next = new Node<T>;  //creates a new node
p -> next -> val = 7;  //assigns the new node with value of 7
p -> next -> next = temp; //points to the new node from the temp
size++;
//---------------------//
//to insert a node in the front
p = ls.getFront();
//check if the lenght exceeds 1037
for(int i = 0; i < 1037; i++)
{
	= = p-> next;
} 