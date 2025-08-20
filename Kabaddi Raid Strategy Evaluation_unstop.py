def evaluate_raids(n, raids, stamina):
    costs = {'T': 3, 'F': 1, 'R': 2}
    valid = []
    for idx in range(n):
        raid = raids[idx]
        max_stamina = stamina[idx]
        current_stamina = 0
        touched = False
        valid_raid = True

        if not raid or raid[-1] != 'R':
            continue  # Must end with R

        for i, ch in enumerate(raid):
            if ch not in costs:
                valid_raid = False
                break
            current_stamina += costs[ch]
            if current_stamina > max_stamina:
                valid_raid = False
                break
            if i > 0 and raid[i-1] == 'R' and ch == 'R':
                valid_raid = False
                break

        # Must have at least one 'T' before final 'R'
        last_r_index = raid.rfind('R')
        if last_r_index == -1 or 'T' not in raid[:last_r_index]:
            valid_raid = False

        if valid_raid:
            valid.append((current_stamina, idx))

    # Sort by stamina used, then by original order
    valid.sort()
    return [idx for _, idx in valid]


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')
    n = int(data[0])
    raids = data[1:n+1]
    stamina = list(map(int, data[n+1].split()))
    result = evaluate_raids(n, raids, stamina)
    print(" ".join(map(str, result)))
