import sys
sys.setrecursionlimit(1 << 25)

class SegmentTree:
    def __init__(self, size):
        self.N = size
        self.tree = [0] * (4 * size)
        self.lazy = [0] * (4 * size)

    def push(self, node, l, r):
        if self.lazy[node]:
            self.tree[node] = (r - l + 1) - self.tree[node]
            if l != r:
                self.lazy[node * 2] ^= 1
                self.lazy[node * 2 + 1] ^= 1
            self.lazy[node] = 0

    def update(self, node, l, r, i, j):
        self.push(node, l, r)
        if r < i or j < l:
            return
        if i <= l and r <= j:
            self.lazy[node] ^= 1
            self.push(node, l, r)
            return
        m = (l + r) // 2
        self.update(node * 2, l, m, i, j)
        self.update(node * 2 + 1, m + 1, r, i, j)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]

    def query(self, node, l, r, i, j):
        self.push(node, l, r)
        if r < i or j < l:
            return 0
        if i <= l and r <= j:
            return self.tree[node]
        m = (l + r) // 2
        return self.query(node * 2, l, m, i, j) + self.query(node * 2 + 1, m + 1, r, i, j)


def process_queries(n, edges, queries):
    from collections import defaultdict

    tree = defaultdict(list)
    for u, v in edges:
        tree[u].append(v)
        tree[v].append(u)

    parent = [0] * (n + 1)
    depth = [0] * (n + 1)
    size = [0] * (n + 1)
    heavy = [0] * (n + 1)
    head = [0] * (n + 1)
    pos = [0] * (n + 1)
    current_pos = [1]  # simulate mutable integer

    def dfs(u, p):
        size[u] = 1
        max_size = 0
        for v in tree[u]:
            if v != p:
                parent[v] = u
                depth[v] = depth[u] + 1
                dfs(v, u)
                size[u] += size[v]
                if size[v] > max_size:
                    max_size = size[v]
                    heavy[u] = v

    def decompose(u, h):
        head[u] = h
        pos[u] = current_pos[0]
        current_pos[0] += 1
        if heavy[u]:
            decompose(heavy[u], h)
        for v in tree[u]:
            if v != parent[u] and v != heavy[u]:
                decompose(v, v)

    dfs(1, 0)
    decompose(1, 1)
    seg_tree = SegmentTree(n)

    def path_update(u, v):
        while head[u] != head[v]:
            if depth[head[u]] < depth[head[v]]:
                u, v = v, u
            seg_tree.update(1, 1, n, pos[head[u]], pos[u])
            u = parent[head[u]]
        if depth[u] > depth[v]:
            u, v = v, u
        if u != v:
            seg_tree.update(1, 1, n, pos[u] + 1, pos[v])

    def path_query(u, v):
        res = 0
        while head[u] != head[v]:
            if depth[head[u]] < depth[head[v]]:
                u, v = v, u
            res += seg_tree.query(1, 1, n, pos[head[u]], pos[u])
            u = parent[head[u]]
        if depth[u] > depth[v]:
            u, v = v, u
        if u != v:
            res += seg_tree.query(1, 1, n, pos[u] + 1, pos[v])
        return res

    results = []
    for t, u, v in queries:
        if t == 1:
            path_update(u, v)
        else:
            results.append(path_query(u, v))
    return results


def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    index = 0
    n = int(data[index])
    index += 1
    edges = []
    for _ in range(n - 1):
        a = int(data[index])
        b = int(data[index + 1])
        edges.append((a, b))
        index += 2
    q = int(data[index])
    index += 1
    queries = []
    for _ in range(q):
        t = int(data[index])
        u = int(data[index + 1])
        v = int(data[index + 2])
        queries.append((t, u, v))
        index += 3
    results = process_queries(n, edges, queries)
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
