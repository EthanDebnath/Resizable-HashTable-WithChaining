# Resizable-HashTable-WithChaining
Resizable hash table with custom hash functions and chaining for collision resolution implemented in C++, supporting dynamic growth and shrinking.


I'm implementing a resizable hash table in C++ with collision resolution using chaining. The chaining is handled by custom doubly linked lists, and the hash table supports dynamic resizing based on its load factor.

The hash table uses the **multiplication** and **division** methods for its hash functions, and it automatically grows or shrinks as needed when the load factor exceeds or falls below certain thresholds.

## Features

- **Generic Hashing**: Supports both the multiplication and division methods for hash functions.
- **Doubly Linked List Chaining**: Resolves collisions by chaining using doubly linked lists.
- **Resizable**: Automatically doubles in size when the table becomes full (load factor > 0.75) and halves when it becomes underutilized (load factor < 0.25).
- **C-Style Arrays**: Implemented using raw C-style arrays without using C++ standard library containers.
- **Custom Collision Handling**: Implements custom chaining using a doubly linked list for collision resolution.

## Hash Function

The hash function uses the multiplication method with a constant `A` derived from the golden ratio (`A = 0.6180339887`). The division method is also employed for flexibility and completeness.

```cpp
int hashFunction(int key) const {
    const float A = 0.6180339887;
    return int(capacity * fmod(key * A, 1));
}
