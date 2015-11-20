#include <iostream>
#include "linkedList.cpp"
using namespace std;

template<class kind>
class ListNode;

template<class kind>
class BNode;
ListNode<Monomial> operator +(ListNode<Monomial>& list1, ListNode<Monomial>& list2);
ListNode<Monomial> operator *(ListNode<Monomial>& list1, ListNode<Monomial>& list2);
ListNode<Monomial> listClean(ListNode<Monomial> &poly);
//function declarations

class Monomial
{
private:
    int degree;
    double coefficient;
public:
    Monomial();
    Monomial(int deg, double coeff);//: degree(deg), coefficient(coeff){};
    
    int getDegree() {return degree;}
    void setDegree(int deg){degree = deg; }

    double getCoefficient(){return coefficient;}
    void setCoefficient(double coeff){coefficient = coeff;}
    friend class ListNode<Monomial>;
    friend class BNode<Monomial>;
    
};
/*
Monomial() : default construtor
*/

Monomial::Monomial()
{
    degree = 0;
    coefficient = 0;
}

/*
Monomial() : default construtor that sets degree and coefficient
*/
Monomial::Monomial(int deg, double coeff)
{
    degree = deg;
    coefficient = coeff;
}
/*
operator +(ListNode<Monomial>& list1, ListNode<Monomial>& list2) is an operation overloader.
This function is not the member of any class.
*/
ListNode<Monomial> operator +(ListNode<Monomial>& list1, ListNode<Monomial>& list2)
{
    ListNode<Monomial> tempList1, tempList2, final;
    tempList1 = list1;
    tempList2 = list2;
    
    BNode<Monomial> *p1;

    for(p1 = tempList1.getFront(); p1!= NULL; p1 = p1->getNext())
    {
        tempList2.push_back(p1->getVal());
    }
    tempList2.sortNode();
    cout << "tempList2 " << endl;
    tempList2.printNode();
    final = listClean(tempList2);
    return final;    
}
/*
listClean(ListNode<Monomial> &poly) : adds two polynomials with same degrees and returns the list.
This function is not the member of any class.
*/
ListNode<Monomial> listClean(ListNode<Monomial> &poly)
{
    BNode<Monomial> *pointer;
    ListNode<Monomial> finalList, temp;

    for (pointer = poly.getFront(); pointer->getNext() != NULL; pointer = pointer->getNext())
    {   
        if (pointer->getVal().getDegree() == pointer->getNext()->getVal().getDegree())
        {
            double tempCoef = pointer->getVal().getCoefficient() + pointer->getNext()->getVal().getCoefficient();
            int tempDeg = pointer->getVal().getDegree();
            finalList.push_back(Monomial(tempDeg , tempCoef));
            pointer = pointer->getNext();
        }
        else
        {
            int tempDeg = pointer->getVal().getDegree();
            double tempCoef = pointer->getVal().getCoefficient();
            finalList.push_back(Monomial(tempDeg , tempCoef));
        }
    }
    pointer = poly.getBack();
    finalList.push_back(pointer->getVal());
    return finalList;
}
/*
operator *(ListNode<Monomial>& list1, ListNode<Monomial>& list2) is an operation overloader.
This function is not the member of any class.
*/
ListNode<Monomial> operator *(ListNode<Monomial>& list1, ListNode<Monomial>& list2)
{
    BNode<Monomial> *p1 = list1.getFront();
    BNode<Monomial> *p2 = list2.getFront();
    ListNode<Monomial>  result;

    for (int i = 0; i < list1.getSize(); i++)
    {
        for (int j = 0; j < list2.getSize(); j ++)
        {
            double coeffSum = p1 -> getVal().getCoefficient() * p2 -> getVal().getCoefficient();
            int degreeSum = p1->getVal().getDegree() + p2->getVal().getDegree();
            
            result.push_back(Monomial(degreeSum , coeffSum));
            p2 = p2 -> getNext();
        }
        p1 = p1 -> getNext();
        p2 = list2.getFront();
    }
    
    return result;
}

int main()
{
    Monomial monoList[]= {Monomial(2,2),Monomial(12,3), Monomial(33,1)};
    Monomial monoList1[]= {Monomial(1,5),Monomial(3,2), Monomial(2,3), Monomial(10,6)};
    
    ListNode<Monomial> monoL1(3, monoList);
    ListNode<Monomial> monoL2(4, monoList1);

    ListNode<Monomial> multiply(monoL1 * monoL2);
    ListNode<Monomial> add(monoL1 + monoL2);

    cout << " 1st sparse polynomial: " ;
    monoL1.printNode();
    
    cout << " 2st sparse polynomial: ";
    monoL2.printNode();
    
    cout << " Multiplication of the two sparse polynomial: ";
    multiply.printNode();
    
    cout << " Addition of the two sparse polynomial: ";
    add.printNode();
    
}

