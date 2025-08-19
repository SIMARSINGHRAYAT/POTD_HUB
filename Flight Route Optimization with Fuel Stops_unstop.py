import heapq

def min_refuels(N, M, D, S, T, flights):
    from collections import defaultdict

    graph = defaultdict(list)
    for u, v, dist in flights:
        graph[u].append((v, dist))

    # (refuels, -fuel_left, city)
    heap = [(0, -D, S)]
    visited = {}

    while heap:
        refuels, neg_fuel, u = heapq.heappop(heap)
        fuel = -neg_fuel
        # If at target
        if u == T:
            return refuels
        state = (u, fuel)
        if state in visited and visited[state] <= refuels:
            continue
        visited[state] = refuels

        for v, dist in graph[u]:
            if dist > D:
                continue  # Cannot take this flight at all
            if fuel >= dist:
                # Go without refuel
                heapq.heappush(heap, (refuels, -(fuel - dist), v))
            else:
                # Refuel at current node (not at T)
                if u != T:
                    heapq.heappush(heap, (refuels + 1, -(D - dist), v))
    return -1

# Example usage:
# N, M, D = 5, 6, 500
# S, T = 1, 5
# flights = [
#     [1, 2, 300],
#     [2, 3, 400],
#     [3, 4, 600],
#     [4, 5, 200],
#     [1, 3, 450],
#     [3, 5, 400]
# ]
# print(min_refuels(N, M, D, S, T, flights))  # Output: 1



if __name__ == "__main__":
    N, M, D = map(int, input().split())
    S, E = map(int, input().split())

    flights = [list(map(int, input().split())) for _ in range(M)]

    result = min_refuels(N, M, D, S, E, flights)
    print(result)
