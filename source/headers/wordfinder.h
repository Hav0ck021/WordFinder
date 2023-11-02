#ifndef WORDFINDER_WORDFINDER_H
#define WORDFINDER_WORDFINDER_H

#include "../structures/LinkedList.h"
#include "../structures/NodeWord.h"
#include "../structures/Tree.h"

#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

namespace fs = std::filesystem;

void chooseFile(){

}

void printTreeWord(string fileName){
    TreeAVL<string> tree;
    string line;
    int lineNum = 1;

    ifstream file(fileName);
    while(getline(file, lineNum)){

    }

}

void openFile(){
    const string filePath = fs::path dir{"../resources/texts"};
    "../resources/texts";

}


#endif //WORDFINDER_WORDFINDER_H
