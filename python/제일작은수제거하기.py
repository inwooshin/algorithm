def solution(arr):
    answer = arr
    
    #list 넣으면 최소값 찾아줌
    m = min(arr)
    
    #index 함수로 값이 어디에 있는지 찾을 수 있다
    del answer[answer.index(m)]
    
    if not answer :
        return [-1]
    
    return answer