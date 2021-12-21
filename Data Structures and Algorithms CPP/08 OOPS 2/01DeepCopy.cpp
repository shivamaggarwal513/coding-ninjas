#include <iostream>
using namespace std;

class Student
{
private:
    int age;
    char *name;

public:
    Student(int age, char *name)
    {
        this->age = age;

        // Shallow copy
        // this->name = name;

        // Deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Student(const Student &s)
    {
        this->age = s.age;
        
        // Shallow copy
        // this->name = s.name;

        // Deep copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << name << " " << age << "\n";
    }
};

int main()
{
    char name[] = "abcd";
    Student s1(20, name);
    name[0] = 'x';
    Student s2(24, name);
    Student s3(s1);
    s1.display();
    s2.display();
    s3.display();
    return 0;
}