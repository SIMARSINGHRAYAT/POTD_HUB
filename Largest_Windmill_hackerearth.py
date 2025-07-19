import sys
from collections import deque

def main():
    data = sys.stdin.read().split()
    if not data:
        print(1)
        return
        
    n = int(data[0])
    graph = [[] for _ in range(n+1)]
    index = 1
    for i in range(n-1):
        u = int(data[index]); v = int(data[index+1]); index += 2
        graph[u].append(v)
        graph[v].append(u)
    
    if n == 1:
        print(1)
        return
        
    dist1 = [-1] * (n+1)
    q = deque()
    q.append(1)
    dist1[1] = 0
    u_node = 1
    while q:
        node = q.popleft()
        if dist1[node] > dist1[u_node]:
            u_node = node
        for neighbor in graph[node]:
            if dist1[neighbor] == -1:
                dist1[neighbor] = dist1[node] + 1
                q.append(neighbor)
                
    distU = [-1] * (n+1)
    q.append(u_node)
    distU[u_node] = 0
    v_node = u_node
    while q:
        node = q.popleft()
        if distU[node] > distU[v_node]:
            v_node = node
        for neighbor in graph[node]:
            if distU[neighbor] == -1:
                distU[neighbor] = distU[node] + 1
                q.append(neighbor)
                
    distV = [-1] * (n+1)
    q.append(v_node)
    distV[v_node] = 0
    while q:
        node = q.popleft()
        for neighbor in graph[node]:
            if distV[neighbor] == -1:
                distV[neighbor] = distV[node] + 1
                q.append(neighbor)
                
    deg = [0] * (n+1)
    for i in range(1, n+1):
        deg[i] = len(graph[i])
        
    best_size = 0
    best_center = None
    for i in range(1, n+1):
        ecc_i = max(distU[i], distV[i])
        if deg[i] >= 5 and ecc_i >= 3:
            candidate = deg[i] + ecc_i
            if candidate > best_size:
                best_size = candidate
                best_center = i
            elif candidate == best_size and i < best_center:
                best_center = i
                
    if best_center is None:
        print(1)
    else:
        print(f"{best_size} {best_center}")

if __name__ == "__main__":
    main()
