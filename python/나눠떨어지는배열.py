def solution(arr, divisor):
    answer = []
    for i in arr:
        if not i % divisor:
            answer.append(i)
    
    if answer :
        return sorted(answer)
    else :
        return [-1]