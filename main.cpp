#include <iostream>
#include "DoublyLinkedList.h"
#include "Node.h"

using namespace std;

int main(){
    auto* newList = new DoublyLinkedList(34);
    newList->append(23);
    newList->append(11111);
    newList->deleteNode(1);
    newList->printList();

    return 0;

}