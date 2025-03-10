s = input()
supp = s.upper()
cnt = 0
for i in range(len(s)):
    if(s[i]!=supp[i]):
        cnt += 1
if(cnt<(len(s)/2)):
    print(supp)
else:
    print(s.lower())