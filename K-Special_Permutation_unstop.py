mod = 10**9+7
n_max = 3000

dp = [None] * (n_max + 1)
for i in range(1, n_max + 1):
    j_len = (i + 1) // 2 + 1
    dp[i] = [0] * j_len

if n_max >= 1:
    dp[1][1] = 1

for i in range(2, n_max + 1):
    j_max_i = (i + 1) // 2
    for j in range(1, j_max_i + 1):
        term1 = 0
        if j <= (i // 2):
            term1 = (2 * j * dp[i - 1][j]) % mod
        term2 = 0
        if j - 1 <= (i // 2):
            coef = (i - 2 * j + 2) % mod
            term2 = (coef * dp[i - 1][j - 1]) % mod
        dp[i][j] = (term1 + term2) % mod

import sys
data = sys.stdin.read().split()
if not data:
    print(0)
    exit(0)
    
N = int(data[0])
K = int(data[1])

j_end = min(K, (N + 1) // 2)
total = 0
if N >= 1:
    for j in range(0, j_end + 1):
        if j < len(dp[N]):
            total = (total + dp[N][j]) % mod
        else:
            break
print(total)
