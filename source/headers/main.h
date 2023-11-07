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

char showOptions(){
    char option;
    cout << "1 - Choose a file to open\nE - Exit the WordFinder\nChoose -> ";
    cin >> option;
    cin.ignore();
    cout << "\n";
    return option;
}

int optionsWordFinder(TreeAVL<string> &tree, const char *op){
    switch(*op) {
        case '1':
            chooseFile(tree);
            break;
        case 'e':
        case 'E':
            cout << "Goodbye, see you soon! :) "<< endl;
            return 1;
        default:
            cout << "Invalid option!" << endl;
            break;
    }
    return 0;
}

#endif //WORDFINDER_MAIN_H
