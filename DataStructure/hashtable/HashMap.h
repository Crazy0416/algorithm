//
// Created by 김민호 on 2019-03-03.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

template <class K, class V>
class HashNode {
public:
    K key;
    V val;

public:
    HashNode(K key, V val) : key(key), val(val) {};
};

template <class K, class V>
class HashMap {
private:
    HashNode<K, V>** pHashTable;
    int capacity;
    int _size;

public:
    HashMap() {
        capacity = 20;
        _size = 0;
        pHashTable = new HashNode<K, V>*[capacity];

        for(int i = 0; i < capacity; i++)
            pHashTable[i] = nullptr;
    }

    int hashCode(K key) {
        return key % capacity;
    }

    void insert(K key, V val) {
        int idx = hashCode(key);

        while(pHashTable[idx] != nullptr && pHashTable[idx]->key != key) {
            idx++;
            idx %= capacity;
        }

        if(pHashTable[idx] == nullptr)
            _size++;

        pHashTable[idx] = new HashNode<K, V> (key, val);
    }

    bool remove(K key) {
        int idx = hashCode(key);

        while(pHashTable[idx] != nullptr) {
            if(pHashTable[idx]->key == key) {
                delete pHashTable[idx];
                _size--;
                return true;
            }
            idx++;
            idx %= capacity;
        }
        return false;
    }

    V find(K key) {
        int idx = hashCode(key);
        int count = 0;

        while(pHashTable[idx] != nullptr) {
            if(count++ > capacity)
                return nullptr;

            if(pHashTable[idx]->key == key) {
                return pHashTable[idx]->val;
            }
            idx++;
            idx %= capacity;
        }
        return nullptr;
    }

    int size() {
        return _size;
    }

    bool isEmpty() {
        return _size == 0;
    }
};


#endif //HASHTABLE_HASHTABLE_H
