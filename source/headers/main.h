//
// Created by caiog on 20/10/2023.
//

#ifndef WORDFINDER_MAIN_H
#define WORDFINDER_MAIN_H
#define BUFFER 1024
#incluide <iostream>

int logoExhibition(){
    FILE *logo = fopen("/resources/logo.txt","r");
    if (logo == NULL){
        perror("Erro ao apresentar a logo!");
        return -1;
    }
    char line[BUFFER];

    while(fgets(line, sizeof(line), logo) != NULL){
        for(int i = 0; i < sizeof(line); i++){
            cout << line[i] << endl;
        }
    }
    fclose(logo);
    return 0;
}

#endif //WORDFINDER_MAIN_H
