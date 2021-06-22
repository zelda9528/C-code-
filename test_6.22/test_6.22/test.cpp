#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;
int MinInOrder(int *a, int p1, int p2);
int test(int *a,int size)
{
	if (a == nullptr || size <= 0)
	{
		cout << "ÊäÈë´íÎó\n";
		return -1;
	}
	int p1 = 0;
	int p2 = size - 1;
	int mid;
	while (p2 >= p1)
	{
		if (p2 - p1 == 1)
		{
			mid = p2;
			break;
		}
		mid = (p1 + p2) / 2;

		if (a[p1] == a[p2] && a[mid] == a[p1])
		{
			return MinInOrder(a, p1, p2);
		}

		if (a[mid] >= a[p1])
			p1 = mid;
		if (a[mid] <= a[p2])
			p2 = mid;
		
	}
	return a[mid];
}
int MinInOrder(int *a, int p1, int p2)
{
	int ret = a[p1];
	for (int i = p1; i <= p2; i++)
	{
		if (ret > a[i])
			ret = a[i];
	}
	return ret;
}

int main() 
{
	int a[] = { 1,1,1,0,1 };
	cout << test(a, 5) << endl;
	return 0;
}
