#include"linktelbook.h"
int main(void)
{
	char ch;
	puts("欢迎使用电话本!");
	puts("初始化电话本后才能开始操作,是否初始化(y or else)");
	if ((ch = getchar()) == 'y')
	{
		struct item* head = inittelbook();
		if (head)
		{
			puts("初始化成功!\n");
			menu(head);
		}
	}
	else
	{
		puts("已退出!");
		return 0;
	}
	puts("完成!");
	return 0;
}