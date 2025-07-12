import math
from functools import reduce

def lcm(x, y):
    return x * y // math.gcd(x, y)

def find_valid_time(gears):
    delays = [a for a, f in gears]
    forbids = [f for a, f in gears]

    T = reduce(lcm, delays)  # Candidate time

    # Check forbidden conditions
    for f in forbids:
        if T % f == 0:
            return -1
    return T
n = int(input())
gears = [tuple(map(int, input().split())) for _ in range(n)]
print(find_valid_time(gears))
