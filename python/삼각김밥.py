x, y = map(int, input().split())

num = int(input())

seven_lost = x / y

min = seven_lost

for _ in range(num):

    x, y = map(int, input().split())

    

    other_lost = x / y

    if min > other_lost:

        min = other_lost

print(round(min * 1000, 2))
