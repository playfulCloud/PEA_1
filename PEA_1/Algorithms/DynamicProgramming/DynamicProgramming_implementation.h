//
// Created by Jakub on 27.10.2023.
//

#ifndef PEA_1_DYNAMICPROGRAMMING_IMPLEMENTATION_H
#define PEA_1_DYNAMICPROGRAMMING_IMPLEMENTATION_H

#define INF INT_MAX

#include <vector>
#include "../../Utils/CityMatrix/Matrix.h"

class DynamicProgramming_implementation {
public:




    DynamicProgramming_implementation(int n);

    int tsp(int** dist, int n, int pos, int mask);
    int** dp;
    int** trace;
    int ans;
    int* path;
    int size;
    std::vector<int> currentPath;
    std::vector<std::vector<int>> choice;
    void printBestPath();
};


#endif //PEA_1_DYNAMICPROGRAMMING_IMPLEMENTATION_H
