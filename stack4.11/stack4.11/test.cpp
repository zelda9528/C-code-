#define _CRT_SECURE_NO_WARNINGS 1
#include<stack>
#include<iostream>

using namespace std;


void test()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
}

int main()
{
	test();
	return 0;
}
