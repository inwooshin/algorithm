A = int(input())

for i in range(A):
    B = int(input())
    check = 0
    for j in range(2, 1000001):
        if B % j == 0: 
            print("NO")
            check = 1
            break
    if check == 0:
        print("YES")