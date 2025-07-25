import heapq

def min_cost_uniform_path(grid):
    N, M = len(grid), len(grid[0])
    heights = range(1, 101)  # Try every possible target height
    min_total_cost = float('inf')

    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

    for target_height in heights:
        # Dijkstra's initialization
        dist = [[float('inf')] * M for _ in range(N)]
        pq = []
        start_cost = abs(grid[0][0] - target_height)
        dist[0][0] = start_cost
        heapq.heappush(pq, (start_cost, 0, 0))

        while pq:
            cost, x, y = heapq.heappop(pq)

            if (x, y) == (N - 1, M - 1):
                min_total_cost = min(min_total_cost, cost)
                break  # Early exit on reaching target

            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if 0 <= nx < N and 0 <= ny < M:
                    new_cost = cost + abs(grid[nx][ny] - target_height)
                    if new_cost < dist[nx][ny]:
                        dist[nx][ny] = new_cost
                        heapq.heappush(pq, (new_cost, nx, ny))

    return min_total_cost

# --- Read Input ---
def main():
    import sys
    input = sys.stdin.read
    data = input().strip().split()
    N, M = int(data[0]), int(data[1])
    A = []
    index = 2
    for _ in range(N):
        row = list(map(int, data[index:index + M]))
        A.append(row)
        index += M

    result = min_cost_uniform_path(A)
    print(result)

if __name__ == "__main__":
    main()
