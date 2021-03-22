import math

def solution(n):
    answer = 0
    
    sqr = math.sqrt(n)
    
    #제곱근 한 sqr 이 몫을 뺀 소수자리가 없을경우
    if sqr - int(sqr) == 0.0:
        sqr = int(sqr)
        return (sqr + 1) * (sqr + 1)
    else :
        return -1


print(solution(121))