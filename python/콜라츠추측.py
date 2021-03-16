def solution(num):
    num = float(num)
    count = 0

    #& 과 and 는 다르다!!!!!!!
    #and 는 && 이고 & 는 비트 연산자라고 보면된다!
    while num != 1 and count < 500:
        count += 1
        if not num % 2:
            num /= 2
        else :
            num = num * 3 + 1
            
    return -1 if count >= 500 else count