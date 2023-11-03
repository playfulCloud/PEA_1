//
// Created by Jakub on 27.10.2023.
//

#ifndef PEA_1_MENU_H
#define PEA_1_MENU_H


#include "../../Algorithms/BruteForce/BruteForce_Implementation.h"
#include "../Reader/FileReader.h"
#include "../RandomGenerator/Generator.h"

class Menu {
public:
    void displayMenu();
    void displayAlgorithms();
    BruteForce_Implementation *bruteForceImplementation;
    Generator *generator;
    FileReader *fileReader;
    Matrix graph;
    Matrix randomGraph;

};


#endif //PEA_1_MENU_H
