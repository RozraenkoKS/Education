def main(x):
    min_dist = len(s)
    dist = min_dist
    i_x = -1
    i_y = -1
    for i, x in enumerate(s):
        if x == 'X':
            i_x = i
            if i_y != -1:
                dist = abs(i_x - i_y)
        elif x == 'Y':
            i_y = i
            if i_x != -1:
                dist = abs(i_x - i_y)

        if dist < min_dist:
            min_dist = dist

    if i_x == -1 or i_y == -1:
        return 0
    else:
        return min_dist
    
print(main('XOOYOXXXOY'))
