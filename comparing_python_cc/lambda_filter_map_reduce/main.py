#!/usr/bin/python3

v1 = [  10,  11,  12,  13,  14,  15]  # a vector
v2 = [1000,1100,1200,1300,1400,1500]  # a vector

r1 = map(lambda x,y: x + y, v1, v2);

print (*r1, sep=', ')

i1 = [1,2,3]  # a initializer list
i2 = [10,20,30]  # a initializer list
v4 = [1000,1100,1200,1300,1400,1500]  # a vector

r2 = map(lambda x, y, z: x + y + z, i1, i2, v4)

print (*r2, sep=', ')

