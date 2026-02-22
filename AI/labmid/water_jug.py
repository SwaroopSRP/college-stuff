from collections import deque

def water_jug_bfs(cap1, cap2, goal):
    """
    cap1 = capacity of jug1
    cap2 = capacity of jug2
    goal = required amount
    """

    start = (0, 0)   # initially both empty
    queue = deque()
    queue.append((start, [start]))

    visited = set()

    while queue:
        (x, y), path = queue.popleft()

        # Goal check
        if x == goal or y == goal:
            return path

        if (x, y) in visited:
            continue

        visited.add((x, y))

        # Possible operations:

        next_states = []

        # 1. Fill Jug1
        next_states.append((cap1, y))

        # 2. Fill Jug2
        next_states.append((x, cap2))

        # 3. Empty Jug1
        next_states.append((0, y))

        # 4. Empty Jug2
        next_states.append((x, 0))

        # 5. Pour Jug1 → Jug2
        pour = min(x, cap2 - y)
        next_states.append((x - pour, y + pour))

        # 6. Pour Jug2 → Jug1
        pour = min(y, cap1 - x)
        next_states.append((x + pour, y - pour))

        # Add new states to queue
        for state in next_states:
            if state not in visited:
                queue.append((state, path + [state]))

    return None


print(water_jug_bfs(4, 3, 2))
