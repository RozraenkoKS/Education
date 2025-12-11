# import sys


def main():
    """
    Пример ввода и вывода числа n, где -10^9 < n < 10^9:
    n = int(input())
    print(n)
    """

    x = [int(i) for i in input().split()]
    n = len(x)
    ans = []
    for i in range(n):
        if x[i] != 0:
            ans.append(i)
    print(*ans)

    for i in range(1, n):
        x = [int(i) for i in input().split()]
        ans = []
        for j in range(n):
                if x[j] != 0:
                    ans.append(j)
        print(*ans)



if __name__ == '__main__':
    main()
