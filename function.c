#include"linktelbook.h"
int flag = 1;

//初始化电话本
struct item* inittelbook(void)
{
	struct item* head = (struct item*)malloc(sizeof(struct item));
	if (head)
	{
		puts("初始化成功!");
		head->next = NULL;
		length = 0;
		return head;
	}
	else
		puts("初始化失败!");
}

//新建联系人
int create(struct item* head)
{
	checkpointer(head);
	struct item* temp = (struct item*)malloc(sizeof(struct item));
	if (temp == NULL)
	{
		puts("新建联系人失败!");
		return 0;
	}
	else
	{
		puts("开始新建联系人");
		int s = get(temp);
		if (!s)
		{
			puts("输入失败!");
			return 0;
		}
		temp->next = head->next;
		head->next = temp;
		head = temp;
		length++;
	}
	return 1;
}


//输入并检查字符串
char* s_gets(char* st, int n)
{
	char* ret_val;
	int i = 0;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (st[i] != '\n' && st[i] != '\0')
			i++;
		if (st[i] == '\n')
			st[i] = '\0';
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
	return ret_val;
}

//输入并提供更高级的互动
int  get(struct item* L)
{
	printf("请输入姓名:\n");
	s_gets(L->name, MAXNAME);
	//name初始化为0，输入成功就不是0，下同
	if (L->name[0])
	{
		puts("姓名输入成功！");
	}
	else
	{
		printf("\n姓名输入错误！\n");
		return 0;
	}
	puts("现在请输入电话号码:");
	s_gets(L->telnum, MAXTEL);
	if (L->telnum[0])
	{
		puts("电话号码输入成功！");
	}
	else
	{
		puts("电话号码输入错误！");
		return 0;
	}
	return 1;
}

//打印电话本
void print(struct item* head)
{
	if (!head || !head->next)
	{
		puts("无效的地址!");
		exit(1);
	}
	else
	{
		puts("开始打印");
		struct item* p = head->next;
		int i = length;
		while (p)
		{
			printf("第%d位联系人%s，电话号码是%s\n",
				i, p->name, p->telnum);
			i--;
			p = p->next;
		}
		puts("打印完成!");
	}
}

//插入联系人
int insert(struct item* head, int pos)
{
	checkpointer(head);
	if (pos < 1 || pos > length)
	{
		puts("插入位置无效!");
		return 0;
	}
	else
	{
		puts("开始插入联系人");
		struct item* p = head->next;
		int i = 0;
		while (p && i < length - pos)
		{
			i++;
			p = p->next;
		}
		struct item* temp = (struct item*)malloc(sizeof(struct item));
		if (!temp)
		{
			puts("内存错误!");
			return 0;
		}
		int flag = get(temp);
		if (!flag)
			return 0;
		else
		{
			temp->next = p->next;
			p->next = temp;
			length++;
		}
	}
	return 1;
}

//用名字查找联系人
int checkname(struct item* head)
{
	checkpointer(head);
	//获取查找的姓名
	char name[MAXNAME];
	int i = 0;
	struct item* p = head->next;
	puts("请输入查找的姓名:");
	s_gets(name, MAXNAME);
	while (strcmp(name, p->name) && i<length)
	{
		i++;
		p = p->next;
	}
	if (i < length)
	{
		printf("%s是第%d位联系人，电话号码是%s\n",
			name,length-i,p->telnum);
	}
	else
	{
		puts("无此联系人!");
		return 0;
	}
	return 1;
}

void checkpointer(struct item* head)
{
	if (head == NULL)
	{
		puts("无效的地址!");
		exit(1);
	}
}

//查找电话号码
int checktel(struct item* head)
{
	char tel[MAXTEL];
	int i = 0;
	struct item* p = head->next;
	checkpointer(head);
	puts("请输入查找的电话号码:");
	s_gets(tel, MAXTEL);
	while (strcmp(tel, p->telnum) && i < length)
	{
		i++;
		p = p->next;
	}
	if (i < length)
	{
		printf("电话号码是%s的是第%d位联系人%s\n",
			tel, length - i, p->name);
	}
	else
	{
		puts("无此联系人!");
		return 0;
	}
	return 1;
}

//修改联系人
int revise(struct item* head, int n)
{
	checkpointer(head);
	if (n <1 || n > length)
	{
		puts("无效的修改地址!");
		return 0;
	}
	//定向
	int i = 0;
	struct item* p = head->next;
	while (i < length - n && p)
	{
		i++;
		p = p->next;
	}

	puts("开始修改联系人:");
	int s = get(p);
	if (!s)
	{
		puts("修改失败!");
		return 0;
	}
	else
		puts("修改成功!");
	return 1;
}

//删除联系人
int delete(struct item* head, int n)
{
	checkpointer(head);
	if (n <1 || n > length)
	{
		puts("无效的删除地址!");
		return 0;
	}
	//定向到待删除结点的前一位
	int i = 0;
	struct item* p = head->next;
	while (i < length-n-1 && p)
	{
		i++;
		p = p->next;
	}

	puts("开始删除联系人");
	if (n == 1)
		p->next = NULL;
	else
	{
		struct item* temp = p->next;
		p->next = p->next->next;
		free(temp);
	}
	length--;
	puts("删除成功!");
	return 1;
}

//获取链表长度
int getlength(void)
{
	return length;
}

//倒置链表
int reverse(struct item* head)
{
	checkpointer(head);
	puts("开始倒置联系人列表");
	struct item* p = head->next;
	struct item* temp;
	head->next = NULL;
	while (p)
	{
		temp = p->next;
		p->next = head->next;
		head->next = p;
		p = temp;
	}
	puts("倒置完成");
	return 1;
}

//显示菜单并提供互动
int menu(struct item* head)
{
	char mark[15] = "**************";
	char s;

	printf("\n\n\n\n\n");
	printf("%+20s菜单界面%-20s\n\n", mark, mark);
	printf("%+20s插入联系人按\"a\"%-20s\n\n", mark, mark);
	printf("%+20s删除联系人按\"b\"%-20s\n\n", mark, mark);
	printf("%+20s修改联系人按\"c\"%-20s\n\n", mark, mark);
	printf("%+20s用名字查找联系人按\"d\"%-20s\n\n", mark, mark);
	printf("%+20s用电话号码查找联系人按\"e\"%-20s\n\n", mark, mark);
	printf("%+20s打印全部联系人按\"f\"%-20s\n\n", mark, mark);
	printf("%+20s返回联系人位数按\"g\"%-20s\n\n", mark, mark);
	printf("%+20s逆置电话本按\"h\"%-20s\n\n", mark, mark);
	printf("%+20s创建联系人按\"i\"%-20s\n\n", mark, mark);
	printf("%+20s退出菜单按\"n\"%-20s\n\n", mark, mark);

	printf("\n请输入您的操作:\n");
	while ((s = getchar()) == '\n')
		continue;

	while (1)
	{
		switch (s)
		{
		case 'a':
		{
			int i = 1;
			puts("\n您要新建第几位联系人:");
			if (scanf("%d", &i) == 0)
			{
				puts("输入错误，请重试!");
				flag = 0;
				exitmenu(head);
			}
			getchar();
			flag = insert(head, i);
			exitmenu(head);
			break;
		}
		case'b':
		{
			int i = 0;
			puts("\n您要删除第几位联系人:");
			if (scanf("%d", &i) == 0)
			{
				puts("输入错误，请重试！");
				flag = 0;
				exitmenu(head);
			}
			getchar();
			flag = delete(head, i);
			exitmenu(head);
			break;
		}
		case 'c':
		{
			int i = 0;
			puts("\n您要修改第几位联系人:");
			if (scanf("%d", &i) == 0)
			{
				puts("输入错误，请重试！");
				flag = 0;
				exitmenu(head);
			}
			getchar();
			flag = revise(head, i);
			exitmenu(head);
			break;
		}
		case 'd':
		{
			puts("开始查找");
			getchar();
			flag = checkname(head);
			exitmenu(head);
			break;
		}
		case 'e':
		{
			puts("开始查找");
			getchar();
			flag = checktel(head);
			exitmenu(head);
			break;
		}
		case 'f':
		{
			print(head);
			menu(head);
			break;
		}
		case 'g':
		{
			printf("联系人位数为%d\n", getlength(head));
			menu(head);
			break;
		}
		case 'h':
		{
			flag = reverse(head);
			exitmenu(head);
			break;
		}
		case 'i':
		{
			getchar();
			flag = create(head);
			exitmenu(head);
			break;
		}
		case 'n':
		{
			puts("已退出!");
			free(head);
			exit(1);
		}
		default:
		{
			puts("输入错误，没有该选项!");
			flag = 0;
			exitmenu(head);
			break;
		}
		}
	}

}

//判断用户是否退出
void exitmenu(struct item* head)
{
	char ch;
	if (flag)
	{
		printf("flag:%d\n", flag);
		menu(head);
	}
	else
	{
		puts("您的操作出现错误，是否退出(y or n):");
		if ((ch = getchar()) == 'y')
		{
			flag = 1;
			menu(head);
		}
		else if (ch == 'n')
		{
			puts("已退出!");
			free(head);
			exit(1);
		}
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
}



