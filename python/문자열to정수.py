def solution(s):
    answer = 0
    minus = 1
    count = len(s) - 1
    on = 0
    
    if s[0] == '-':
        minus = -1
        count -= 1
        on = 1
    elif s[0] == '+':
        count -= 1
        on = 1
    
    for i in s[on:]:
        answer += (ord(i) - ord('0')) * minus * pow(10,count)
        count -= 1
        
    return answer

def OtherSolution(s):
    return int(s)
