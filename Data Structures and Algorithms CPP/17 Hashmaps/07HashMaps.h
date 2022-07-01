#include <iostream>
#include <string>
#define PRIME 37

template <typename V>
class HashMaps;

template <typename V>
class ListNode
{
private:
    std::string key;
    V value;
    ListNode<V> *next;

    friend class HashMaps<V>;

public:
    ListNode() 
    : next(nullptr) {}

    ListNode(std::string key) 
    : key(key), value(0), next(nullptr) {}

    ListNode(std::string key, V value) 
    : key(key), value(value), next(nullptr) {}

    ListNode(std::string key, V value, ListNode *next) 
    : key(key), value(value), next(next) {}

    ~ListNode() { delete next; }
};

template <typename V>
class HashMaps
{
private:
    ListNode<V> **bucket;
    int mapSize;
    int bucketSize;

    int hashFunction(std::string key)
    {
        int idx = 0, coeff = 1;
        for (std::string::reverse_iterator it = key.rbegin(); it != key.rend(); it++)
        {
            idx += (*it) * coeff;
            idx %= bucketSize;
            coeff *= PRIME;
            coeff %= bucketSize;
        }
        return idx % bucketSize;
    }

    void reHash()
    {
        int oldBucketSize = bucketSize, i;
        ListNode<V> **oldBucket = bucket;
        mapSize = 0;
        bucketSize *= 2;
        bucket = new ListNode<V>*[bucketSize];
        for (i = 0; i < bucketSize; i++)
            bucket[i] = nullptr;
        for (i = 0; i < oldBucketSize; i++)
        {
            for (ListNode<V> *temp = oldBucket[i]; temp; temp = temp->next)
                insert(temp->key, temp->value);
            delete oldBucket[i];
        }
        delete []oldBucket;
    }

public:
    HashMaps()
    {
        mapSize = 0;
        bucketSize = 5;
        bucket = new ListNode<V>*[bucketSize];
        for (int i = 0; i < bucketSize; i++)
            bucket[i] = nullptr;
    }

    void insert(std::string key, V value)
    {
        int idx = hashFunction(key);
        ListNode<V> *head = bucket[idx];
        for (ListNode<V> *temp = head; temp; temp = temp->next)
        {
            if (temp->key == key)
            {
                temp->value = value;
                return;
            }
        }
        ListNode<V> *newHead = new ListNode<V>(key, value, head);
        bucket[idx] = newHead;
        mapSize++;
        if (loadFactor() > 0.7)
            reHash();
    }

    V at(std::string key)
    {
        for (ListNode<V> *temp = bucket[hashFunction(key)]; temp; temp = temp->next)
            if (temp->key == key)
                return temp->value;
        return 0;
    }

    V erase(std::string key)
    {
        int idx = hashFunction(key);
        ListNode<V> *head = bucket[idx];
        ListNode<V> *temp = head, *prev = nullptr;
        while (temp)
        {
            if (temp->key == key)
            {
                if (prev)
                    prev->next = temp->next;
                else
                    bucket[idx] = temp->next;
                V value = temp->value;
                temp->next = nullptr;
                delete temp;
                mapSize--;
                return value;
            }
            prev = temp;
            temp = temp->next;
        }
        return 0;
    }

    int size() { return mapSize; }

    double loadFactor() { return (double)mapSize / (double)bucketSize; }

    ~HashMaps()
    {
        for (int i = 0; i < bucketSize; i++)
            delete bucket[i];
        delete []bucket;
    }
};