//
//  listNode.cpp
//  project 2
//
//  Created by Sanjay Shrestha on 11/11/15.
//  Copyright © 2015 Sanjay Shrestha. All rights reserved.
//

#include <iostream>
using namespace std;

#include "linkedList.h"  
//the header for the function declaration of the below functions/methods


class Monomial;
/*
 BNode<kind>::BNode() : default constructor
 */
template <class kind>
BNode<kind>::BNode()
{
    setVal(NULL);
    prev = NULL;
    next = NULL;
}
/*
 BNode<kind>::BNode(kind data) :  constructor that sets the (data)value of the node
 */
template <class kind>
BNode<kind>::BNode(kind data)
{
    setVal(data);
    prev = NULL;
    next = NULL;
}
/*
 BNode<kind>::BNode(kind data, BNode<kind>* p1,BNode<kind>* p2) : construtor that sets value or 
 data of the node between the given pointers
 */
template <class kind>
BNode<kind>::BNode(kind data, BNode<kind>* p1,BNode<kind>* p2)
{
    setVal(data);
    prev = p1;
    next = p2;
}
/*
 ListNode() ::  is the default constructor for the class ListNode.
 It sets the pointers back and front to NULL.
 */
template <class kind>
ListNode<kind>::ListNode()
{
    front = NULL;
    back = NULL;
    size = 0;
}
/*
 ListNode() ::  is the default constructor that sets the data in the list for one node
 */
template <class kind>
ListNode<kind>::ListNode(kind data)
{
    setVal(data);
    front = NULL;
    back = NULL;
    size = 0;
}
/*
 ListNode() ::  is the default constructor that takes the size of the array and array 
 and makes a list node.
 */
template<class kind>
ListNode<kind>::ListNode(int sizeArr, kind arr[])
:size(0)
{
    front = back = NULL;
    for(int i = 0; i < sizeArr; i++)
    {
        push_back(arr[i]);
    }
    
}
/*
 empty() ::  is an boolean accessor that indicates whether the BListNode is empty.
 True if empty else false
 */
template <class kind>
bool ListNode<kind>::empty()
{
    return(front == NULL);
}
//test

/*
 push_front(kind addData ):: is the method in the class ListNode.
 It adds data in the front of the linked ListNode
 */
template <class kind>
void ListNode<kind>::push_front(kind addData)
{
    if(empty())
    {
        BNode<kind> *temp;  //creates a pointer
        temp = new BNode<kind>(addData);  //creates a new node and sets the value for the node
        temp -> next = NULL;
        temp -> prev = NULL;
        front = temp;
        back = temp;
        setSize();
        return;
    }
    BNode<kind> *temp = front;  //creates a pointer
    front = new BNode<kind>(addData);  //creates a new node sets the value for the node
    front -> next = temp;
    front -> prev = NULL;
    setSize();
    //points the next pointer to the previously front
    //delete temp;    //Dont know if this is necessary
}
/*
 pop_front() pops the data from the front of the linked ListNode.
 We assume that the bListNode is not empty so we don't check for NULL.
 */
template<class kind>
kind ListNode<kind>::pop_front()
{
    BNode<kind> *temp;
    temp = front;  //creates a pointer
    front = front -> next;  //assignes front pointer to the next pointer
    kind data = temp -> val; //assign temporary before deleting temp
    delete temp;
    subtractSize();
    return data;
}
/*
 push_back(kind addData) adds data in the end of the ListNode.
 */
template<class kind>
void ListNode<kind>::push_back(kind addData)
{
    if(back == NULL) //if the back pointer is empty
    {
        front = back = new BNode<kind>(addData);  //creates new pointer front
        front -> next = NULL;    //points the next to NULL
        setSize();
        return;
    }
    BNode<kind> *temp;
    temp = new BNode<kind>(addData);   //assignes new pointer temp and a new
    temp -> prev = back;
    back -> next = temp;
    back = temp;
    temp->next = NULL;
    setSize();
}
/*
 pop_back() returns data from the end.
 */
template<class kind>
kind ListNode<kind>::pop_back()
{
    BNode<kind> *temp = back -> prev;//creates a node previous to the last node
    temp ->next = NULL;  //points next to NULL;
    //temp ->val = back ->val; //sets value of temp to value of the last node
    kind value = back->val;
    delete back; //deletes the last node
    back = temp;  //sets temp as the back
    subtractSize();
    return value;
    
}
/*
 insert(T data, Bnode<kind> p) inserts the data current the pointer p.
 */
template<class kind>
kind ListNode<kind>::insert(kind data, BNode<kind> currentThis)
{
    BNode<kind> *temp;
    temp = new BNode<kind>(data);
    if (currentThis == NULL) {
        front-> val =  data;//set val to data
        //front-> back = NULL; //set the node as the back to NULL
        //p-> front = NULL; // set the front as NULL
    }
    else
    {
        if(currentThis->next == NULL)
        {
            currentThis-> next-> val = data; //sets val of the NULL node to data
            currentThis->next-> back = NULL; //sets back of the pointer as NULL
        }
        else
        {
            BNode<kind> *temp; //makes new pointer
            temp = new BNode<kind>; //temp points to the new created new node
            temp -> val = data; //inserts data to the new node
            currentThis->next->prev = temp;   //points next of the p to temp
            currentThis->next = temp; //points to temp
            temp->prev = currentThis;    //points prev of the temp to p
        }
    }
}
/*
 ListNode.sublst(BNode<kind> a,BNode<kind> z) returns a list of node between the provided pointers

 */
template<class kind>
ListNode<kind> ListNode<kind>::sublst(BNode<kind> from,BNode<kind> to)
{
    BNode<kind> *temp;
    ListNode<kind> tempList = new ListNode<kind>;
    temp = from;
    tempList.push_front(temp->val);
    while (temp != to)
    {
        temp = temp->next;
        tempList.push_back(temp->val);
    }
}
/*
printNode() prints the data in the node(designed for polynomials with deg and coeff)
 */
template<class kind>
void ListNode<kind>::printNode()
{
    BNode<kind> *temp;
    
    temp = front;
    
    while(temp->next != NULL)
    {
        cout << temp-> val.getCoefficient() << "x^"<<temp->val.getDegree() << " + ";
        temp = temp -> next;
    }
    temp = back;
    cout << temp-> val.getCoefficient() << "x^"<<temp->val.getDegree();
    cout <<  endl;
}
/*
 ~ListNode is the destructor
 */
template<class kind>
ListNode<kind>::~ListNode()
{
    BNode<kind> *temp;
    while (front != NULL){
        temp = front->next;
        
        delete front;
        front = temp;
    }
}
/*
deleteNode(BNode<kind> *current) deletes the node.
 */
template <class kind>
void ListNode<kind>::deleteNode(BNode<kind> *current)
{
    if (current -> next == NULL && current -> prev == NULL)
        cout << "List is empty" << endl;

    else if (current -> prev == NULL)
    {
        front = current -> next;
        front -> prev = NULL;
    }
    else if (current -> next == NULL)
    {
        back = current -> prev;
        back -> next = NULL;
    }
    else
    {
        current -> prev -> next = current -> next;
        current -> next -> prev = current -> prev;
    }
    delete current;
    subtractSize();
}
/*
sortNode() sorts the list according to degree (cmp type)
 */
template <class kind>
void ListNode<kind>::sortNode()
{
    if (empty())
    {
        cout << "list empty" << endl;
        return;
    }
    
    BNode<kind> *outer = front;
    BNode<kind> *inner = front;
    BNode<kind> *min = front;
    while (outer)
    {
        min = outer;
        inner = outer;
        while (inner)
        {
            if (inner->val.getDegree() < min->val.getDegree())
            {
                min = inner;
            }
            inner = inner->next;
        }
        kind tmp = min->val;
        min->val = outer->val;
        outer->val = tmp;
        outer = outer->next;
    }
}
/*
operator [](int index) returns the template type of data at the given index.
This is an operator overloader.
 */
template<class kind>
kind ListNode<kind>::operator [](int index)
{
    if((index < 0) || (index > getSize()) )cout << "Out of Bound. Check your bounds, here is the head of the list!" << endl;
    else if (index == 0)
    {
        return (front->val);
    }
    else
    {
        BNode<kind> *temp;
        temp = front;
        for(int i = 0; i < index ; i++)
        {
            temp =  temp->next;
        }
        return (temp-> val);
    }
    return front->val;
}
/*
operator = (const ListNode<kind> &first) is an assignment overloaders.
It copys the list node.
 */
template<class kind>
ListNode<kind>& ListNode<kind>::operator = (const ListNode<kind> &first)
{
    //cout << "looking at indexes" << endl;
    if(first.front == NULL) cout <<"List is empty. "<< endl;
    
    
    else
    {
        BNode<kind> *temp = first.front;
        while(temp != NULL)
        {
            push_back(temp->val);
            temp = temp->next;
        }
    }
    return *this;
}

