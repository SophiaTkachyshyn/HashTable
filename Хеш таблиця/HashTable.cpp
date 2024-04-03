#include<iostream>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable<std::string, int> myHashTable;

    myHashTable.insert("apple", 10);
    myHashTable.insert("banana", 20);
    myHashTable.insert("orange", 30);

    std::cout << "HashTable contents:" << std::endl;
    myHashTable.printTable();

    std::cout << "Value for key 'banana': " << myHashTable.get("banana") << std::endl;

    std::cout << "Does 'apple' exist in HashTable? " << (myHashTable.contains("apple") ? "Yes" : "No") << std::endl;

    myHashTable.remove("apple");

    std::cout << "HashTable contents after removing 'apple':" << std::endl;
    myHashTable.printTable();

    return 0;
}