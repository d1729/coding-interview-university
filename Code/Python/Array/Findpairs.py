def printPairs():
    for item in nums:
        temp = Sum - item
        if temp >= 0 and binMap[temp] == 1:
            print(item, temp, sep=' ')
        binMap[item] = 1
Sum = int(input())
n = input()
nums = [int(i) for i in input().split()]
binMap = [0] * 100000
printPairs()
