class SegmentTree:
    def __init__(self, data):
        self.n = len(data)
        self.tree = [0] * (4 * self.n)
        self.lazy = [0] * (4 * self.n)
        self.build(data, 0, 0, self.n - 1)

    def build(self, data, idx, l, r):
        if l == r:
            self.tree[idx] = data[l]
        else:
            m = (l + r) // 2
            self.build(data, 2*idx+1, l, m)
            self.build(data, 2*idx+2, m+1, r)
            self.tree[idx] = self.tree[2*idx+1] + self.tree[2*idx+2]

    def push(self, idx, l, r):
        if self.lazy[idx] != 0:
            self.tree[idx] += (r - l + 1) * self.lazy[idx]
            if l != r:
                self.lazy[2*idx+1] += self.lazy[idx]
                self.lazy[2*idx+2] += self.lazy[idx]
            self.lazy[idx] = 0

    def update(self, idx, l, r, ql, qr, val):
        self.push(idx, l, r)
        if qr < l or ql > r:
            return
        if ql <= l and r <= qr:
            self.lazy[idx] += val
            self.push(idx, l, r)
            return
        m = (l + r) // 2
        self.update(2*idx+1, l, m, ql, qr, val)
        self.update(2*idx+2, m+1, r, ql, qr, val)
        self.tree[idx] = self.tree[2*idx+1] + self.tree[2*idx+2]

    def query(self, idx, l, r, ql, qr):
        self.push(idx, l, r)
        if qr < l or ql > r:
            return 0
        if ql <= l and r <= qr:
            return self.tree[idx]
        m = (l + r) // 2
        return self.query(2*idx+1, l, m, ql, qr) + self.query(2*idx+2, m+1, r, ql, qr)


def turbine_operations(n, q, initial_flows, operations):
    st = SegmentTree(initial_flows)
    results = []

    for op in operations:
        if op[0] == 1:
            _, l, r, v = op
            st.update(0, 0, n - 1, l - 1, r - 1, v)
        else:
            _, l, r = op
            res = st.query(0, 0, n - 1, l - 1, r - 1)
            results.append(res)

    return results



def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    
    index = 0
    n = int(data[index])
    q = int(data[index + 1])
    index += 2
    
    initial_flows = list(map(int, data[index:index + n]))
    index += n
    
    operations = []
    for _ in range(q):
        op_type = int(data[index])
        if op_type == 1:
            l = int(data[index + 1])
            r = int(data[index + 2])
            v = int(data[index + 3])
            operations.append((op_type, l, r, v))
            index += 4
        elif op_type == 2:
            l = int(data[index + 1])
            r = int(data[index + 2])
            operations.append((op_type, l, r))
            index += 3

    # Call the user logic function
    results = turbine_operations(n, q, initial_flows, operations)
    
    # Print results for each type 2 operation
    for result in results:
        print(result)


if __name__ == "__main__":
    main()
