#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
double avg_TurnaroundTime;//平均周转时间
double AQTT;//平均带权周转时间
struct progress {
	char proName[80];
	int arriveTime;//到达时间
	int serviceTime;//服务时间
	//int flag;		//访问标志，未访问1，访问0
	int finishTime;//完成时间
	int cyclingTime;//周转时间
	double float_Wi;//带权周转时间
};

struct progress course[80];
//struct progress course[80]={{0,4},{1,3},{2,5},{3,2},{4,4}};
void health_Examine(int *courseNum)//输入合法性检查
{
	return;
}

void progressNum(int *courseNum)//进程数目
{
	int i = 0;
	for (i = 0; i < *courseNum; i++) {
		printf("请输入第%d个进程的相应信息。\n", i + 1);
		printf("请输入进程名:");
		scanf("%s", course[i].proName);
		printf("请输入到达时间:");
		scanf("%d", &course[i].arriveTime);
		printf("请输入服务时间:");
		scanf("%d", &course[i].serviceTime);
	}
	return;
}

/*void sort_course(int *courseNum)//对进程按照到达时间进行排序
{int i=0,j=0;
	struct progress temp=0;
	for(i=0;i<*courseNum-1; i++)
		for(j=i; j<*courseNum; j++){
			if(course[j].arriveTime > course[j+1].arriveTime) {
				temp = course[j];
				course[j] = course[j+1];
				course[j+1] = temp; }}
	return;
}*/


void finish_Time(int *courseNum)//进程的完成时间
{
	int i = 0;
	if (course[0].arriveTime != 0)//第一个进程的时间
	{
		course[0].finishTime = course[0].arriveTime + course[0].serviceTime;
	}
	course[0].finishTime = course[0].serviceTime;
	for (i = 1; i < *courseNum; i++) {
		if (course[i - 1].finishTime >= course[i].arriveTime) {
			course[i].finishTime = course[i - 1].finishTime + course[i].serviceTime;
		}
		else {
			course[i].finishTime = course[i].arriveTime + course[i].serviceTime;
		}
	}
	return;
}
void cyclingTime(int *courseNum)//周转时间
{
	int i = 0;
	for (i = 0; i < *courseNum; i++) {
		course[i].cyclingTime = course[i].finishTime - course[i].arriveTime;
	}
	return;
}

void float_Wi(int *courseNum)//带权周转时间
{
	int i = 0;
	for (i = 0; i < *courseNum; i++) {
		course[i].float_Wi = (double)course[i].cyclingTime / course[i].serviceTime;
	}
	return;
}

void avgTurnaroundTime(int *courseNum)//平均周转时间
{
	int i = 0, sum_TurnaroundTime = 0;
	for (i = 0; i < *courseNum; i++) {
		sum_TurnaroundTime += course[i].cyclingTime;
	}
	avg_TurnaroundTime = sum_TurnaroundTime / (*courseNum);
	return;
}
void _AQTT(int *courseNum)//平均带权周转时间
{
	int i = 0;
	double sum_float_Wi = 0;
	for (i = 0; i < *courseNum; i++) {
		sum_float_Wi += course[i].float_Wi;
	}
	AQTT = sum_float_Wi / (*courseNum);
	return;
}

void print_FIFO(int *courseNum)//输出进程相关的信息
{
	int i = 0;
	printf("进程的相应信息。\n");
	printf("进程\t到达时间\t服务时间\t完成时间\t周转时间\t带权周转\n");//
	for (i = 0; i < *courseNum; i++) {
		//printf("第%个进程的相应信息。\n", i+1);
		printf("%s\t    %d\t\t    %d\t\t    %d\t\t   %d\t\t   %.002lf\t\t\n", course[i].proName, course[i].arriveTime, course[i].serviceTime, course[i].finishTime, course[i].cyclingTime, course[i].float_Wi);
		//putchar('\n');
	}
	printf("平均周转时间\t平均带权周转时间\n");
	printf("   %.002lf\t\t   %.002lf\n", avg_TurnaroundTime, AQTT);
	return;
}
int main() {
	int courseNum = 5;
	printf("请输入进程数：");
	scanf("%d", &courseNum);
	progressNum(&courseNum);//

	//sort_course(&courseNum);//对进程按照到达时间进行排序
	finish_Time(&courseNum);//进程的完成时间
	cyclingTime(&courseNum);//周转时间
	float_Wi(&courseNum);//带权周转时间
	avgTurnaroundTime(&courseNum);//平均周转时间
	_AQTT(&courseNum);//平均带权周转时间
	print_FIFO(&courseNum);// 
	return 0;
}
