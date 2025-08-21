#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;
const int MAXN = 100001;

int n, m;
int gc[21][21];
ll dp[MAXN][21];
vector<int> adj[MAXN];

void dfs(int cur, int par) {
    bool leaf = true;

    // initialize dp[cur][i] = 1 for all i
    for (int i = 1; i <= m; i++) dp[cur][i] = 1;

    for (int nxt : adj[cur]) {
        if (nxt == par) continue;
        leaf = false;
        dfs(nxt, cur);

        for (int i = 1; i <= m; i++) {
            ll ways = 0;
            for (int j = 1; j <= m; j++) {
                ways += dp[nxt][gc[i][j]];
                if (ways >= MOD) ways -= MOD;
            }
            dp[cur][i] = (dp[cur][i] * ways) % MOD;
        }
    }

    // leaf correction
    if (leaf) {
        for (int i = 2; i <= m; i++) dp[cur][i] = 0;
        dp[cur][1] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // gcd precomputation
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            gc[i][j] = __gcd(i, j);
        }
    }

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[1][i];
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << "\n";
    return 0;
}
