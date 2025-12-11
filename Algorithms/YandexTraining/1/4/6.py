from sys import stdin

info = {}

for line in stdin:
    name, product, quantity = line.split()
    info[(name, product)] = info.get((name, product), 0) + int(quantity)

name = 42
for key in sorted(info.keys()):
    curr_name = key[0]
    if name != curr_name:
        name = curr_name
        print(f'{name}:')
        print(key[1], info[key])
    else:
        print(key[1], info[key])
