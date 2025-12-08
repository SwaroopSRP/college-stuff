class SudokuSolver:
    def __init__(self, board):
        self.board = board

    def print_board(self):
        for i, row in enumerate(self.board):
            for j, num in enumerate(row):
                if j in (2, 5):
                    print(num, end=" | ")
                else:
                    print(num, end="  ")
            print()
            if i in (2, 5):
                print("- " * 14)

    def is_valid(self, row, col, num):
        for x in range(9):
            if self.board[row][x] == num:
                return False
        for x in range(9):
            if self.board[x][col] == num:
                return False
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(3):
            for j in range(3):
                if self.board[start_row + i][start_col + j] == num:
                    return False
        return True

    def solve(self):
        for row in range(9):
            for col in range(9):
                if self.board[row][col] == 0:
                    for num in range(1, 10):
                        if self.is_valid(row, col, num):
                            self.board[row][col] = num
                            if self.solve():
                                return True
                            self.board[row][col] = 0
                    return False
        return True


def input_board():
    conf = input("Do you want to enter the Sudoku board manually? (y/n): ")
    if conf.lower() in ("y", "yes"):
        board = []
        print("Enter the Sudoku board (row by row), use 0 for empty cells:")
        for i in range(9):
            while True:
                try:
                    row = list(map(int, input(f"Row {i + 1}: ").strip().split()))
                    if len(row) != 9 or any(num < 0 or num > 9 for num in row):
                        raise ValueError
                    board.append(row)
                    break
                except ValueError:
                    print("Invalid input. Please enter exactly 9 numbers (0-9) separated by spaces.")
        return board
    else:
        board = [
            [5, 3, 0, 0, 7, 0, 0, 0, 0],
            [6, 0, 0, 1, 9, 5, 0, 0, 0],
            [0, 9, 8, 0, 0, 0, 0, 6, 0],
            [8, 0, 0, 0, 6, 0, 0, 0, 3],
            [4, 0, 0, 8, 0, 3, 0, 0, 1],
            [7, 0, 0, 0, 2, 0, 0, 0, 6],
            [0, 6, 0, 0, 0, 0, 2, 8, 0],
            [0, 0, 0, 4, 1, 9, 0, 0, 5],
            [0, 0, 0, 0, 8, 0, 0, 7, 9]
        ]
        return board


def main():
    board = input_board()
    solver = SudokuSolver(board)
    print("\nGiven Sudoku board:")
    solver.print_board()
    if solver.solve():
        print("\nSolved Sudoku board:")
        solver.print_board()
    else:
        print("No solution exists")


if __name__ == "__main__":
    main()
