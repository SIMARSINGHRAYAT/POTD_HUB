import sys
import math
from math import gcd
input = sys.stdin.readline

def solve(x):
    divisors = set()
    for i in range(1, int(math.isqrt(x)) + 1):
        if x % i == 0:
            if i != x:
                divisors.add(i)
            if x // i != x and i != x // i:
                divisors.add(x // i)
    D = len(divisors)
    if D == 0:
        print(0)
        return

    N = 0
    k = 1
    while True:
        sq = 4 * k * k
        if sq >= x:
            break
        if x % sq == 0:
            N += 1
        k += 1

    if N == 0:
        print(0)
    else:
        g = gcd(N, D)
        print(f"{N//g}/{D//g}")

T = int(input())
for _ in range(T):
    X = int(input())
    solve(X)
