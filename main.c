#include"linktelbook.h"
int main(void)
{
	char ch;
	puts("��ӭʹ�õ绰��!");
	puts("��ʼ���绰������ܿ�ʼ����,�Ƿ��ʼ��(y or else)");
	if ((ch = getchar()) == 'y')
	{
		struct item* head = inittelbook();
		if (head)
		{
			puts("��ʼ���ɹ�!\n");
			menu(head);
		}
	}
	else
	{
		puts("���˳�!");
		return 0;
	}
	puts("���!");
	return 0;
}