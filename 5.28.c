#include <stdio.h>


char changeCase(char alphabet)
{
	// 檢查是否為大寫字母 (ASCII: 'A' 到 'Z')
	if (alphabet >= 'A' && alphabet <= 'Z')
	{
		// 轉換成小寫：加上固定的差值 ('a' - 'A' = 32)
		return alphabet + ('a' - 'A');
	}

	// 檢查是否為小寫字母 (ASCII: 'a' 到 'z')
	if (alphabet >= 'a' && alphabet <= 'z')
	{
		// 轉換成大寫：減去固定的差值
		return alphabet - ('a' - 'A');
	}

	// 如果不是英文字母，則返回原字元
	return alphabet;
}

void test_5_28()
{
	printf("\n--- 5.28: 改變大小寫測試 ---\n");
	printf("'A' 轉為: %c\n", changeCase('A'));
	printf("'V' 轉為: %c\n", changeCase('V'));
	printf("'5' 轉為: %c\n", changeCase('5'));
}

int main()
{
	test_5_28();
	// ... 其他程式碼
	return 0;
}