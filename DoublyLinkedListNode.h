struct DoublyLinkedListNode {
    int key;
    int value;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;

    DoublyLinkedListNode(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};
