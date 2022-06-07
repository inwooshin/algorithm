end = int(input())

for i in range(end):
    arr = list(map(str, input().split('-')))
    
    sentence = arr[0]
    number = int(arr[1])
    
    add_all = 0

    for j in range(3):
        add_all += int(ord(arr[0][j]) - ord('A')) * pow(26, 2 - j)
    
    if abs(add_all - number) <= 100:
        print('nice')
    else :
        print('not nice')
