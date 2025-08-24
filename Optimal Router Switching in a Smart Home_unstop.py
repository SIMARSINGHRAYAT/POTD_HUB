def calculate_max_demand(n, k, demands, switch_costs):
    dp = [[[-1] * (k + 2) for _ in range(n)] for _ in range(1 << n)]
    # Initialize: Start at room 0, demand collected, 0 switches used
    dp[1 << 0][0][0] = demands[0]

    for mask in range(1 << n):
        for last in range(n):
            for switches in range(k + 1):
                if dp[mask][last][switches] == -1:
                    continue
                for nxt in range(n):
                    if mask & (1 << nxt):
                        continue
                    if switches + 1 > k:
                        continue
                    new_mask = mask | (1 << nxt)
                    dp[new_mask][nxt][switches + 1] = max(
                        dp[new_mask][nxt][switches + 1],
                        dp[mask][last][switches] + demands[nxt]
                    )

    ans = 0
    for mask in range(1 << n):
        for last in range(n):
            for switches in range(k + 1):
                if dp[mask][last][switches] > ans:
                    ans = dp[mask][last][switches]
    return ans


def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    index = 0
    n = int(data[index])
    k = int(data[index + 1])
    index += 2
    demands = [int(data[i]) for i in range(index, index + n)]
    index += n
    switch_costs = []
    for i in range(n):
        row = [int(data[j]) for j in range(index, index + n)]
        switch_costs.append(row)
        index += n
    result = calculate_max_demand(n, k, demands, switch_costs)
    print(result)

if __name__ == "__main__":
    main()
