

#ifndef DOUBLY_LINKED_LIST_NODE_H
#define DOUBLY_LINKED_LIST_NODE_H


class Node {
public:
    int value;
    Node* next;
    Node* previous;


    explicit Node(int value);
};


#endif //DOUBLY_LINKED_LIST_NODE_H
