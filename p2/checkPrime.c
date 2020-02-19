#include <stdio.h>
#include <stdbool.h>

bool checkPrime(int number)
{
    bool check = false;
    for (int i = 2; i <= number / 2; ++i)
    {
        if (number % i == 0)
        {
            check = true;
        }
    }
    return check;
}
int main(int argc, char* argv[])
{
    int num = atoi(argv[1]);
    if (!checkPrime(num))
    {
        printf("%d is prime\n", num);
    }
    else
    {
        printf("%d is not prime\n", num);
    }

    return 0;
}