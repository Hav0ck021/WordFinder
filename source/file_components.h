#ifndef WORDFINDER_FILE_COMPONENTS_H
#define WORDFINDER_FILE_COMPONENTS_H
#include <filesystem>
#include "structures/LinkedList.h"

using namespace std;

struct files{
    std::filesystem::path nameFile;
    LinkedList<int> *lines;
};
#endif //WORDFINDER_FILE_COMPONENTS_H
