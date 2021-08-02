a = int(input())

right = 0

 

for i in range(a):

    String = input()

    for j in range(len(String)):

        if len(String) == 1:

            right += 1

            break

        else :

            if j + 2 <= len(String):

                if String[j] in String[j+2:] and String[j] != String[j+1]:

                    break

        

        if j == len(String) - 1:

            right += 1

            

print(right)