#include <bits/stdc++.h>
using namespace std;

int mat[1009][1009];
int row[1009][1009];
int col[1009][1009];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // Input matrix and reset row/col arrays
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> mat[i][j];
                row[i][j] = col[i][j] = 0; // Clear for each test case
            }
        }
        
        int colMax = 0, rowMax = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // Count consecutive equal elements in the column
                col[i][j] = 1;
                if (i > 1 && mat[i][j] == mat[i - 1][j]) {
                    col[i][j] += col[i - 1][j];
                }
                // Count consecutive equal elements in the row
                row[i][j] = 1;
                if (j > 1 && mat[i][j] == mat[i][j - 1]) {
                    row[i][j] += row[i][j - 1];
                }
                colMax = max(colMax, col[i][j]);
                rowMax = max(rowMax, row[i][j]);
            }
        }
        cout << (colMax * rowMax) << endl;
    }
    return 0;
}
