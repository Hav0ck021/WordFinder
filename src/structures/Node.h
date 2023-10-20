//
// Created by caiog on 18/10/2023.
//

#ifndef WORDFINDER_NODE_H
#define WORDFINDER_NODE_H


template <typename typ>
class Node{
    typ data;
    Node<typ>* prev = nullptr;
    Node<typ>* next = nullptr;
};


#endif //WORDFINDER_NODE_H
