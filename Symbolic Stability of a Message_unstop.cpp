def check_symbolic_stability(S):
    allowed = set(['#', '@', '$', '%', '&', '*', '!'])

    # Check if all allowed symbols are present at least once
    if not allowed.issubset(S):
        return "UNSTABLE"

    # Check no two adjacent symbols are the same
    for i in range(1, len(S)):
        if S[i] == S[i-1]:
            return "UNSTABLE"

    # Check each symbol count is even
    from collections import Counter
    counts = Counter(S)
    for sym in allowed:
        if counts[sym] % 2 != 0:
            return "UNSTABLE"

    return "STABLE"


if __name__ == "__main__":
    S = input().strip()  # Read the entire line as input
    result = check_symbolic_stability(S)
    print(result)
