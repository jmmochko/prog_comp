s=str(input()) + "$"
n,z=len(s),0
#para encontrar la menor potencia de 2 mas grande que n
while(pow(2,z)<n):
    z+=1
#encontrada
a=[(s[m],m) for m in range(n)]
a=sorted(a)
c=[0 for v in range(n)]
p=[a[o][1] for o in range(n)]
for i in range(1,n):
    if a[i][0]==a[i-1][0]:
        c[p[i]]=c[p[i-1]]
    else:
        c[p[i]]=c[p[i-1]]+1
    
for k in range(z):
    ar=[((c[i], c[(i+pow(2,k))%n]), i) for i in range(n)]
    ar=sorted(ar)
    p=[ar[o][1] for o in range(n)]
    for i in range(1,n):
        if ar[i][0]==ar[i-1][0]:
            c[p[i]]=c[p[i-1]]
        else:
            c[p[i]]=c[p[i-1]]+1
for f in range(n):
    print(p[f], end=" ")