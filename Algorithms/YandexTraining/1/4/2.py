from sys import stdin

words = {}
ans = []

for line in stdin:
    for word in line.split():
        if word not in words:
            words[word] = 0
        ans.append(words[word])
        words[word] += 1

print(*ans)