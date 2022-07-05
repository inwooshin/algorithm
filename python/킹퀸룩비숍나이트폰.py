in_arr = list(map(int, input().split()))
arr = [1,1,2,2,2,8]

for i in range(len(in_arr)):
    tmp = arr[i] - in_arr[i]
    
    print(tmp, end = ' ')
