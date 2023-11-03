#include <iostream>
#include "headers/main.h"

int main() {
    logoExhibition();
    char option = showOptions();
    optionsWordFinder(&option);
    return 0;
}
