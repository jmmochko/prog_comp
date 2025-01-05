vi = []
wi = []

dp = [[-1 for i in range(1001)]for j in range(1001)]

def f(i,c):
    if c<0:
        return -1000000000
    
    if dp[i][c] != -1:
        return dp[i][c]

    if i == 0:
        if wi[i] <= c:
            dp[i][c] = vi[i]
        else:
            dp[i][c] = 0
    else:
        dp[i][c] = max(f(i-1,c),f(i-1,c-wi[i])+vi[i])
    
    return dp[i][c]

if __name__ == "__main__":
    c = int(input())
    vi = [int(i) for i in input().split(" ")]
    wi = [int(i) for i in input().split(" ")]

    print(f(len(vi)-1,c))