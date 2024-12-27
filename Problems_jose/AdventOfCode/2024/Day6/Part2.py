Ds = [[-1,0],[0,1],[1,0],[0,-1]]

def has_cycle(mat):
    n = len(mat)
    m = len(mat[0])
    vis = [[False for j in range(m)]for i in range(n)]
    s = [0,0]
    for i in range(n):
        for j in range(m):
            if mat[i][j] == '^':
                s = [i,j]
                break
    d = 0
    #advance s twice and 
    while True:
        vis[s[0]][s[1]] = True
        ni,nj = s[0] + Ds[d][0], s[1] + Ds[d][1]
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            break
        if mat[ni][nj] == '#':
            d = (d + 1) % 4
        else:
            s = [ni,nj]
    res = 0
    for i in range(n):
        for j in range(m):
            if vis[i][j]:
                res += 1

    

if __name__ == "__main__":
    mat = []
    with open("2024/Day6/puzzleinput.txt", "r") as file:
        for line in file:
            mat.append(list(line.replace('\n','')))
    n = len(mat)
    m = len(mat[0])
    vis = [[False for j in range(m)]for i in range(n)]
    s = [0,0]
    for i in range(n):
        for j in range(m):
            if mat[i][j] == '^':
                s = [i,j]
                break
    d = 0
    while True:
        vis[s[0]][s[1]] = True
        ni,nj = s[0] + Ds[d][0], s[1] + Ds[d][1]
        if ni < 0 or ni >= n or nj < 0 or nj >= m:
            break
        if mat[ni][nj] == '#':
            d = (d + 1) % 4
        else:
            s = [ni,nj]
    res = 0
    for i in range(n):
        for j in range(m):
            if vis[i][j]:
                res += 1

    print(res)