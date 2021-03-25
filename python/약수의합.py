def solution(n):
    answer = 0
    
    for i in range(1,n+1):
        if not n % i:
            answer += i
            
    return answer

def solution(n):
    return n + sum([i for i in range(1, n // 2 + 1) if not n % i])