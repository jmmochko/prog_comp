import math
ip = [int(i) for i in input().split(" ")]
r,x,y,a,b = ip[0], ip[1], ip[2], ip[3], ip[4]
dist = math.sqrt((x-a)*(x-a) + (y-b)*(y-b))
diam = 2*r
moves = dist/diam
print(math.ceil(moves))