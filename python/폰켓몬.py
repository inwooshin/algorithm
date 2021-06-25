def solution(nums):
    answer = 0
    
    a = []
    
    for i in nums:
        if i not in a:
            a.append(i)
    
    if len(a) > len(nums) / 2:
        answer = len(nums) / 2
    else :
        answer = len(a)
        
    return answer