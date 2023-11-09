#include <iostream>
#include "headers/main.h"
#include "structures/Tree.h"
#include "structures/LinkedList.h"
#include "headers/main.h"

void cleanTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    TreeAVL<string> tree;
    logoExhibition();
    bool continueMenu = true;

    do {
        int option = showOptions();
        int op;
        optionsWordFinder(tree, &option);

        cout << "continue?\n"
                "1 - yes\n"
                "2 - no\n" << endl;
        cin >> op;
        cleanTerminal();

        if (op != 1) {
            continueMenu = false;
        }
    } while (continueMenu);

    return 0;
}