def solution(lottos, win_nums):
    answer = [0, 0]
    
    for i in range(len(lottos)):
        if lottos[i] in win_nums:
            answer[0] += 1
            answer[1] += 1
            win_nums.remove(lottos[i])
            
    for i in range(len(lottos)):
        if lottos[i] == 0 and len(win_nums) != 0:
            del win_nums[0]
            answer[0] += 1
    
    for i in range(2):
        if 7 - answer[i] > 6:
            answer[i] = 6
        else : answer[i] = 7 - answer[i]
    
    return answer