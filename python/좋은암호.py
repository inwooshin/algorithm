arr = list(map(int, input().split()))

for i in range(2, arr[1]):
    if (arr[0] % i == 0):
        print('BAD', i)
        quit()

print('GOOD')