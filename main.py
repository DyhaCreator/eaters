import random
import functions as fc
import creatures as cr

'''fileToCreate = open('file.bin','wb')
dataI = fc.randomFile(50*1024)
fileToCreate.write(bytearray(dataI))
fileToCreate.close()'''

path = input('enter path to your file: ')
file = open(path, 'rb')
dataString = file.read()
file.close()
data = fc.stringToIntArr(dataString)

SIZE_WORLD = len(data)
EAT_TO_MOVE = 30
EAT_TO_DIVISION = 512
SUB_EAT_TO_DIVISION = 512
MAX_SIZE_POPULATION = 0
crs = []
c = cr.Creatures(SIZE_WORLD)
crs.append(c)
print(len(crs))
print('start')
#print(data)
x = 0
while len(crs) != 0 and x < 75:
    x+=1
    indexes = []
    for i in range(len(crs)):
        if crs[i].x == 0:
            crs[i].speed = 1
        elif crs[i].x == SIZE_WORLD - 1:
            crs[i].speed = -1
        else:
            if data[crs[i].x - 1] > data[crs[i].x + 1]:
                crs[i].speed = -1
            elif data[crs[i].x - 1] < data[crs[i].x + 1]:
                crs[i].speed = 1
        crs[i].x += crs[i].speed
        crs[i].eat -= EAT_TO_MOVE
        crs[i].eat += data[crs[i].x]
        data[crs[i].x] = 0
        if crs[i].eat >= EAT_TO_DIVISION:
            c = cr.Creatures(SIZE_WORLD-1)
            crs.append(c)
            crs[i].eat -= SUB_EAT_TO_DIVISION
        file = open(path, 'wb')
        file.write(bytearray(data))
        file.close()
        if crs[i].eat <= 0:
            indexes.append(i)

    for i in range(len(indexes)):
        crs.pop(indexes[i]-i)
    MAX_SIZE_POPULATION = max(MAX_SIZE_POPULATION, len(crs))
    print(x,'population -', len(crs))
    #print(data)
    #print(len(crs))
#print(data)
print('max population -',MAX_SIZE_POPULATION)
print('end')
#print(data)