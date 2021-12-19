#include <iostream>
using namespace std;

class ComplexNumber
{
private:
    int real, img;

public:
    ComplexNumber(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void print()
    {
        // cout << real << " " << (img >= 0 ? "+ " : "- ") << abs(img) << "j\n";
        cout << real << " + i" << img << "\n";
    }

    void plus(const ComplexNumber &c2)
    {
        real += c2.real;
        img += c2.img;
    }

    void multiply(const ComplexNumber &c2)
    {
        int realTemp = real * c2.real - img * c2.img;
        img = real * c2.img + img * c2.real;
        real = realTemp;
    }
};

int main()
{
    int real1, real2, img1, img2;
    cin >> real1 >> img1;
    cin >> real2 >> img2;

    ComplexNumber c1(real1, img1), c2(real2, img2);
    
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    
    return 0;
}