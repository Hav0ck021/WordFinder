#ifndef WORDFINDER_Word_H
#define WORDFINDER_Word_H
#include "LinkedList.h"
#include <cstring>

using namespace std;

template <typename typ>
class Word : public LinkedList<typ> {
private:
    char *word;
    int ct1 = 0;
    int ct2 = 0;
    int countLine = 0;
    char* lines;
public:
    Word() : word(nullptr) {} // Construtor padrão

    Word(const char* word, int ct1, int ct2, int countLine) : ct1(ct1), ct2(ct2), countLine(countLine) {
        // Aloque espaço para a palavra
        this->word = new char[strlen(word) + 1];
        strcpy(this->word, word);
    }

    // Construtor que aceita uma string e converte para char*
    Word(const string& wordStr) : word(nullptr) {
        // Aloque espaço para a palavra
        word = new char[wordStr.length() + 1]; // +1 para o caractere nulo
        strcpy(word, wordStr.c_str()); // Copie a string para o char*
    }

    // Destrutor para liberar a memória alocada
    ~Word() { delete[] word; }

    // Métodos ou operadores de conversão
    operator char*() const { return word; }

    char* dynamicAllocateLines();
    void printWords();
    bool compareWords(const string& word1, const string& word2);
    char* copyWords(char *word2);
    void printDirectoryTree(Node<typ>* root, const string& prefix = "");
    void showAllLines();
    void increaseCountWordList(int num);
};

template<typename typ>
void Word<typ>::increaseCountWordList(int num) {
    ct1 += num;
}

template <typename typ>
char* Word<typ>::dynamicAllocateLines(){
    lines = (char *)malloc(countLine* sizeof(char));
    return lines;
}

template <typename typ>
void Word<typ>::showAllLines(){
    cout << "[ ";
    for(int i = 0; lines[i] != '\0'; i++){
        cout << lines[i] << ", ";
    }
}

// Função responsável pela formatação da impressão das palavras
template <typename typ>
void Word<typ>::printWords() {
    cout << "*-----------------------------------------------------*" << endl;
    cout << "| Word: " << word << endl;
    cout << "| Count total: " << ct1 + ct2 << endl;
    cout << "| Count 1: " << ct1 << " Count 2: " << ct2 << endl;  // Corrigidos os nomes dos membros
    cout << "| Line: ", showAllLines();
    cout << "*-----------------------------------------------------*" << endl;
}

template <typename typ>
void Word<typ>::printDirectoryTree(Node<typ>* root, const string& prefix) {
    if (root == nullptr) {
        return;
    }

    std::cout << prefix << "└── " << root->key << std::endl;

    std::string newPrefix = prefix + "    ";

    printDirectoryTree(root->left, newPrefix + "│   ");
    printDirectoryTree(root->right, newPrefix + "│   ");
}

template <typename typ>
// Função responsável por comparar 2 strings
bool Word<typ>::compareWords(const string& word1, const string& word2) {
    return word1 == word2;
}
template <typename typ>
char* Word<typ>::copyWords(char* word2) {
    return strcpy(word, word2);
}
#endif //WORDFINDER_Word_H