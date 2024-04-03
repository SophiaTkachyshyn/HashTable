#pragma once
#include <iostream>

template<typename K, typename V>
class HashTable {
private:
    static const size_t DEFAULT_SIZE = 100; 
    std::pair<K, V>* pairs; 
    size_t size; 

    size_t getHash(const K& key) const {
        size_t hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % size;
    }

public:
    HashTable(size_t initialSize = DEFAULT_SIZE) : size(0) {
        pairs = new std::pair<K, V>[initialSize](); // Виділення пам'яті для динамічного масиву
        size = initialSize;
    }

     ~HashTable() {
        delete[] pairs; // Звільнення виділеної пам'яті
    }


    void insert(const K& key, const V& value) {
        size_t index = getHash(key);
        pairs[index] = std::make_pair(key, value);
    }

    V& get(const K& key) {
        size_t index = getHash(key);
        return pairs[index].second;
    }

    bool contains(const K& key) {
        size_t index = getHash(key);
        return pairs[index].first == key;
    }

    void remove(const K& key) {
        size_t index = getHash(key);
        pairs[index] = std::pair<K, V>();
    }

    void printTable() const {
        for (size_t i = 0; i < size; ++i) {
            if (!pairs[i].first.empty()) {
                std::cout << "Key: " << pairs[i].first << ", Value: " << pairs[i].second << std::endl;
            }
        }
    }
};
