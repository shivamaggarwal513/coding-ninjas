#include <iostream>

template <typename T>
class QueueArray
{
private:
    T *data;
    int rearIndex;
    int frontIndex;
    int queueSize;
    int capacity;

public:
    QueueArray(int maxSize = 5)
    {
        data = new T[maxSize];
        rearIndex = 0;
        frontIndex = -1;
        queueSize = 0;
        capacity = maxSize;
    }

    void enqueue(T val)
    {
        if (queueSize == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = frontIndex; i < capacity; i++)
                newData[i - frontIndex] = data[i];
            for (int i = 0; i < rearIndex; i++)
                newData[i + frontIndex + 1] = data[i];
            
            delete []data;
            data = newData;
            rearIndex = capacity;
            frontIndex = 0;
            capacity *= 2;
        }
        if (frontIndex == -1)
            frontIndex = 0;
        data[rearIndex] = val;
        rearIndex = (rearIndex + 1) % capacity;
        queueSize++;
    }

    T dequeue()
    {
        if (this->isEmpty())
        {
            std::cout << "Queue is empty\n";
            return 0;
        }
        T val = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        queueSize--;
        if (!queueSize)
            rearIndex = 0, frontIndex = -1;
        return val;
    }

    T front()
    {
        if (this->isEmpty())
        {
            std::cout << "Queue is empty\n";
            return 0;
        }
        return data[frontIndex];
    }

    int size()
    {
        return queueSize;
    }

    bool isEmpty()
    {
        return queueSize == 0;
    }
};