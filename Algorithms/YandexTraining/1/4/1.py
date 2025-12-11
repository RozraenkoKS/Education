n = int(input())
syn = {}
for i in range(n):
    word1, word2 = map(str, input().split())
    syn[word1] = word2
    syn[word2] = word1

word = str(input())
print(syn[word])