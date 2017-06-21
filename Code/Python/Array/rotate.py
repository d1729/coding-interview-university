def reverseArray(arr, d):
    d %= len(arr)
    return arr[d:] + arr[:d]

arr = [1, 2, 3, 4, 5, 6, 7]
arr = reverseArray(arr, 2)

for item in arr:
    print(item, end=' ')
print(' ')