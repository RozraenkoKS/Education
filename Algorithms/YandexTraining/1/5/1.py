n = int(input())
shirts = list(map(int, input().split())) 
m = int(input())
pants = list(map(int, input().split()))

i = 0
j = 0

mindiff = abs(shirts[0] - pants[0])
ans = (shirts[0], pants[0])

while i < len(shirts) and j < len(pants):

    a = shirts[i]
    b = pants[j]

    diff = abs(a - b)
    if diff < mindiff:
        mindiff = diff
        ans = (a, b)

    if a < b:
        i += 1
    else:
        j += 1

print(*ans)