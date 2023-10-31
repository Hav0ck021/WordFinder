#ifndef WORDFINDER_FILEPROCESSOR_H
#define WORDFINDER_FILEPROCESSOR_H
#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "../structures/LinkedList.h"
#include "../structures/NodeWord.h"

template<typename typ>
LinkedList<Word<typ>> wordList;

template<typename typ>
Word<typ> word;

template<typename typ>
class FileProcessor {
public:
    FileProcessor(const string& fileName) : fileName_(fileName) {}

    void processFile();

public:
    string fileName_;
};

template<typename typ>
void FileProcessor<typ>::processFile(){
    ifstream file("arquivo1.txt");

    if (!file) {
        cout << "Error opening the file: " << fileName_ << endl;
        return;
    }

    regex pattern("[^a-zA-Z0-9]+"); // Expressão regular para remover caracteres não alfanuméricos

    string line;
    int lineNumber = 1;
    int count = 1;

    while (getline(file, line)) {
        istringstream iss(line);
        string wordForm;

        while (iss >> wordForm) {
            wordForm = regex_replace(wordForm, pattern, "");

            if (wordForm.size() >= 3) {
                wordList<typ>.bubbleSort(); // Correção necessária na implementação da ordenação

                // Transformar para letras maiúsculas
                transform(wordForm.begin(), wordForm.end(), wordForm.begin(), ::toupper);

                // Realizar uma pesquisa sequencial na lista
                wordList<typ>.sequentialSearch(wordForm);

                if (wordList<typ>.sequentialSearch(wordForm) == nullptr) {
                    // A palavra não existe na lista, então adicione-a
                    Word<typ> newWord(wordForm.c_str(), count, 0, lineNumber);;
                    wordList<typ>.insertNode(newWord);
                } else {
                    // A palavra já existe na lista, atualize o contador
                    word<typ>.increaseCountWordList(count);
                }
            }
        }

        lineNumber++;
    }

    file.close();
}
#endif //WORDFINDER_FILEPROCESSOR_H