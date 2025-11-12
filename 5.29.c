#include <stdio.h>
#include <stdlib.h> 

// *********************************************************
// 徊ㄧ计程そ计 (GCD)
// *********************************************************
int gcd(int a, int b) 
{
    // 絋玂 a, b 琌獶璽计
    a = (a > 0) ? a : -a;
    b = (b > 0) ? b : -b;

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// *********************************************************
// 5.29: 程そ计 (LCM) ㄧ计
// *********************************************************
long long lcm(int a, int b)
{
    if (a == 0 || b == 0) 
    {
        return 0;
    }

    // 盢块矗ど long long 獽璸衡
    long long abs_a = (long long)a > 0 ? a : -(long long)a;
    long long abs_b = (long long)b > 0 ? b : -(long long)b;

    long long common_divisor = gcd((int)abs_a, (int)abs_b);

    // 璸衡 LCM
    return (abs_a / common_divisor) * abs_b;
}

// *********************************************************
// 祘Α㎝代刚
// *********************************************************
int main() {
    printf("--- 5.29: 程そ计 (LCM) 代刚 ---\n");

    int num1 = 12;
    int num2 = 18;
    printf("LCM(%d, %d) = %lld \n", num1, num2, lcm(num1, num2));

    return 0;
}