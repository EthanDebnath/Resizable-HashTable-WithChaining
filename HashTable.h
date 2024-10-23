#include "DoublyLinkedList.h"
#include <cmath>

class HashTable {
private:
    DoublyLinkedList** table;
    int capacity;
    int size;

    float loadFactor() const {
        return static_cast<float>(size) / capacity;
    }

    int hashFunction(int key) const {
        // Multiplication method with a constant A (in this case, a fraction)
        const float A = 0.6180339887; // Example fraction (commonly used golden ratio)
        return int(capacity * fmod(key * A, 1));  // Returns index based on multiplication method
    }

    void rehash(int newCapacity) {
        DoublyLinkedList** oldTable = table;
        int oldCapacity = capacity;

        // Create a new table with the new capacity
        capacity = newCapacity;
        table = new DoublyLinkedList*[capacity]();
        size = 0;

        // Rehash all the elements in the old table
        for (int i = 0; i < oldCapacity; ++i) {
            if (oldTable[i]) {
                DoublyLinkedListNode* current = oldTable[i]->head;
                while (current) {
                    insert(current->key, current->value);
                    current = current->next;
                }
                delete oldTable[i];
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int initialCapacity = 8) : capacity(initialCapacity), size(0) {
        table = new DoublyLinkedList*[capacity]();
    }

    // Insert a key-value pair
    void insert(int key, int value) {
        int index = hashFunction(key);
        if (!table[index]) {
            table[index] = new DoublyLinkedList();
        }
        
        DoublyLinkedListNode* existingNode = table[index]->find(key);
        if (existingNode) {
            existingNode->value = value;  // Update value if key already exists
        } else {
            table[index]->insert(key, value);
            size++;
        }

        // Resize if load factor > 0.75 (grow the table)
        if (loadFactor() > 0.75) {
            rehash(capacity * 2);
        }
    }

    // Remove a key-value pair
    void remove(int key) {
        int index = hashFunction(key);
        if (table[index]) {
            table[index]->remove(key);
            size--;
        }

        // Resize if load factor < 0.25 (shrink the table)
        if (loadFactor() < 0.25 && capacity > 8) {
            rehash(capacity / 2);
        }
    }

    // Find a value by key
    int find(int key) const {
        int index = hashFunction(key);
        if (table[index]) {
            DoublyLinkedListNode* node = table[index]->find(key);
            if (node) return node->value;
        }
        return -1;  // Indicate key not found
    }

    ~HashTable() {
        for (int i = 0; i < capacity; ++i) {
            if (table[i]) delete table[i];
        }
        delete[] table;
    }
};
