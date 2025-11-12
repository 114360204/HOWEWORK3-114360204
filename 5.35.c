#include <stdio.h>
#include <limits.h> // 用於 UINT_MAX 和 ULLONG_MAX

unsigned long long int fibonacci(unsigned int n) 
{
    // 處理基礎案例 F(0) 和 F(1)
    if (n == 0) 
    {
        return 0; // F(0) = 0
    }
    if (n == 1) 
    {
        return 1; // F(1) = 1
    }

    // 初始化前兩項
    unsigned long long int previous_term = 0; // F(i-2)
    unsigned long long int current_term = 1;  // F(i-1)
    unsigned long long int next_term;         // F(i)

    // 從 i = 2 開始迭代到 n
    // 總共執行 n - 1 次迴圈
    for (unsigned int i = 2; i <= n; i++) 
    {
        // F(i) = F(i-1) + F(i-2)
        next_term = current_term + previous_term;

        // 檢查是否溢出 (溢出檢查是 b) 部分的基礎，但在此處作為安全措施)
        // 如果 current_term > ULLONG_MAX - previous_term，則會溢出
        // 由於我們使用的是 unsigned long long，溢出時會繞回 0，這可能導致錯誤結果。
        // 在此處我們假設輸入不會導致溢出 (留給 b) 部分解決)。

        // 更新變數，準備下一輪迭代
        previous_term = current_term;
        current_term = next_term;
    }

    return current_term; // 返回 F(n)
}


// *********************************************************
// 主程式和測試
// *********************************************************
int main() 
{
    printf("--- 5.35: 非遞迴費氏數列測試 ---\n");

    // 測試前幾項
    printf("F(0) = %llu (預期: 0)\n", fibonacci(0));
    printf("F(1) = %llu (預期: 1)\n", fibonacci(1));
    printf("F(6) = %llu (預期: 8)\n", fibonacci(6));
    printf("F(10) = %llu (預期: 55)\n", fibonacci(10));
    printf("F(20) = %llu (預期: 6765)\n", fibonacci(20));

    // -----------------------------------------------------
    // 5.35 b): 確定系統可列印的最大費氏數
    // -----------------------------------------------------

    // 找出最大可列印的費氏數 (即 ULLONG_MAX 所能容納的最大 F(n))
    unsigned int n = 0;
    unsigned long long int current_f = 0;
    unsigned long long int next_f = 1;
    unsigned long long int prev_f = 0;

    while (next_f > current_f) 
    { // 檢查條件：當 next_f 不再大於 current_f 時，表示發生溢出。
        prev_f = current_f;
        current_f = next_f;

        // 溢出檢查 (更準確): 如果 prev_f > ULLONG_MAX - current_f，則 next_f 會溢出。
        if (current_f > ULLONG_MAX - prev_f) 
        {
            printf("\n--- 5.35 b): 最大費氏數分析 ---\n");
            printf("第 %u 項 (F(%u)) 即將導致 unsigned long long 溢出。\n", n + 1, n + 1);
            printf("您的系統能列印的最大費氏數是:\n");
            printf("F(%u) = %llu\n", n, current_f);
            break;
        }

        next_f = current_f + prev_f;
        n++;
    }

    return 0;
}