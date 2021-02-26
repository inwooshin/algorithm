def solution(a, b):
    answer = ['SUN','MON','TUE','WED','THU','FRI','SAT']
    
    # 5 인덱스부터 시작
    # 1월 31, 2월 29, 3월 31, 4월 30, 5월 31, 6월 30, 7월 31
    # 8월 31, 9월 30, 10월 31, 11월 30, 12월 31
    
    month = [31,29,31,30,31,30,31,31,30,31,30]
    
    return answer[(sum(month[:a-1])+b+4) % 7]