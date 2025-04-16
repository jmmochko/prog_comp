if __name__ == "__main__":
    t = int(input())
    for __ in range(t):
        nm = [int (i) for i in input().split(" ")]
        n,m = nm[0], nm[1]
        a = input().split(" ")
        vis = [False for _ in range(n)]
        best = 0
        for ___ in range(m):
            b = input().split(" ")
            cnt = 0
            #print("m = ", ___)
            for i in range(n):
                if b[i] == a[i]:
                    vis[i] = True
                    cnt += 1
                    #print("i = ", i)
            best = max(best,cnt)
            #print("best = ",best)
        canSolve = True
        for v in vis:
            canSolve = canSolve and v
        if canSolve:
            res = n + (2*(n-best))
            print(res)
        else:
            print(-1)