//
// Created by Jakub on 27.10.2023.
//

#ifndef PEA_1_BRANCHANDBOUND_IMPLEMENTATION_H
#define PEA_1_BRANCHANDBOUND_IMPLEMENTATION_H


#include <climits>

class BranchAndBound_Implementation {
public:
    BranchAndBound_Implementation(int n);
    int* final_path;
    bool* visited;
    int N;
    int final_res = INT_MAX;
    int* curr_path;

    void TSPRec(int **adj, int curr_bound, int curr_weight, int level, int **curr_path);

    int secondMin(int **adj, int i);

    int firstMin(int **adj, int i);

    void copyToFinal(int *curr_path);

    void TSP(int **adj);

    void TSPRec(int **adj, int curr_bound, int curr_weight, int level, int *curr_path);

    void printResult();
};


#endif //PEA_1_BRANCHANDBOUND_IMPLEMENTATION_H
