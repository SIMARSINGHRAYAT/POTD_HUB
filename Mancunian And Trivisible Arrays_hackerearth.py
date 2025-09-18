n = int(input())
a = list(map(int, input().split()))
not_div3 = sum(1 for x in a if x % 3 != 0)
print(not_div3)
