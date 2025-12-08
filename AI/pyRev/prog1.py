# Given a base-10 integer n, convert it to binary (base-2). Then find and print the base-10 integer denoting the 
# maximum number of consecutive 1’s in n’s binary representation.

num = int(input("Enter the base-10 no.: ").strip())

ctr = 0
max_ctr = 0

while num != 0:
    if num & 1:
        ctr += 1
        if ctr > max_ctr:
            max_ctr = ctr
    else:
        ctr = 0
    
    num = num >> 1

print("Max. no. of consec. 1's:", max_ctr)
