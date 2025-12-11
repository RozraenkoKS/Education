N = int(input())
x = [0] * (N + 1)
y = [0] * (N + 1)

for i in range(1, N + 1):
    xi, yi = map(int, input().split())
    x[i] = xi
    y[i] = yi

up = [0] * (N + 1)   
down = [0] * (N + 1)

for i in range(2, N + 1):
    diff = y[i] - y[i - 1]
    up[i] = up[i - 1] + (diff if diff > 0 else 0)
    down[i] = down[i - 1] + ((-diff) if diff < 0 else 0)

M = int(input())
for _ in range(M):
    s, f = map(int, input().split())
    if s < f:
        print(up[f] - up[s])
    else:
        print(down[s] - down[f])

