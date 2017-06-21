import sys
def findTwoSmallest(arr):
    smallest = secondSmallest = sys.maxsize
    for item in arr:
        if item < smallest:
            secondSmallest = smallest
            smallest = item
        elif item < secondSmallest and item != smallest:
            secondSmallest = item
    if smallest == sys.maxsize:
        print("There are no elements in this array")
    elif secondSmallest == sys.maxsize:
        print("There is no second smallest element in this array")
    else:
        print("Smallest element: ", smallest, " Second Smallest element: ", secondSmallest)

arr = [12, 13, 1, 10, 34, 1]
findTwoSmallest(arr)
