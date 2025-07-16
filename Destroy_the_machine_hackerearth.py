def is_machine_running(T, D, x):
    if x == T:
        return "YES"
    if x < T + D:
        return "NO"
    # Check for pattern match
    if (x - T) % D == 0 or (x - T - 1) % D == 0:
        return "YES"
    return "NO"

def main():
    # Read input values
    T, D, x = map(int, input().split())
    # Output result
    print(is_machine_running(T, D, x))

# Run the program
if __name__ == "__main__":
    main()
