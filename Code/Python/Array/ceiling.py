def ceilSearch(arr, left, right, key):
    if left <= right:
        mid = left + (right - left) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            return ceilSearch(arr, mid + 1, right, key)
        else:
            if mid - 1 >= left and arr[mid - 1] >= key:
                return ceilSearch(arr, left, mid - 1, key)
            else:
                return mid
    return -1

arr = [1, 2, 8, 10, 10, 12, 19]
pos = ceilSearch(arr, 0, len(arr) - 1, 29)
print(arr[pos]) if pos != -1 else print("No ceiling found")