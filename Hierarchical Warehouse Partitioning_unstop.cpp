#include <iostream>
#include <vector>
#include <algorithm> // for std::max

int user_logic(int N, int M, int L, const std::vector<std::vector<std::vector<int>>>& warehouse) {
    int max_stock = 0; // Since all values are non-negative
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < L; k++) {
                max_stock = std::max(max_stock, warehouse[i][j][k]);
            }
        }
    }
    return max_stock;
}

int main() {
    int N, M, L;
    std::cin >> N >> M >> L;

    std::vector<std::vector<std::vector<int>>> warehouse(
        N, std::vector<std::vector<int>>(M, std::vector<int>(L))
    );

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < L; k++) {
                std::cin >> warehouse[i][j][k];
            }
        }
    }

    int result = user_logic(N, M, L, warehouse);
    std::cout << result << std::endl;

    return 0;
}
