#include "IntLinkedList.h"

#include <cassert>

//Initialize static varaible used for debugging
int ListNode::nodeCount = 0;


LinkedList::LinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
}

LinkedList::~LinkedList() {
    //TODO - actually delete all nodes

    cout << "Just destroyed a list. There are "
         << ListNode::nodeCount << " total nodes left in the program.\n";
}


LinkedList::LinkedList(const LinkedList& other) {
    //TODO - Write copy constructor...
    //Don't forget to initialize head/tail/length

    assert(0);  //blow up for now
}


LinkedList& LinkedList::operator=(const LinkedList& other) {
    if(this != &other) {
        //TODO - delete all existing nodes
        //TODO - copy nodes from other list
        assert(0);  //blow up for now
    }
    return *this;
}


void LinkedList::print() const {
    //current will point to each element in turn
    ListNode* current = head;

    while(current != nullptr) {
        cout << current->data << " ";   //print current item
        current = current->next;        //advance to next
    }
    cout << endl;
}


void LinkedList::insertStart(int value) {
    ListNode* temp = new ListNode(value);

    temp->next = head;  //old head is what new node points to
    head = temp;        //new node is now head

    //if there is no second node, new node is both head and tail
    if(head->next == nullptr)
        tail = head;

    length++;
}


void LinkedList::insertEnd(int value) {
    //TODO - Implement me
}

void LinkedList::removeEnd() {
    //TODO - Implement me
}



void LinkedList::removeFirst() {
    if(head == nullptr)
        throw out_of_range("Can't remove from empty list");

    ListNode* targetNode = head;

    head = head->next;  //find new head

    //Check to see if the nodes we are deleting was also the tail
    if(targetNode == tail) {
        tail = nullptr;
    }

    delete targetNode;

    length--;
}

void LinkedList::insertAt(int index, int value) {
    //TODO - Insert value at given location of list
    //This version needs to think about the tail pointer
}

void LinkedList::removeAt(int index) {
    if(index < 0 || index >= length)
        throw out_of_range("Bad index in removeAt");

    if(index == 0) {
        //First item is special case... use removeFirst for it
        removeFirst();
        return;
    }

    //Find node BEFORE one we want to delete - it is "current"
    ListNode* current = head;
    for(int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    ListNode* nodeToRemove = current->next;

    //Cut node out of list
    current->next = nodeToRemove->next;

    delete nodeToRemove;    //Delete it from heap

    //Is there nothing left after current node? Then it is the new tail
    if(current->next == nullptr)
        tail = current;

    length--;
}

int LinkedList::listSize() const {
    return length;
}

int LinkedList::retrieveAt(int index) const {
    if(index < 0 || index >= length)
        throw out_of_range("Bad index in retrieveAt");

    ListNode* current = head;
    for(int stepsLeft = index; stepsLeft > 0; stepsLeft--) {
        current = current->next;
        //know those steps are safe, since we checked index against length
    }

    return current->data;
}
