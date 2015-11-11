
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
    cout << getSize()  << endl;
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
    size = 0;
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
    if(empty())
    {
        BNode<kind> *temp;  //creates a pointer
        temp = new BNode<kind>(addData);  //creates a new node and sets the value for the node
        temp -> next = NULL;
        temp -> prev = NULL;
        front = temp;
        back = temp;
        setSize();
        cout << "List was empty so Created a new node   :" << getSize() << endl;
        return;
    }
    BNode<kind> *temp = front;  //creates a pointer
    front = new BNode<kind>(addData);  //creates a new node sets the value for the node
    front -> next = temp;
    front -> prev = NULL;
    setSize();
    cout << "new node pushed in the front  " << getSize() << endl;
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
    kind data = temp -> val; //assign temporary before deleting temp
    delete temp;
    subtractSize();
    cout <<"pop front CHECKING. and the size is " << getSize() <<endl;
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
        //front -> val = addData;  //assigns value to the pointer
        front -> next = NULL;    //points the next to NULL
        setSize();
        cout << "back was empty so created a new node thru push_back  " << getSize()<< endl;
        return;
    }
    BNode<kind> *temp;
    temp = new BNode<kind>(addData);   //assignes new pointer temp and a new
    temp -> prev = back;
    back -> next = temp;
    back = temp;
    temp->next = NULL;
    setSize();
    cout << "added data in the end " << getSize()<< endl;
    //delete temp; //May be??
}
// Ayalew DELETE FUNCTION 
void ListNode<kind>::delete(int index)
{
    BNode<kind>* temp1 = head;
    if(index == 1){
        head == temp1- >next; //head now points to second node.
        delete temp1;
        return;
    }
    int i
    for( i = 0;i<index-2;i++)
        temp1 = temp1->next;
    // temp1 points to (n-1)th Node
    BNode<kind>* temp2 = temp1->next //nth Node
    temp1->next = temp2->next; //(n+1)th Node
    delete temp2; //delete temp2;
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
    cout << "pop back CHECKING and the size is " << getSize() <<endl;
    return value;
    
}
/*
 insert(T data, Bnode<kind> p) inserts the data after the pointer p.
 */
template<class kind>
kind ListNode<kind>::insert(kind data, BNode<kind> afterThis)
{
    BNode<kind> *temp;
    temp = new BNode<kind>(data);
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
    BNode<kind> *temp, *temp1, *current, *previous;   //creates two pointers
    temp = &from;                 //assigns temp to the begining of the requested node
    //creates a new node and assignes pointer to it
    /*while(temp != NULL && temp != &to)  //if not temp is not NULL and temp is not the last
     {
     cout <<"1" <<endl;
     //cout << temp->next->val << endl;
     if(temp->next != NULL && temp->val > temp->next->val)   //if the value in temp is greater than the next node value
     {
     //temp1  = temp;
     //temp-> val = temp->next-> val;
     //temp->next  = temp1;
     //temp->prev->next = temp1->next;
     //temp->prev = temp1->next;
     
     //temp->next = temp1->next->next;
     /*cout << "3" << endl;
     //temp1 = new BNode<kind>(0);
     //temp1 = temp;
     cout << "here2" << endl;
     cout << "temp val: " << temp->val <<", temp->next val: " << temp->next->val << endl;
     cout << "temp->prev->next->val = " << temp->prev->next->val << endl;
     temp->prev->next = temp->next; // or temp1->prev
     cout << "here1" <<endl;
     temp->next->prev = temp->prev;
     cout << "here" << endl;
     temp->prev = temp->next;
     temp->next = temp->next->next;
     
     cout << "4" <<endl;
     //temp1->prev = temp->next;
     //temp->prev->next = temp->next; // or temp1->prev
     //temp->next->prev = temp->prev;
     
     //delete temp;
     cout <<"2" <<endl;
     
     cout << "2" <<endl;
     BNode<kind> *before, *after, *furtherAft;
     
     /*before = temp->prev;
     after = temp->next;
     furtherAft = after->next;
     cout << "here" << endl;
     if (before != NULL){
     before->next = after;
     //furtherAft = after->next;
     cout << "inside the if" << endl;
     }
     else{
     before = NULL;
     }
     
     temp->next = furtherAft;
     temp->prev = after;
     
     after->next = temp;
     after->prev = before;
     
     //temp->next = after->next
     
     
     before = temp->prev;
     after = temp->next;
     furtherAft = temp->next->next;
     
     after->prev = before;
     after->next = temp;
     
     if (before){
     before->next = after;
     }
     
     
     temp->prev = after;
     temp->next = furtherAft;
     
     
     
     
     }
     else
     {
     if (temp->next != NULL){
     cout << "temp and temp->next vals: " << temp->val << ", " << temp->next->val << endl;
     }
     temp = temp->next;
     }
     printNode();
     
     }*/
    for(int i = 0; i <  getSize(); i++){
        current = previous = temp;
        cout << "ok" << endl;
        while(current->next != NULL){
            cout << "before" << endl;
            if (current->val > current->next->val){
                //if (previous == &from){
                //temp1 = previous->prev;
                //}
                temp = current->next;
                current->next = current->next->next;
                temp->next = current;
                
                
                
                
                previous->next = temp;
                if (temp->prev){
                    temp->prev = current->prev->prev;
                }
                else{
                    temp->prev = NULL;
                }
                
                cout << "before" << endl;
                current->prev = temp;
                cout << "after" << endl;
            }
            // move along
            previous = current;
            current = current->next;
            cout << "after move" << endl;
        }
        printNode();
    }
}
template<class kind>
void ListNode<kind>::printNode()
{
    BNode<kind> *temp;
    /*temp = new BNode<kind>;
     temp->front;
     if(front == NULL)
     {
     cout << "List is empty, nothing to display" << endl;
     return;
     }
     */
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
    //temp = front;
    while (front != NULL){
        temp = front->next;
        
        delete front;
        cout << "ok" << endl;
        front = temp;
    }
    delete temp;
    cout << "Done" <<endl;
}

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
        //temp = new BNode<kind>;
        temp = front;
        for(int i = 0; i == index ; i++)
        {
            temp =  temp->next;
        }
        return (temp-> val);
    }
    return front->val;
}


int main()
{
    /*ListNode<int> a;
     a.push_front(5);
     a.push_front(9);
     a.push_front(20);
     a.push_back(6);
     a.push_front(14);
     a.push_back(7);
     a.push_back(12);
     a.push_back(17);
     a.push_back(27);
     cout<< "POP FRONT :" <<a.pop_front()<< endl;
     cout<< "POP BACK :" <<a.pop_back()<< endl;
     cout << a.getSize() - 1 << " is the SIZE" << endl; // fix getsize
     cout << a[0] << " value of first index" << endl;
     BNode<int> front = a.getFront();
     BNode<int> back = a.getBack();
     cout << "presort" << endl;
     
     a.sort(front,back);
     a.printNode();
     */
    {
        cout << "now b" << endl;
        ListNode<int> b;
        b.push_front(1);
        b.push_front(2);
        b.push_front(3);
        
        cout << "size: "<<b.getSize() << endl;
        BNode<int> frontb = b.getFront();
        BNode<int> backb = b.getBack();
        b.printNode();
        b.sort(frontb,backb);
        b.printNode();
    }
    cout << "ok!" <<endl;
    
    
    //a.printNode();
    
}
