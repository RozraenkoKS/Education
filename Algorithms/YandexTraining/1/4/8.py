m, n = map(int, input().split())
W = {}

word = input().strip()
string = input().strip()
res = 0

for i in word:
    W[i] = W.get(i, 0) + 1

def is_word(substring):
    S = {}
    for j in substring:
        S[j] = S.get(j, 0) + 1
    for key in W.keys():
        if W[key] != S.get(key, 0):
            return False
    return True

for i in range(n - m + 1):
    res += int(is_word(string[i: i + m]))

print(res)
