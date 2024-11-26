arr2 = []

num = int(input("Enter no. of elements: "))
arr1 = [int(input(f"Enter element {i}: ")) for i in range(num)]
print(arr1)
for i in arr1:
    if i not in arr2:
        arr2.append(i)
        arr1[arr1.index(i)] = None
print(arr2)
for i in arr2:
    for j in arr1:
        if i == j:
            print(f"{i} is in {arr1.index(i)}", end="")
            for k in range(arr1.index(i) + 1, len(arr1)):
                if i == arr1[k]:
                    print(f", {arr1[k]}")
                else:
                    print()
            break
