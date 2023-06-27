import random

def randomFile(size):
    data = []
    for i in range(size):
        data.append(random.randint(0,255))
    return data

def intArrToString(d):
    s = ''
    for i in range(len(d)):
        s += chr(d[i])
    return s
def stringToIntArr(s):
    d = []
    for i in range(len(s)):
        d.append(s[i])
    return d

'''fileToCreate = open('file.bin','wb')
dataI = randomFile(256)
fileToCreate.write(bytearray(dataI))
fileToCreate.close()'''

path = input('enter path to your file: ')
file = open(path, 'rb+')
dataString = file.read()
data = stringToIntArr(dataString)
print(data)