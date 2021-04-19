#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<functional>
using namespace std;


template<class T>
struct Less {
	bool operator()(const T&a, const T&b)
	{
		return a < b;
	}
};

template<class T>
struct Greater {
	bool operator()(const T&a, const T&b)
	{
		return a > b;
	}
};

template<class T,class Container, class Compare>
class PriorityQueue
{
public:
	//向下调整
	void shiftDown()
	{
		int parent = 0;
		int child = 2 * parent + 1;
		while (child < arr.size())
		{
			if (child + 1 < arr.size() && cmp(arr[child] , arr[child + 1]))
			{
				child++;
			}
			if (cmp(arr[parent] , arr[child]))
			{
				//交换
				swap(arr[parent], arr[child]);
				//更新位置
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}

	//向上调整
	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			if (cmp(arr[parent] , arr[child]))
			{
				swap(arr[parent], arr[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}

	}

	void push(const T&val)
	{
		arr.push_back(val);
		shiftUp(arr.size() - 1);
	}

	void pop()
	{
		//交换
		swap(arr[0], arr[arr.size() - 1]);
		//尾删
		arr.pop_back();
		//向下调整
		shiftDown();
	}

	T& top()
	{
		return arr.front();
	}

	size_t size()
	{
		return arr.size();
	}

	bool empty()
	{
		return arr.empty();
	}
private:
	Container arr;
	Compare cmp;
};

void test()
{
	priority_queue<int,vector<int>,Greater<int>> pq;
	pq.push(1);
	pq.push(3);
	pq.push(9);
	pq.push(0);
	pq.push(30);
	pq.push(11);
	pq.push(6);

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
}

int main()
{
	test();
	return 0;
}