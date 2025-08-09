def is_perfect_square(n):
    x = int(n**0.5)
    return x*x == n

T = int(input())
for _ in range(T):
    N = int(input().strip())
    test1 = 5*N*N + 4
    test2 = 5*N*N - 4

    # For extra safety, use isqrt from math
    from math import isqrt
    def is_psq(x):
        y = isqrt(x)
        return y*y == x

    if is_psq(test1) or is_psq(test2):
        print("YES")
    else:
        print("NO")
