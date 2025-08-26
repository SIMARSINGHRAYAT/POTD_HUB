n, m, q = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
diff = [[0] * (m + 2) for _ in range(n + 2)]
for _ in range(q):
    r, c, s, d = map(int, input().split())
    r -= 1
    c -= 1
    diff[r][c] += d
    diff[r + s][c] -= d
    diff[r][c + s] -= d
    diff[r + s][c + s] += d
for i in range(n + 1):
    for j in range(m + 1):
        if i > 0:
            diff[i][j] += diff[i - 1][j]
        if j > 0:
            diff[i][j] += diff[i][j - 1]
        if i > 0 and j > 0:
            diff[i][j] -= diff[i - 1][j - 1]
for i in range(n):
    row = []
    for j in range(m):
        row.append(str(a[i][j] + diff[i][j]))
    print(" ".join(row))
