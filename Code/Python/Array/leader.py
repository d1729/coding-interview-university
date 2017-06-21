import sys
def printLeaders(arr):
    max_right = -sys.maxsize
    for i in range(len(arr) - 1, -1, -1):
        if arr[i] > max_right:
            print(arr[i], end=' ')
        max_right = max(arr[i], max_right)


l = [int(i) for i in  input().split()]
printLeaders(l)