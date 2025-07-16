import sys
sys.setrecursionlimit(300000)

def main():
    data = sys.stdin.read().split()
    if not data:
        return
    
    n = int(data[0])
    q = int(data[1])
    A = list(map(int, data[2:2+n]))
    
    size = 4 * n
    tree_freq = [[0] * 8 for _ in range(size)]
    tree_lazy = [0] * size
    
    def build(node, l, r):
        if l == r:
            for i in range(8):
                tree_freq[node][i] = 0
            tree_freq[node][A[l]] = 1
        else:
            mid = (l + r) // 2
            left_child = 2 * node
            right_child = 2 * node + 1
            build(left_child, l, mid)
            build(right_child, mid+1, r)
            for i in range(8):
                tree_freq[node][i] = tree_freq[left_child][i] + tree_freq[right_child][i]
    
    build(1, 0, n-1)
    
    def push_down(node, l, r):
        if tree_lazy[node] != 0:
            if l != r:
                left_child = 2 * node
                right_child = 2 * node + 1
                temp_left = tree_freq[left_child][:]
                for j in range(8):
                    tree_freq[left_child][j] = temp_left[j ^ tree_lazy[node]]
                tree_lazy[left_child] ^= tree_lazy[node]
                
                temp_right = tree_freq[right_child][:]
                for j in range(8):
                    tree_freq[right_child][j] = temp_right[j ^ tree_lazy[node]]
                tree_lazy[right_child] ^= tree_lazy[node]
                
            tree_lazy[node] = 0

    def update(node, l, r, ql, qr, M):
        if qr < l or ql > r:
            return
        push_down(node, l, r)
        if ql <= l and r <= qr:
            temp = tree_freq[node][:]
            for j in range(8):
                tree_freq[node][j] = temp[j ^ M]
            tree_lazy[node] ^= M
            return
        
        mid = (l + r) // 2
        left_child = 2 * node
        right_child = 2 * node + 1
        update(left_child, l, mid, ql, qr, M)
        update(right_child, mid+1, r, ql, qr, M)
        for j in range(8):
            tree_freq[node][j] = tree_freq[left_child][j] + tree_freq[right_child][j]
    
    def query(node, l, r, ql, qr):
        if qr < l or ql > r:
            return [0] * 8
        push_down(node, l, r)
        if ql <= l and r <= qr:
            return tree_freq[node][:]
        
        mid = (l + r) // 2
        left_child = 2 * node
        right_child = 2 * node + 1
        left_vec = query(left_child, l, mid, ql, qr)
        right_vec = query(right_child, mid+1, r, ql, qr)
        res = [0] * 8
        for j in range(8):
            res[j] = left_vec[j] + right_vec[j]
        return res

    index = 2 + n
    output = []
    for _ in range(q):
        t = int(data[index]); index += 1
        if t == 1:
            L = int(data[index]); R = int(data[index+1]); M = int(data[index+2]); index += 3
            update(1, 0, n-1, L-1, R-1, M)
        else:
            L = int(data[index]); R = int(data[index+1]); index += 2
            freq_vec = query(1, 0, n-1, L-1, R-1)
            output.append(str(max(freq_vec)))
    
    sys.stdout.write("\n".join(output))

if __name__ == '__main__':
    main()
