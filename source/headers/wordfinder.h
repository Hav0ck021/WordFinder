#ifndef WORDFINDER_WORDFINDER_H
#define WORDFINDER_WORDFINDER_H

#include "../structures/LinkedList.h"
#include "../structures/Tree.h"
#include "../file_components.h"

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

string toUpperWord(string &input) {
    int i = 0;
    while (input[i] != '\0') {
        input[i] = toupper(input[i]);
        i++;
    }
    return input;
}

char* collectOnlyFileName(const filesystem::path& filePath){
    string fileStr = filePath.filename().string();  // Use filename() para obter apenas o nome do arquivo.
    char* charArray = new char[fileStr.length() + 1];
    strcpy(charArray, fileStr.c_str());
    return charArray;
}

TreeNode<string>* searchNodeInTree(TreeNode<string> *root, const string &word) {
    if (root == nullptr) {
        return nullptr;
    }

    if (word == root->data) {
        return root;
    } else if (word < root->data) {
        return searchNodeInTree(root->left, word);
    } else {
        return searchNodeInTree(root->right, word);
    }
}

bool searchWordInTree(TreeAVL<string> &tree, string &word) {
    string wordUp = toUpperWord(word);
    TreeNode<string> *foundNode = searchNodeInTree(tree.getNode(word), word);

    if (foundNode != nullptr) {
        cout << "Word '" << word << "' found. Count: " << foundNode->countLeaf << endl;
        return true;
    } else {
        cout << "Word '" << word << "' not found in the tree." << endl;
        return false;
    }
}

void insertFileinTree(TreeAVL<string> &tree, const filesystem::path& fileName){
    string line;
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
                        if(auxNode->files->getData(i).nameFile == fileName){
                            fileExist = true;
                            auxNode->files->getData(i).lines->insertNode(lineNumbers);
                            auxNode->countLeaf++;
                            break;
                        }
                        i++;
                    }

                    if(!fileExist){
                        files informations;
                        informations.nameFile = fileName;
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

void printFile(TreeAVL<string> &tree, const filesystem::path& fileName){
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

void openFile(TreeAVL<string> &tree, const filesystem::path& fileName){
    int option;
    cout << "How do you want to open the file:\n"
            "1 - Only upload the file in tree struct\n"
            "2 - in a tree format showing the words\n"
            "3 - in a textual line format?\n"
            "Choose -> ";

    cin >> option;
    cout << "\n";
    switch (option) {
        case 1:
            insertFileinTree(tree, fileName);
            break;
        case 2:
            insertFileinTree(tree, fileName);
            tree.printTree();
            break;
        case 3:
            printFile(tree, fileName);
            break;
        default:
            cout << "Invalid option!" << endl;
            break;
    }
}

int countFiles(const filesystem::path& directoryPath){
    int count = 0;
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            count++;
        }
    }
    return count;
}

char** collectNameFiles(const filesystem::path& directoryPath){
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

    char **fileNames = collectNameFiles(filePath);

    cout << "Files: " << endl;
    for(int i = 0; i < countFile; i++){
        cout << i + 1 << " - " << collectOnlyFileName(fileNames[i]) << endl;
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
