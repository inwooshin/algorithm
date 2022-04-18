A = int(input())
B = list( map(int, input().split()) )
ms = 0
ys = 0
all = 0

for i in B:
    all += i
    ys += (i // 30) * 10
    ms += (i // 60) * 15

    if i != 0:
        ys += 10
        ms += 15

if ms < ys:
    print('M %d' % (ms))
elif ms > ys :
    print('Y %d' % (ys))
else :
    print('Y M %d' % (ms))