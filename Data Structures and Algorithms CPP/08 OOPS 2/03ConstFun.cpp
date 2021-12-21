#include <iostream>
using namespace std;

int __gcd(int m, int n)
{
    if (m == 0)
        return n;
    return __gcd(n % m, m);
}

class Fraction
{
private:
    int numerator, denominator;

public:
    Fraction(int numerator, int denominator)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int getNum() const { return numerator; }

    int getDen() const { return denominator; }

    void setNum(int numerator) { this->numerator = numerator; }

    void setDen(int denominator) { this->denominator = denominator; }
    
    void print() const { cout << numerator << "/" << denominator << "\n"; }

    void add(const Fraction &f2)
    {
        numerator = numerator * f2.denominator + denominator * f2.numerator;
        denominator = denominator * f2.denominator;
        simplify();
    }

    void multiply(const Fraction &f2)
    {
        numerator *= f2.numerator;
        denominator *= f2.denominator;
        simplify();
    }

    void simplify()
    {
        int gcd = __gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }
};

int main()
{
    Fraction f1(10, 2), f2(15, 4);
    f1.print(); f2.print();
    f1.add(f2);
    f1.print(); f2.print();
    f1.multiply(f2);
    f1.print(); f2.print();
    return 0;
}