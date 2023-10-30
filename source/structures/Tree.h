#ifndef WORDFINDER_ARVORE_H
#define WORDFINDER_ARVORE_H
#include <iostream>
#include <cstring>
#define BUFFER 1024

using namespace std;

template <typename typ>
struct TreeNode{
    typ data = NULL;
    int height;
    int countLeaf = 0;
    int balancer = 0; // Must be -1, 0 or 1
    TreeNode<typ>* sourceTree = nullptr;
    TreeNode<typ>* left = nullptr;
    TreeNode<typ>* right = nullptr;
};

template <typename typ>
class TreeAVL {
private:
    TreeNode<typ>* root = nullptr;
    void printTreeDCE(TreeNode<typ>* node);
    void printTreeECD(TreeNode<typ>* node);
    void printTreeCDE(TreeNode<typ>* node);

public:
    TreeAVL();
    ~TreeAVL();
    TreeNode<typ>* createTree(typ d);
    int getHeight(TreeNode<typ>* leaf);
    int getBalance(TreeNode<typ>* leaf);
    void printTree(TreeNode<typ>* root);
    TreeNode<typ>* getRoot(typ d);
    TreeNode<typ>* insertLeaf(typ d);
    TreeNode<typ>* searchTreeContent(typ d);
    /** char* verifyLengthWords(char* a, char* b); **/
    int max(int a, int b);
    TreeNode<typ>* leftRotation(TreeNode<typ>* x);
    TreeNode<typ>* rightRotation(TreeNode<typ>* y);
    void printTreeDCE();
    void printTreeECD();
    void printTreeCDE();
};

template<typename typ>
TreeAVL<typ>::TreeAVL(){
    cout << "Tree has been created!" << endl;
}

template<typename typ>
TreeAVL<typ>::~TreeAVL() {
    cout << "Tree has been deleted!" << endl;
}

template<typename typ>
TreeNode<typ>* TreeAVL<typ>::createTree(typ d){
    TreeNode<typ>* aux = new TreeNode<typ>();
    aux->data = d;
    aux->height++;
    return aux;
}

template<typename  typ>
int TreeAVL<typ>::getHeight(TreeNode<typ>* leaf){
    return (leaf == nullptr) ? 0 : leaf->heigth;
}

template<typename  typ>
int TreeAVL<typ>::getBalance(TreeNode<typ>* leaf){
    return (leaf == nullptr) ? 0 : (heigth(leaf->left) - heigth(leaf->right));
}

template<typename typ>
void TreeAVL<typ>::printTree(TreeNode<typ>* node){
    if (node != nullptr) {
        cout << node->data << endl;
        printTree(node->left);
        printTree(node->right);
    }
}

template<typename typ>
TreeNode<typ>* TreeAVL<typ>::insertLeaf(typ d){

}

/** template<typename typ>
char* Tree<typ>::verifyLengthWords(char* a, char* b){
    return (strlen(a) > strlen(b)) ? a : b;
} **/

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

    x->right = x;
    y->left = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

template<typename typ>
TreeNode<typ>* TreeAVL<typ>::searchTreeContent(typ d){

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
#endif //WORDFINDER_ARVORE_H
