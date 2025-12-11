def initmemory(maxn):
    memory = []
    for i in range(maxn):
        memory.append([0, i + 1, 0])
    return [memory, 0]

def newnode(memstruct):
    memory, firstfree = memstruct
    memstruct[1] = memory[firstfree][1]
    return firstfree

def delnode(memstruct, index):
    memory, firstfree = memstruct
    memory[index][1] = firstfree
    memstruct[1] = index

def createandfillnode(memstruct, key):
    index = newnode(memstruct)
    memstruct[0][index][0] = key
    memstruct[0][index][1] = -1
    memstruct[0][index][2] = -1
    return index

def add(memstruct, root, x):
    key = memstruct[0][root][0]
    if x < key:
        left = memstruct[0][root][1]
        if left == -1:
            memstruct[0][root][1] = createandfillnode(memstruct, x)
        else:
            add(memstruct, left, x)
    elif x > key:
        right = memstruct[0][root][2]
        if right == -1:
            memstruct[0][root][2] = createandfillnode(memstruct, x)
        else:
            add(memstruct, right, x)

def main(n, keys):
    memstruct = initmemory(n)
    root = createandfillnode(memstruct, keys[0])
    for i in range(1, n):
        add(memstruct, root, keys[i])


if __name__ == '__main__':
    keys = list(map(int, input().split()))[:-1]
    n = len(keys)

    if len(keys) == 0:
        print(0)
    else:
        print(main(n, keys))
    