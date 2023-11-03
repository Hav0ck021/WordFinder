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
    Node<typ>* getNode(int position);
public:
    void insertNode(typ d);
    void removeNode(int position);
    void clearMemory();
    void printList();
    void printNode(Node<typ>* node);
    int getSize();
    typ binarySearch(typ goal);
    Node<typ> *sequentialSearch(typ goal);
    void swapData(Node<typ>* node1, Node<typ>* node2);
    void quickSort();
    void quickSort(Node<typ>* left, Node<typ>* right);
    Node<typ>* partition(Node<typ>* left, Node<typ>* right);
};

template <typename typ>
void LinkedList<typ>::swapData(Node<typ>* node1, Node<typ>* node2) {
    if (node1 != nullptr && node2 != nullptr) {
        typ temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
}

template <typename typ>
void LinkedList<typ>::quickSort() {
    Node<typ>* left = begin;
    Node<typ>* right = end;
    quickSort(left, right);
}

template <typename typ>
void LinkedList<typ>::quickSort(Node<typ>* left, Node<typ>* right) {
    if (left != nullptr && right != nullptr && left != right && left->prev != right) {
        Node<typ>* pivot = partition(left, right);
        quickSort(left, pivot->prev);
        quickSort(pivot->next, right);
    }
}

template <typename typ>
Node<typ>* LinkedList<typ>::partition(Node<typ>* left, Node<typ>* right) {
    typ pivot = right->data;
    Node<typ>* i = left->prev;

    for (Node<typ>* j = left; j != right; j = j->next) {
        if (j->data < pivot) {
            i = (i == nullptr) ? left : i->next;
            swapData(i, j);
        }
    }
    i = (i == nullptr) ? left : i->next;
    swapData(i, right);
    return i;
}

template<typename typ>
void LinkedList<typ>::insertNode(typ d){
    Node<typ> *newNode;
    newNode = new Node<typ>();

    newNode->data = d;

    if (size == 0) {
        begin = end = newNode;
    } else {
        newNode->prev = end;
        end->next = newNode;
        end = newNode;
    }
    size++;
}

template<typename typ>
Node<typ>* LinkedList<typ>::getNode(int position){
    if (position < 0 || position > getSize() - 1){
        return nullptr;
    }

    Node<typ>* auxNode;
    int k = getSize() / 2;
    if (position > k ){
        auxNode = end;
        for(int i = getSize() - 1; i > position; i--){
            auxNode = auxNode->prev;
        }
    } else {
        auxNode = begin;
        if (position < k) {
            for (int i = 0; i < position; i++) {
                auxNode = auxNode->next;
            }
        }
    }
    return auxNode;
}

template<typename typ>
void LinkedList<typ>::removeNode(int position){
    Node<typ>* auxNode = getNode(position);

    if (auxNode != nullptr) {
        if (auxNode->next != nullptr) {
            auxNode->next->prev = auxNode->prev;
        }
        if (auxNode->prev != nullptr) {
            auxNode->prev->next = auxNode->next;
        }
        if (position == 0) {
            begin = auxNode->next;
        }
        if (position == size - 1) {
            end = auxNode->prev;
        }

        delete auxNode;
        size--;
    }
}

template<typename typ>
void LinkedList<typ>::clearMemory() {
    while (begin != nullptr && getSize() != 0) {
        removeNode(0);
    }
    end = nullptr;
    cout << "memory has been cleared!" << endl;
}

template<typename typ>
typ LinkedList<typ>::binarySearch(typ goal) {
    Node<typ>* left = begin;
    Node<typ>* right = end;

    Node<typ>* mid = left;
    int midPosition = 0;

    while (mid != right) {
        mid = mid->next;
        midPosition++;
    }

    mid = left;
    for (int i = 0; i < midPosition / 2; i++) {
        mid = mid->next;
    }

    if (mid->data == goal) {
        cout << "The program has found the data! It is -> " << mid->data << endl;
        return mid->data;
    } else if (mid->data < goal) {
        left = mid->next;
    } else {
        right = mid;
    }

    throw std::runtime_error("Element not found in the list");
}
template<typename typ>
void LinkedList<typ>::printNode(Node<typ>* node){
    cout << "dado -> " << node->data << endl;
}

template<typename typ>
void LinkedList<typ>::printList(){
    Node<typ> *auxNode = begin;
    while(auxNode != nullptr){
        printNode(auxNode);
        auxNode = auxNode->next;
    }
}

template<typename typ>
Node<typ> *LinkedList<typ>::sequentialSearch(typ goal) {
    for(Node<typ>* auxNode = begin; auxNode != nullptr; auxNode = auxNode->next){
        if (auxNode->data == goal) {
            cout << "The program has found the data! It is -> " << auxNode->data << endl;
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
