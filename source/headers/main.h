#ifndef WORDFINDER_MAIN_H
#define WORDFINDER_MAIN_H

#define BUFFER 1024
#include <iostream>
#include "wordfinder.h"

using namespace std;

int logoExhibition(){
    FILE *logo = fopen("resources/logo.txt","r");
    if (logo == nullptr){
        perror("Error displaying the logo!");
        return -1;
    }

    char line[BUFFER];

    while(fgets(line, sizeof(line), logo) != nullptr){
        cout << line;
    }
    cout << "\n\n";

    fclose(logo);
    return 0;
}

int showOptions(){
    int option;

    cout << "1 - Choose a file to open\n"
            "2 - Search a word into files\n"
            "3 - Exit the WordFinder\n"
            "Choose -> ";
    cin >> option;
    cin.ignore();
    cout << "\n";

    return option;
}

int optionsWordFinder(TreeAVL<string> &tree, int *op){
    switch(*op) {
        case 1:
            chooseFile(tree);
            break;
        case 2:
        {
            chooseFile(tree);
            string word;
            cout << "Insert a word to search: ";
            cin >> word;
            searchWordInTree(tree, word);
            break;
        }
        case 3:
            cout << "Goodbye, see you soon! :) "<< endl;
            return 1;
        default:
            cout << "Invalid option!" << endl;
            break;
    }
    return 0;
}

#endif //WORDFINDER_MAIN_H
