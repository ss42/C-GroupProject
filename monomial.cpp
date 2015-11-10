#include <iostream>
#include "linkedList.h"
using namespace std;
class Monomial
{
private:
    double coeff;
	int degree;
public:
    monomial();//default constructor
    Monomial(const Monomial& mono); //copy constructor
    int getDegree() const; //to get degree(highest degree)
    void setDegree(int value); //to set the highest degree(size of the array)
    void readMonomial(); //reads monomial from the user
    void setCoefficient(int k, double value); //sets the coefficient of the monomial
    double getCoefficient(int c) const; //returns the coefficient of the requested degree
    double evaluate(double value); //evaluates the monomial with the given value
    //void copy(const Polynomial& poly); //makes a copy of the polynomial  *** USE THIS IF THE COPY CONSTRUCTOR DOES OT WORK)
    Polynomial operator =(const Polynomial& poly); //assignes a polynomial to a polynomial
    friend Polynomial operator +(const Polynomial& poly1, const Polynomial& poly2); //add two polynomials
    friend Polynomial operator +(double constant, const Polynomial& poly); //adds a constant to a polynomial
    friend Polynomial operator +(const Polynomial& poly, double constant); // adds a polynomial to a constan
    friend Polynomial operator -(const Polynomial& poly1, const Polynomial& poly2); //subtract two polynomials
    friend Polynomial operator -(double constant, const Polynomial& poly); //subtracts a polynomial from a constant
    friend Polynomial operator -(const Polynomial& poly, double constant); //subtracts a constant from a polynomial
    friend Polynomial operator *(const Polynomial& poly1, const Polynomial& poly2); //multiplies two polynomials
    friend Polynomial operator *(double constant, const Polynomial& poly); //multiplies a constant to a polynomial
    friend Polynomial operator *(const Polynomial& poly, double constant); //multiplies a polynomial to a constant
    friend ostream& operator <<(ostream& input, Polynomial& poly); //overloads the output
    ~Polynomial();
};
typedef linkedList<Monomial> Mono;


int main()
{
	Mono p1, p2;
}

