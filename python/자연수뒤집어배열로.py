def solution(n):
    answer = []
    
    for i in range(len(str(n))):
        tmp = n % 10
        n = int(n / 10)
        answer.append(tmp)
    
    return answer