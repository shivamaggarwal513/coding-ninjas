#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;
    static int totalStudents;

public:
    Student()
    {
        totalStudents++;
    }

    static int getTotalStudents() { return totalStudents; }
};

int Student::totalStudents = 0;

int main()
{
    Student s1, s2;
    cout << Student::getTotalStudents() << "\n";
    return 0;
}