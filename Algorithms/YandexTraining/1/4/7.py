from sys import stdin
bank = {}

for line in stdin:
    words = line.split()
    if words[0] == 'DEPOSIT':
        bank[words[1]] = bank.get(words[1], 0) + int(words[2])
    elif words[0] == 'INCOME':
        for key in bank.keys():
            if bank[key] > 0:
                bank[key] += int(0.01 * int(words[1]) * bank[key])
    elif words[0] == 'TRANSFER':
        bank[words[1]] = bank.get(words[1], 0) - int(words[3])
        bank[words[2]] = bank.get(words[2], 0) + int(words[3])
    elif words[0] == 'WITHDRAW':
        bank[words[1]] = bank.get(words[1], 0) - int(words[2])
    elif words[0] == 'BALANCE':
        print(bank.get(words[1], 'ERROR'))
