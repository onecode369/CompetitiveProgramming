import math

adjList = []
d = []
def findPD(d,node):
    if(len(adjList[node]) == 0):
        d[node] = 1
        return 1
    d[node] =  1
    for x in adjList[node]:
        if(d[x] == -1):
            d[x] = findPD(d,x)
        d[node] = (int)((d[node]*d[x])/(int)(math.gcd(d[x],d[node])))
    d[node] *= len(adjList[node])
    return d[node]

n = int(input())

num = []
for i in range(0,n):
    d.append(-1)
    adjList.append([])
    num.append(0)

p = list(map(int, input().split(" ")))
p.insert(0,-1)
for i in range(0,n-1):
    adjList[p[i+1]-1].append(i+1)

temp = findPD(d,0)
t = int(input())

q = []
while(t):
    left = 0
    node ,numTask = map(int,input().split(" "))
    node -= 1
    q.append(node)
    num[node] = numTask
    while(len(q)):
        y = q[0]
        if(num[y]%d[y] != 0):
            if(len(adjList[y])):
                if(num[y]%len(adjList[y]) != 0):
                    left += num[y]
                else:
                    for x in adjList[y]:
                        num[x] = num[y]/len(adjList[y])
                        q.append(x)
        q.remove(q[0])
    print(int(left))
    t -= 1