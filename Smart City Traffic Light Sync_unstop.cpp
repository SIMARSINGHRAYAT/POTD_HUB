import heapq

def minTimeToReach(N, M, G, R, adj):
    min_time = [float('inf')] * (N + 1)
    heap = [(0, 1)]
    min_time[1] = 0

    while heap:
        t, u = heapq.heappop(heap)
        if u == N:
            return t
        if t > min_time[u]:
            continue
        for v in adj[u]:
            travel_time = t + 1
            g, r = G[v-1], R[v-1]
            cycle = g + r
            t_mod = travel_time % cycle
            if t_mod < g:
                arrival = travel_time
            else:
                wait = cycle - t_mod
                arrival = travel_time + wait
            if arrival < min_time[v]:
                min_time[v] = arrival
                heapq.heappush(heap, (arrival, v))
    return -1


if __name__ == "__main__":
    N, M = map(int, input().split())
    G = list(map(int, input().split()))
    R = list(map(int, input().split()))

    adj = [[] for _ in range(N + 1)]
    for _ in range(M):
        U, V = map(int, input().split())
        adj[U].append(V)
        adj[V].append(U)  # Assuming bidirectional roads

    # Call the user logic function and print the result
    result = minTimeToReach(N, M, G, R, adj)
    print(result)
