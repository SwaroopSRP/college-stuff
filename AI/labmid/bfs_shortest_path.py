from collections import deque

def bfs_shortest_path(graph, start, goal):
    """
    graph: adjacency list (dictionary)
    start: starting node
    goal: destination node
    """

    # Create queue and push (node, path)
    queue = deque()
    queue.append((start, [start]))

    visited = set()

    while queue:
        node, path = queue.popleft()

        # If goal found → return path
        if node == goal:
            return path

        if node not in visited:
            visited.add(node)

            # Add neighbors to queue
            for neighbor in graph[node]:
                queue.append((neighbor, path + [neighbor]))

    return None   # If no path exists
