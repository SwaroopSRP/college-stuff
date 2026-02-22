from collections import deque

def monkey_banana_bfs():

    start = ("door", "window", False, False)

    queue = deque([(start, [start])])
    visited = set()

    positions = ["door", "middle", "window"]

    while queue:
        state, path = queue.popleft()
        monkey, box, on_box, has_banana = state

        # Goal check
        if has_banana:
            return path

        if state not in visited:

            visited.add(state)

            next_states = []

            # 1. Move
            if not on_box:
                for pos in positions:
                    if pos != monkey:
                        next_states.append((pos, box, False, has_banana))

            # 2. Push
            if monkey == box and not on_box:
                for pos in positions:
                    if pos != monkey:
                        next_states.append((pos, pos, False, has_banana))

            # 3. Climb
            if monkey == box and not on_box:
                next_states.append((monkey, box, True, has_banana))

            # 4. Grab
            if monkey == "middle" and on_box:
                next_states.append((monkey, box, True, True))

            for new_state in next_states:
                queue.append((new_state, path + [new_state]))

    return None
