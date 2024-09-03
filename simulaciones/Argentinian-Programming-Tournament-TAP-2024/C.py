#take input
N = int(input())
ax,ay,az = map(int,input().split(" "))
sx,sy,sz = map(int,input().split(" "))
base = []
for _ in range(N):
    x,y = map(int,input().split(" "))
    base.append([x,y])

#find where the line from the apex to the sun intersects the ground
# l = s + x(a-s) --> 0 = sz + x(az-sz) ---> sz=x(az-sz) ---> sz/(az-sz) = x
iz = sz/(az-sz)
ix = sx + iz*(ax-sx)
iy = sy + iz*(ay-sy)
#find if <ix,iy> is under base
res = True
base.append([2,2])
base.sort()
print(base)
if(res):
    print("N")
else:
    print("S")