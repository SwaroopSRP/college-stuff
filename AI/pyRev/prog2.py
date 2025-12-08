# Given a square matrix, calculate the absolute difference between the sums of its diagonals

n = int(input("Dim. of sq. matrix:"))
print("Enter the matrix row-values:")
matrix = []
for _ in range(n):
    row = list(map(int, input().split()))
    matrix.append(row)

prim = 0
sec = 0

for i in range(n):
    prim += matrix[i][i]
    sec += matrix[i][n - 1 - i]

print(abs(prim - sec))
