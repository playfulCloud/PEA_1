//
// Created by Jakub on 27.10.2023.
//

#ifndef PEA_1_MENU_H
#define PEA_1_MENU_H


#include "../../Algorithms/BruteForce/BruteForce_Implementation.h"
#include "../Reader/FileReader.h"
#include "../RandomGenerator/Generator.h"
#include "../../Algorithms/DynamicProgramming/DynamicProgramming_implementation.h"

class Menu {
public:
    void displayMenu();
    void displayAlgorithms(Matrix matrix);
    BruteForce_Implementation *bruteForceImplementation;
    DynamicProgramming_implementation *dynamicProgrammingImplementation;
    Generator *generator;
    FileReader *fileReader;
    Matrix graph;
    Matrix randomGraph;


};


#endif //PEA_1_MENU_H
