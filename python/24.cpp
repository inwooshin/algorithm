now_time = list(map(int, input().split(':')))
start_time = list(map(int, input().split(':')))

hour, min, sec = (0,1,2)

now_all_sec = now_time[hour] * 3600 + now_time[min] * 60 + now_time[sec]
start_all_sec = start_time[hour] * 3600 + start_time[min] * 60 + start_time[sec]

remain_sec = 0

if start_all_sec >= now_all_sec :
    remain_sec = start_all_sec - now_all_sec
else :
    remain_sec = (start_all_sec + (24 * 3600)) - now_all_sec

remain_hour = remain_sec // 3600
remain_sec -= 3600 * remain_hour
remain_min = remain_sec // 60
remain_sec -= 60 * remain_min

print('%02d:%02d:%02d' %(remain_hour, remain_min, remain_sec))
