#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Score
{
	int english_;
	int math_;
	int com_;
	int clg_;
};
struct student
{
	char name[30];
	int num;
	char sex[20];
	struct Score score;
	struct student *next;
};

struct student *build(int n)//创建链表
{

	int i;
	struct student *head, *p1, *p2;
	p2 = head = (struct student *)malloc(sizeof(struct student));
	for (i = 0; i < n; i++)
	{
		p1 = (struct student *)malloc(sizeof(struct student));
		p2->next = p1;
		p2 = p1;
	}
	p2->next = NULL;
	p2 = head->next;
	while (p2 != NULL)
	{

		printf("请输入学生的姓名:");
		scanf("%s", &p2->name);
		printf("请输入学生的学号:");
		scanf("%d", &p2->num);
		printf("请输入学生的性别:");
		scanf("%s", &p2->sex);
		printf("请分别输入学生的英语，数学，计导，C语言成绩:");
		scanf("%d%d%d%d", &p2->score.english_, &p2->score.math_, &p2->score.com_, &p2->score.clg_);
		p2 = p2->next;
	}
	return head;
}


void printfs(struct student *head)//全部输出函数
{
	struct student *p2;
	p2 = head->next;
	while (p2 != NULL)
	{
		printf("学生的姓名为:");
		printf("%s\n", p2->name);
		printf("学生的学号为:");
		printf("%d", p2->num);
		printf("\n的性别为:");
		printf("%s\n", p2->sex);
		printf("学生的英语，数学，计导，C语言成绩分别为:");
		printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_);
		printf("\n\n\n");
		p2 = p2->next;
	}
}

void insert2(struct student *head)    //插入函数
{
	int n = 0;
	struct student *p0, *p1, *p2;
	p0 = (struct student *)malloc(sizeof(struct student));
error1:printf("请输入修改后学生的姓名:");
	scanf("%s", &p0->name);
	printf("学生的学号:");
	scanf("%d", &p0->num);
	printf("学生的性别:");
	scanf("%s", &p0->sex);
	printf("分别输入学生的英语，数学，计导，C语言成绩:");
	scanf("%d%d%d%d", &p0->score.english_, &p0->score.math_, &p0->score.com_, &p0->score.clg_);

	p2 = head->next;
	while (p2 != NULL)
	{
		if (p0->num == p2->num)
		{
			printf("您所要插入的学号已存在，请重新输入！");
			goto error1;
		}
		p2 = p2->next;
	}

	p2 = head->next;
	p1 = p2->next;
	if (p0->num < p2->num)
	{
		p0->next = p2;
		head->next = p0;

	}
	else
		while (p1 != NULL)
		{
			if (p2->num<p0->num&&p1->num>p0->num)
			{
				p0->next = p1;
				p2->next = p0;
				break;
			}

			p1 = p1->next;
			p2 = p2->next;
		}
	if (p2->next == NULL)
	{
		if (p2->num < p0->num)
		{
			p2->next = p0;
			p0->next = NULL;
		}
	}


}
void sort(struct student *head)//成绩排序
{
	struct student *p1, *p2;
	int i = 0, j, t, x, m;
	float n = 0;
	int a[100], b[100];
	p1 = head->next;
	while (p1 != NULL)
	{
		b[i] = p1->score.clg_ + p1->score.com_ + p1->score.english_ + p1->score.math_;
		i++;
		p1 = p1->next;
	}
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (b[x] > b[x + 1])
			{
				t = b[x];
				b[x] = b[x + 1];
				b[x + 1] = t;
			}
	printf("学生总分排序为：");
	for (x = 0; x < i; x++)
		printf("%d", b[x]);



	p1 = head->next;
	i = 0;
	while (p1 != NULL)
	{
		a[i] = p1->score.english_;
		i++;
		p1 = p1->next;
	}

	for (m = 0; m < i; m++)
		n += a[m];
	n = n / i;
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (a[x] > a[x + 1])
			{
				t = a[x];
				a[x] = a[x + 1];
				a[x + 1] = t;
			}
	printf("英语成绩从低到高排序为:");
	for (x = 0; x < i; x++)
		printf("%d ", a[x]);
	printf("平均成绩为：");
	printf("%.1f", n);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (a[i - 1] == p2->score.english_)
		{
			printf("\n\n\n\t英语成绩最高的学生的姓名为:");
			printf("%s\n", p2->name);
			printf("\t学生的学号为:");
			printf("%d", p2->num);
			printf("\t学生的性别为:");
			printf("%s\n", p2->sex);
			printf("\t学生的英语，数学，计导，C语言成绩分别为:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}



	i = 0;
	n = 0;
	p1 = head->next;
	while (p1 != NULL)
	{
		a[i] = p1->score.math_;
		i++;
		p1 = p1->next;
	}
	for (m = 0; m < i; m++)
		n += a[m];
	n = n / i;
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (a[x] > a[x + 1])
			{
				t = a[x];
				a[x] = a[x + 1];
				a[x + 1] = t;
			}
	printf("\n数学成绩从低到高排序为:");
	for (x = 0; x < i; x++)
		printf("%d ", a[x]);
	printf("平均成绩为：");
	printf("%.1f", n);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (a[i - 1] == p2->score.math_)
		{
			printf("\n\n\n\t数学成绩最高的学生的姓名为:");
			printf("%s\n", p2->name);
			printf("\t学生的学号为:");
			printf("%d", p2->num);
			printf("\t学生的性别为:");
			printf("%s\n", p2->sex);
			printf("\t学生的英语，数学，计导，C语言成绩分别为:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}
	i = 0;
	n = 0;
	p1 = head->next;
	while (p1 != NULL)
	{
		a[i] = p1->score.com_;
		i++;
		p1 = p1->next;
	}
	for (m = 0; m < i; m++)
		n += a[m];
	n = n / i;
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (a[x] > a[x + 1])
			{
				t = a[x];
				a[x] = a[x + 1];
				a[x + 1] = t;
			}
	printf("\n计算机导论成绩从低到高排序为:");
	for (x = 0; x < i; x++)
		printf("%d ", a[x]);
	printf("平均成绩为：");
	printf("%.1f", n);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (a[i - 1] == p2->score.com_)
		{
			printf("\n\n\n\t计导成绩最高的学生的姓名为:");
			printf("%s\n", p2->name);
			printf("\t学生的学号为:");
			printf("%d", p2->num);
			printf("\t学生的性别为:");
			printf("%s\n", p2->sex);
			printf("\t学生的英语，数学，计导，C语言成绩分别为:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}


	i = 0;
	n = 0;
	p1 = head->next;
	while (p1 != NULL)
	{
		a[i] = p1->score.clg_;
		i++;
		p1 = p1->next;
	}
	for (m = 0; m < i; m++)
		n += a[m];
	n = n / i;
	for (j = 0; j < i; j++)
		for (x = 0; x < i - x; x++)
			if (a[x] > a[x + 1])
			{
				t = a[x];
				a[x] = a[x + 1];
				a[x + 1] = t;
			}
	printf("\nC语言成绩从低到高排序为:");
	for (x = 0; x < i; x++)
		printf("%d ", a[x]);
	printf("平均成绩为：");
	printf("%.1f", n);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (a[i - 1] == p2->score.clg_)
		{
			printf("\n\n\n\tC语言成绩最高的学生的姓名为:");
			printf("%s\n", p2->name);
			printf("\t学生的学号为:");
			printf("%d", p2->num);
			printf("\t学生的性别为:");
			printf("%s\n", p2->sex);
			printf("\t学生的英语，数学，计导，C语言成绩分别为:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}

}
void find(struct student *head)//按照学号查找函数
{
	int i, n = 0;
	struct student *p2;
	p2 = head->next;
	printf("请输入您所要查找的学生学号:");
	scanf("%d", &i);
	while (p2 != NULL)
	{
		if (i == p2->num)
		{
			printf("\n\n\n\t您所要查找的学生的姓名为:");
			printf("%s\n", p2->name);
			printf("\t学生的学号为:");
			printf("%d", p2->num);
			printf("\t学生的性别为:");
			printf("%s\n", p2->sex);
			printf("\t学生的英语，数学，计导，C语言成绩分别为:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++; break;
		}
		p2 = p2->next;
	}
	if (n == 0)
		printf("\t\t查无此人！");
}
void finds1(struct student *head)//按照姓名查找函数
{
	char a[30];
	int n = 0;
	struct student *p2;
	printf("请输入你所需要查找的姓名:");
	scanf("%s", a);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (strcmp(a, p2->name) == 0)
		{
			printf("学生的姓名为:");
			printf("%s\n", p2->name);
			printf("学生的学号为:");
			printf("%d", p2->num);
			printf("学生的性别为:");
			printf("%s\n", p2->sex);
			printf("学生的英语，数学，计导，C语言成绩分别为:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++;
		}
		p2 = p2->next;
	}
	if (n == 0)
		printf("\t\t查无此人！");
}
void finds2(struct student *head)//查找不及格学生成绩
{
	int n = 0, i = 0;
	struct student *p2, *p0;
	p0 = (struct student *)malloc(sizeof(struct student));
	p2 = head->next;
	while (p2 != NULL)
	{
		if (p2->score.english_ < 60 || p2->score.math_ < 60 || p2->score.com_ < 60 || p2->score.clg_ < 60)
		{
			printf("\n\n\n\t不及格的学生的姓名为:");
			printf("%s\n", p2->name);
			printf("\t学生的学号为:");
			printf("%d", p2->num);
			printf("\t学生的性别为:");
			printf("%s\n", p2->sex);
			printf("\t学生的英语，数学，计导，C语言成绩分别为:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_); n++; i++;
		}
		p2 = p2->next;
	}
	printf("\n\t不及格的人数总共有%d个\n\n", i);
	if (n == 0)
		printf("无不及格学生！");

}




void change(struct student *head)//修改函数
{
	int i, n = 0;
	struct student *p2;
error:printf("请输入您所要修改的学生学号:");
	scanf("%d", &i);
	p2 = head->next;
	while (p2 != NULL)
	{
		if (i == p2->num)
		{
			printf("学生的姓名为:");
			printf("%s\n", p2->name);
			printf("学生的学号为:");
			printf("%d", p2->num);
			printf("学生的性别为:");
			printf("%s\n", p2->sex);
			printf("学生的英语，数学，计导，C语言成绩分别为:");
			printf("%d %d %d %d\n", p2->score.english_, p2->score.math_, p2->score.com_, p2->score.clg_);
			n++;
			break;
		}
		p2 = p2->next;
	}
	if (n == 0)//若未查找到，则报错
	{
		printf("查无此人！");
		goto error;
	}
	printf("请输入修改后学生的姓名:");
	scanf("%s", &p2->name);
	printf("学生的学号:");
	scanf("%d", &p2->num);
	printf("学生的性别:");
	scanf("%s", &p2->sex);
	printf("分别输入学生的英语，数学，计导，C语言成绩:");
	scanf("%d%d%d%d", &p2->score.english_, &p2->score.math_, &p2->score.com_, &p2->score.clg_);

}
void deletes(struct student *head)//删除函数

{
	int n;
	struct student *p2, *p1;
	printf("请输入所需要删除人的学号\n");
	scanf("%d", &n);
	p1 = head;
	p2 = head->next;
	while (p2 != NULL)
	{
		if (n == p2->num)
		{
			p1->next = p2->next;
			break;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

}


int main()
{
	int n, i;
	struct student * head;

	printf(" **************************************************************************************************\n");
	printf("  ************************************************************************************************ \n");
	printf("*   ***********************************敦德励学，知形相长**************************************** *\n");
	printf("*    *******************************************************************************************  *\n");
	printf("*     *****************************************************************************************   *\n");
	printf("*              **********************************************************************             *\n");
	printf("*              *           -------------------------------------------              *             *\n");
	printf("*              *           |         这里是学生管理系统              |              *             *\n");
	printf("*              *            ------------------------------------------              *             *\n");
	printf("*              *                                                                    *             *\n");
	printf("*              **********************************************************************             *\n");
	printf("*    *******************************************************************************************\n");
	printf("*   *********************************************************************************************\n");
	printf("*   ****              忠诚进取                  &&                  精工博艺             *******\n");
	printf("* ************************************************************************************************\n");
	printf(" **************************************************************************************************\n");
	printf("\n");
	printf(" 请创建学生信息\n");
	printf("\n");
	printf(" 输入您所要创建的学生人数:");
	scanf("%d", &n);
	head = build(n);
	printf("\n\n创建成功,请输入任意键继续！");
	while (getchar() != '\n');
	getchar();
	system("cls");
star:printf("\n\n\t\t学生档案管理系统");
	printf("\n\n\t----------------------------------------");
	printf("\n\n\t\t1：查找学生信息系统");
	printf("\n\n\t\t2：修改学生信息系统");
	printf("\n\n\t\t3：插入学生信息系统");
	printf("\n\n\t\t4：删除学生信息系统");
	printf("\n\n\t\t5：输出学生信息系统");
	printf("\n\n\t\t6：学生成绩排序系统");
	printf("\n\n\t\t0：退出系统");
	printf("\n\n\t----------------------------------------");
	printf("\n\n请选择你要的服务（按数字1~6进入）：");
	while (i)
	{
		printf("\n\n\n");
		scanf("%d", &i);
		system("cls");
		switch (i)
		{
		case 1:
			printf("\t1,按学号查询\n");
			printf("\t2,按姓名查询\n");
			printf("\t3,查找不及格学生信息\n\n");
			printf("\t请选择你所需要查询的方式\n");
			printf("请输入1或2来选择你所需要的方式:");
			scanf("%d", &n);
			if (n == 1)
				find(head);
			if (n == 2)
				finds1(head);
			if (n == 3)
				finds2(head);
			printf("\n\n请输入任意字符继续"); break;
		case 2:change(head); printf("修改成功！\n\n"); printf("\n\n请输入任意字符继续"); break;
		case 3:	insert2(head);
			printf("插入完成！\n\n");
			printf("\n\n请输入任意字符继续");
			break;
		case 4:deletes(head); printf("删除成功！\n\n"); printf("\n\n请输入任意字符继续"); break;
		case 5:printfs(head); printf("\n\n请输入任意字符继续"); break;
		case 6:sort(head); break;
		case 0:printf("谢谢您的使用，继续将退出！谢谢！"); break;
		default:printf("输入错误，请重新输入！");
		}
		while (getchar() != '\n');
		getchar();
		system("cls");
		goto star;
		return;
	}
}