//
// Created by caiog on 20/10/2023.
//
/** Arquivo que irá realizar a busca das palavras e contabilizar a quantidade
 *  de repetições e em quais linhas estão estabelecidas. **/

#include <iostream>
#include "structures/LinkedList.h"
#include "structures/Tree.h"
#include "structures/NodeWord.h"

int main(){
    std::cout << "\n";

    LinkedList<int> lista = LinkedList<int>();
    lista.insertNode(5);
    lista.insertNode(6);
    lista.insertNode(2);
    lista.insertNode(1);
    lista.insertNode(35);
    lista.insertNode(23);
    lista.insertNode(17);
    lista.insertNode(16);

    lista.bubbleSort();
    lista.printList();
    lista.binarySearch(1);

    lista.removeNode(1);
    lista.printList();

    lista.clearMemory();
    lista.printList();

    std::cout << "\n";
    lista.printList();

    lista.binarySearch(6);

    return 0;
}