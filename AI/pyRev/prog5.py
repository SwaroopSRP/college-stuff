# You are given a string containing characters A and B only. Your task is to change it into a string such that 
# there are no matching adjacent characters, by deleting zero or more characters. 
# Find the minimum number of required deletions

s = input("Enter the string (A and B only): ")

deletions = 0

for i in range(1, len(s)):
    if s[i] == s[i - 1]:
        deletions += 1

print("Minimum deletions:", deletions)
