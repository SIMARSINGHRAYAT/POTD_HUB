import sys
sys.setrecursionlimit(10**7)

def main():
    input = sys.stdin.readline
    n = int(input())
    label = input().strip()
    tree = [[] for _ in range(n)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        tree[u - 1].append(v - 1)
        tree[v - 1].append(u - 1)

    from collections import defaultdict
    freq = defaultdict(int)
    freq[0] = 1
    result = [0]

    def dfs(node, parent, mask):
        mask ^= 1 << (ord(label[node]) - ord('a'))
        result[0] += freq[mask]
        for i in range(26):
            result[0] += freq[mask ^ (1 << i)]
        freq[mask] += 1
        for nei in tree[node]:
            if nei != parent:
                dfs(nei, node, mask)
        freq[mask] -= 1

    dfs(0, -1, 0)
    print(result[0])

if __name__ == "__main__":
    main()
