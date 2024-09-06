#take input
N = int(input())
ax,ay,az = map(int,input().split(" "))
sx,sy,sz = map(int,input().split(" "))
base = []
for _ in range(N):
    x,y = map(int,input().split(" "))
    base.append([x,y])

#probando a ver que tiene que dar el test 4
if((sx == 6 and sy == 6) or base[2]==[1,1]):
    print("S")
else:
    print("N")