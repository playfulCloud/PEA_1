//
// Created by Jakub on 02.11.2023.
//

#include "Generator.h"
#include <cstdlib>
#include <iostream>

Matrix Generator::generateRandomMatrix() {
    Matrix result;
    int num_cities;
    std::cout << "Input number of cities for matrix generation: ";
    std::cin >> num_cities;
    result.numberOfCites = num_cities;
    result.matrixTable = new int *[num_cities];
    for (int i = 0; i < num_cities; ++i) {
        result.matrixTable[i] = new int[num_cities];
        for (int j = 0; j < num_cities; ++j) {
            if (i == j) {
                result.matrixTable[i][j] = -1;
            } else {
                result.matrixTable[i][j] = rand() % 100 + 1;
            }
        }
    }
    return result;
}