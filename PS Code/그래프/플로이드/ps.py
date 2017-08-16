N = int(input())
dp = [[float('inf')] * (N+1) for i in range(N+1)]
for i in range(int(input())):
    u, v, w = map(int, input().split())
    dp[u][v] = min(dp[u][v], w)
    
for i in range(N+1):
    dp[i][i] = 0
    
for k in range(1, N+1):
    for i in range(1, N+1):
        for j in range(1, N+1):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

for i in range(1, N+1):
    for j in range(1, N+1):
        if(dp[i][j] == float('inf')):
            print(0, end = ' ')
        else:
            print(dp[i][j], end = ' ')
    print()
