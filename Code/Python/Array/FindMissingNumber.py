#Find the number missing in the range 1 to n
n = int(input())
numbers = [int(i) for i in input().split(' ')]
val = 0
for i in range(1, n + 1):
    val ^= i
for i in numbers:
    val ^= i
print(val)