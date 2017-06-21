def findPairs():
    arr.sort()
    l = 0
    r = len(arr) - 1
    bestVal = arr[l] + arr[r]
    low = l
    high = r
    while l < r:
        temp = arr[l] + arr[r]
        if abs(temp) < bestVal:
            bestVal = temp
            low = l
            high = r

        if arr[l] + arr[r] > 0:
            r -= 1
        else:
            l += 1
    return low, high

'''n = int(input())
arr = [int(i) for i in input().split()]'''
arr = [-1,2,10,100]
(l, r) = findPairs()
print(arr[l], arr[r], sep=' ')
