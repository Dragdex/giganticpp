#!/usr/bin/python3

import datetime
import random
import math

v1 = [  10,  11,  12,  13,  14,  15]  # a vector
v2 = [1000,1100,1200,1300,1400,1500]  # a vector

start = datetime.datetime.now() 

for i in range(10000000):
    r1 = map(lambda x,y: x + y, v1, v2);

end = datetime.datetime.now() 

print ("const loop ", math.floor((end-start).total_seconds() * 1000), " ms")

##################################


start = datetime.datetime.now() 

for i in range(10000000):
    v1 = [  random.random(),  random.random(),  random.random(),  random.random(),  random.random(), random.random()]  # a vector
    v2 = [  random.random(),  random.random(),  random.random(),  random.random(),  random.random(), random.random()]  # a vector
    r1 = map(lambda x,y: x + y, v1, v2);

end = datetime.datetime.now() 

print ("random loop ", math.floor((end-start).total_seconds() * 1000), " ms")
