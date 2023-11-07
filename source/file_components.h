#ifndef WORDFINDER_FILE_COMPONENTS_H
#define WORDFINDER_FILE_COMPONENTS_H

#include "structures/LinkedList.h"

using namespace std;

struct files{
    string nameFile;
    LinkedList<int> *lines;
};
#endif //WORDFINDER_FILE_COMPONENTS_H
