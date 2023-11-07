#ifndef WORDFINDER_ARVORE_H
#define WORDFINDER_ARVORE_H
#include <iostream>
#include <cstring>
#include "../structures/LinkedList.h"
#include "../file_components.h"

using namespace std;

template <typename typ>
struct TreeNode{
    typ data;
    int height;
    int countLeaf = 1;
    TreeNode<typ>* left;
    TreeNode<typ>* right;
    LinkedList<files> *files = nullptr;

};

template <typename typ>
class TreeAVL {
private:
    TreeNode<typ>* root;
    int balancer = 0; // Must be -1, 0 or 1
    void printTreeDCE(TreeNode<typ>* node);
    void printTreeECD(TreeNode<typ>* node);
    void printTreeCDE(TreeNode<typ>* node);
    TreeNode<typ>* getNode(TreeNode<typ>* node, typ d);

public:
    TreeAVL();
    ~TreeAVL();

    int getHeight(TreeNode<typ>* leaf);
    int getBalance(TreeNode<typ>* leaf);
    int max(int a, int b);

    void printTreeDCE();
    void printTreeECD();
    void printTreeCDE();
    void printTree();
    void printTree(TreeNode<typ>* node);
    void printDirectoryTree(TreeNode<typ>* root, bool isLeft = true, const string& prefix = "");
    void insertLeaf(typ data);
    void destroyTree(TreeNode<typ>* node);

    TreeNode<typ>* getNode(typ d);
    TreeNode<typ>* createNode(typ d);
    TreeNode<typ>* insertLeaf(TreeNode<typ> *leaf, typ d);
    TreeNode<typ>* leftRotation(TreeNode<typ>* x);
    TreeNode<typ>* rightRotation(TreeNode<typ>* y);
};

template<typename typ>
TreeAVL<typ>::TreeAVL(){
    root = nullptr;
}

template<typename typ>
TreeAVL<typ>::~TreeAVL() {
    destroyTree(root);
}

template<typename typ>
void TreeAVL<typ>::destroyTree(TreeNode<typ>* node) {
    if (node == nullptr)
        return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

template <typename typ>
TreeNode<typ>* TreeAVL<typ>::getNode(typ d) {
    return getNode(root, d);
}

template <typename typ>
TreeNode<typ>* TreeAVL<typ>::getNode(TreeNode<typ>* node, typ d) {
    if (node == nullptr) {
        return nullptr;
    }

    if (d == node->data) {
        return node;
    } else if (d < node->data) {
        return getNode(node->left, d);
    } else {
        return getNode(node->right, d);
    }
}

template<typename typ>
TreeNode<typ>* TreeAVL<typ>::createNode(typ d){
    TreeNode<typ>* auxNode = new TreeNode<typ>();

    auxNode->data = d;
    auxNode->left = nullptr;
    auxNode->right = nullptr;
    auxNode->height = 1;
    auxNode->countLeaf = 1;

    return auxNode;
}

template <typename typ>
void TreeAVL<typ>::insertLeaf(typ data) {
    root = insertLeaf(root, data);
}

template<typename typ>
TreeNode<typ>* TreeAVL<typ>::insertLeaf(TreeNode<typ> *leaf, typ d){
    if(leaf == nullptr){
        return(createNode(d));
    }

    // Insertion process
    if (d < leaf->data)
        leaf->left = insertLeaf(leaf->left, d);
    else if (d > leaf->data)
        leaf->right = insertLeaf(leaf->right, d);
    else {
        leaf->countLeaf++;
        return leaf;
    }

    // Balancer process
    leaf->height = 1 +
            max(getHeight(leaf->left), getHeight(leaf->right));
    int balance = getBalance(leaf);

    // Left, Left Case
    if (balance > 1 && d < leaf->left->data)
        return rightRotation(leaf);
    // Right, Right Case
    if (balance < -1 && d > leaf->right->data)
        return leftRotation(leaf);
    // Left, Right Case
    if (balance > 1 && d > leaf->left->data){
        leaf->left = leftRotation(leaf->left);
        return rightRotation(leaf);
    }
    // Right, Left Case
    if (balance < -1 && d < leaf->right->data){
        leaf->right = rightRotation(leaf->right);
        return leftRotation(leaf);
    }
    // Return leaf without changes
    return leaf;
}

template<typename  typ>
int TreeAVL<typ>::getHeight(TreeNode<typ>* leaf){
    return (leaf == nullptr) ? 0 : leaf->height;
}

template<typename  typ>
int TreeAVL<typ>::getBalance(TreeNode<typ>* leaf){
    return (leaf == nullptr) ? 0 : (getHeight(leaf->left) - getHeight(leaf->right));
}

template<typename typ>
int TreeAVL<typ>::max(int a, int b)
{
    return (a > b)? a : b;
}

template<typename typ>
TreeNode<typ>* TreeAVL<typ>::leftRotation(TreeNode<typ>* x){
    TreeNode<typ> *y = x->right;
    TreeNode<typ> *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

template<typename typ>
TreeNode<typ>* TreeAVL<typ>::rightRotation(TreeNode<typ>* y){
    TreeNode<typ> *x = y->left;
    TreeNode<typ> *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

template<typename typ>
void TreeAVL<typ>::printTreeDCE(){
    if(root != nullptr){
        this->printTreeDCE(root);
    }
}

template<typename typ>
void TreeAVL<typ>::printTreeDCE(TreeNode<typ>* node){
    if(node->right != nullptr){
        printTreeDCE(node->right);
    }
    cout << node->data << endl;
    if(node->left != nullptr){
        printTreeDCE(node->left);
    }
}

template<typename typ>
void TreeAVL<typ>::printTreeECD(){
    if(root != nullptr){
        this->printTreeECD(root);
    }
}

template<typename typ>
void TreeAVL<typ>::printTreeECD(TreeNode<typ>* node){
    if(node->left != nullptr){
        printTreeDCE(node->left);
    }
    cout << node->data << endl;
    if(node->right != nullptr){
        printTreeDCE(node->right);
    }
}

template<typename typ>
void TreeAVL<typ>::printTreeCDE(){
    if(root != nullptr){
        this->printTreeCDE(root);
    }
}

template<typename typ>
void TreeAVL<typ>::printTreeCDE(TreeNode<typ>* node){
    cout << node->data << endl;
    if(node->right != nullptr){
        printTreeDCE(node->right);
    }
    if(node->left != nullptr){
        printTreeDCE(node->left);
    }
}

template<typename typ>
void TreeAVL<typ>::printTree(){
    printDirectoryTree(root,true,"");
}

template<typename typ>
void TreeAVL<typ>::printTree(TreeNode<typ>* node){
    if (node != nullptr) {
        printDirectoryTree(node,true,"");
    }
}

template<typename typ>
void TreeAVL<typ>::printDirectoryTree(TreeNode<typ>* root, bool isLeft, const string& prefix) {
    if (root != nullptr) {
        cout << prefix;
        cout << (isLeft ? "+-- " : "+-- ");
        cout << root->data << " [Count: "<< root->countLeaf << " ]" << "[Lines: ]" << endl;

        string nextPrefix = prefix + (isLeft ? "|   " : "    ");

        printDirectoryTree(root->left, true, nextPrefix);
        printDirectoryTree(root->right, false, nextPrefix);
    }
}

#endif //WORDFINDER_ARVORE_H
