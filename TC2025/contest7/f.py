import queue
g = []
color = []
vistos = []
sePuede = True
def bfs(u):
    q = queue.Queue(maxsize = len(g))
    q.put(u)
    while(not q.empty()):
        yo = q.get()
        for nodo in g[yo]:
            vistos[min(nodo,0)] = True
            if(color[nodo] == 2):
                color[nodo] = 1 - color[yo]
                q.put(nodo)
            elif color[nodo] == color[yo]:
                return False
    return True

if __name__ == "__main__":
    nm = [int(i) for i in input().split(" ")]
    n = nm[1]
    m = nm[0]
    for i in range(n):
        g.append([])
        color.append(2)
    for _ in range(m):
        p = input()
        if(p[0]=='!'):
            if(color[int(p[1::]) - 1] == 1):
                sePuede = False
            color[int(p[1::]) - 1] = 0
            continue
        if(not '->' in p):
            if(color[int(p) - 1] == 0):
                sePuede = False
            color[int(p) - 1] = 1
            continue
        td = p.split(" -> ")
        trs = [int(i) for i in td[0].split(" ")]
        nodo = td[1]
        if('!' not in nodo):
            nuevoNodo = len(g)
            g.append([])
            color.append(2)
            nodo = int(nodo) - 1
            g[nuevoNodo].append(nodo)
            for k in trs:
                g[k-1].append(nuevoNodo)
            continue
        nodo = int(nodo[1::]) - 1
        for k in trs:
            g[nodo].append(k-1)
            g[k-1].append(nodo)
    for i in range(len(g)):
        vistos.append(False)
    for nodo in range(n):
        if not vistos[nodo] and color[nodo] != 2:
            vistos[nodo] = True
            sePuede = sePuede and bfs(nodo)
            if not sePuede:
                break
    if sePuede:
        for nodo in range(n):
            if color[nodo] == 0 or color[nodo] == 2:
                print('F',end = '')
            else:
                print('T',end = '')
        print('')
    else:
        print('conflict')
    