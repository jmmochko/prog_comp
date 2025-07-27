import random

if __name__ == "__main__":
    t = int(input())
    for case in range(t):
        nm = [int(i) for i in input().split(" ")]
        n = int(nm[0])
        m = int(nm[1])
        cont = 0
        for tr in range(7):
            x = random.randint(1,n)
            y = random.randint(1,m)
            print(f'DIG {x} {y}')
            res = int(input())
            if(res==1):
                cont+=1
            if(cont==2):
                break
        break
