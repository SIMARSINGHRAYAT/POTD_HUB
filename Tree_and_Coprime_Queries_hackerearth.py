import sys
import math
from collections import deque

def main():
    data = sys.stdin.read().split()
    it = iter(data)
    n = int(next(it))
    q = int(next(it))
    val = [0] * (n + 1)
    for i in range(1, n + 1):
        val[i] = int(next(it))
    
    graph = [[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u = int(next(it))
        v = int(next(it))
        graph[u].append(v)
        graph[v].append(u)
    
    depth = [-1] * (n + 1)
    parent0 = [0] * (n + 1)
    depth[1] = 0
    queue = deque([1])
    while queue:
        u = queue.popleft()
        for v in graph[u]:
            if depth[v] == -1:
                depth[v] = depth[u] + 1
                parent0[v] = u
                queue.append(v)
    
    LOG = (n).bit_length()
    up = [[0] * (n + 1) for _ in range(LOG)]
    for i in range(1, n + 1):
        up[0][i] = parent0[i]
    
    for i in range(1, LOG):
        for v in range(1, n + 1):
            p = up[i - 1][v]
            if p:
                up[i][v] = up[i - 1][p]
    
    def lca(a, b):
        if depth[a] < depth[b]:
            a, b = b, a
        d = depth[a] - depth[b]
        for i in range(LOG - 1, -1, -1):
            if d & (1 << i):
                a = up[i][a]
        if a == b:
            return a
        for i in range(LOG - 1, -1, -1):
            if up[i][a] != up[i][b]:
                a = up[i][a]
                b = up[i][b]
        return up[0][a]
    
    out_lines = []
    for _ in range(q):
        t = int(next(it))
        if t == 0:
            a = int(next(it))
            x = int(next(it))
            val[a] = x
        else:
            a = int(next(it))
            b = int(next(it))
            c_val = int(next(it))
            p = lca(a, b)
            count = 0
            cur = a
            while cur != p:
                if math.gcd(val[cur], c_val) == 1:
                    count += 1
                cur = parent0[cur]
            if math.gcd(val[p], c_val) == 1:
                count += 1
            cur = b
            while cur != p:
                if math.gcd(val[cur], c_val) == 1:
                    count += 1
                cur = parent0[cur]
            out_lines.append(str(count))
    
    sys.stdout.write("\n".join(out_lines) + "\n")

if __name__ == '__main__':
    main()
