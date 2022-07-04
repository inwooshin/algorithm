
num = int(input())

all = 0

score = 0

arr = list(map(int, input().split()))

    

for check in arr:

    if check == 1:

        score += 1

    else :

        score = 0

    all += score

print(all)
