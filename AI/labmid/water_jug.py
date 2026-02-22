from collections import deque

def water_jug_bfs(cap1, cap2, goal):

    start = (0, 0)
    queue = deque([(start, [start])])
    visited = set()

    while queue:
        (x, y), path = queue.popleft()

        if x == goal or y == goal:
            return path

        if (x, y) in visited:
            continue

        visited.add((x, y))

        next_states = []

        next_states.append((cap1, y))          # Fill Jug1
        next_states.append((x, cap2))          # Fill Jug2
        next_states.append((0, y))             # Empty Jug1
        next_states.append((x, 0))             # Empty Jug2

        pour = min(x, cap2 - y)
        next_states.append((x - pour, y + pour))  # J1 → J2

        pour = min(y, cap1 - x)
        next_states.append((x + pour, y - pour))  # J2 → J1

        for state in next_states:
            if state not in visited:
                queue.append((state, path + [state]))

    return None


print(water_jug_bfs(4, 3, 2))
