import heapq

def ucs_shortest_path(graph, start, goal):
    """
    graph: adjacency list with weights
           { node: [(neighbor, cost), ...] }

    start: starting node
    goal: destination node
    """

    # Priority queue stores (total_cost, node, path)
    pq = []
    heapq.heappush(pq, (0, start, [start]))

    visited = set()

    while pq:
        cost, node, path = heapq.heappop(pq)

        # If goal reached → return result
        if node == goal:
            return path, cost

        if node not in visited:
            visited.add(node)

            # Expand neighbors
            for neighbor, edge_cost in graph[node]:
                heapq.heappush(
                    pq,
                    (cost + edge_cost, neighbor, path + [neighbor])
                )

    return None

graph = {
    "A": ["B", "C"],
    "B": ["D", "E"],
    "C": ["F"],
    "D": [],
    "E": ["F"],
    "F": []
}

print(bfs_shortest_path(graph, "A", "F"))
