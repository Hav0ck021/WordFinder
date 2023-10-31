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
    void insertNode(typ d);
    void removeNode(typ id);
    bool compareDataNode(typ data1, typ data2);
    Node<typ>* getNodeByID(typ id);
    Node<typ>* getNodeByPosition(int position);
    void clearMemory();
    void bubbleSort();
    typ binarySearch(typ goal);
    typ sequentialSearch(typ goal);
    void printList();
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
void LinkedList<typ>::removeNode(typ id){
    Node<typ>* position = getNodeByID(id);

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
        cout << "deleted!" << endl;
        delete position;
    }
}

template<typename typ>
bool compareDataNode(typ data1, typ data2){
    return (strcmp(data1, data2) == 0);
}

template<typename typ>
Node<typ>* LinkedList<typ>::getNodeByID(typ id){
    if (size == 0 || id > size){
        return nullptr;
    }
    Node<typ>* auxNode = begin;

    while(auxNode != nullptr) {
        if(auxNode->data == id) {
            return auxNode;
        }
        auxNode = auxNode->next;
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
    return auxNode;
}

template<typename typ>
void LinkedList<typ>::clearMemory() {
    Node<typ>* auxNode = end;
    while (auxNode != nullptr) {
        removeNode(auxNode->data);
        auxNode = auxNode->prev;
    }
}

template<typename typ>
void LinkedList<typ>::bubbleSort(){
    if (begin == end || begin == nullptr || end == nullptr) {
        return;
    }
    bool changed;

    do {
        changed = false;
        Node<typ>* currentNode = begin;
        Node<typ>* nextNode = currentNode->next;

        while (nextNode != nullptr){
            if (currentNode->data > currentNode->next->data) {
                typ tempData = currentNode->data;
                currentNode->data = currentNode->next->data;
                currentNode->next->data = tempData;

                changed = true;
            }
            currentNode = nextNode;
            nextNode = nextNode->next;
        }
    } while (changed);
}

template<typename typ>
typ LinkedList<typ>::binarySearch(typ goal) {
    Node<typ>* left = begin;
    Node<typ>* right = end;

    Node<typ>* mid = left;

    for (int i = 0; i < size / 2; i++) {
        mid = mid->next;
    }

    while (left != nullptr && left != right) {
        if (mid->data == goal) {
            cout << "The program has found the data! It is -> " << mid->data << endl;
            return mid->data;
        } else if (mid->data != goal) {
            left = mid->next;
        } else {
            right = mid;
        }
    }

    cout << "Not found." << endl;
    return nullptr;
}

template<typename typ>
void LinkedList<typ>::printList(){
    Node<typ> *auxNode = begin;
    while(auxNode != nullptr){
        cout << "dado -> " << auxNode->data << endl;
        auxNode = auxNode->next;
    }
}

#endif //WORDFINDER_LINKEDLIST_H
