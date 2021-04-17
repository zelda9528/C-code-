#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int arr[200];
	int a = 0;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + a);
	for (int i = 0; i < a; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;

}