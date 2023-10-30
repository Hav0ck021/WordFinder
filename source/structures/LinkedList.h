#ifndef WORDFINDER_LINKEDLIST_H
#define WORDFINDER_LINKEDLIST_H
#include <iostream>

using namespace std;

template <typename typ>
struct Node {
    typ data;
    Node<typ>* prev = nullptr;
    Node<typ>* next = nullptr;
};

template <typename typ>
class LinkedList {
private:
    int size = 0;
    Node<typ>* begin = nullptr;
    Node<typ>* end = nullptr;


public:
    LinkedList();
    ~LinkedList();
    void insertNode(typ d);
    void removeNode(int position);
    Node<typ>* getNodeByPosition(int position);
    void deleteNode(int position);
    void clearMemory();
    void bubbleSort();
    Node<typ>* partition();
    void quickSort();
    void quickSort(Node<typ>* low, Node<typ>* high);
    typ binarySearch(typ goal);
};

template<typename typ>
void LinkedList<typ>::insertNode(typ d){
    Node<typ>* auxNode = new Node<typ>();

    auxNode->data = d;

    if (size == 0) {
        begin = end = auxNode;
    } else {
        auxNode->prev = begin;
        end->next = auxNode;
        end = auxNode;
    }
    size++;
}

template<typename typ>
void LinkedList<typ>::removeNode(int id){
    Node<typ>* position = binarySearch(id);

    if (position != nullptr) {
        if (position->prev != nullptr) {
            position->prev->next = position->next;
        } else {
            begin = position->next;
        }

        if (position->next != nullptr) {
            position->next->prev = position->prev;
        } else {
            end = position->prev;
        }

        delete position;
    }
}

template<typename typ>
Node<typ>* LinkedList<typ>::getNodeByPosition(int position){
    if (size == 0 || position > size){
        return nullptr;
    }
    int k = 0;
    Node<typ>* auxNode = begin;

    while(k < position) {
        auxNode = auxNode->next;
        ++k;
    }
}

template<typename typ>
void LinkedList<typ>::deleteNode(int position){
    if(size == 0){ return; }
    Node<typ> delNode = getNodeByPosition(position);

    (delNode->prev != nullptr) ? (delNode->prev->next = delNode->next) :
    (begin = delNode->next);

    (delNode->next != nullptr) ? (delNode->next->prev = delNode->prev) :
    (end = delNode->prev);

    delete delNode;
    size--;
    cout << "deleted!" << endl;
}

template<typename typ>
void LinkedList<typ>::clearMemory() {
    while (size > 0)
    {
        Node<typ>* auxNode = end;
        end = end->previous;
        delete auxNode;
        size--;
    }
    begin = end = nullptr;
}

template<typename typ>
void LinkedList<typ>::bubbleSort(){
    if (begin == end) {
        return;
    }

    bool changed;
    Node<typ>* lastUnsortedNode = nullptr;

    do {
        changed = false;
        Node<typ>* currentNode = begin;

        while (currentNode->next != lastUnsortedNode){
            if (currentNode->data > lastUnsortedNode->next->data) {
                typ tempData = currentNode->data;
                currentNode->data = currentNode->next->data;
                currentNode->next->data = tempData;

                changed = true;
            }
            currentNode = currentNode->next;
        }
        lastUnsortedNode = currentNode;

    } while (changed);
}

template<typename typ>
Node<typ>* LinkedList<typ>::partition(){
    if (begin == end)
        return nullptr;

    typ tempData, pivot = end->data;
    Node<typ>* i = begin->prev;

    for(Node<typ>* j = begin; j != end; j = j->next){
        if(j->data <= pivot){
            i = (i == nullptr) ? begin : i->next;

            tempData = i->data;
            i->data = j->data;
            j->data = tempData;
        }
    }
    i = (i == nullptr) ? begin : i->next;

    tempData = i->data;
    i->data = end->data;
    end->data = tempData;

    return i;
}

template<typename typ>
void LinkedList<typ>::quickSort() {
    quickSort(begin, end);
}

template<typename typ>
void LinkedList<typ>::quickSort(Node<typ>* low, Node<typ>* high){
    if(low < high && low != high && low != nullptr && high != nullptr){
        Node<typ>* pivot = partition();
        quickSort(begin, pivot->prev);
        quickSort(pivot->next, end);
    }
}

template<typename typ>
typ LinkedList<typ>::binarySearch(typ goal) {
    while (begin != end && begin == nullptr && end == nullptr) {
        Node<typ>* auxNode = begin;

        while (auxNode != end){
            auxNode = (goal >= auxNode->data) ?
                      (auxNode->next) :
                      (auxNode->prev);
        }

        if (auxNode->data == goal){
           return auxNode->data;
        } else {
            (goal > auxNode->data) ?
            (begin = auxNode->next) :
            (end = auxNode->prev);
        }
    }
    cout << "Not found." << endl;
    return -1;
}

#endif //WORDFINDER_LINKEDLIST_H
