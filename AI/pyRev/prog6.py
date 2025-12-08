#You are given an integer N. Your task is to print an alphabet rangoli of size N.


import string

n = int(input("Enter size: "))
alphabet = string.ascii_lowercase

all_lines = []

for i in range(n):
    left_part = alphabet[n-1 : i : -1]
    middle_letter = alphabet[i]
    right_part = alphabet[i+1 : n]

    letters = list(left_part) + [middle_letter] + list(right_part)

    line = " ".join(letters)

    width = 4*n - 3
    line = line.center(width, " ")

    all_lines.append(line)

for line in all_lines:
    print(line)

for line in reversed(all_lines[:-1]):
    print(line)
