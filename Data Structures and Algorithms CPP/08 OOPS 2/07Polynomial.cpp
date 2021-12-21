#include <iostream>
using namespace std;

class Polynomial
{
    int *coeff;
    int capacity;

public:
    Polynomial(int capacity = 5)
    {
        coeff = new int[capacity];
        this->capacity = capacity;
        for (int i = 0; i < capacity; i++)
            coeff[i] = 0;
    }

    Polynomial(const Polynomial &P)
    {
        this->capacity = P.capacity;
        this->coeff = new int[P.capacity];
        for (int i = 0; i < P.capacity; i++)
            this->coeff[i] = P.coeff[i];
    }

    void setCoefficient(int degree, int coefficient)
    {
        if (degree >= capacity)
        {
            int *newCoeff = new int[degree + 1];
            for (int i = 0; i < capacity; i++)
                newCoeff[i] = coeff[i];
            for (int i = capacity; i < degree; i++)
                newCoeff[i] = 0;
            
            delete []coeff;
            capacity = degree + 1;
            coeff = newCoeff;
        }
        coeff[degree] = coefficient;
    }

    Polynomial operator+(const Polynomial &P2) const
    {
        int maxCap = max(this->capacity, P2.capacity);
        int minCap = min(this->capacity, P2.capacity);
        Polynomial P3(maxCap);

        for (int i = 0; i < minCap; i++)
            P3.coeff[i] = this->coeff[i] + P2.coeff[i];
        
        int *temp = (minCap == this->capacity) ? P2.coeff : this->coeff;

        for (int i = minCap; i < maxCap; i++)
            P3.coeff[i] = temp[i];
        
        return P3;
    }

    Polynomial operator-(const Polynomial &P2) const
    {
        int maxCap = max(this->capacity, P2.capacity);
        int minCap = min(this->capacity, P2.capacity);
        Polynomial P3(maxCap);

        for (int i = 0; i < minCap; i++)
            P3.coeff[i] = this->coeff[i] - P2.coeff[i];
        
        int *temp = (minCap == this->capacity) ? P2.coeff : this->coeff;
        int sign = (minCap == this->capacity) ? -1 : 1;

        for (int i = minCap; i < maxCap; i++)
            P3.coeff[i] = sign * temp[i];
        
        return P3;
    }

    Polynomial operator*(const Polynomial &P2) const
    {
        Polynomial P3(this->capacity * P2.capacity);
        
        for (int i = 0; i < this->capacity; i++)
            for (int j = 0; j < P2.capacity; j++)
                P3.coeff[i + j] += this->coeff[i] * P2.coeff[j];
        
        return P3;
    }

    void operator=(const Polynomial &P2)
    {
        this->capacity = P2.capacity;
        this->coeff = new int[P2.capacity];
        for (int i = 0; i < P2.capacity; i++)
            this->coeff[i] = P2.coeff[i];
    }

    void print() const
    {
        for (int i = 0; i < capacity; i++)
            if (coeff[i] != 0)
                cout << coeff[i] << "x" << i << " ";
        cout << "\n";
    }

    ~Polynomial()
    {
        delete []coeff;
    }
};

int main()
{
    int n, m, i;

    cin >> n;
    Polynomial P1;
    int *P1Deg = new int[n];
    int P1Coeff;

    for (i = 0; i < n; i++)
        cin >> P1Deg[i];
    for (i = 0; i < n; i++)
    {
        cin >> P1Coeff;
        P1.setCoefficient(P1Deg[i], P1Coeff);
    }
    delete []P1Deg;

    cin >> m;
    Polynomial P2;
    int *P2Deg = new int[m];
    int P2Coeff;

    for (i = 0; i < m; i++)
        cin >> P2Deg[i];
    for (i = 0; i < m; i++)
    {
        cin >> P2Coeff;
        P2.setCoefficient(P2Deg[i], P2Coeff);
    }
    delete []P2Deg;

    Polynomial P3;
    int choice;
    cin >> choice;

    if (choice == 1)
        P3 = P1 + P2;
    else if (choice == 2)
        P3 = P1 - P2;
    else if (choice == 3)
        P3 = P1 * P2;
    
    P3.print();

    return 0;
}