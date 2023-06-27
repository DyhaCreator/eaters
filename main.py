import numpy as np
import functions as fc

'''fileToCreate = open('file.bin','wb')
dataI = randomFile(256)
fileToCreate.write(bytearray(dataI))
fileToCreate.close()'''

path = input('enter path to your file: ')
file = open(path, 'rb')
dataString = file.read()
file.close()
data = fc.stringToIntArr(dataString)

if len(data) % 16 != 0:
    for i in range(16 - len(data)%16):
        data.append(0)

data = np.reshape(data,(len(data)//16,16))

print(data)

