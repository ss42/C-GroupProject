#include <iostream>
#include "monomial.cpp"
using namespace std;

template<class kind>
class ListNode;

template<class kind>
class BNode;


class Monomial;

int main()
{
    //Monomial<int> mono = Monomial<int>(1,1.5);
    Monomial monoList[]= {Monomial(2,3),Monomial(2,35), Monomial(23,55)};
    Monomial monoList1[]= {Monomial(3,3),Monomial(2,10)};
    
    ListNode<Monomial> monoL1(3, monoList);
    ListNode<Monomial> monoL2(2, monoList1);
    //monoList(mono1);
    //monoList.pushback(mono2);
    ListNode<Monomial> temp(monoL1 + monoL2);
    //temp = monoL1 + monoL2;
    monoL1.printNode();
    monoL2.printNode();
    //result.printNode();
    
}