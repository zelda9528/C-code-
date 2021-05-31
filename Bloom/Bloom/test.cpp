#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//位图
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



template <class T,class Hash1, class Hash2, class Hash3>
class BloomFilter {
private:
	//底层封装位图
	BitSet _bit;
	size_t _bitCount;	//记录bit位的个数
public:
	BloomFilter(size_t num)
		:_bit(5 * num)
		,_bitCount(5 * num)
	{}

	//存储信息：使用多个bit位
	void set(const T& val)
	{
		Hash1 h1;
		Hash2 h2;
		Hash3 h3;
		int idx1 = h1(val) % _bitCount;
		int idx2 = h2(val) % _bitCount;
		int idx3 = h3(val) % _bitCount;
		//用位图中封装的接口将三个哈希位置的值置1
		_bit.Set(idx1);
		_bit.Set(idx2);
		_bit.Set(idx3);
	}
	 
	//查找
	bool find(const T&val)
	{
		Hash1 h1;
		Hash2 h2;
		Hash3 h3;
		int idx1 = h1(val) % _bitCount;
		int idx2 = h2(val) % _bitCount;
		int idx3 = h3(val) % _bitCount;
		//
		if (!_bit.find(idx1))
			return false;
		if (!_bit.find(idx2))
			return false;
		if (!_bit.find(idx3))
			return false;

		return true;//可能存在


	}


};

struct HashFun1 {
	size_t operator()(const string & str)
	{
		size_t hash = 0;
		for (const auto &ch : str)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};
struct HashFun2 {
	size_t operator()(const string & str)
	{
		size_t hash = 0;
		for (const auto &ch : str)
		{
			hash = hash * 1313131 + ch;
		}
		return hash;
	}
};
struct HashFun3 {
	size_t operator()(const string & str)
	{
		size_t hash = 0;
		for (const auto &ch : str)
		{
			hash = hash * 65599 + ch;
		}
		return hash;
	}
};

void test()
{
	BloomFilter<string, HashFun1, HashFun2, HashFun3> blm(10);
	string str1 ="1https://editor.csdn.net/md?not_checkout=1&articleId=117413980";
	string str2 ="2https://editor.csdn.net/md?not_checkout=1&articleId=117413980";
	string str3 ="3https://editor.csdn.net/md?not_checkout=1&articleId=117413980";

	blm.set(str1);
	blm.set(str2);
	blm.set(str3);
	string str4 ="4https://editor.csdn.net/md?not_checkout=1&articleId=117413980";

	cout<<"str4存在吗: " << blm.find(str4) << endl;

}

int main()
{
	test();
	return 0;
}