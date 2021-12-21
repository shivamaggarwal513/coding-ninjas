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

    Fraction add(const Fraction &f2) const
    {
        Fraction fNew(numerator * f2.denominator + denominator * f2.numerator, denominator * f2.denominator);
        fNew.simplify();
        return fNew;
    }

    Fraction multiply(const Fraction &f2) const
    {
        Fraction fNew(numerator * f2.numerator, denominator * f2.denominator);
        fNew.simplify();
        return fNew;
    }

    Fraction operator+(const Fraction &f2) const
    {
        Fraction fNew(numerator * f2.denominator + denominator * f2.numerator, denominator * f2.denominator);
        fNew.simplify();
        return fNew;
    }

    Fraction operator*(const Fraction &f2) const
    {
        Fraction fNew(numerator * f2.numerator, denominator * f2.denominator);
        fNew.simplify();
        return fNew;
    }

    bool operator==(const Fraction &f2) const
    {
        return (float)numerator / denominator == (float)f2.numerator / f2.denominator;
    }

    // Pre-increment
    Fraction &operator++()
    {
        numerator += denominator;
        simplify();
        return *this;
    }

    // Post-increment
    Fraction operator++(int)
    {
        Fraction fNew(*this);
        numerator += denominator;
        simplify();
        fNew.simplify();
        return fNew;
    }

    Fraction &operator+=(const Fraction &f2)
    {
        numerator = numerator * f2.denominator + denominator * f2.numerator; 
        denominator *= f2.denominator;
        simplify();
        return *this;
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
    Fraction f3 = f1.add(f2);
    Fraction f4 = f1.multiply(f2);
    Fraction f5 = f1 + f2;
    Fraction f6 = f1 * f2;

    cout << (f3 == f5 ? "+Equal" : "+NotEqual") << "\n";
    cout << (f4 == f6 ? "*Equal" : "*NotEqual") << "\n";

    f1.print();
    f2.print();
    f3.print();
    f4.print();
    f5.print();
    f6.print();

    Fraction f7 = ++(++f6);
    f6.print();
    f7.print();

    Fraction f8 = f7++;
    f7.print();
    f8.print();

    (f8 += f7) += f7;
    f7.print();
    f8.print();
    
    return 0;
}