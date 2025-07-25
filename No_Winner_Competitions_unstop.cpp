import sys

# Set higher recursion depth for deep DP calls
try:
    sys.setrecursionlimit(2000)
except Exception as e:
    print(f"Warning: Could not set recursion depth. {e}", file=sys.stderr)
    pass

# --- Global Precomputation ---
MOD = 10**9 + 7
MAX_N = 505
fact = [1] * MAX_N
invfact = [1] * MAX_N

# Precompute factorials
for i in range(1, MAX_N):
    fact[i] = (fact[i - 1] * i) % MOD

# Precompute inverse factorials using Fermat's Little Theorem
invfact[MAX_N - 1] = pow(fact[MAX_N - 1], MOD - 2, MOD)
for i in range(MAX_N - 2, -1, -1):
    invfact[i] = (invfact[i + 1] * (i + 1)) % MOD

memo = {}

# --- Helper Functions ---
def power(a, b):
    res = 1
    a %= MOD
    while b > 0:
        if b % 2 == 1:
            res = (res * a) % MOD
        a = (a * a) % MOD
        b //= 2
    return res

def nCr_mod(n, r):
    if r < 0 or r > n:
        return 0
    if r == 0 or r == n:
        return 1
    if r > n // 2:
        r = n - r
    num = fact[n]
    den = (invfact[r] * invfact[n - r]) % MOD
    return (num * den) % MOD

def solve_g(i, m):
    if i == 0:
        return 0
    if i == 1:
        return m % MOD
    if m <= 0:
        return 0

    state = (i, m)
    if state in memo:
        return memo[state]

    E = min(m, i - 1)
    R = m - E
    g_i_m = 0

    for k in range(1, i + 1):
        combinations = nCr_mod(i, k)
        if combinations == 0:
            continue
        term_k_winner = solve_g(k, R)
        if term_k_winner == 0 and k > 0:
            continue
        pow_E = power(E, i - k)
        term = (combinations * term_k_winner) % MOD
        term = (term * pow_E) % MOD
        g_i_m = (g_i_m + term) % MOD

    memo[state] = g_i_m
    return g_i_m

def no_winner_competition(N, M):
    memo.clear()
    total_ways = power(M, N)
    ways_one_winner = solve_g(N, M)
    ways_no_winner = (total_ways - ways_one_winner + MOD) % MOD
    return ways_no_winner

def main():
    input_data = sys.stdin.read
    try:
        data = input_data().strip().split()
        N = int(data[0])
        M = int(data[1])
        if not (1 <= N < MAX_N and 1 <= M):
            print(f"Constraints violated: 1 <= N < {MAX_N}, 1 <= M", file=sys.stderr)
            return
        result = no_winner_competition(N, M)
        print(result)
    except (ValueError, IndexError):
        print("Invalid input format. Please provide two integers N and M.", file=sys.stderr)
    except Exception as e:
        print(f"An unexpected error occurred: {e}", file=sys.stderr)

if __name__ == "__main__":
    main()
