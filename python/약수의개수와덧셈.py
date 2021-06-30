def getMeas(number, arr):
    for i in range(1, number + 1):
        if number % i == 0:
            arr.append(i)
    
    return len(arr)
    
def solution(left, right):
    answer = 0
    
    for i in range(left, right + 1):
        arr = []
        if getMeas(i, arr) % 2 == 0:
            answer += i
        else : answer -= i
    
    return answer