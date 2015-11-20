//
//  listNode.hpp
//  Project 2
//  
//  Created by Sanjay Shrestha on 11/11/15.
//  Copyright © 2015 Sanjay Shrestha. All rights reserved.
//  

template<class kind>
class ListNode;

template <class kind>
class BNode
{
private:
    kind val;                       //data type to be stored in the Node
    BNode<kind> *prev, *next;       //pointers to the node
public:
    BNode(); //default constructor
    BNode(kind data);      
    BNode(kind data, BNode<kind>* p1,BNode<kind>* p2);//constructor
    kind getVal(){return val;}             //accessors to get value of the node
    void setVal(kind data){val = data;}    //mutators to set the value of the node
    BNode<kind>* getNext(){return next;}    //accessor to get the pointer
    BNode<kind>* getprev(){return prev;} 
    friend class ListNode<kind>;         
    friend class Monomial;
    
};
template <class kind>
class ListNode
{
private:
    BNode<kind> *front, *back;          //pointer of the node the head and the tail
    int size;                            //size of the list node
public:
    ListNode();//default constructor
    ListNode(kind data);//constructor that takes data
    ListNode(int size, kind arr[]);         //constructor that takes size of the array and a array
    BNode<kind>* getFront(){return front;}   //accessor to get the pointer
    BNode<kind>* getBack(){return back;}
    void setSize(){size++;}               //mutators to set the size of the list
    void subtractSize(){size--;}
    int getSize(){return size;}
    bool empty(); //boolean accessor that indicates whether the ListNode is empty
    void push_front(kind addData);     //add a node in the front
    void push_back(kind addData);       // add a node in the back
    void printNode();                   // to print the node
    kind pop_back();             //to get the template type from back of the node
    kind pop_front();            // to get the template type from the front of the node
    void sortNode();              // sort node inorder of degrees
    void deleteNode(BNode<kind> *current);        //delete the node
    kind insert(kind data, BNode<kind> afterThis);//insert data after the pointer p
    ListNode<kind> sublst(BNode<kind> from,BNode<kind> to); // returns a ListNode which is a copy of ListNode, starting a to z
    
    kind operator [](int index);                //operator overloader to get the index of the nodelist
    ListNode<kind>& operator= (const ListNode<kind> &first);
       //assignment operator overloader (similar to copy constructor)
    
    friend class BNode<kind>;
    friend class Monomial;
    friend ListNode<kind> operator +(ListNode<kind>& list1, ListNode<kind>& list2);

    ~ListNode(); //destuctor
    
};