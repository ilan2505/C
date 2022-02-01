import sys
import random
tsp = [32,2,98,4,46]
cmd = ''
choises = random.sample(range(200),k=100)
for i in choises:
   if i in tsp: continue
   cmd += 'D ' + str(i) + ' '
print(cmd)
exit(0)



cmd = 'A 200 '
for i in range(200):
    cmd += 'n ' + str(i) + ' '
    for j in random.sample(range(200),k=100):
        if j == i: continue
        cmd += str(j) + ' ' + str(random.randrange(1,20)) + ' '

cmd += 'T 5 32 2 98 4 46'
print(cmd)