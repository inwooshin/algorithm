def solution(n):
    answer = 0

    for i in range(len(str(n))):
        answer += n % 10
        n = int(n/10)

    return answer