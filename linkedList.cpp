template <class kind>
BNode<kind>::BNode()
{
    setVal(NULL);
    prev = NULL;
    next = NULL;
}
template <class kind>
BNode<kind>::BNode(kind data)
{
    setVal(data);
    prev = NULL;
    next = NULL;
}
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
    setSize();
}
/*
 ListNode() ::  is the copy constructor for the class List.
 */

template <class kind>
ListNode<kind>::ListNode(kind data)
{
    setVal(data);
    front = NULL;
    back = NULL;
    setSize();
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
 push_front(kind a ):: is the method in the class ListNode.
 It adds data in the front of the linked ListNode
 */
template <class kind>
void ListNode<kind>::push_front(kind addData)
{
    BNode<kind> *temp = front;  //creates a pointer
    front = new BNode<kind>;  //creates a new node
    front -> val = addData;      //sets the value for the node
    front -> next = temp;
    front -> prev = NULL;
    setSize();
    //points the next pointer to the previously front
    //delete temp;    //Dont know if this is necessary
}
/*
 pop_front(kind data) pops the data from the front of the linked ListNode.
 We assume that the bListNode is not empty so we don't check for NULL.
 */
template<class kind>
kind ListNode<kind>::pop_front()
{
    BNode<kind> *temp;
    temp = front;  //creates a pointer
    front = front -> next;  //assignes front pointer to the next pointer
    int data = temp -> val; //assign temporary before deleting temp
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
        front = back = new BNode<kind>;  //creates new pointer front
        front -> val = addData;  //assigns value to the pointer
        front -> next = NULL;    //points the next to NULL
        setSize();
        return;
    }
    BNode<kind> *temp;
    temp = new BNode<kind>;   //assignes new pointer temp and a new node
    temp -> val = addData;
    temp -> next = NULL;
    back -> next = temp;
    back = temp;
    setSize();
    //delete temp; //May be??
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
 insert(T data, Bnode<kind> p) inserts the data after the pointer p.
 */
template<class kind>
kind ListNode<kind>::insert(kind data, BNode<kind> afterThis)
{
    BNode<kind> *temp;
    temp = new BNode<kind>;
    temp->val = data;
    if (afterThis == NULL) {
        front-> val =  data;//set val to data
        //front-> back = NULL; //set the node as the back to NULL
        //p-> front = NULL; // set the front as NULL
    }
    else
    {
        if(afterThis->next == NULL)
        {
            afterThis-> next-> val = data; //sets val of the NULL node to data
            afterThis->next-> back = NULL; //sets back of the pointer as NULL
        }
        else
        {
            BNode<kind> *temp; //makes new pointer
            temp = new BNode<kind>; //temp points to the new created new node
            temp -> val = data; //inserts data to the new node
            afterThis->next->prev = temp;   //points next of the p to temp
            afterThis->next = temp; //points to temp
            temp->prev = afterThis;    //points prev of the temp to p
        }
    }
}
/*
 ListNode.sublst(BNode<kind> a,BNode<kind> z)
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
 ListNode.sort(BNode<kind> a,BNode<kind> z)
 */
template<class kind>
void ListNode<kind>::sort(BNode<kind> &from,BNode<kind> &to)
{
    BNode<kind> *temp, *temp1;   //creates two pointers
    temp = from;                 //assigns temp to the begining of the requested node
    temp1 = new BNode<kind>;     //creates a new node and assignes pointer to it
    while(temp->val != NULL and temp != to)  //if not temp is not NULL and temp is not the last
    {
        if(temp->val > temp->next->val)   //if the value in temp is greater than the next node value
        {
            temp1 ->val = temp;
            temp-> val = temp->next-> val;
            temp->next -> val = temp1 ->val;
        }
        else
        {
            temp = temp->next;
        }
        
    }
}
template<class kind>
void ListNode<kind>::printNode(BNode<kind> node)
{
    BNode<kind> *temp;
    temp = new BNode<kind>;
    if(front == NULL)
    {
        cout << "List is empty, nothing to display" << endl;
        return;
    }
    temp = front;
    cout << " The list is :"<< endl;
    while(temp!= NULL)
    {
        cout << temp-> val << " <-> ";
        temp = temp -> next;
    }
    cout << "  End  "<< endl;
}
/*
 ~ListNode is the destructor
 */
template<class kind>
ListNode<kind>::~ListNode()
{
    // walk through each node and delete them one at a time
    BNode<kind> *temp;
    while (front != NULL){
        temp = front->next;
        delete front;
        front = temp;
    }
    delete temp;
}



int main()
{
    ListNode<int> a;
    // make a BNode, then insert
    a.push_front(5);
    
}
