def min_operations(n, E, T):
    # User logic to be implemented here
    # Parameters:
    #  - n: Number of sectors
    #  - E: List of initial energy levels
    #  - T: List of required energy thresholds
    # Return:
    #  - An integer representing the minimum number of wave operations needed
    diff = [T[i] - E[i] for i in range(n)]

    ops = 0
    i = 0
    while i < n:
        if diff[i] == 0:
            i += 1
            continue

        sign = 1 if diff[i] > 0 else -1
        j = i
        while j < n and diff[j] * sign > 0:
            j += 1

        min_val = min(abs(diff[k]) for k in range(i, j))
        ops += min_val

        for k in range(i, j):
            diff[k] -= sign * min_val

    return ops # Placeholder return statement

if __name__ == '__main__':
    n = int(input()) # Read the number of sectors

    E = list(map(int, input().split())) # Read initial energy levels
    T = list(map(int, input().split())) # Read required energy thresholds

    # Call the user logic function
    result = min_operations(n, E, T)

    # Print the result
    print(result)
