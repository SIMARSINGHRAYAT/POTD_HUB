def minEnergyCost(energy, N, K):
    dp = [float('inf')] * N
    dp[0] = 0
    for i in range(1, N):
        for j in range(max(0, i-K), i):
            dp[i] = min(dp[i], dp[j] + abs(energy[i] - energy[j]))
    return dp[N-1]

if __name__ == "__main__":
    N, K = map(int, input().split())
    energy = list(map(int, input().split()))
    result = minEnergyCost(energy, N, K)
    print(result)
