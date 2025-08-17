for _ in range(int(input())):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    min_A = min(A)
    print(max(0, K - min_A))
