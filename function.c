#include"linktelbook.h"
int flag = 1;

//��ʼ���绰��
struct item* inittelbook(void)
{
	struct item* head = (struct item*)malloc(sizeof(struct item));
	if (head)
	{
		puts("��ʼ���ɹ�!");
		head->next = NULL;
		length = 0;
		return head;
	}
	else
		puts("��ʼ��ʧ��!");
}

//�½���ϵ��
int create(struct item* head)
{
	checkpointer(head);
	struct item* temp = (struct item*)malloc(sizeof(struct item));
	if (temp == NULL)
	{
		puts("�½���ϵ��ʧ��!");
		return 0;
	}
	else
	{
		puts("��ʼ�½���ϵ��");
		int s = get(temp);
		if (!s)
		{
			puts("����ʧ��!");
			return 0;
		}
		temp->next = head->next;
		head->next = temp;
		head = temp;
		length++;
	}
	return 1;
}


//���벢����ַ���
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

//���벢�ṩ���߼��Ļ���
int  get(struct item* L)
{
	printf("����������:\n");
	s_gets(L->name, MAXNAME);
	//name��ʼ��Ϊ0������ɹ��Ͳ���0����ͬ
	if (L->name[0])
	{
		puts("��������ɹ���");
	}
	else
	{
		printf("\n�����������\n");
		return 0;
	}
	puts("����������绰����:");
	s_gets(L->telnum, MAXTEL);
	if (L->telnum[0])
	{
		puts("�绰��������ɹ���");
	}
	else
	{
		puts("�绰�����������");
		return 0;
	}
	return 1;
}

//��ӡ�绰��
void print(struct item* head)
{
	if (!head || !head->next)
	{
		puts("��Ч�ĵ�ַ!");
		exit(1);
	}
	else
	{
		puts("��ʼ��ӡ");
		struct item* p = head->next;
		int i = length;
		while (p)
		{
			printf("��%dλ��ϵ��%s���绰������%s\n",
				i, p->name, p->telnum);
			i--;
			p = p->next;
		}
		puts("��ӡ���!");
	}
}

//������ϵ��
int insert(struct item* head, int pos)
{
	checkpointer(head);
	if (pos < 1 || pos > length)
	{
		puts("����λ����Ч!");
		return 0;
	}
	else
	{
		puts("��ʼ������ϵ��");
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
			puts("�ڴ����!");
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

//�����ֲ�����ϵ��
int checkname(struct item* head)
{
	checkpointer(head);
	//��ȡ���ҵ�����
	char name[MAXNAME];
	int i = 0;
	struct item* p = head->next;
	puts("��������ҵ�����:");
	s_gets(name, MAXNAME);
	while (strcmp(name, p->name) && i<length)
	{
		i++;
		p = p->next;
	}
	if (i < length)
	{
		printf("%s�ǵ�%dλ��ϵ�ˣ��绰������%s\n",
			name,length-i,p->telnum);
	}
	else
	{
		puts("�޴���ϵ��!");
		return 0;
	}
	return 1;
}

void checkpointer(struct item* head)
{
	if (head == NULL)
	{
		puts("��Ч�ĵ�ַ!");
		exit(1);
	}
}

//���ҵ绰����
int checktel(struct item* head)
{
	char tel[MAXTEL];
	int i = 0;
	struct item* p = head->next;
	checkpointer(head);
	puts("��������ҵĵ绰����:");
	s_gets(tel, MAXTEL);
	while (strcmp(tel, p->telnum) && i < length)
	{
		i++;
		p = p->next;
	}
	if (i < length)
	{
		printf("�绰������%s���ǵ�%dλ��ϵ��%s\n",
			tel, length - i, p->name);
	}
	else
	{
		puts("�޴���ϵ��!");
		return 0;
	}
	return 1;
}

//�޸���ϵ��
int revise(struct item* head, int n)
{
	checkpointer(head);
	if (n <1 || n > length)
	{
		puts("��Ч���޸ĵ�ַ!");
		return 0;
	}
	//����
	int i = 0;
	struct item* p = head->next;
	while (i < length - n && p)
	{
		i++;
		p = p->next;
	}

	puts("��ʼ�޸���ϵ��:");
	int s = get(p);
	if (!s)
	{
		puts("�޸�ʧ��!");
		return 0;
	}
	else
		puts("�޸ĳɹ�!");
	return 1;
}

//ɾ����ϵ��
int delete(struct item* head, int n)
{
	checkpointer(head);
	if (n <1 || n > length)
	{
		puts("��Ч��ɾ����ַ!");
		return 0;
	}
	//���򵽴�ɾ������ǰһλ
	int i = 0;
	struct item* p = head->next;
	while (i < length-n-1 && p)
	{
		i++;
		p = p->next;
	}

	puts("��ʼɾ����ϵ��");
	if (n == 1)
		p->next = NULL;
	else
	{
		struct item* temp = p->next;
		p->next = p->next->next;
		free(temp);
	}
	length--;
	puts("ɾ���ɹ�!");
	return 1;
}

//��ȡ������
int getlength(void)
{
	return length;
}

//��������
int reverse(struct item* head)
{
	checkpointer(head);
	puts("��ʼ������ϵ���б�");
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
	puts("�������");
	return 1;
}

//��ʾ�˵����ṩ����
int menu(struct item* head)
{
	char mark[15] = "**************";
	char s;

	printf("\n\n\n\n\n");
	printf("%+20s�˵�����%-20s\n\n", mark, mark);
	printf("%+20s������ϵ�˰�\"a\"%-20s\n\n", mark, mark);
	printf("%+20sɾ����ϵ�˰�\"b\"%-20s\n\n", mark, mark);
	printf("%+20s�޸���ϵ�˰�\"c\"%-20s\n\n", mark, mark);
	printf("%+20s�����ֲ�����ϵ�˰�\"d\"%-20s\n\n", mark, mark);
	printf("%+20s�õ绰���������ϵ�˰�\"e\"%-20s\n\n", mark, mark);
	printf("%+20s��ӡȫ����ϵ�˰�\"f\"%-20s\n\n", mark, mark);
	printf("%+20s������ϵ��λ����\"g\"%-20s\n\n", mark, mark);
	printf("%+20s���õ绰����\"h\"%-20s\n\n", mark, mark);
	printf("%+20s������ϵ�˰�\"i\"%-20s\n\n", mark, mark);
	printf("%+20s�˳��˵���\"n\"%-20s\n\n", mark, mark);

	printf("\n���������Ĳ���:\n");
	while ((s = getchar()) == '\n')
		continue;

	while (1)
	{
		switch (s)
		{
		case 'a':
		{
			int i = 1;
			puts("\n��Ҫ�½��ڼ�λ��ϵ��:");
			if (scanf("%d", &i) == 0)
			{
				puts("�������������!");
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
			puts("\n��Ҫɾ���ڼ�λ��ϵ��:");
			if (scanf("%d", &i) == 0)
			{
				puts("������������ԣ�");
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
			puts("\n��Ҫ�޸ĵڼ�λ��ϵ��:");
			if (scanf("%d", &i) == 0)
			{
				puts("������������ԣ�");
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
			puts("��ʼ����");
			getchar();
			flag = checkname(head);
			exitmenu(head);
			break;
		}
		case 'e':
		{
			puts("��ʼ����");
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
			printf("��ϵ��λ��Ϊ%d\n", getlength(head));
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
			puts("���˳�!");
			free(head);
			exit(1);
		}
		default:
		{
			puts("�������û�и�ѡ��!");
			flag = 0;
			exitmenu(head);
			break;
		}
		}
	}

}

//�ж��û��Ƿ��˳�
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
		puts("���Ĳ������ִ����Ƿ��˳�(y or n):");
		if ((ch = getchar()) == 'y')
		{
			flag = 1;
			menu(head);
		}
		else if (ch == 'n')
		{
			puts("���˳�!");
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



