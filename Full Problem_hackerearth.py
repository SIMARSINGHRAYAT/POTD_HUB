t = int(input())
for _ in range(t):
    x = int(input())
    n = 360 / (180 - x)
    if n == int(n) and n >= 3:
        print("YES")
    else:
        print("NO")
