from sys import stdin

words = {}
max_count = 0
max_word = ''

for line in stdin:
    for word in line.split():
        words[word] = words.get(word, 0) + 1
        if words[word] > max_count or (words[word] == max_count and (max_word == '' or word < max_word)):
            max_count = words[word]
            max_word = word

print(max_word)
