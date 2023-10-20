#ifndef WORDFINDER_ARVORE_H
#define WORDFINDER_ARVORE_H
#include <iostream>

using namespace std;

template <typename typ>
struct TreeNode{
    typ data;
    int countLeaf = 0;
    TreeNode<typ>* left = nullptr;
    TreeNode<typ>* right = nullptr;
};

template <typename typ>
class Tree {
private:
    Tree<typ>* source = nullptr;
public:
    Tree(TreeNode<typ>* tree, typ d){
        tree->data = d;
        tree->left = tree->right = nullptr;
    }
    ~Tree();
    Tree* createTree(typ d, Tree<typ>* l, Tree<typ>* r){
        Tree* aux = new Tree;
        aux->data = d;
        aux->left = l;
        aux->right = r;
        return aux;
    }
    void printTree(Tree* aux){
        if (aux != nullptr) {
            cout << aux->data << endl;
            printTree(aux->left);
            printTree(aux->right);
        }
    }
    Tree* appendTree(typ d){
        if (source == nullptr) {
            source = new TreeNode<typ>();
            source->data = d;
        } else {
            TreeNode<typ>* newNode = new TreeNode<typ>();
            newNode->data = d;
        }
    }
    Tree* searchTreeContent(typ d){
        /** a
         *
         * **/
    }
};

template<typename typ>
Tree<typ>::~Tree() {

}


#endif //WORDFINDER_ARVORE_H
