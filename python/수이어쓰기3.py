
end = int(input())
all = ''

for i in range(1, end + 1):
   all += str(i)

print(all.find(str(end)) + 1)
