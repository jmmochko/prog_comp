def cntXmas(mat):
    res = 0
    n = len(mat)
    m = len(mat[-1])
    for i in range(1,n-1):
        for j in range(1,m-1):
            if(not mat[i][j]=='A'):
                continue
            d1 = mat[i-1][j-1] + mat[i+1][j+1]
            d2 = mat[i+1][j-1] + mat[i-1][j+1]
            if 'M' in d1 and 'S' in d1 and 'M' in d2 and 'S' in d2:
                res += 1
    return res

if __name__ == '__main__':
    m = []
    with open("2024/Day4/puzzleinput.txt", "r") as file:
        for line in file:
            m.append(line)
    print(cntXmas(m))