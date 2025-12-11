N = int(input())
words = []
ans = 0

for i in range(N):
    words.append(input())

for word in input().split():
    if word not in words:   
        count = sum(c.isupper() for c in word)
        if count != 1:
            ans += 1

print(ans)