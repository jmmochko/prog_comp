ops = ["AA","CC"]
t = int(input())
for _ in range(t):
    s = input()
    t = input()
    cnt1 = 0
    cnt2 = 0
    for c in s:
        if(c == 'B'):
            cnt1 += 1
    for c in t:
        if(c == 'B'):
            cnt2 += 1
    s = s.replace('B','')
    t = t.replace('B','')
    while(True):
        tiene = False
        for op in ops:
            if op in s:
                tiene = True
            s = s.replace(op,'')
        if not tiene:
            break
    while(True):
        tiene = False
        for op in ops:
            if op in t:
                tiene = True
            t = t.replace(op,'')
        if not tiene:
            break
    if(t==s and cnt1%2 == cnt2%2):
        print("YES")
    else:
        print("NO")

#ACAC
#AACC