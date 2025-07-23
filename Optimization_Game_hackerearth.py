def optimize_game(arr):
    i = 0
    while i < len(arr):
        carry = arr[i] // 2
        arr[i] %= 2
        if carry > 0:
            if i + 1 < len(arr):
                arr[i + 1] += carry
            else:
                arr.append(carry)
        i += 1
    return sum(arr)

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))
    print(optimize_game(A))
