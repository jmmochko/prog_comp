def is_safe(nums):
    if(len(nums)<=2):
        return True
    
    #increasing
    prob = False
    inc = True
    numsinc = [i for i in nums]
    for i in range(1,len(nums)):
        if(numsinc[i-1]>=numsinc[i] or abs(numsinc[i-1]-numsinc[i]) > 3):
            if(prob):
                inc = False
                break
            prob = True
            numsinc[i] = numsinc[i-1]

    #decreasing    
    prob = False
    dec = True
    numsdec = [i for i in nums]
    for i in range(1,len(nums)):
        if(numsdec[i-1]<=numsdec[i] or abs(numsdec[i-1]-numsdec[i]) > 3):
            if(prob):
                dec = False
                break
            prob = True
            numsdec[i] = numsdec[i-1]

    return dec or inc
    
if __name__ == "__main__":
    res = 0
    nums = [int(s) for s in input().split(" ")]
    while(len(nums)>0):
        if(is_safe(nums) or is_safe(nums[::-1])):
            res += 1
        try:
            nums = [int(s) for s in input().split(" ")]
        except:
            break
    print(res)