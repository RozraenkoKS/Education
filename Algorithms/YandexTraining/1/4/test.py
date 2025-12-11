from sys import stdin
import re

n, c ,d = input().split()
n = int(n)

key_words = []
tokens = []
counter = {}

for i in range(n):
    key_words.append(input())
    
for line in stdin:

    if c == 'YES':
        tokens.extend(re.findall(r"[A-Za-z0-9_]+", line))
    else:
        tokens.extend(re.findall(r"[A-Za-z0-9_]+", line))

max_count = 1
max_count_word = tokens[0]

for token in tokens:
    
    if token not in key_words:
        count = counter.get(token, 0) + 1
        counter[token] = count

        if count > max_count:
            max_count = count
            max_count_word = token

print(max_count_word)
