#include <iostream>
using namespace std;

class DequeueArray
{
private:
    int *data;
    int rearIndex;
    int frontIndex;
    int dequeueSize;
    int capacity;

public:
    DequeueArray(int maxSize = 5)
    {
        data = new int[maxSize];
        rearIndex = -1;
        frontIndex = -1;
        dequeueSize = 0;
        capacity = maxSize;
    }

    void insertFront(int val)
    {
        if (dequeueSize == capacity)
        {
            cout << "-1\n";
            return;
        }
        if (rearIndex == -1)
            frontIndex = rearIndex = 0;
        else
            frontIndex = frontIndex ? frontIndex - 1 : capacity - 1;
        data[frontIndex] = val;
        dequeueSize++;
    }

    void insertRear(int val)
    {
        if (dequeueSize == capacity)
        {
            cout << "-1\n";
            return;
        }
        if (frontIndex == -1)
            frontIndex = rearIndex = 0;
        else
            rearIndex = (rearIndex + 1) % capacity;
        data[rearIndex] = val;
        dequeueSize++;
    }

    int deleteFront()
    {
        if (!dequeueSize)
            return -1;
        int val = data[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        dequeueSize--;
        if (!dequeueSize)
            frontIndex = rearIndex = -1;
        return val;
    }

    int deleteRear()
    {
        if (!dequeueSize)
            return -1;
        int val = data[rearIndex];
        rearIndex = rearIndex ? rearIndex - 1 : capacity - 1;
        dequeueSize--;
        if (!dequeueSize)
            frontIndex = rearIndex = -1;
        return val;
    }

    int getFront()
    {
        return dequeueSize ? data[frontIndex] : -1;
    }

    int getRear()
    {
        return dequeueSize ? data[rearIndex] : -1;
    }
};

int main()
{
    int q, a, b;
    DequeueArray dq;
    cin >> q;
    while (q--)
    {
        cin >> a;
        switch (a)
        {
            case 1:
                cin >> b;
                dq.insertFront(b);
                break;
            case 2:
                cin >> b;
                dq.insertRear(b);
                break;
            case 3:
                cout << dq.deleteFront() << "\n";
                break;
            case 4:
                cout << dq.deleteRear() << "\n";
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
        }
    }
    return 0;
}