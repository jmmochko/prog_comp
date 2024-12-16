def is_safe(nums):
    if(len(nums)<=1):
        return True
    if(nums[0]==nums[1]):
        return False
    if(nums[0]>nums[1]):
        for i in range(1,len(nums)):
            if(nums[i-1]<=nums[i] or abs(nums[i-1]-nums[i]) > 3):
                return False
    else:
        for i in range(1,len(nums)):
            if(nums[i-1]>=nums[i] or abs(nums[i-1]-nums[i]) > 3):
                return False
    return True
    
if __name__ == "__main__":
    res = 0
    nums = [int(s) for s in input().split(" ")]
    while(len(nums)>0):
        if(is_safe(nums)):
            res += 1
        print(res)
        nums = [int(s) for s in input().split(" ")]