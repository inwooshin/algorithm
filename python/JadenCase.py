def solution(s):
    JadenCase = ""
    sep = 0
    
    for i in range(len(s)):
        if s[i] == " ": 
            sep = 0
            JadenCase += s[i]
            continue
        else: 
            sep += 1
        
        if sep == 1: 
            JadenCase += s[i].upper()
        else :
            JadenCase += s[i].lower()
    
    return JadenCase

def solution(s):
    Jaden = ''
    
    for i in s.split(" "):
        if i == '':
            Jaden += ' '
            continue
        Jaden += i[0].upper() + i[1:].lower()
        
        if s.split(" ")[-1] != i:
            Jaden += ' '
    
    return Jaden

def solution(s):
    return ' '.join([word.capitalize() for word in s.split(" ")])