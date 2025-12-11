n, k = map(int, input().split())
a = list(map(int, input().split()))
prefixes = [0] * (n + 1)

for i in range(1, n + 1):
    prefixes[i] = prefixes[i - 1] + a[i - 1]

ans = 0
i, j = 0, 1
while i <= n and j <= n:
    diff = prefixes[j] - prefixes[i]
    if diff == k:
        ans += 1
        i += 1
        j += 1
    elif diff < k:
        j += 1
    else:
        i += 1

print(ans)
print(prefixes)