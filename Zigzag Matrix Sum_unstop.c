#include <stdio.h>

int zigzagSum(int matrix[100][100], int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Left to right
            for (int j = 0; j < m; j++)
                sum += matrix[i][j];
        } else {
            // Right to left
            for (int j = m - 1; j >= 0; j--)
                sum += matrix[i][j];
        }
    }
    return sum;
}

int main() {
    int n, m, matrix[100][100];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);
    printf("%d\n", zigzagSum(matrix, n, m));
    return 0;
}
