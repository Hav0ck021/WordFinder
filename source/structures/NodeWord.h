//
// Created by caiog on 18/10/2023.
//

#ifndef WORDFINDER_NODEWORD_H
#define WORDFINDER_NODEWORD_H


template <typename typ>
class NodeWord{
private:
    typ data;
    NodeWord<typ>* prev = nullptr;
    NodeWord<typ>* next = nullptr;
public:

};


#endif //WORDFINDER_NODEWORD_H
