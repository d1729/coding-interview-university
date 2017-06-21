def merge(arr, left, mid, right):
    temp = [i for i in arr]
    i = k = left
    j = mid + 1
    inv_count = 0
    while i <= mid and j <= right:
        if arr[i] <= arr[j]:
            temp[k] = arr[i]
            i += 1
        else:
            temp[k] = arr[j]
            j += 1
            inv_count += mid + 1 - i
        k += 1

    while i <= mid:
        temp[k] = arr[i]
        i += 1
        k += 1

    while j <= right:
        temp[k] = arr[j]
        j += 1
        k += 1

    arr = temp
    return inv_count

def findInversions(left, right):
    inv_count = 0
    if left < right:
        mid = left + (right - left) // 2
        inv_count = findInversions(left, mid)
        inv_count += findInversions(mid + 1, right)
        inv_count += merge(arr, left, mid, right)
    return inv_count

'''n = int(input())
arr = [int(i) for i in input().split()]'''
arr = [1, 20, 6, 4, 5]
print(findInversions(0, len(arr) - 1))