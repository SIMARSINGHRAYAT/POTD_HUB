def main():
    import math

    # Precompute primes up to 100
    is_prime = [True] * 101
    is_prime[0] = False
    is_prime[1] = False
    for i in range(2, 101):
        if is_prime[i]:
            for j in range(i*i, 101, i):
                is_prime[j] = False

    n = int(input().strip())
    arr = list(map(int, input().split()))
    
    # Initialize dp table with zeros
    dp = [[0] * n for _ in range(n)]
    
    # Precompute for segments of length 1
    for i in range(n):
        left_b = arr[i-1] if i-1 >= 0 else 1
        right_b = arr[i+1] if i+1 < n else 1
        base_score = (left_b + 2) * arr[i] * (right_b + 2)
        bonus_score = arr[i] if arr[i] >= 2 and is_prime[arr[i]] else 0
        dp[i][i] = base_score + bonus_score
        
    # Compute for segments of longer lengths
    for length in range(2, n+1):
        for i in range(0, n - length + 1):
            j = i + length - 1
            left_b = arr[i-1] if i-1 >= 0 else 1
            right_b = arr[j+1] if j+1 < n else 1
            best = 0
            for k in range(i, j+1):
                left_seg = dp[i][k-1] if k-1 >= i else 0
                right_seg = dp[k+1][j] if k+1 <= j else 0
                base_score = (left_b + 2) * arr[k] * (right_b + 2)
                bonus_score = arr[k] if arr[k] >= 2 and is_prime[arr[k]] else 0
                total = left_seg + right_seg + base_score + bonus_score
                if total > best:
                    best = total
            dp[i][j] = best
            
    print(dp[0][n-1])

if __name__ == "__main__":
    main()
