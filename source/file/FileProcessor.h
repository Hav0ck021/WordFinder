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
using namespace std;

template<typename typ>
class FileProcessor : private LinkedList<typ> {
private:
    char* fileName;
public:
    FileProcessor(char* fileName) : fileName(fileName) {}
    void processFile();

};

template<typename typ>
void FileProcessor<typ>::processFile(){
    {
        ifstream file(fileName);
        LinkedList<typ> words;

        if (!file) {
            cout << "Error opening the file: " << fileName << endl;
            return;
        }

        regex pattern("[^a-zA-Z0-9]+"); // Expressão regular para remover caracteres não alfanuméricos

        string line;
        int lineNumber = 1;
        int sequentialSearchResult = -1;
        int count = 1;

        while (getline(file, line)) {
            istringstream iss(line);
            string wordForm;

            while (iss >> wordForm) {
                wordForm = regex_replace(wordForm, pattern, "");

                if (wordForm.size() >= 3) {
                    words.bubbleSort(); // Correção necessária na implementação da ordenação

                    // Transformar para letras maiúsculas
                    transform(wordForm.begin(), wordForm.end(), wordForm.begin(), ::toupper);

                    // Realizar uma pesquisa sequencial na lista
                    sequentialSearchResult = sequential_search(words, wordForm);

                    if (sequentialSearchResult == -1) {
                        // A palavra não existe na lista, então adicione-a
                        Word newWord;
                        newWord.copyWords(wordForm);
                        newWord.ct1 = count;
                        newWord.ct2 = 0; // Preencha o valor apropriado, se necessário
                        newWord.line = lineNumber;
                        newWord.insertNode(newWord);
                    } else {
                        // A palavra já existe na lista, atualize o contador
                        words.ct1 += count;
                    }
                }
            }

            lineNumber++;
        }

        file.close();
    }
}
#endif //WORDFINDER_FILEPROCESSOR_H