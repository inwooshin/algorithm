import math

def solution(n):
    tmp = n
    answer = 0
    add = 0
    
    for i in range(1, n + 1):
        add = 0
        for j in range(i,n + 1):
            add += j
            if add == n:
                answer += 1
            elif add > n:
                break
        
    return answer