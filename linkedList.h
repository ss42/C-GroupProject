#include <iostream>
using namespace std;

template<class kind>
class ListNode;

template <class kind>
class BNode
{
    template<class X> friend class ListNode;
private:
    kind val;
    BNode<kind> *prev, *next;
public:
    //constructors
    BNode();//default constructor
    BNode(kind data);
    BNode(kind data, BNode<kind>* p1,BNode<kind>* p2);//constructor
    void setVal(kind data){val = data;}
};
template <class kind>
class ListNode
{
    //friend class BNode<kind>; // might need to be templated, same with the other friend
private:
    BNode<kind> *front, *back;
    int size;
public:
    //constructors
    ListNode();//default constructor
    ListNode(kind data);//constructor that takes data
    BNode<kind> getFront(){return *front;}
    BNode<kind> getBack(){return *back;}
    void setSize(){size++;}
    void subtractSize(){size--;}
    int getSize(){return size;}
    bool empty(); //boolean accessor that indicates whether the BListNode is empty
    void push_front(kind addData);
    void push_back(kind addData);
    void printNode();
    void delete(int n);
    kind pop_back();
    kind pop_front();
    kind insert(kind data, BNode<kind> afterThis);//insert data after the pointer p
    ListNode<kind> sublst(BNode<kind> from,BNode<kind> to); // returns a ListNode which is a copy of ListNode, starting a to z
    kind operator [](int index);
    ~ListNode(); //destuctor
    void sort(BNode<kind> &from,BNode<kind> &to); //sorts the portion of ListNode bounded by a and z //this should support the overloaded operators == , <  //default value for front and back
    //void sort(BNode<kind> a,BNode<kind> z, cmp());//see the hw description
    
    //assignmnents
    //overloaded operator : ListNode[2] should refer to the 3rd node of the ListNode
    
    //make ListNode a friend of BNode
};