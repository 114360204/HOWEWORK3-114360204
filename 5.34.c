#include <stdio.h>

long long power(int base, int exponent)
{
    // ✅ 終止條件一：0 次方 = 1
    if (exponent == 0)
        return 1;

    // ✅ 終止條件二：1 次方 = base
    if (exponent == 1)
        return (long long)base;

    // ✅ 遞迴步驟
    return (long long)base * power(base, exponent - 1);
}

int main()
{
    printf("--- 5.34: 遞迴求冪測試 ---\n");

    int base1 = 3;
    int exp1 = 4;
    printf("power(%d, %d) = %lld\n", base1, exp1, power(base1, exp1));

    int base2 = 5;
    int exp2 = 0;
    printf("power(%d, %d) = %lld\n", base2, exp2, power(base2, exp2));

    return 0;
}
