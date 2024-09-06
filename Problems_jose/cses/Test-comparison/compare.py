user = open("Problems_jose/cses/Test-comparison/ruser.txt", "r")
correct = open("Problems_jose/cses/Test-comparison/correct.txt", "r")
c =""
i = 0
errors = []
for u in user:
    c = correct.readline()
    if(c!=u):
        print(f"ERROR FOUND AT TEST {i}")
        errors.append(i)
    i+=1

t = open("Problems_jose/cses/Test-comparison/testcase.txt")
j = -1
for l in t:
    if(j in errors):
        print(l)
    j += 1
print(len(errors))