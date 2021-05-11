def solution(participant, completion):
    par = []
    pas = []
    
    for i in participant:
        par.append(i)
        
    for j in completion:
        pas.append(j)
    
    par.sort()
    pas.sort()
    
    for i in range(0 , len(participant)):
        if i == len(participant) - 1:
            return par[i]
        elif par[i] != pas[i]:
            return par[i]

def solution(par, pas):
    par.sort()
    pas.sort()
    
    for i in range(0 , len(par)):
        if i == len(par) - 1:
            return par[i]
        elif par[i] != pas[i]:
            return par[i]

import collections


def solution(participant, completion):
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]