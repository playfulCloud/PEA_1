//
// Created by Jakub on 27.10.2023.
//

#ifndef PEA_1_MENU_H
#define PEA_1_MENU_H


#include "../../Algorithms/BruteForce/BruteForce_Implementation.h"
#include "../Reader/FileReader.h"

class Menu {
public:
    void displayMenu();
    BruteForce_Implementation *bruteForceImplementation;
    FileReader *fileReader;


};


#endif //PEA_1_MENU_H
