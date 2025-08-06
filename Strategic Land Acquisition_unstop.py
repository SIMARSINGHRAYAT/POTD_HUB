from collections import deque

def find_min_cost_and_max(grid, N, M, K):
    min_total_price = float('inf')
    lowest_max_price = float('inf')

    # Helper function to process a 1D array (row or column) with sliding window
    def process_line(line):
        nonlocal min_total_price, lowest_max_price
        window_sum = 0
        max_deque = deque()

        for i in range(len(line)):
            window_sum += line[i]

            # Maintain deque for max in the window
            while max_deque and line[i] >= line[max_deque[-1]]:
                max_deque.pop()
            max_deque.append(i)

            # When window reaches size K
            if i >= K - 1:
                if i >= K:
                    window_sum -= line[i - K]
                    if max_deque[0] == i - K:
                        max_deque.popleft()

                current_max = line[max_deque[0]]
                if window_sum < min_total_price:
                    min_total_price = window_sum
                    lowest_max_price = current_max
                elif window_sum == min_total_price:
                    lowest_max_price = min(lowest_max_price, current_max)

    # Check all rows
    for row in grid:
        process_line(row)

    # Check all columns
    for col in range(M):
        column = [grid[row][col] for row in range(N)]
        process_line(column)

    return (min_total_price, lowest_max_price)

def main():
    # Input handling
    N, M, K = map(int, input().split())
    grid = [list(map(int, input().split())) for _ in range(N)]

    # Call the user logic function
    result = find_min_cost_and_max(grid, N, M, K)

    # Output the result
    print(result[0], result[1])

if __name__ == "__main__":
    main()
