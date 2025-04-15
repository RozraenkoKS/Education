#include <iostream>

int main()
{
    int num{ 100 };
    int i{};
    int j{};
    int k{};
    int n{};

    while (num < 1000)
    {
        i = num / 100;
        j = (num / 10) % 10;
        k = num % 10;

        n = i * i * i + j * j * j + k * k * k;

        if (n == num)
        {
            std::cout << n << " ";
        }

        num += 1;
    }

    return 0;
}
