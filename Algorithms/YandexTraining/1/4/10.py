from sys import stdin
import re

n, c, d = input().split()
n = int(n)
c = c.lower()
d = d.lower()

sensitive = (c == 'yes')
can_start_with_digit = (d == 'yes')

key_words = set()
tokens = []
counter = {}


for i in range(n):

    key_word = input()

    if not sensitive:
        key_word = key_word.lower()  

    key_words.add(key_word)
    
for line in stdin:
    
    tokens.extend(re.findall(r"[A-Za-z0-9_]+", line))

max_count = 0
max_count_word = ''

for token in tokens:

    if not can_start_with_digit and token[0].isdigit():
        continue

    if token.isdigit():
        continue

    if not sensitive:
        token = token.lower()
    
    if token not in key_words:
        count = counter.get(token, 0) + 1
        counter[token] = count

        if count > max_count:
            max_count = count
            max_count_word = token

print(max_count_word)
