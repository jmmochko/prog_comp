if __name__ == "__main__":
    nrc = [int(i) for i in input().split(" ")]
    n,r,c = nrc[0],nrc[1],nrc[2]
    r-=1
    c-=1
    cands = [i for i in range(n)]
    i,j = 0,n-1
    res = []
    while(len(cands)>2):
        i = (i + r) % len(cands)
        j = (j - c) % len(cands)
        if i==j:
            res.append(cands[i])
            cands.pop(i)
            j = (j-1)%len(cands)
        else:
            cands.pop(max(i,j))
            cands.pop(min(i,j))
            if i>j:
                i = (i-1)%len(cands)
                j = (j-1)%len(cands)
            else:
                j = (j-2)%len(cands)
    for e in cands:
        res.append(e)
    res.sort()
    for e in res:
        print(e+1,end=" ")
    print('')

