

#ifndef DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
#define DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
#include "Node.h"

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length = 0;

public:
    explicit DoublyLinkedList(int value);
    DoublyLinkedList() = default;
    void printList();
    void getHead();
    void getTail();
    void getLength();
    void append(int value);
    void deleteLast();
    void prepend(int value);
    void deleteFirst();
    Node* get(int index);
    bool set(int value,int index);
    bool insert(int value,int index);
    bool deleteNode(int index);
};


#endif //DOUBLY_LINKED_LIST_DOUBLYLINKEDLIST_H
