def leftBinSearch(arr, left, right, key):
    if left > right:
        return -1
    mid = left + (right - left) // 2
    if arr[mid] == key:
        if mid == 0 or arr[mid - 1] != arr[mid]:
            return mid
        else:
            return leftBinSearch(arr, left, mid - 1, key)
    elif arr[mid] < key:
        return leftBinSearch(arr, mid + 1, right, key)
    else:
        return leftBinSearch(arr, left, mid - 1, key)

arr = [1, 2, 3, 3, 3, 3, 10]
x = 3
temp = leftBinSearch(arr, 0, len(arr) - 1, x)
if temp != -1 and temp + len(arr) // 2 < len(arr) and arr[temp + len(arr) // 2] == x:
    print(x, " Occurs more than ", len(arr) // 2, " times")
else:
    print(x, " Doesn't occur more than", len(arr) // 2, " times")