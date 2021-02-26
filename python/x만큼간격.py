def solution(x, n):
    answer = []
    sum = 0
    for i in range(n):
        sum += x
        answer.append(sum)
    return answer

def solution2(x,n):
    return [i * x + x for i in range(n)]