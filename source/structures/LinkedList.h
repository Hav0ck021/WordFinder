#ifndef WORDFINDER_LINKEDLIST_H
#define WORDFINDER_LINKEDLIST_H
#include <iostream>
#include <stdexcept>

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
    int size;
    Node<typ>* begin;
    Node<typ>* end;
    Node<typ>* partition(Node<typ>* low, Node<typ>* high);
    void swapData(Node<typ>* a, Node<typ>* b);
public:
    void insertNode(typ d);
    void removeNode(typ id);
    Node<typ>* getNodeByPosition(int position);
    int getSize();

    void quickSort();
    void quickSort(Node<typ>* low, Node<typ>* high);
    void clearMemory();
    typ binarySearch(typ goal);
    Node<typ> *sequentialSearch(typ goal);
    void printList();
};

template <typename typ>
void LinkedList<typ>::swapData(Node<typ>* a, Node<typ>* b) {
    typ temp = a->data;
    a->data = b->data;
    b->data = temp;
}

template <typename typ>
Node<typ>* LinkedList<typ>::partition(Node<typ>* low, Node<typ>* high) {
    typ pivot = high->data;
    Node<typ>* i = low->prev;

    for (Node<typ>* j = low; j != high; j = j->next) {
        if (j->data < pivot) {
            i = (i == nullptr) ? low : i->next;
            swapData(i, j);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swapData(i, high);
    return i;
}

template <typename typ>
void LinkedList<typ>::quickSort() {
    Node<typ>* low = begin;
    Node<typ>* high = end;
    quickSort(low, high);
}

template <typename typ>
void LinkedList<typ>::quickSort(Node<typ>* low, Node<typ>* high) {
    if (high != nullptr && low != high && low != high->next) {
        Node<typ>* pivot = partition(low, high);
        quickSort(low, pivot->prev);
        quickSort(pivot->next, high);
    }
}

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
        delete position;
        cout << "deleted!" << endl;
    }
}

/** template<typename typ>
Node<typ>* LinkedList<typ>::getNodeByID(typ id){
   if (size == 0){
       return nullptr;
   }
   Node<typ>* auxNode = begin;
   while(auxNode != nullptr) {
      if(auxNode->data == id) {
           return auxNode;
        }
       auxNode = auxNode->next;
   }
} **/

template<typename typ>
Node<typ>* LinkedList<typ>::getNodeByPosition(int position){
    if (size == 0 || position > size){
        return nullptr;
    }

    int k = size / 2;
    Node<typ>* auxNode = begin;

    if (position < k){
        for(int i = 0; i < position; i++){
            auxNode = auxNode->next;
        }
    } else {
        auxNode = end;
        for(int i = size - 1; i > position; i--){
            auxNode = auxNode->prev;
        }
    }
    return auxNode;
}

template<typename typ>
void LinkedList<typ>::clearMemory() {
    while (begin != nullptr) {
        removeNode(begin->data);
        clearMemory();
    }
    end = nullptr;
    size = 0;
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

template<typename typ>
Node<typ> *LinkedList<typ>::sequentialSearch(typ goal) {
    for(Node<typ>* auxNode = begin; auxNode != nullptr; auxNode = auxNode->next){
        if (auxNode->data == goal) {
            return auxNode;
        }
    }
    throw std::runtime_error("Element not found in the list");
}

template <typename typ>
int LinkedList<typ>::getSize() {
    return size;
}
#endif //WORDFINDER_LINKEDLIST_H
