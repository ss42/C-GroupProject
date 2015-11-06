template <class S>
class Bnode
{
	private:
		S val;
		BNode<S> *prev, *next;
		public:
			//constructors
			Bnode();//default constructor
			Bnode();//copy constructors
			S pop_back();
			destructor();
};
template <class T>
class List
{
private:
	Bnode<S> *front, *back;
	int size;
public:
	//constructors
	List();//default constructor
    bool empty(); //boolean accessor that indicates whether the Blist is empty
	void push_front(T a);
	void push_back(T a);
	T pop_back();
	T pop_front();
    insert(T data, Bnode<S> p);//insert data after the pointer p
    ~List();
	
	//delete method
	//constructors and destructors needed
};