dependencies = {-1:set()}

def is_ordered(sequence):
    for i in range(len(sequence)):
        if sequence[i] not in dependencies.keys():
            continue
        for j in range(i+1,len(sequence)):
            if sequence[j] in dependencies[sequence[i]]:
                return False
            
    return True

if __name__ == '__main__':
    res = 0
    with open("2024/Day5/puzzleinput.txt", "r") as file:
        for line in file:
            if '|' in line:
                dependency = [int(i) for i in line.split('|')]
                if dependency[1] not in dependencies.keys():
                    dependencies[dependency[1]] = set()
                dependencies[dependency[1]].add(dependency[0])
            elif ',' in line:
                sequence = [int(i) for i in line.split(',')]
                if(is_ordered(sequence)):
                    res += sequence[int(len(sequence)/2)]
    print(res)
