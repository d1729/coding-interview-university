def getMax(arr):
    length = len(arr)-1
    if(length <= 1):
        return 0
    maxnum = arr[length]
    maxdist = 0
    for i in range(length - 1, -1, -1):
        if arr[i] > maxnum:
            maxnum = arr[i]
        else:
            if (maxnum - arr[i]) > maxdist :
                maxdist = maxnum - arr[i]
    return maxdist

arr = [7, 9, 5, 6, 3, 2]
print(getMax(arr))
