#include <iostream>

template <typename T>
class StackArray
{
private:
    T *data;
    int topIdx;
    int capacity;

public:
    StackArray(int maxSize = 5)
    {
        data = new T[maxSize];
        topIdx = -1;
        capacity = maxSize;
    }

    void push(T val)
    {
        if (topIdx == capacity - 1)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
                newData[i] = data[i];
            delete []data;
            data = newData;
            capacity *= 2;
        }
        data[++topIdx] = val;
    }

    T pop()
    {
        if (this->isEmpty())
        {
            std::cout << "Stack is empty\n";
            return 0;
        }
        else
            return data[topIdx--];
    }

    T top()
    {
        if (this->isEmpty())
        {
            std::cout << "Stack is empty\n";
            return 0;
        }
        else
            return data[topIdx];
    }

    int size()
    {
        return topIdx + 1;
    }

    bool isEmpty()
    {
        return topIdx == -1;
    }
};