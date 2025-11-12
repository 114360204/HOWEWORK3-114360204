#include <stdio.h>

long long power(int base, int exponent) 
{

    // 1. 【終止條件 / 基礎案例】(Base Case)
    // 當 exponent 等於 1 時，遞迴終止並返回 base^1 = base。
    if (exponent == 1) 
    {
        return (long long)base;
    }

    // 2. 【遞迴步驟】(Recursion Step)
    // 使用題目要求的關係式： base^exponent = base * base^(exponent - 1)
    // 呼叫 power 函數計算 exponent - 1 的結果，然後乘以 base。
    return (long long)base * power(base, exponent - 1);
}


// -----------------------------------------------------------
// 測試範例
// -----------------------------------------------------------
int main() 
{
    printf("--- 5.34: 遞迴求冪測試 ---\n");

    int base1 = 3;
    int exp1 = 4;
    printf("power(%d, %d) = %lld \n", base1, exp1, power(base1, exp1));


    return 0;
}