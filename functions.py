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