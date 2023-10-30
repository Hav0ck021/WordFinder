//
// Created by caiog on 18/10/2023.
//

#ifndef WORDFINDER_NODEWORD_H
#define WORDFINDER_NODEWORD_H
#include "LinkedList.h"
#include <string.h>

/**template <typename typ>
class ListWord : private LinkedList<typ>{
private:
    char data[1024];
    node<typ>* prev = nullptr;
    node<typ>* next = nullptr;
public:
    char** loadFile(char *filename, int *len);
};

char** loadFile(char *filename, int *len) {
    ;
}**/

using namespace std;

class Word {
private:
    char word[64];
    int ct1 = 0;
    int ct2 = 0;
    int countLine = 0;
    char* lines;
public:
    Word();
    ~Word();
    char* dynamicAllocateLines();
    void printWords();
    bool compareWords(char *word1, char *word2);
    char* copyWords(char *word2);
    void showAllLines();
};

char* Word::dynamicAllocateLines(){
    lines = (char *)malloc(countLine* sizeof(char));
    return lines;
}

void Word::showAllLines(){
    cout << "[ ";
    for(int i = 0; lines[i] != '\0'; i++){
        cout << lines[i] << ", ";
    }
}

// Função responsável pela formatação da impressão das palavras
void Word::printWords() {
    cout << "*-----------------------------------------------------*" << endl;
    cout << "| Word: " << word << endl;
    cout << "| Count total: " << ct1 + ct2 << endl;
    cout << "| Count 1: " << ct1 << " Count 2: " << ct2 << endl;  // Corrigidos os nomes dos membros
    cout << "| Line: ", showAllLines();
    cout << "*-----------------------------------------------------*" << endl;
}

// Função responsável por comparar 2 strings
bool Word::compareWords(char *word1, char *word2) {
    return strcmp(word1, word2);
}

char* Word::copyWords(char* word2) {
    return strcpy(word, word2);
}

#endif //WORDFINDER_NODEWORD_H
