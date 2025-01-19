if __name__ == "__main__":
    s,t = input(),input()
    s = s.upper()
    t = t.upper()
    for position in range(len(s)):
        if(s[position] < t[position]):
            print(-1)
            break
        elif(s[position] > t[position]):
            print(1)
            break
        if(position == len(s)-1):
            print(0)