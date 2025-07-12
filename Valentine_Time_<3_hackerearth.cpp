#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 1000001;
vector<int> totalDiv(MAX, 0), primeDiv(MAX, 0);

// Sieve to count total divisors and prime divisors
void preprocess() {
    vector<bool> isPrime(MAX, true);
    isPrime[0] = isPrime[1] = false;

    // Precompute prime numbers
    for (int i = 2; i * i < MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 1; i < MAX; ++i) {
        for (int j = i; j < MAX; j += i) {
            totalDiv[j]++;
            if (isPrime[i]) primeDiv[j]++;
        }
    }
}

int getBestNumber(int L, int R) {
    int bestNum = L;
    int bestScore = totalDiv[L] - primeDiv[L];

    for (int x = L + 1; x <= R; ++x) {
        int score = totalDiv[x] - primeDiv[x];
        if (score > bestScore || (score == bestScore && x < bestNum)) {
            bestScore = score;
            bestNum = x;
        }
    }

    return bestNum;
}

int main() {
    preprocess();  // Run sieve before queries

    int T;
    cin >> T;

    while (T--) {
        int L, R;
        cin >> L >> R;
        cout << getBestNumber(L, R) << endl;
    }

    return 0;
}
