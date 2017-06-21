def product(arr):
    prod = []
    for i in range(len(arr)):
        if i == 0:
            prod.append(1)
        else:
            prod.append(prod[i - 1] * arr[i - 1])
    temp = 1
    for i in range(len(arr) - 1, -1, -1):
        prod[i] *= temp
        temp *= arr[i]

    for item in prod:
        print(item, end = ' ')

arr = [10, 3, 5, 6, 2]
product(arr)