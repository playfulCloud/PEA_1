#include "DynamicProgramming_implementation.h"
#include <algorithm>
#include <iostream>

int DynamicProgramming_implementation::tsp(int** dist, int n, int pos, int mask) {
    int ans = INT_MAX;
    if(mask == (1<<n)-1) {
        currentPath.push_back(0); // Dodaj punkt powrotu do początkowego miasta
        return dist[pos][0];
    }

    if(dp[pos][mask] != -1)
        return dp[pos][mask];


    for(int city=0; city<n; city++) {
        if((mask & (1<<city)) == 0){
            int newBitMask = mask | (1<<city);
            int total_distance = dist[pos][city] + tsp(dist, n, city, newBitMask);
            ans = std::min(ans, total_distance);
        }

    }

    if(ans != INT_MAX) {
        currentPath.push_back(pos); // Dodaj aktualne miasto do ścieżki
    }

    return dp[pos][mask] = ans;
}

DynamicProgramming_implementation::DynamicProgramming_implementation(int n) {
    ans = INT_MAX;
    dp = new int*[n];
    size = n;
    for(int i = 0; i < n; i++) {
        dp[i] = new int[(1<<n)];
    }
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < (1<<n); j++){
            dp[i][j] = -1;
        }
    }
}
