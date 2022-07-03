#include <vector>
#include <utility>

template <typename T>
class MinPriorityQueue
{
private:
    std::vector<T> arr;

    int parentChildMin(int &pI)
    {
        int min = pI, lC = 2 * pI + 1, rC = 2 * pI + 2;
        if (lC < arr.size() && arr[lC] < arr[min])
            min = lC;
        if (rC < arr.size() && arr[rC] < arr[min])
            min = rC;
        return min;
    }

public:
    MinPriorityQueue() {}

    void insert(T val)
    {
        arr.push_back(val);
        int cI = arr.size() - 1, pI = (cI - 1) / 2;
        while (cI > 0 && arr[cI] < arr[pI])
        {
            std::swap(arr[cI], arr[pI]);
            cI = pI;
            pI = (cI - 1) / 2;
        }
    }

    T remove()
    {
        if (arr.empty())
            return 0;
        T val = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        int pI = 0, cI = parentChildMin(pI);
        while (cI != pI)
        {
            std::swap(arr[pI], arr[cI]);
            pI = cI;
            cI = parentChildMin(pI);
        }
        return val;
    }

    T getMin() { return arr.empty() ? 0 : arr[0]; }

    bool isEmpty() { return arr.empty(); }

    int size() { return arr.size(); }
};

template <typename T>
class MaxPriorityQueue
{
private:
    std::vector<T> arr;

    int parentChildMax(int &pI)
    {
        int max = pI, lC = 2 * pI + 1, rC = 2 * pI + 2;
        if (lC < arr.size() && arr[lC] > arr[max])
            max = lC;
        if (rC < arr.size() && arr[rC] > arr[max])
            max = rC;
        return max;
    }

public:
    MaxPriorityQueue() {}

    void insert(T val)
    {
        arr.push_back(val);
        int cI = arr.size() - 1, pI = (cI - 1) / 2;
        while (cI > 0 && arr[cI] > arr[pI])
        {
            std::swap(arr[cI], arr[pI]);
            cI = pI;
            pI = (cI - 1) / 2;
        }
    }

    T remove()
    {
        if (arr.empty())
            return 0;
        T val = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        int pI = 0, cI = parentChildMax(pI);
        while (cI != pI)
        {
            std::swap(arr[pI], arr[cI]);
            pI = cI;
            cI = parentChildMax(pI);
        }
        return val;
    }

    T getMax() { return arr.empty() ? 0 : arr[0]; }

    bool isEmpty() { return arr.empty(); }

    int size() { return arr.size(); }
};