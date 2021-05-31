#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class BitSet {
private:
	//整数数组
	vector<int> _bit;

public:
	//位图的大小和数据范围有关，与数据个数无关
	BitSet(size_t rang) :_bit(rang / 32 + 1)
	{}

	//存储信息
	void Set(size_t num)
	{
		//先计算位置： /32  %32
		int idx = num / 32;		//整数位置
		int bitIdx = num % 32;	//bit位置
		//把对应bit位置1，按位或操作
		_bit[idx] |= 1 << bitIdx;
	}

	//查找信息
	bool find(size_t num)
	{
		//先算位置
		int idx = num / 32;
		int bitIdx = num % 32;
		//再看值
		return _bit[idx] >> bitIdx & 1;
	}

	//删除信息
	void Reset(size_t num)
	{
		//先算位置
		int idx = num / 32;
		int bitIdx = num % 32;
		//置为0: 将1左移后取反，按位与操作
		_bit[idx] &= (~(1 << bitIdx));
	}

};

void test()
{
	BitSet bit(512);
	bit.Set(1);
	bit.Set(512);
	bit.Set(2);
	bit.Set(64);
	bit.Set(15);

	cout << "1是否存在：" << bit.find(1) << endl;
	cout << "2是否存在：" << bit.find(2) << endl;
	cout << "3是否存在：" << bit.find(3) << endl;
	cout << "512是否存在：" << bit.find(512) << endl;

	cout << "------------" << endl;
	bit.Reset(512);
	cout << "512是否存在：" << bit.find(512) << endl;


}


int main()
{
	test();
	return 0;
}