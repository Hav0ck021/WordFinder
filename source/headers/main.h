//
// Created by caiog on 20/10/2023.
//

#ifndef WORDFINDER_MAIN_H
#define WORDFINDER_MAIN_H

#define BUFFER 1024
#include <iostream>

using namespace std;

int logoExhibition(){
    FILE *logo = fopen("resources/logo.txt","r");
    if (logo == nullptr){
        perror("Erro ao apresentar a logo! ");
        return -1;
    }

    char line[BUFFER];

    while(fgets(line, sizeof(line), logo) != nullptr){
        cout << line;
    }
    cout << "\n";

    fclose(logo);
    return 0;
}

int optionsWordFinder(int *op){
    switch(*op) {
        case 1:
            break;
        case 'e' | 'E':
            break;
    }
    return 0;
}

#endif //WORDFINDER_MAIN_H
