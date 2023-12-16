
#include "Node.h"
#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

DoublyLinkedList::DoublyLinkedList(int value) {
    Node* newNode = new Node(value);
    length = 1;
    head = newNode;
    tail = newNode;

}

void DoublyLinkedList::printList() {
    auto* temp = head;
    while(temp){
        cout<<temp->value<<endl;
        temp = temp->next;
    }
}

void DoublyLinkedList::getHead() {
    cout<<this->head->value<<endl;

}

void DoublyLinkedList::getTail() {
    cout<<this->tail->value<<endl;

}

void DoublyLinkedList::getLength() {
    cout<<this->length<<endl;

}

void DoublyLinkedList::append(int value) {
    auto* newNode = new Node(value);

    if (length==0){
        head= newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    length++;

}

void DoublyLinkedList::deleteLast() {
    Node* temp = tail;
    if (length == 0) return;
    else if(length==1) {head = nullptr; tail= nullptr;}
    else {
        tail = tail->previous;
        tail->next = nullptr;
    }
    delete temp;
    length--;
}

void DoublyLinkedList::prepend(int value) {
    auto* newNode = new Node(value);
    if(length == 0){head = newNode; tail = newNode;}
    else{
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
    length++;

}

void DoublyLinkedList::deleteFirst() {
    Node* temp = head;
    if (length == 0) return;
    if(length==1){head = nullptr;tail = nullptr;}
    else{
    head= head->next;
    head->previous = nullptr;
    }
    delete temp;
    length--;

}

Node* DoublyLinkedList::get(int index) {
    Node* temp = head ;
    if(index<0 || index>=length){return nullptr;}
    if(index<length/2){
        for(int i = 0;i<index;i++) {
            temp = temp->next;
        }}
    else{
        temp = tail;
        for(int i = length-1; i>index;i--){
            temp = temp->previous;
        }
    }
    return temp;
}

bool DoublyLinkedList::set(int value, int index) {
    auto* temp = this->get(index);
    if(temp){
    temp->value= value;
    return true;
    }
        return false;

}

bool DoublyLinkedList::insert(int value, int index) {
    if (index<0 || index>length){return false;}
    if (index == 0){prepend(value); return true;}
    if(index == length){ append(value); return true;}
    Node* newNode = new Node(value);
    Node* before = this->get(index-1);
    Node* after = before->next;
    newNode->previous = before;
    newNode->next = after;
    before->next= newNode;
    after->previous = newNode;
    return true;

}

bool DoublyLinkedList::deleteNode(int index) {
    if (index<0 || index>=length){return false;}
    if(index == length-1){deleteLast();return true;}
    if(index == 0){deleteFirst();return true;}
    Node* temp = get(index);
    temp->next->previous = temp->previous;
    temp->previous->next = temp->next;
    length--;
    delete temp;
    return true;
}






