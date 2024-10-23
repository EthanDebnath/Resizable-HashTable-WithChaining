#include "DoublyLinkedListNode.h"

class DoublyLinkedList {
public:
    DoublyLinkedListNode* head;
    DoublyLinkedListNode* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Insert a new node at the end
    void insert(int key, int value) {
        DoublyLinkedListNode* newNode = new DoublyLinkedListNode(key, value);
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    // Remove a node by key
    void remove(int key) {
        DoublyLinkedListNode* current = head;
        while (current) {
            if (current->key == key) {
                if (current->prev) current->prev->next = current->next;
                if (current->next) current->next->prev = current->prev;
                if (current == head) head = current->next;
                if (current == tail) tail = current->prev;
                delete current;
                return;
            }
            current = current->next;
        }
    }

    // Find a node by key
    DoublyLinkedListNode* find(int key) {
        DoublyLinkedListNode* current = head;
        while (current) {
            if (current->key == key) return current;
            current = current->next;
        }
        return nullptr;
    }

    ~DoublyLinkedList() {
        DoublyLinkedListNode* current = head;
        while (current) {
            DoublyLinkedListNode* next = current->next;
            delete current;
            current = next;
        }
    }
};
