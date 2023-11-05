#include "DynamicProgramming_implementation.h"
#include <algorithm>
#include <iostream>
#include <valarray>

static std::vector<std::vector<int>> matrix;
static std::vector<std::vector<std::vector<int>>> mask_path_matrix; // dla przechowywania �cie�ek minimalnych dla poszczeg�lnych kombinacji miast
static std::vector<std::vector<int>> mask_cost_matrix;
static int visited_all_mask;


DynamicProgramming_implementation::DynamicProgramming_implementation(int n) {
    ans = INT_MAX;
    dp = new int *[n];
    size = n;
    visited_all_mask = (1 << n) - 1;
    for (int i = 0; i < n; i++) {
        dp[i] = new int[(1 << n)];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }
}




std::vector<int> DynamicProgramming_implementation::held_karp(int** dist) {
    for (int i = 0; i < size; i++) {
        std::vector<int> row;
        for (int j = 0; j < size; j++) {
            row.push_back(dist[i][j]);
        }
        matrix.push_back(row);
    }

    mask_cost_matrix.resize(
            pow(2, size));           // utworzenie macierzy o wymiarach [2^n][n] i wype�nienie jej warto�ci� -1
    mask_path_matrix.resize(pow(2, size));
    for (int i = 0; i < mask_cost_matrix.size(); i++) {
        mask_path_matrix[i].resize(size);
        for (int j = 0; j < size; j++) {
            mask_cost_matrix[i].push_back(-1);
        }
    }

    // maska samych 1 oznaczaj�ca odwiedzenie wszystkich wierzcho�k�w
    visited_all_mask = (1 << size) - 1;

//    auto start_time = std::chrono::high_resolution_clock::now();
     int result = this->recursive_held_karp(1,0,dist);
//    auto end_time = std::chrono::high_resolution_clock::now();
//
//    std::chrono::nanoseconds time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

    std::cout << "result: " << result <<std::endl;
    std::vector<int> result_path = mask_path_matrix[1][0];
    std::reverse(result_path.begin(), result_path.end());

    for (int i = 0; i < size; i++)
    {
        std::cout<< "->" << result_path[i] << ' ';
    }
    std::cout << '\n';

    matrix.clear();
    mask_path_matrix.clear();
    mask_cost_matrix.clear();

    return result_path;
}

int DynamicProgramming_implementation::recursive_held_karp(int mask, int vertex, int** dist)
{

    if (mask == visited_all_mask)  // odwiedzono już wszystkie wierzchołki
    {
        mask_path_matrix[mask][vertex].push_back(vertex);
        return dist[vertex][0];
    }

    if (mask_cost_matrix[mask][vertex] != -1)  // sprawdzenie czy już zapisaliśmy tę wartość
    {
        return mask_cost_matrix[mask][vertex];
    }

    int result = INT_MAX;
    int next_vertex = -1;
    for (int i = 0; i < matrix.size(); i++)
    {
        if ((mask & (1 << i)) == 0)        // sprawdzenie czy wierzchołek jest nieodwiedzony
        {
            int possible_result = dist[vertex][i] + recursive_held_karp(mask | (1 << i), i, dist);  // dodajemy do maski nowy wierzchołek i wywołujemy rekurencyjnie
            if (possible_result < result) // porównujemy z dotychczasowym i wybieramy mniejszy
            {
                result = possible_result;
                next_vertex = i;
            }
        }
    }

    if (next_vertex != -1)
    {
        mask_path_matrix[mask][vertex] = mask_path_matrix[mask | (1 << next_vertex)][next_vertex];
        mask_path_matrix[mask][vertex].push_back(vertex);
    }
    mask_cost_matrix[mask][vertex] = result;   // zapisujemy otrzymany wynik do tablicy

    return result;
}

