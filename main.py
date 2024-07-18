import heapq


def get_input_state():
    print("Enter the initial state of the puzzle (use 0 for the empty space):")
    state = []
    for _ in range(3):
        state.extend(map(int, input().split()))
    return state


def is_solvable(state):
    inversion_count = 0
    state = [num for num in state if num != 0]
    for i in range(len(state)):
        for j in range(i + 1, len(state)):
            if state[i] > state[j]:
                inversion_count += 1
    return inversion_count % 2 == 0


def heuristic(state, goal):
    distance = 0
    for i in range(1, 9):
        current_index = state.index(i)
        goal_index = goal.index(i)
        distance += abs(current_index // 3 - goal_index // 3) + abs(current_index % 3 - goal_index % 3)
    return distance


def get_neighbors(state):
    neighbors = []
    zero_index = state.index(0)
    zero_row, zero_col = zero_index // 3, zero_index % 3

    moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    for move in moves:
        new_row, new_col = zero_row + move[0], zero_col + move[1]
        if 0 <= new_row < 3 and 0 <= new_col < 3:
            new_index = new_row * 3 + new_col
            new_state = state[:]
            new_state[zero_index], new_state[new_index] = new_state[new_index], new_state[zero_index]
            neighbors.append(new_state)
    return neighbors


def a_star(start, goal):
    open_set = []
    heapq.heappush(open_set, (0 + heuristic(start, goal), 0, start, []))
    closed_set = set()

    while open_set:
        _, cost, state, path = heapq.heappop(open_set)

        if state == goal:
            return path + [state]

        closed_set.add(tuple(state))

        for neighbor in get_neighbors(state):
            if tuple(neighbor) in closed_set:
                continue
            heapq.heappush(open_set, (cost + 1 + heuristic(neighbor, goal), cost + 1, neighbor, path + [state]))

    return None


def print_solution(solution):
    if not solution:
        print("No solution found.")
    else:
        for step in solution:
            print_state(step)
            print()


def print_state(state):
    for i in range(3):
        print(state[i * 3:(i + 1) * 3])


if __name__ == "__main__":
    initial_state = get_input_state()
    goal_state = [1, 2, 3, 4, 5, 6, 7, 8, 0]

    if is_solvable(initial_state):
        solution = a_star(initial_state, goal_state)
        print_solution(solution)
    else:
        print("The given initial state is not solvable.")
