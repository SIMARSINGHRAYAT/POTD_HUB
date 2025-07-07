#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Helper function to check if a number is prime
bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i <= sqrt(num); i += 2)
        if (num % i == 0) return false;
    return true;
}

void prime_matrix(int n, vector<vector<int>>& matrix) {
    vector<bool> row(n, false), col(n, false);

    // First pass: identify rows and columns to be marked
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (isPrime(matrix[i][j])) {
                row[i] = true;
                col[j] = true;
            }

    // Second pass: mark the matrix
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (row[i] || col[j])
                matrix[i][j] = -1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    prime_matrix(n, matrix);

    for (const auto& row : matrix) {
        for (const auto& val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}
