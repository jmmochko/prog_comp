if __name__ == "__main__":
    n = int(input())
    x = 0
    for i in range(n):
        opp = input()
        if '+' in opp:
            x += 1
        else:
            x -= 1
    print(x)