//
// Created by caiog on 18/10/2023.
//

#ifndef WORDFINDER_QUEUE_H
#define WORDFINDER_QUEUE_H
#include <iostream>

using namespace std;

template <typename typ>
struct NodeQueue {
    typ data;
    NodeQueue<typ>* prev = nullptr;
    NodeQueue<typ>* next = nullptr;
};

template <typename typ>
class Queue {
private:
    NodeQueue<typ>* begin = nullptr;
    NodeQueue<typ>* end = nullptr;
    int size = 0;

    NodeQueue<typ>* getNode(int position) {
        NodeQueue<typ>* findNode = nullptr;
        if (position >= 0 && position < size) {
            NodeQueue<typ>* pointNode = end;
            for(int i = size - 1; i >= 0; i--, pointNode->prev) {
                if (i == position){
                    findNode = pointNode;
                    break;
                }
            }
        }
        return findNode;
    }

public:
    Queue();
    ~Queue();
    void insertQueue(Queue<typ>& list,typ d);
    NodeQueue<typ>* getNodeByPosition(Queue<typ>& list,int position);
    void deleteQueue(Queue<typ>& list, int position);
};

template<typename typ>
void Queue<typ>::insertQueue(Queue<typ>& list,typ d){
    NodeQueue<typ>* auxNode = new NodeQueue<typ>();

    auxNode->data = d;

    if (list.size == 0) {
        list.begin = list.end = auxNode;
    } else {
        auxNode->prev = list.begin;
        list.end->next = auxNode;
        list.end = auxNode;
    }
    size++;
}

template<typename typ>
NodeQueue<typ>* Queue<typ>::getNodeByPosition(Queue<typ>& list, int position){
    if (list.size == 0 || position > list.size){
        return list;
    }
    int k = 0;
    NodeQueue<typ>* auxNode = list.begin;
    while(k < position) {
        auxNode = auxNode->next;
        ++k;
    }
}

template<typename typ>
void Queue<typ>::deleteQueue(Queue<typ>& list, int position){
    if(list.size == 0){ return; }
    NodeQueue<typ> delNode = getNodeByPosition(list, position);

    (delNode->prev != nullptr) ? (delNode->prev->next = delNode->next) :
    (list.begin = delNode->next);

    (delNode->next != nullptr) ? (delNode->next->prev = delNode->prev) :
    (list.end = delNode->prev);

    delete delNode;
    list.size--;
    cout << "deleted!" << endl;
}

#endif //WORDFINDER_QUEUE_H
