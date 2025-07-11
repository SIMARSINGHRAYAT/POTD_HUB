mod = 1000000007
MAX = 100000
fact = [1] * (MAX + 1)

for i in range(1, MAX + 1):
    fact[i] = (fact[i - 1] * i) % mod

import sys

def main():
    data = sys.stdin.read().split()
    t = int(data[0])
    index = 1
    out_lines = []
    for _ in range(t):
        a = int(data[index])
        b = int(data[index + 1])
        c = int(data[index + 2])
        d = int(data[index + 3])
        index += 4
        res = fact[a] * fact[b] % mod
        res = res * fact[c] % mod
        out_lines.append(str(res))
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    main()
