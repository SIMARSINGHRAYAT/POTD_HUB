#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> a(N, vector<int>(N));
        vector<vector<int>> dp(N, vector<int>(N, 1));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> a[i][j];
            }
        }

        int ans = 1;
        for (int i = 1; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                if (a[i][j] == a[i-1][j] &&
                    a[i][j] == a[i][j-1] &&
                    a[i][j] == a[i-1][j-1]) {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                } else {
                    dp[i][j] = 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
