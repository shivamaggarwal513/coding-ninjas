#include <iostream>
using namespace std;

class Student
{
public:
    int age;
    const int rollNo;
    int &x;

    Student(int age, int rollNo) : age(age), rollNo(rollNo), x(this->age) {}
};

int main()
{
    Student s1(20, 101);
    return 0;
}