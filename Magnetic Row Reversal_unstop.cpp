#include <iostream>
#include <vector>
using namespace std;

int minOperationsToNonNegative(int n, int k, vector<int>& A) {
    int flips = 0;
    for (int i = 0; i <= n - k; ++i) {
        if (A[i] == -1) {
            for (int j = 0; j < k; ++j) {
                if (A[i + j] != 0)
                    A[i + j] *= -1;
            }
            ++flips;
        }
    }
    // Check for impossible case
    for (int i = n - k + 1; i < n; ++i) {
        if (A[i] == -1)
            return -1;
    }
    return flips;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];
    cout << minOperationsToNonNegative(n, k, A) << endl;
    return 0;
}
