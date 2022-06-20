
arr = ['-','\\','(','@','?','>','&','%', '/']

while True:
    tmp = input()
    
    if tmp == '#':
        break

    all_value = 0
    
    for i in range(len(tmp) - 1, -1, -1):
        value = arr.index(tmp[len(tmp) - i - 1])
        
        if value == 8:
            value = -1
        
        all_value += (8 ** i) * value
        
        # print(value)
    
    print(all_value)
