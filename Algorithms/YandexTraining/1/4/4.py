n = int(input())
c = {}
for i, c_i in enumerate(list(map(int, input().split()))):
    c[i + 1] = c_i

k = int(input())

for p_j in list(map(int, input().split())):
    c[p_j] -= 1

for i in range(n):
    if c[i + 1] >= 0:
        print('NO')
    else:
        print('YES')