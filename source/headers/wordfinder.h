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

void printTreeFile(const string& fileName){
    TreeAVL<string> tree;
    string line;
    int lineNum = 1;

    ifstream file(fileName);

    if (file.is_open()) {
        while (getline(file, line)) {
            istringstream iss(line);
            string word;
            while (iss >> word) {
                word = removeSpecialCharacters(word);
                if (word.size() > 3) {
                    tree.insertLeaf(word);
                }
            }
            lineNum++;
        }
        file.close();
        tree.printTree();
    } else {
        cout << "Unable to open file: " << fileName << endl;
    }
}

void printFile(const string& fileName){
    TreeAVL<string> tree;
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

void openFile(const string& fileName){
    int option;
    cout << "How do you want to open the file:\n1 - in a tree format showing the words\n2 - in a textual line format?\nChoose -> ";
    cin >> option;
    cout << "\n";
    switch (option) {
        case 1:
            printTreeFile(fileName);
            break;
        case 2:
            printFile(fileName);
            break;
        default:
            cout << "Invalid option!" << endl;
            break;
    }
}

int countFiles(const string& directoryPath){
    int count = 0;
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            count++;
        }
    }
    return count;
}

char** collectNameFiles(const string& directoryPath){
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

void chooseFile(){
    const string filePath = fs::path {"resources/texts/"};
    int option = 0, countFile = countFiles(filePath);

    char **fileNames = collectNameFiles(filePath);

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
        openFile(fileNames[option]);
    }
}

#endif //WORDFINDER_WORDFINDER_H
