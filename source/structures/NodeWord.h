#ifndef WORDFINDER_Word_H
#define WORDFINDER_Word_H
#include "LinkedList.h"
#include <string>
#include <cstring>

using namespace std;

template <typename typ>
class Word {
private:
    LinkedList<typ> wordList;

    int countLine;
    int lines[128];
public:
    Word() {}
    Word(const string& wordStr) {
        wordList.insertNode(wordStr);
        countLine = 0;
    }

    void printAllWords();
    bool compareWords(const string& word1, const string& word2);
    void printDirectoryTree(Node<typ>* root, const string& prefix = "");
    void printTable(typ d);
    void showAllLines();
    void increaseCountWordList(int num);
};

template<typename typ>
void Word<typ>::increaseCountWordList(int num) {
    countLine += num;
}

template <typename typ>
void Word<typ>::showAllLines(){
    cout << "[ ";
    for(int i = 0; lines[i] != '\0'; i++){
        cout << lines[i] << ", ";
    }
    cout << " ]" << endl;
}

template <typename typ>
void Word<typ>::printTable(typ d){
    cout << "*-----------------------*" << endl;
    cout << "| Word: " << wordList.getNodeByID(d) << endl;
    cout << "| Count total: " << countLine << endl;
    cout << "| Line: ", showAllLines();
    cout << "*----------------------*" << endl;
}

template <typename typ>
void Word<typ>::printDirectoryTree(Node<typ>* root, const string& prefix) {
    if (root == nullptr) {
        return;
    }

    std::cout << prefix << "└── " << printTable(root->data) << std::endl;

    std::string newPrefix = prefix + "    ";

    printDirectoryTree(root->left, newPrefix + "│   ");
    printDirectoryTree(root->right, newPrefix + "│   ");
}

// Função responsável por comparar 2 strings
template <typename typ>
bool Word<typ>::compareWords(const string& word1, const string& word2) {
    if (word1 == word2) {
        return true;
    } else {
        return word1.size() > word2.size();
    }
}
#endif //WORDFINDER_Word_H