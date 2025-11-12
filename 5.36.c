#include <stdio.h>

void solveHanoi(int n, char source_peg, char destination_peg, char auxiliary_peg) 
{
    // 終止條件：如果圓盤數 n = 1，直接移動圓盤
    if (n == 1) 
    {
        printf("將圓盤 1 從柱子 %c 移動到柱子 %c\n", source_peg, destination_peg);
        return;
    }

    // 1. 將 n-1 個圓盤從起始柱 (source) 移到輔助柱 (auxiliary)
    // 這裡，目標柱 (destination) 暫時作為輔助柱。
    solveHanoi(n - 1, source_peg, auxiliary_peg, destination_peg);

    // 2. 將第 n 個 (最大的) 圓盤從起始柱 (source) 移到目標柱 (destination)
    printf("將圓盤 %d 從柱子 %c 移動到柱子 %c\n", n, source_peg, destination_peg);

    // 3. 將 n-1 個圓盤從輔助柱 (auxiliary) 移到目標柱 (destination)
    // 這裡，起始柱 (source) 暫時作為輔助柱。
    solveHanoi(n - 1, auxiliary_peg, destination_peg, source_peg);
}

// -----------------------------------------------------------
// 主程式和測試
// -----------------------------------------------------------
int main() 
{
    int disks;

    printf("--- 5.36: 漢諾塔 (Towers of Hanoi) 模擬 ---\n");
    printf("請輸入要移動的圓盤數量 (例如: 3): ");

    // 讀取圓盤數量
    if (scanf_s("%d", &disks) != 1 || disks < 1)
    {
        printf("錯誤：圓盤數量必須是 >= 1 的整數。\n");
        return 1;
    }

    printf("\n移動 %d 個圓盤的步驟如下：\n", disks);

    // 初始呼叫：將 disks 從 A 移到 C，B 作為輔助
    solveHanoi(disks, 'A', 'C', 'B');

    // 計算總步數 (2^n - 1)
    long long moves = 1;
    for (int i = 0; i < disks; i++) 
    {
        moves *= 2;
    }
    moves -= 1;

    printf("\n總共需要 %lld 步完成移動。\n", moves);

    // 題外話：64 個圓盤需要 2^64 - 1 步，這是個天文數字。

    return 0;
}