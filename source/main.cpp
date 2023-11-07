#include <iostream>
#include "headers/main.h"
#include "structures/Tree.h"
#include "structures/LinkedList.h"
#include "headers/main.h"

int main() {
    TreeAVL<string> tree;
    logoExhibition();
    char option = showOptions();
    optionsWordFinder(tree, &option);
    tree.printTree();
    return 0;
}