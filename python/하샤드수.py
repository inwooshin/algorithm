def solution(x):
    every = 0
    tmp = x
    for i in range(len(str(x))):
        every += int(tmp) % 10
        tmp /= 10
        
    return True if x % every == 0 else False

def solution(x):
    #sum 함수가 리스트를 그냥 넘겨주면 다 더해주기 때문에 리스트를
    #안에 for 문을 넣어주고 그대로 sum 에 넣으면 총합을 얻을 수 있다.
    return x % sum([int(a) for a in str(x)]) == 0