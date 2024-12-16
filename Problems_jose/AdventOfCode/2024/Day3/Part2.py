import re

def count_muls(txt):
    valid = re.findall(r"(do\(\)(?:(?!don't\(\)).)*)",txt)
    valid = valid + re.findall(r"^(.*?don't\(\))",txt)
    res = 0
    for val in valid:
        muls = re.findall(r"mul\(\d{1,3},\d{1,3}\)",val)
        for mul in muls:
            nums = mul[4:len(mul)-1]
            nums = [int(i) for i in nums.split(',')]
            res += nums[0]*nums[1]
    return res

if __name__ == "__main__":
    res = 0
    with open("2024/Day3/puzzleinput.txt", "r") as file:
        data = file.read().replace('\n',' ')
        res += count_muls(data)
    print(res)