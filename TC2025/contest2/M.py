import math
nr = [float(i) for i in input().split(" ")]
n,r = nr[0], nr[1]
alpha = 2*math.pi / n
beta = (math.pi - alpha) / 2
beta = math.sin(beta)
alpha = math.sin(alpha)
res = r/(((2*beta)/alpha)-1)
print(round(res,10))