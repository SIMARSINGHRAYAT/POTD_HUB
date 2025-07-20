import heapq

def min_parking_spots(cars):
    if not cars:
        return 0

    # Convert each car to (arrival, departure)
    times = [(a, a + d) for a, d in cars]
    times.sort()  # Sort by arrival time

    min_heap = []
    max_spots = 0

    for arrival, departure in times:
        while min_heap and min_heap[0] <= arrival:
            heapq.heappop(min_heap)  # Free up spots

        heapq.heappush(min_heap, departure)
        max_spots = max(max_spots, len(min_heap))

    return max_spots


if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split('\n')
    N = int(data[0])
    cars = []
    for i in range(1, N + 1):
        A, D = map(int, data[i].split())
        cars.append((A, D))
    
    result = min_parking_spots(cars)
    print(result)
