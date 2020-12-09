#define _CRT_SECURE_NO_WARNINGS 1

// #include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <tchar.h>
#include<stdio.h>

typedef enum { true = 1, false = 0 }bool;
#define MAX_PROCESS 10 //进程数上限
#define MAX_RESOURCE_KIND 10 //资源种类上限
#define MAX_RESOURCE_NUM 20	//每种资源可用数上限

int resource;	//实际资源种类数
int process;	//实际进程数
int safe_list[MAX_PROCESS];	//安全序列

struct AVAILABLE {	//可用资源向量
	int resource_number; //资源数目
	int work;	//工作向量	
}Resource[MAX_RESOURCE_KIND], R_backup[MAX_RESOURCE_KIND];

struct PROC {	//进程数据向量表
	int max[MAX_RESOURCE_KIND];	//最大需求矩阵
	int allocation[MAX_RESOURCE_KIND];	//分配矩阵
	int need[MAX_RESOURCE_KIND];	//需求矩阵
	bool finish;	//满足标记
}Process[MAX_PROCESS], P_backup[MAX_PROCESS];

void zero();
void show_me();
void init();
void init_allocation();
void update();
void backup();
void re_backup();
bool allocation();
bool one_allocation(int a, int b, int c);
bool release();
bool one_release(int a, int b, int c);
int is_safe();
void test();
int banker();
void menu();

void zero() {//清零
	for (int i = 0; i < MAX_RESOURCE_KIND; i++) {
		Resource[i].resource_number = 0;
	}
	for (int i = 0; i < MAX_RESOURCE_KIND; i++) {
		for (int j = 0; j < MAX_RESOURCE_KIND; j++) {
			Process[i].max[j] = 0;
			Process[i].allocation[j] = 0;
			Process[i].need[j] = 0;
		}
	}
}


void show_me() {//绘制矩阵
	printf("\n  Available矩阵  ");
	for (int i = 0; i < resource; i++) {
		printf("%d ", Resource[i].resource_number);
	}
	printf("\n");
	printf("\n  Max矩阵");
	for (int i = 0; i < MAX_RESOURCE_KIND * 2 - 7; i++) printf(" ");
	printf("Allocation矩阵");
	for (int i = 0; i < MAX_RESOURCE_KIND * 2 - 14; i++) printf(" ");
	printf("Need矩阵");
	for (int i = 0; i < MAX_RESOURCE_KIND * 2 - 8; i++) printf(" ");

	for (int i = 0; i < process; i++) {
		printf("\n  ");
		for (int j = 0; j < resource; j++) printf("%d ", Process[i].max[j]);
		for (int i = 0; i < MAX_RESOURCE_KIND * 2 - resource * 2; i++) printf(" ");
		for (int j = 0; j < resource; j++)	printf("%d ", Process[i].allocation[j]);
		for (int i = 0; i < MAX_RESOURCE_KIND * 2 - resource * 2; i++) printf(" ");
		for (int j = 0; j < resource; j++) printf("%d ", Process[i].need[j]);
	}
	printf("\n");
}


void init() {//初始化
	int n;
	printf("\n输入资源种类数  ");
	scanf("%d", &n);
	resource = n;
	for (int i = 0; i < resource; i++) {
		printf("\n输入第%d种资源数量  ", i + 1);
		scanf("%d", &n);
		Resource[i].resource_number = n;
	}
	printf("\n输入进程数  ");
	scanf("%d", &n);
	process = n;
	for (int i = 0; i < process; i++) {
		int a, flag;
		flag = 0;
		printf("\n输入进程%d种资源使用数目  ", i + 1);
		for (int j = 0; j < resource; j++) {
			scanf("%d", &a);
			Process[i].max[j] = a;
			if (a > Resource[j].resource_number) flag = 1;
		}
		if (flag == 1) {
			i--;
			printf("\n需求超过资源上限请重新输入\n");
		}
		getchar();
	}
}

void init_allocation() {//初始分配状态
	for (int i = 0; i < process; i++) {
		int a, flag;
		flag = 0;
		printf("\n输入进程%d当前资源占用情况  ", i + 1);
		for (int j = 0; j < resource; j++) {
			scanf("%d", &a);
			Process[i].allocation[j] = a;
			if (a > Resource[j].resource_number) flag = 1;
		}
		if (flag == 1) {
			i--;
			printf("\n当前资源占用超过资源上限请重新输入\n");
		}
	}
	update();
}


void update() {//更新需求矩阵need和资源向量allocation
	for (int i = 0; i < process; i++) {
		for (int j = 0; j < resource; j++) {
			Process[i].need[j] = Process[i].max[j] - Process[i].allocation[j];
			Resource[j].resource_number -= Process[i].allocation[j];
		}
	}
}
bool allocation() {
	backup();
	printf("\n请输入 进程号以及对应资源所分配的数目用空格隔开\n");
	int pro_num;
	scanf("%d", &pro_num);
	int aff[MAX_RESOURCE_KIND];
	for (int i = 0; i < resource; i++) {
		scanf("%d", &aff[i]);
	}
	for (int i = 0; i < resource; i++) {
		if (one_allocation(pro_num - 1, i, aff[i]) == false) {//调用单次分配函数尝试分配
			re_backup();
			return false;
		}
	}
	return true;
}

bool one_allocation(int a, int b, int c) {//单次分配
	if (c > Process[a].need[b]) {
		printf("要求超过所需上限，请求失败\n");
		return false;
	}
	else if (c > Resource[b].resource_number) {
		printf("无足够资源，请求失败\n");
		return false;
	}
	Resource[b].resource_number -= c;
	Process[a].need[b] -= c;
	Process[a].allocation[b] += c;
	return true;
}
void backup() {		//数据备份
	for (int i = 0; i < process; i++) {
		P_backup[i] = Process[i];
	}
	for (int i = 0; i < resource; i++) {
		R_backup[i] = Resource[i];
	}
}
void re_backup() {	//数据还原
	for (int i = 0; i < process; i++) {
		Process[i] = P_backup[i];
	}
	for (int i = 0; i < resource; i++) {
		Resource[i] = R_backup[i];
	}
}
bool release() {	//释放资源
	backup();
	printf("\n请输入 进程号以及对应资源所分配的数目用空格隔开\n");
	int pro_num;
	scanf("%d", &pro_num);
	int aff[MAX_RESOURCE_KIND];
	for (int i = 0; i < resource; i++) {
		scanf("%d", &aff[i]);
	}
	for (int i = 0; i < resource; i++) {
		if (one_release(pro_num, i, aff[i]) == false) {
			re_backup();
			return false;
		}
	}
	return true;
}
bool one_release(int a, int b, int c) {//资源释放
	if (c > Process[a].allocation[b]) {
		printf("释放超过所有上限，请求失败\n");
		return false;
	}
	Resource[b].resource_number += c;
	Process[a].need[b] += c;
	Process[a].allocation[b] -= c;
	return true;
}

int is_safe() {	//安全性检测算法

	for (int i = 0; i < resource; i++) {
		Resource[i].work = Resource[i].resource_number;
	}
	for (int i = 0; i < process; i++) {
		Process[i].finish = false;
		safe_list[i] = 0;
	}
	test();
	bool flag = true;
	for (int i = 0; i < process; i++) {
		if (Process[i].finish == false) {
			flag = false;
			break;
		}
	}
	if (flag == true) {
		printf("\n系统状态安全");
		printf("\n安全序列为  ");
		for (int i = 0; i < process; i++) {
			printf("%d ", safe_list[i]);
		}
		return 1;
	}
	else {
		printf("\n系统状态不安全");
		return -1;
	}
}


void test() {	//安全性算法的递归分支
	for (int i = 0; i < process; i++) {
		bool flag = true;
		if (Process[i].finish == false) {
			for (int j = 0; j < resource; j++) {
				if (Process[i].need[j] > Resource[j].work) {
					flag = false;
					break;
				}
			}
			if (flag == true) {
				for (int j = 0; j < resource; j++) {
					Resource[j].work += Process[i].allocation[j];
					Process[i].finish = true;
				}
				for (int k = 0; k < process; k++) {
					if (safe_list[k] == 0) {
						safe_list[k] = i + 1;
						break;
					}
				}
				test();	//递归处理
			}
		}
	}
}


int banker() {//银行家算法
	backup();	//备份
	if (allocation() == false) return -1;
	bool flag;
	flag = is_safe();
	if (flag == true) {
		char k;
		printf("\n是否分配（y/n）  ");
		scanf("%c", &k);
		if (k == 'y') return 1;
		else {
			re_backup();
			return -1;
		}
	}
	else {
		re_backup();
		return -1;
	}
}
void menu() {	//菜单函数
	printf("\n请输入指令\n");
	printf("\n初始化(init) 显示数据矩阵(show) 判断安全性(safe)\n申请资源(request) 释放资源(release) 退出(quit)\n清屏(clear)\n");
	char code[20];
	while (1) {
		printf("\n");
		scanf("%s", code);
		if (_stricmp(code, "init") == 0) {	//重置操作
			zero();
			init();
			init_allocation();
		}
		else if (_stricmp(code, "show") == 0) {	//显示功能
			show_me();
		}
		else if (_stricmp(code, "safe") == 0) {	//判断安全性
			is_safe();
		}
		else if (_stricmp(code, "request") == 0) {	//申请资源
			printf("\n是否使用银行家算法保证安全性（y/n）\n");
			scanf("%s", code);
			if (_stricmp(code, "y") == 0) banker();
			else allocation();
		}
		else if (_stricmp(code, "release") == 0) {	//释放资源
			release();
		}
		else if (_stricmp(code, "quit") == 0) {	//退出
			return;
		}
		else if (_stricmp(code, "clear") == 0) {	//清屏
			system("cls");
			printf("\n请输入指令\n");
			printf("\n初始化(init) 显示数据矩阵(show) 判断安全性(safe)\n申请资源(request) 释放资源(release) 退出(quit)\n清屏(clear)\n");
		}
		else printf("命令无效，请重新输入\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	zero();
	init();
	init_allocation();
	show_me();
	is_safe();*/
	menu();
	getchar();
	return 0;
}