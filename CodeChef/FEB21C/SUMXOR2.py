def nCr(n,r):
    return 1

MOD = 998244353
n = int(input())
arr = []
ans = []
cntOnes = []
for i in (0,n+1):
    arr.append(0)
for i in (1,n+1):
    arr[i] = int(intput())
for i in (0,31):
    cntO = 0
    for j in (1,n+1):
        if((1 << i) & arr[j]):
            cntO += 1
    cntOnes.append(cntO)

for i in (0,n+1):
    ans1 = 0
    for j in (1,i+1):
        for k in (0,31):
            if((cntOnes[k] >= j) and ((n-cntOnes[k]) >= (i-j))):
                ans1 += ((((1 << k)%MOD) * ((nCr(cntOnes[k],j)*nCr(n-cntOnes[k],(i-j)))%MOD))%MOD)
            ans1 %= MOD
        j += 2
    ans[i] = ans1
    ans[i] += ans[i-1]
    ans[i] %= MOD

t = int(input())
while(t):
    x = int(input())
    println(ans[x])
    t -= 1