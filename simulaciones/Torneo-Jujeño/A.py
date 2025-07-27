if __name__ == '__main__':
    xy = [int(i) for i in input().split(" ")]
    x,y = xy[0],xy[1]
    if x*y + 3*y != 0 and x!=5:
        res = (x*x*x - x*y + (5-y)/(5-x)) / (x*y + 3*y)
        print(f"{res:.3f}")
    else:
        print('IMPOSIBLE')