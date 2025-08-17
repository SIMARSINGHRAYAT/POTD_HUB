n = int(input().strip())
cards = [input().strip() for _ in range(n)]
i = 0
while i < len(cards):
    j = i
    color_ok = True
    number_ok = True
    last_valid = -1
    while j < len(cards):
        if j > i:
            if color_ok and cards[j][0] != cards[i][0]:
                color_ok = False
            if number_ok and cards[j][1] != cards[i][1]:
                number_ok = False
        length = j - i + 1
        if length >= 3 and (color_ok or number_ok):
            last_valid = j
        if not color_ok and not number_ok:
            break
        j += 1
        
    if last_valid != -1:
        del cards[i:last_valid+1]
        i = max(0, i - 2)
    else:
        i += 1

if not cards:
    print("All cards removed!")
else:
    print(" ".join(cards))
