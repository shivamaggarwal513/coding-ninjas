#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair
{
    T1 x;
    T2 y;

public:
    Pair() {}
    Pair(T1 x, T2 y) : x(x), y(y) {}
    void setX(T1 x) { this->x = x; }
    void setY(T2 y) { this->y = y; }
    T1 getX() { return x; }
    T2 getY() { return y; }
};

int main()
{
    Pair<int, char> p1;
    p1.setX(10);
    p1.setY('F');
    cout << p1.getX() << " " << p1.getY() << "\n";

    Pair<Pair<int, double>, char> p2;
    p2.setX(Pair<int, double> (10, 10.5));
    p2.setY('G');
    cout << p2.getX().getX() << " " << p2.getX().getY() << " " << p2.getY() << "\n";
    
    return 0;
}