#  You are given an array and you need to find number of triplets of indices (i, j, k) such that 
# the elements at those indices are in geometric progression for a given common ratio r and i < j < k.

from collections import defaultdict

print("Enter the array elements (space-separated):")
arr = list(map(int, input().strip().split()))
r = int(input("Enter the common ratio: ").strip())

left = defaultdict(int)
right = defaultdict(int)

for val in arr:
    right[val] += 1

triplets = 0

for x in arr:
    right[x] -= 1
    
    if x % r == 0 and r!= 0: # if divisible
        leftc = left[x // r]
        rightc = right[x * r]
        triplets += leftc * rightc
    
    left[x] += 1

print("Number of triplets in GP:", triplets)
