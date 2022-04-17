A, B = map(int, input().split())
data = list(map(int, input().split(',')))
count = 0

for i in range(B):
    output = []
    for j in range(len(data)):
        if j == 0:
            continue
        
        output.append(data[j] - data[j - 1])
    
    data = output

for j in range(len(data)):
    print(data[j], end = '')
    if j != len(data) - 1:
        print(',', end = '')
