def solution(num):
    answer = ''
    
    if num % 2 == 0:
        answer += 'Even'
    else :
        answer += 'Odd'
    
    return answer

print(solution(3))
print(solution(4))
print(solution(5))
print(solution(6))
print(solution(7))