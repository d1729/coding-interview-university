def findMaority(arr):
    maj_index = 0
    count = 1
    for i in range(1, len(arr)):
        if arr[i] == arr[maj_index]:
            count += 1
        else:
            count -= 1
        if count == 0:
            maj_index = i
            count = 1
    return arr[maj_index]

arr = [1, 3, 1, 1, 2]
if len(arr) == 0:
    print("Array is Empty")
else:
    majorityElement = findMaority(arr)
    count = 0
    for item in arr:
        if item == majorityElement:
            count += 1
    if count > len(arr) // 2:
        print(majorityElement)
    else:
        print("No majority element exists")