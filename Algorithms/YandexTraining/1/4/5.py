n = int(input())
blocks = {}
h_max = 0

for i in range(n):
    w, h = map(int, input().split())
    if w not in blocks:
        blocks[w] = h
    else:
        if h > blocks[w]:
            blocks[w] = h
            
print(sum(blocks.values()))