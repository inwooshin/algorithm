def solution(s):
    answer = 0
    
    for i in s:
        if i == 'p' or i == 'P':
            answer += 1
        elif i == 'y' or i == 'Y':
            answer -= 1

    if answer == 0:
        return True
    else :
        return False

def OtherSolution(s):
    return s.lower().count('p') == s.lower().count('y')