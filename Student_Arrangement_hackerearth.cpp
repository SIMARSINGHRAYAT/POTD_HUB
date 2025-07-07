#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> seats(M + 1, 0); // 1-based indexing
    set<int> availableRows;
    for (int i = 1; i <= M; ++i) {
        availableRows.insert(i);
    }

    int notPreferred = 0;

    for (int i = 0; i < N; ++i) {
        int pref = A[i];
        auto it = availableRows.lower_bound(pref);

        if (it == availableRows.end()) {
            it = availableRows.begin(); // wrap around
        }

        if (it == availableRows.end()) {
            // No available row
            notPreferred++;
            continue;
        }

        int assignedRow = *it;
        seats[assignedRow]++;
        if (assignedRow != pref) {
            notPreferred++;
        }

        if (seats[assignedRow] == K) {
            availableRows.erase(assignedRow);
        }
    }

    cout << notPreferred << '\n';
    return 0;
}
