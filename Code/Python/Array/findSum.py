def findSum(arr, _sum):
    binMap = [0] * (max(arr) + 1)
    for item in arr:
        temp = _sum - item
        if temp >= 0 and binMap[temp] == 1:
            print(temp, item, sep = ' ')
        binMap[item] = 1

arr = [1, 4, 45, 6, 10, 8]
findSum(arr, _sum = 16)