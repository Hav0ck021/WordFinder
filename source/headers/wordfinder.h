#ifndef WORDFINDER_WORDFINDER_H
#define WORDFINDER_WORDFINDER_H

#include "../structures/LinkedList.h"
#include "../structures/Tree.h"

#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;
namespace fs = std::filesystem;

string removeSpecialCharacters(const string& input) {
    string result;

    for (char c : input) {
        if (std::isalpha(c) || std::isspace(c)) {
            result += c;
        }
    }
    return result;
}

string toUpperWord(string& input){
    int i = 0;
    while(input[i] != '\0'){
        input[i] = toupper(input[i]);
        i++;
    }
    return input;
}

string collectOnlyFileName(const filesystem::path fileName){
    string fileStr = fileName.string();
    int size = fileStr.size();

    while(fileStr[size] != '\\'){
        fileStr[size - (size + 1)] = fileStr[size];
        size--;
    }

    return fileStr;
}

void printTreeFile(TreeAVL<string> &tree, const filesystem::path fileName){
    string line, fileStr = collectOnlyFileName(fileName);
    int lineNum = 1;

    ifstream file(fileName);
    int lineNumbers = 1;

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string word;
            while (iss >> word) {
                word = removeSpecialCharacters(word);
                TreeNode<string> *auxNode = tree.getNode(word);

                if (word.size() > 3) {
                    word = toUpperWord(word);
                    tree.insertLeaf(word);

                    if(auxNode == nullptr){
                        tree.insertLeaf(word);
                        auxNode = tree.getNode(word);
                        auxNode->files = new LinkedList<files>();
                    }

                    bool fileExist = false;
                    int i = 0;

                    while(i < auxNode->files->getSize()){
                        if(auxNode->files->getData(i).nameFile == fileStr){
                            fileExist = true;
                            auxNode->files->getData(i).lines->insertNode(lineNumbers);
                            auxNode->countLeaf++;
                            break;
                        }
                        i++;
                    }

                    if(!fileExist){
                        files informations;
                        informations.nameFile = fileStr;
                        informations.lines = new LinkedList<int>();
                        informations.lines->insertNode(lineNum);
                        auxNode->files->insertNode(informations);
                    }
                }
            }
            lineNum++;
        }
        file.close();
    } else {
        cout << "Unable to open file: " << fileName << endl;
    }
}

void printFile(TreeAVL<string> &tree, const filesystem::path fileName){
    string line;
    int lineNum = 1;

    ifstream file(fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            cout << "Line " << lineNum << ": " << line << endl;

            tree.insertLeaf(line);

            lineNum++;
        }
        file.close();
        cout << "\n";
    } else {
        cout << "Unable to open file: " << fileName << endl;
    }
    cout << "\n";
}

void openFile(TreeAVL<string> &tree, const filesystem::path fileName){
    int option;
    cout << "How do you want to open the file:\n1 - in a tree format showing the words\n2 - in a textual line format?\nChoose -> ";
    cin >> option;
    cout << "\n";
    switch (option) {
        case 1:
            printTreeFile(tree, fileName);
            break;
        case 2:
            printFile(tree, fileName);
            break;
        default:
            cout << "Invalid option!" << endl;
            break;
    }
}

int countFiles(const filesystem::path directoryPath){
    int count = 0;
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            count++;
        }
    }
    return count;
}

char** collectNameFiles(TreeAVL<string> &tree, const filesystem::path directoryPath){
    int fileCount = countFiles(directoryPath);
    char **fileNames = new char*[fileCount];

    int index = 0;
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            fileNames[index] = new char[entry.path().string().size() + 1];
            strcpy(fileNames[index], entry.path().string().c_str());
            index++;
        }
    }
    return fileNames;
}

void chooseFile(TreeAVL<string> &tree){
    const filesystem::path filePath = fs::path {"resources/texts/"};
    int option = 0, countFile = countFiles(filePath);

    char **fileNames = collectNameFiles(tree, filePath);

    cout << "Files: " << endl;
    for(int i = 0; i < countFile; i++){
        cout << i + 1 << " - " << fileNames[i] << endl;
    }

    cout << "Choose one: " << endl;
    cin >> option;

    if (option > countFile || option < 1){
        throw std::runtime_error("Invalid option!\n");
    } else {
        option--;
        openFile(tree, fileNames[option]);
    }
}

#endif //WORDFINDER_WORDFINDER_H
