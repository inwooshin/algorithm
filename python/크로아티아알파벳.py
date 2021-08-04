cmpString = input()

cro = ['c=','c-', 'd-', 'lj', 'nj', 's=', 'z=']

_3rd = ['dz=']

count = 0

 

i = 0

while i < len(cmpString):

    if i+3 <= len(cmpString) and cmpString[i:i+3] in _3rd:

        i += 3

        count += 1

    elif cmpString[i:i+2] in cro:

        i += 2

        count += 1

    else :

        i += 1

        count += 1

    

print(count)
