def solution(n):
    answer = ''
    
    for i in range(0,n):
        if i % 2 == 0:
            answer += '수'
        else:
            answer += '박'
    
    return answer

def ohterSolution(n):
    return (n * '수박')[0:n]

#출력 결과 확인
print(solution(4))
print(solution(5))
print(solution(6))
print(solution(7))

print(ohterSolution(4))
print(ohterSolution(5))
print(ohterSolution(6))
print(ohterSolution(7))