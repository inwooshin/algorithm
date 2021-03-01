def solution(arr):
    answer = []
    
    for i in range(len(arr)):
        if i == 0:
            answer.append(arr[i])
        elif answer[len(answer) - 1] == arr[i]:
            continue
        else :
            answer.append(arr[i])
            
    return answer

def solution(s):
    a = []
    for i in s:
        # 이렇게 하면 a 맨마지막의 list를 리턴 a[-1] 이라고 하면
        # 리스트가 비어있을 때 참조 불가능
        #[i] 이렇게 써주면 리스트로 바꿔줌
        if a[-1:] == [i]: continue
        a.append(i)
    
    return a