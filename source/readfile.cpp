#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "structures/LinkedList.h" // Certifique-se de incluir o cabeçalho da lista personalizada
#include "structures/NodeWord.h" // Certifique-se de incluir o cabeçalho da classe Word
#include "file/FileProcessor.h"
template<typename typ>


int main() {
    clock_t tempoInicial = clock();

    FileProcessor arquivo1("resources/texts/arquivo1.txt");
    FileProcessor arquivo2("resources/texts/arquivo2.txt");

    arquivo1.processFile();
    arquivo2.processFile();

    clock_t tempoFinal = clock();

    double tempoDecorrido = double(tempoFinal - tempoInicial) / CLOCKS_PER_SEC;

    cout << "Tempo de execução: " << tempoDecorrido << " segundos" << endl;

    return 0;
}